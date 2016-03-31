#
# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make lista' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = clang

CFLAGS  = -g

# Stands for Final FileName
FFN  = run

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: armazem
	@echo "Done. Run the file '$(FFN)' to see the output.";
	@echo "Run 'make finish' if you wish to clear the *.o files and other necessary files for building.";

# To create the final executable file we need the object file
# lista.o:
#
armazem: deps
	$(CC) $(CFLAGS) -o $(FFN) teste_armazem.c contentor.o armazem.o pilha_contentores.o fila_contentores.o

# To create the object file lista.o, we need the source
# file lista.c:
#
deps: 
	$(CC) $(CFLAGS) -c contentor.c -c armazem.c -c pilha_contentores.c -c fila_contentores.c
	
# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	@$(RM) run *.o *~
	@echo "Cleaned";
	
finish: 
	@$(RM) *.o *~
	@echo "Cleaned build files.";