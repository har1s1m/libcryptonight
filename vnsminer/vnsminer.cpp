#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <uint256.h>
#include <arith_uint256.h>
#include <type_traits>
#include <algorithm>
#include <jsonrpccpp/client/connectors/httpclient.h>
#include "jsonrpc_getwork.h"
#include "cryptonight.h"

inline std::string toHex(uint64_t _n) 
{
        std::ostringstream ss; 
        ss << std::hex << std::setfill('0') << std::setw(sizeof(_n) * 2) << _n; 
        return ss.str();
}

bool getWork(const std::string & url, std::string & powHash, std::string & diff){
        ::JsonrpcGetwork * p_client = new ::JsonrpcGetwork(new jsonrpc::HttpClient(url));
	Json::Value v = p_client->eth_getWork();
	//std::cout<< v.toStyledString()<<std::endl;
	if (v.isArray() && v.size() == 3){
		powHash = v[0].asString();
		diff = v[2].asString();
		std::cout<<powHash<<std::endl;
		std::cout<<diff<<std::endl;
		return true;
	}
	return false;
}

bool submitWork(const std::string &url, unsigned long long nonce, const uint256 & job, const uint256 & pow){
        ::JsonrpcGetwork * p_client = new ::JsonrpcGetwork(new jsonrpc::HttpClient(url));
	try
	{
		bool accepted = p_client->eth_submitWork(std::string("0x") + toHex(nonce)
						, std::string("0x") + job.ToString()
						, std::string("0x") + pow.ToString());
		if (accepted) {
			std::cout<<"Solution Accepted!"<<std::endl;
			return true;
		}
		else {
			std::cout<<"Solution Rejected!"<<std::endl;
		}
	}
	catch (jsonrpc::JsonRpcException const& _e)
	{
		std::cout<< "Failed to submit solution.";
		std::cout<< (_e.what());
	}
	return false;
} 

int main(int argc, char * argv[])
{
	char input [48] = {0};
	unsigned long long nonce = 0;
	unsigned char hash[128];
	int i = 0;

	std::string powHash, diff = "";
	if (!getWork(argv[1], powHash, diff)) exit(1);

	// Note: hash1.data is little-endian	
	uint256 hash1 = uint256S(powHash);
	//std::cout<<hash1.ToString()<<std::endl;
	//printf("%02x\n", *hash1.begin());

	uint256 target = uint256S(diff);
	//std::cout<<target.ToString()<<std::endl;

	while(true){
		// big-endian
		for(i=0;i<32;i++)input[i]=*(hash1.begin()+(32-i-1));	
		memset(&input[32],0,8);
		// big-endian
		memcpy(&input[40], &nonce, sizeof(nonce));

		cryptonight_hash(hash, input, 48);
		// Note: hash is big-endian, result is little-endian. reverse it.
		uint256 result; for(i = 0; i<32;i++) *(result.begin() + (32-i-1)) = hash[i];
		
		if (UintToArith256(target)>UintToArith256(result)){
			printf("%s.%0llx\n",result.ToString().c_str(), nonce);
			if (submitWork(argv[1], nonce, hash1, result)){

			}
			break;
		}
		nonce++;
	}

	return 0;
}

// g++ -I/usr/include/jsoncpp -I/usr/include/jsonrpccpp -o vnsminer -g vnsminer.cpp -L./build -lcryptonight -ljsonrpccpp-client -ljsonrpccpp-common -ljsoncpp

// ref: https://cryptonote.org/cns/cns008.txt
