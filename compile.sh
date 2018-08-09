#!/bin/bash

#Compilation script

g++ -c -o db.o db.cpp;
g++ db.o main.cpp -o main;
echo "Compiled main file. Run by ./main";
