cmake_minimum_required(VERSION 2.8)

project(CryptoNight)

find_package(OpenSSL)

set(CMAKE_CXX_FLAGS "-g -O2 -Wall")

add_library(cryptonight 
	./crypto/aesb.c
	./crypto/c_blake256.c
	./crypto/c_groestl.c
	./crypto/c_jh.c
	./crypto/c_keccak.c
	./crypto/c_keccak.h
	./crypto/c_skein.c
	./crypto/oaes_config.h
	./crypto/oaes_lib.c
	cryptonight.c)

install(FILES cryptonight.h DESTINATION include)
install(TARGETS cryptonight LIBRARY ARCHIVE DESTINATION lib)

# mkdir -p build && cd build && cmake -DCMAKE_INSTALL_PREFIX=./ ../ && make && make install
