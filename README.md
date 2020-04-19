安装要求 Ubuntu 16.04 LTS (64-bit) 

安装依赖

    sudo apt-get update
    sudo apt-get install autoconf cmake make automake libtool git libboost-all-dev libssl-dev g++ libcurl4-openssl-dev

克隆项目

    git clone https://github.com/malechain/columbu.git
    cd columbu
    git checkout master # may substitute "master" with current release tag
    git submodule update --init --recursive
    cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo .
    make


运行公链
    ./witness_node


连接钱包

    ./cli_wallet

