#!/usr/bin/env bash

mkdir out
echo "Begin" > out/aula_compile_output

make

echo "Executing the compiled programs"
./run| tee out/run.output

