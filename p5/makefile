# Macros
SRC = src/
SRC_TEST = $(SRC)test.cpp $(SRC)DNI.cpp $(SRC)counter.cpp
SRC_DEMO_PROGRAM = $(SRC)demoModeProgram.cpp $(SRC)DNI.cpp $(SRC)counter.cpp
SRC_STAT_PROGRAM = $(SRC)statModeProgram.cpp $(SRC)DNI.cpp $(SRC)counter.cpp
OUT = bin/
OUT_TEST_FILE = $(OUT)exeTest
OUT_DEMO_FILE= $(OUT)exeDemo
OUT_STAT_FILE = $(OUT)exeStat

# Reglas explícitas
default:
	g++ -g $(SRC_DEMO_PROGRAM) -o $(OUT_DEMO_FILE)

run: default 

test: 
	g++ -g $(SRC_TEST) -o $(OUT_TEST_FILE)

demo:
	g++ -g $(SRC_DEMO_PROGRAM) -o $(OUT_DEMO_FILE)
	
stat:
	g++ -g $(SRC_STAT_PROGRAM) -o $(OUT_STAT_FILE)




