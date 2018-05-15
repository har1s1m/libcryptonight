cmake_minimum_required(VERSION 2.8)

project(libcryptonight)

find_package(OpenSSL)

set(CMAKE_CXX_FLAGS "-g -Wall")

include_directories(${LIBCRYPTONIGHT_SOURCE_DIR}/crypto)

add_library(libcryptonight 
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
