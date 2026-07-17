# FileOrganizer

Application that organize files based on the file extension.

## Installation
### Windows
- Make sure gcc compiler is installed.

```
git clone https://github.com/amaleshkk/FileOrganizer.git
cd FileOrganizer
g++ src/*.cpp -o fileOrganizer
```
### Linux
- Make sure gcc compiler and cmake is installed.

```
sudo apt install build-essential git cmake
git clone https://github.com/amaleshkk/FileOrganizer.git
cd FileOrganizer
mkdir build
cd build
cmake ..
cmake --build .
```
### Alternate Method (without cmake)
```
git clone https://github.com/amaleshkk/FileOrganizer.git
cd FileOrganizer
g++ src/*.cpp -o fileOrganizer
```
## Usage

```
# windows
./fileOrganizer.exe "<inputFolderPath>" "<outputFolderPath>"
# linux
./fileOrganizer "<inputFolderPath>" "<outputFolderPath>"
```

## License

[MIT](https://choosealicense.com/licenses/mit/)