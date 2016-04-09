#!/usr/bin/env bash
find . -name makefile |
while read p
do
	cdir=`readlink -f .`
	p=`readlink -f "$p"`
	cd "${p%%/makefile}/"    # ... or any other command using $filename
	make
	./run < args
	cd "$cdir"
done
