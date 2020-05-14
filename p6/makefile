# Macros
SRC = src/
SRC_MAIN_PROGRAM = $(SRC)optionsMain.cpp $(SRC)DNI.cpp $(SRC)counter.cpp
OUT = bin/
OUT_MAIN_FILE= $(OUT)exe

# Reglas explícitas
default:
	g++ -g $(SRC_MAIN_PROGRAM) -o $(OUT_MAIN_FILE)

run: default 

clean:
	-rm bin/*