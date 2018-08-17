CC=mpicxx
CFLAGS=-o
INCLUDEFLAGS=-I.

EXECUTABLE=mpi-hello.exe local-max.exe systolic-max.exe systolic-matvec.exe

all: $(EXECUTABLE)

mpi-hello.exe:
	$(CC) mpi_hello.c $(CFLAGS) $@ $(INCLUDEFLAGS)

local-max.exe: 
	$(CC) slurp_file.cc local-max.cc $(CFLAGS) $@ $(INCLUDEFLAGS)

systolic-max.exe: 
	$(CC) slurp_file.cc systolic-max.cc $(CFLAGS) $@ $(INCLUDEFLAGS)

systolic-matvec.exe: 
	$(CC) slurp_file.cc systolic-matvec.cc $(CFLAGS) $@ $(INCLUDEFLAGS)


