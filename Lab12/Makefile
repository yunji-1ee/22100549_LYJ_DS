CC = g++ 
LIBPATH = ./
LIB = $(LIBPATH)Queue.cpp
INCLUDEPATH = -I$(LIBPATH)
EXE1 = DS061
EXE2 = DS062
EXE3 = DS063
EXEALL = $(EXE1) $(EXE2) $(EXE3)

all : $(EXEALL)

$(EXE1): $(EXE1).cpp $(LIB)
	$(CC) -o $@ $^ $(INCLUDEPATH)

$(EXE2): $(EXE2).cpp $(LIB)
	$(CC) -o $@ $^ $(INCLUDEPATH)
	
$(EXE3): $(EXE3).cpp $(LIB)
	$(CC) -o $@ $^ $(INCLUDEPATH)

clean:
	rm $(EXEALL)