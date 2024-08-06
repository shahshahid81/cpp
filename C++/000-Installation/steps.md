# Installation

## Ubuntu

### Installation Command
```
sudo apt update;
sudo apt install -y build-essential git cmake libssh-dev libsqlite3-dev libpcre2-dev bison flex;
```

### To Run a program
1. Compile the program using ```g++ -Wall -std=c++17 main.cpp -o main```
   `-Wall` is to enable all warnings. `-std` is to choose which standard to use for compiling. `-o` is to specify the name of the output file.
2. Run the program using `./main`  command.

### Online **shell**
* https://cpp.sh/
* https://www.onlinegdb.com/
* https://ideone.com/