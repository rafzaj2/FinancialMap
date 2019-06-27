IDIR=./include
CXX=g++ -std=c++11
CFLAGS=-I~/Programing/FinancialMap/backend
SRCDIR=src

ODIR=obj

LIBS=-lpistache -lpthread

_DEPS = authentication.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = authentication.o main.o  
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_SRCS = main.cpp authentication.cpp
SRCS = $(patsubst %,$(SRCDIR)/%,$(_SRCS))

$(ODIR):
	mkdir -p $(ODIR)

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	$(CXX) -o $@ $^ $(LIBS)

start: build
	./build

.PHONY: clean

clean:
	rm -f $(ODIR) build
