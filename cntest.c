#include <stdlib.h>
#include <stdio.h>

void cryptonight_hash(void* output, const void* input, size_t len);

int main(int argc, char * argv[])
{
	unsigned char hash[128];
	int i = 0;
	cryptonight_hash(hash, "123123123", 9);
	for (i = 0; i < 32; i++)printf("%02x", hash[i]);
	printf("\n");	
	return 0;
}

// gcc -o cntest -g cntest.c -L./build/lib -lcryptonight
