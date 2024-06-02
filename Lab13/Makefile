CC = g++ 
LIBPATH = ./
LIB = $(LIBPATH)Queue.cpp
INCLUDEPATH = -I$(LIBPATH)
EXE1 = DS071
EXE2 = DS072
EXE3 = DS073
EXE4 = DS074
EXE5 = DS075
EXE6 = DS076

EXEALL = $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5) $(EXE6)

all : $(EXEALL)

$(EXE1): $(EXE1).cpp $(LIB)
	$(CC) -o $@ $^ $(INCLUDEPATH)

$(EXE2): $(EXE2).cpp $(LIB)
	$(CC) -o $@ $^ $(INCLUDEPATH)
	
$(EXE3): $(EXE3).cpp $(LIB)
	$(CC) -o $@ $^ $(INCLUDEPATH)

$(EXE4): $(EXE4).cpp $(LIB)
	$(CC) -o $@ $^ $(INCLUDEPATH)

$(EXE5): $(EXE5).cpp $(LIB)
	$(CC) -o $@ $^ $(INCLUDEPATH)

$(EXE6): $(EXE6).cpp $(LIB)
	$(CC) -o $@ $^ $(INCLUDEPATH)
clean:
	rm $(EXEALL)