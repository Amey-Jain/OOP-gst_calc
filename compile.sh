#!/bin/bash

#Compilation script

g++ -g -Wall -c -o db.o db.cpp;
g++ -g -Wall -c -o product.o product.cpp;
g++ -g -Wall db.o product.o main.cpp -o main;
echo "Compiled main file. Run by ./main";
