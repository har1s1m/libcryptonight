cmake_minimum_required(VERSION 2.8)

project(CryptoNight)

find_package(OpenSSL)
find_package(Boost)


set(CMAKE_CXX_FLAGS "-g -O2 -Wall -maes -std=c++11 -std=gnu++11")
set(CMAKE_C_FLAGS "-g -O2 -Wall -maes")

add_library(cryptonight 
	./crypto/groestl.h
	./crypto/oaes_lib.h
	./crypto/random.c
	./crypto/warnings.h
	./crypto/jh.h
	./crypto/aesb.c
	./crypto/hash-extra-jh.c
	./crypto/blake256.c
	./crypto/tree-hash.c
	./crypto/hash.c
	./crypto/hex.h
	./crypto/chacha.c
	./crypto/slow-hash.c
	./crypto/hash-ops.h
	./crypto/hash.h
	./crypto/keccak.h
	./crypto/generic-ops.h
	./crypto/skein.h
	./crypto/memwipe.c
	./crypto/hash-extra-groestl.c
	./crypto/crypto.cpp
	./crypto/varint.h
	./crypto/skein.c
	./crypto/crypto.h
	./crypto/pod-class.h
	./crypto/oaes_lib.c
	./crypto/hash-extra-skein.c
	./crypto/hash-extra-blake.c
	./crypto/crypto-ops-data.c
	./crypto/util.h
	./crypto/chacha.h
	./crypto/blake256.h
	./crypto/span.h
	./crypto/oaes_config.h
	./crypto/initializer.h
	./crypto/memwipe.h
	./crypto/keccak.c
	./crypto/.gitignore
	./crypto/skein_port.h
	./crypto/readme.md
	./crypto/random.h
	./crypto/crypto-ops.c
	./crypto/groestl.c
	./crypto/int-util.h
	./crypto/jh.c
	./crypto/groestl_tables.h
	./crypto/crypto-ops.h
	cryptonight.h
	cryptonight.c)

install(FILES cryptonight.h DESTINATION include)
install(TARGETS cryptonight LIBRARY ARCHIVE DESTINATION lib)

# mkdir -p build && cd build && cmake -DCMAKE_INSTALL_PREFIX=./ ../ && make && make install

