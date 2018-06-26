# libcryptonight
cryptonight library

# building

## depends

```
sudo apt-get install libjsonrpccpp-dev
sudo apt-get install libjsoncpp-dev
sudo apt-get install libcurl4-openssl-dev
```

## system requirements
1. cmake > 3.5

## build

```
git clone --branch vnsminer https://github.com/imharrywu/libcryptonight
git checkout origin/vnsminer -b master
mkdir build
cd build && cmake .. && make
```

## run

```
./vnsminer http://127.0.0.1:8888/0x12345123451234512345
```



