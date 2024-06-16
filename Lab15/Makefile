CC = g++
CXXFLAGS = -std=c++11 -Wall
LIBPATH = ./

INCLUDEPATH = -I$(LIBPATH)
EXE1 = DS091
EXE2 = DS092
EXE3 = DS093

EXEALL = $(EXE1) $(EXE2) $(EXE3)

all: $(EXEALL)

$(EXE1): $(EXE1).cpp
	$(CC) $(CXXFLAGS) -o $@ $^ $(INCLUDEPATH)

$(EXE2): $(EXE2).cpp
	$(CC) $(CXXFLAGS) -o $@ $^ $(INCLUDEPATH)
	
$(EXE3): $(EXE3).cpp
	$(CC) $(CXXFLAGS) -o $@ $^ $(INCLUDEPATH)

clean:
	rm -f $(EXEALL)

run1: $(EXE1)
	./$(EXE1)

run2: $(EXE2)
	./$(EXE2)

run3: $(EXE3)
	./$(EXE3)
