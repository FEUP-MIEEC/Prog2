#!/usr/bin/env bash

echo "Begin" > out/aula_compile_output

mkdir out
# Compilar todos os ficheiros na pasta.
GLOBIGNORE="*_.c"
for f in *.c; do
    echo -n "Compiling the file" $f"..." | tee -a out/compile
    clang $f -g -lm -o ${f%.*}.out | tee -a out/compile
    echo " done!" | tee -a out/compile
done

cat out/compile

echo "Executing the compiled programs"
# ./01.out | tee out/01.output
# ./02.out | tee out/02.output
# ./03.out | tee out/03.output
# ./04.out | tee out/04.output
# ./05.out | tee out/05.output
# ./06.out | tee out/06.output
# ./07.out | tee out/07.output
# ./08.out | tee out/08.output
# ./09.out | tee out/09.output

