// Copyright (c) 2012-2013 The Cryptonote developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

// Modified for CPUminer by Lucas Jones

#include <stdlib.h> 
#include "cryptonight.h"

void cryptonight_hash(void* output, const void* input, size_t len) {
	cn_slow_hash(input, len, output, 1, 0);
	return ;
}
