Diff between this version(ver1~6) and cryptonight v7
=============================================================

https://monero.stackexchange.com/questions/7923/what-exactly-has-been-changed-in-pow-algorithms-in-the-v7-fork

v1~6

```
state = keccak(block_data)
scratchpad = fill_scratchpad(state)
loop 524,288 times
  address = compute_address(scratchpad, state)
  modification1(scratchpad, address)
  address = compute_address(scratchpad, state)
  modification2(scratchpad, address)
text = reduce(scratchpad, state)
result = extra_hash(keccak(mix(text, state)))
```

v7

```
state = keccak(block_data)
tweak = compute_tweak(block_data, state)
scratchpad = fill_scratchpad(state)
loop 524,288 times
  address = compute_address(scratchpad, state)
  modification1(scratchpad, address)
  extra_modification1(scratchpad, address)
  address = compute_address(scratchpad, state)
  modification2(scratchpad, address)
  extra_modification2(scratchpad, address, tweak)
text = reduce(scratchpad, state)
result = extra_hash(keccak(mix(text, state)))
```
