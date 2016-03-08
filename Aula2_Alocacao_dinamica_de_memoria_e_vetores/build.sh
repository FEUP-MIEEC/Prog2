#!/usr/bin/env bash

mkdir out
echo "Begin" > out/aula_compile_output
# Compilar todos os ficheiros na pasta.
GLOBIGNORE="*_.c"
for f in [0-9]*.c; do
    echo -n "Compiling the file" $f"..." | tee -a out/compile
    clang $f -g -lm -o ${f%.*}.out | tee -a out/compile
    echo " done!" | tee -a out/compile
done

clang -o vetor.o -c vetor.c

clang 03.2_.c vetor.o
clang 03.3_.c vetor.o


echo "Executing the compiled programs"
./01.out <<< "8 1 2 3 5 4 6 7 8 " | tee out/01.output

