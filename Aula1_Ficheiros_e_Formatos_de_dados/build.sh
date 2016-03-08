#!/usr/bin/env bash

echo "Begin" > out/aula_compile_output

mkdir out
# Compilar todos os ficheiros na pasta.
for f in {[0-9][0-9],[0-9][0-9].[0-9]}.c; do
    echo -n "Compiling the file" $f"..." | tee -a out/compile
    clang $f -g -lm -o ${f%.*}.out | tee -a out/compile
    echo " done!" | tee -a out/compile
done


echo "Executing the compiled programs"
./01.1.out | tee out/01.1.output
./01.3.out | tee out/01.3.output
./02.out | tee out/02.output
./03.out | tee out/03.output
./04.out | tee out/04.output
./05.out | tee out/05.output

