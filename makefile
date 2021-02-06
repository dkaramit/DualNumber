Path=$(PWD)

LONG=  #leave empty to use doubles
# LONG=long #set to long , in order to use long doubles

Headers=$(wildcard ./*.hpp)

CC=g++
STD=-std=c++17
OPT=-O3



FLG=  $(STD)  -I "$(Path)"  -lm   $(OPT) -DLONG=$(LONG) 

all:Dual_example.run 


Dual_example.run: makefile $(Headers) Dual_example.cpp
	$(CC) -o "$(Path)/Dual_example.run" "$(Path)/Dual_example.cpp" $(FLG) -Wall


clean:
	@[ -f "$(Path)/Dual_example.run" ] && rm "$(Path)/Dual_example.run" || true