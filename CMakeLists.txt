cmake_minimum_required(VERSION 2.8)

project(CryptoNight)

find_package(OpenSSL)
find_package(Boost)


set(CMAKE_CXX_FLAGS "-g -O2 -Wall -maes -std=c++11 -std=gnu++11")
set(CMAKE_C_FLAGS "-g -O2 -Wall -maes")

add_library(cryptonight 
	./cryptonight/groestl.h
	./cryptonight/oaes_lib.h
	./cryptonight/random.c
	./cryptonight/warnings.h
	./cryptonight/jh.h
	./cryptonight/aesb.c
	./cryptonight/hash-extra-jh.c
	./cryptonight/blake256.c
	./cryptonight/tree-hash.c
	./cryptonight/hash.c
	./cryptonight/hex.h
	./cryptonight/chacha.c
	./cryptonight/slow-hash.c
	./cryptonight/hash-ops.h
	./cryptonight/hash.h
	./cryptonight/keccak.h
	./cryptonight/generic-ops.h
	./cryptonight/skein.h
	./cryptonight/memwipe.c
	./cryptonight/hash-extra-groestl.c
	./cryptonight/crypto.cpp
	./cryptonight/varint.h
	./cryptonight/skein.c
	./cryptonight/crypto.h
	./cryptonight/pod-class.h
	./cryptonight/oaes_lib.c
	./cryptonight/hash-extra-skein.c
	./cryptonight/hash-extra-blake.c
	./cryptonight/crypto-ops-data.c
	./cryptonight/util.h
	./cryptonight/chacha.h
	./cryptonight/blake256.h
	./cryptonight/span.h
	./cryptonight/oaes_config.h
	./cryptonight/initializer.h
	./cryptonight/memwipe.h
	./cryptonight/keccak.c
	./cryptonight/.gitignore
	./cryptonight/skein_port.h
	./cryptonight/readme.md
	./cryptonight/random.h
	./cryptonight/crypto-ops.c
	./cryptonight/groestl.c
	./cryptonight/int-util.h
	./cryptonight/jh.c
	./cryptonight/groestl_tables.h
	./cryptonight/crypto-ops.h
	cryptonight.h
	cryptonight.c)

install(FILES cryptonight.h DESTINATION include)
install(TARGETS cryptonight LIBRARY ARCHIVE DESTINATION lib)

# mkdir -p build && cd build && cmake -DCMAKE_INSTALL_PREFIX=./ ../ && make && make install

AUX_SOURCE_DIRECTORY(./vnsminer/ VNS_MINER_SRCS)
include_directories(./vnsminer/)
include_directories(./)
ADD_EXECUTABLE(vnsminer ${VNS_MINER_SRCS})
TARGET_LINK_LIBRARIES(vnsminer jsonrpccpp-client)
TARGET_LINK_LIBRARIES(vnsminer jsonrpccpp-common)
TARGET_LINK_LIBRARIES(vnsminer jsoncpp)
TARGET_LINK_LIBRARIES(vnsminer cryptonight)
