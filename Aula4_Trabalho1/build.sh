#!/usr/bin/env bash

mkdir out
echo "Begin" > out/aula_compile_output

clang -c lista.c
clang lista-teste.c lista.o

echo "Executing the compiled programs"
valgrind --leak-check=full -v ./a.out| tee out/a.output

