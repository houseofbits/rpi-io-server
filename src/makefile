IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = Parser.h Server.h IOHandler.h Request.h IOException.h BasicResponse.h HttpStatusCodes.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o Parser.o Server.o IOHandler.o Request.o BasicResponse.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

rpiioserver: $(OBJ)
	$(CC) -o ../$@ $^ $(CFLAGS) $(LIBS)  ../abelibs/IOPi/ABE_IoPi.cpp

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
