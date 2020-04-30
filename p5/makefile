# Macros
SRC = src/
SRC_TEST = $(SRC)test.cpp $(SRC)DNI.cpp $(SRC)counter.cpp
SRC_MAIN_PROGRAM = $(SRC)mainProgram.cpp $(SRC)DNI.cpp $(SRC)counter.cpp
OUT = bin/
OUT_TEST_FILE = $(OUT)exeTest
OUT_MAIN_FILE= $(OUT)exe
OUT_STAT_FILE = $(OUT)exeStat

# Reglas explícitas
default:
	g++ -g $(SRC_MAIN_PROGRAM) -o $(OUT_MAIN_FILE)

run: default 

test: 
	g++ -g $(SRC_TEST) -o $(OUT_TEST_FILE)

clean:
	-rm bin/*



