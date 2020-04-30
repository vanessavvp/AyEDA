# Macros
SRC = src/
SRC_TEST = $(SRC)test.cpp $(SRC)DNI.cpp $(SRC)counter.cpp
SRC_MOD = $(SRC)mainProgram.cpp $(SRC)ISBN.cpp $(SRC)counter.cpp
OUT = bin/
OUT_TEST_FILE = $(OUT)exeTest
OUT_DEMO_FILE= $(OUT)exe
OUT_STAT_FILE = $(OUT)exeStat
OUT_MOD = $(OUT)exeMod

# Reglas explícitas
default:
	g++ -g $(SRC_MOD) -o $(OUT_DEMO_FILE)

run: default 

test: 
	g++ -g $(SRC_TEST) -o $(OUT_TEST_FILE)

clean:
	-rm bin/*



