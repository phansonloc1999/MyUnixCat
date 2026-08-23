# MyUnixCat

A reimplementation of GNU's cat command for Unix and Unix-like platforms with minimal dependencies written in C/C++

## Prerequisites

### Linux (built and tested on)

*G++ version 9.3.0 or above*

*GNU Make 4.2.1 or above*

## Installation

Clone the repository

``$ git clone https://github.com/phansonloc1999/MyUnixCat.git``

``$ cd MyUnixCat``

Compile and install

### Linux  
``$ sudo make install``

## How to use

``mycat -h`` to show usages

``mycat [IN FILE PATH]`` to display file contents into the current shell window

``mycat > [OUT FILE PATH]`` to input contents and save them to out file

``mycat [IN FILE PATH] [OUT FILE PATH]`` to copy contents from in file to out file
