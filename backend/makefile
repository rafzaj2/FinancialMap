IDIR = ./include
CXX = g++ -std=c++11
CFLAGS=-I ~/Programing/FinancialMap/backend
SRCDIR=./src

ODIR=./obj

LIBS=-lpistache -lpthread

_DEPS = authentication.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o authentication.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

# obj/main.o: src/main.cpp include/authentication.h
# 	g++ -std=c++11 -c src/main.cpp $(CFLAGS)

make: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 


# LIBS=-lpistache -lpthread
# IDIR = ./include
# CXXFLAGS=-I$(IDIR)
# ODIR=./obj
# SRCDIR=./src


# make: backendServer.out
	

# backendServer.out: main.o authentication.o
# 	g++ -std=c++11 -o backendServer main.o authentication.o $(LIBS) $(CXXFLAGS)

# main.o: main.cpp authentication.h
# 	g++ -std=c++11 -c main.cpp

# authentication.o: authentication.cpp authentication.h
# 	g++ -std=c++11 -c authentication.cpp
