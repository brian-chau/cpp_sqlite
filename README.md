1. Install SQLite with `sudo apt-get install sqlite3 libsqlite3-dev`
2. Install fmt library.
    1. Install `cmake`:
        ```
        sudo apt install cmake
        ```
    2. Download fmt library from: https://fmt.dev/latest/index.html
    3. Unzip the `fmt` downloaded file.
    4. Follow the instructions from here: https://fmt.dev/latest/usage.html#installing-the-library
        1. Run the following commands:
            ```
            mkdir build
            cd build
            cmake ..
            make
            sudo make install
            ```
3. Install OpenSSL from here: https://www.openssl.org/source/
    1. Download the latest OpenSSL tar.gz file.
    2. Run the following commands:
    ```
    sudo apt update
    sudo apt install build-essential checkinstall zlib1g-dev -y
    sudo apt upgrade
    sudo tar -xzf openssl-3.0.3.tar.gz
    cd openssl-3.0.3
    sudo ./Configure
    sudo make
    sudo make test
    ln -s libssl.so.3 libssl.so
    sudo ldconfig
    sudo make install
    ```
4. Install `curl` from here: https://curl.se/download.html
    1. Download the latest curl tar.gz file.
    2. Run the following commands to install it:
    ```
    sudo apt update
    sudo tar -xzf curl-7.83.1.tar.gz
    cd curl-7.83.1
    sudo ./configure --with-openssl --with-gnutls --with-wolfssl
    sudo make
    sudo make test
    sudo make install
    ```
