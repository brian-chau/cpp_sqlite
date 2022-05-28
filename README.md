# cpp_sqlite

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
