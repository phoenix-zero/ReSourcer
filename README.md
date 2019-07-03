[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

# ReSourcer

Using C++ for developing something awesome??

## Introducing ReSourcer
### A lightweight RCC and resource library for C++

Compiling and managing your resource is easier than you think.

## Build using

- C++
> C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or "C with Classes". The language has expanded significantly over time, and modern C++ has object-oriented, generic, and functional features in addition to facilities for low-level memory manipulation. It is almost always implemented as a compiled language, and many vendors provide C++ compilers, including the Free Software Foundation, LLVM, Microsoft, Intel, and IBM, so it is available on many platforms.
- Boost
> Boost is a set of libraries for the C++ programming language that provide support for tasks and structures such as linear algebra, pseudorandom number generation, multithreading, image processing, regular expressions, and unit testing. It contains over eighty individual libraries.

## Installation

- Download the latest ReSourcer source
```bash 
git clone git@github.com:phoenix-zero/ReSourcer.git
```
- Build the compiler
```bash
# From the RCC directory
mkdir build && cd build
qmake ..
make
```
- Build the library
```bash
# From the lib directory
mkdir build && cd build
qmake ..
make
```

- Copy resourcer.hpp to /usr/local/include
- Copy libReSourcer_Lib.a to /usr/local/lib
- Copy ReSourcer_RCC (executable) to /usr/local/bin

> Note: The build system can be improved a lot, working on that.

- [x] Done

## Features and support
- [x] ReSourcer is tested with both binary and text files

- [ ] Files are kept by id, path no supported yet

- [ ] Needs an internal file handler, to handle both resource files and external files

## Example

In example folder, you can find

- SimpleTest
```bash
# For graphical version
make graphic=-DGRAPHIC incsLoc=/usr/local/include linksLoc=/usr/local/lib rccLoc=/usr/local/bin
# For text version 
make incsLoc=/usr/local/include linksLoc=/usr/local/lib rccLoc=/usr/local/bin
./exec
```

- NQueen
```bash
make incsLoc=/usr/local/include linksLoc=/usr/local/lib rccLoc=/usr/local/bin
./exec
```

> Both the examples, run the RCC to compile *.rcc into *.cpp files. ReSourcer_RCC uses -o tag for output and -i (positional) tag for input
> Example "ReSourcer_RCC res.rcc -o res.cpp" produces res.cpp from res.rcc


## Documentation comming soon



# Contribution
Feel free to contribute, no restrictions yet :stuck_out_tongue_winking_eye:
