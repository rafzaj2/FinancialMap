# IDIR=./include
# CXX=g++ -std=c++11
# CFLAGS=-I~/Programing/FinancialMap/backend
# SRCDIR=src

# ODIR=obj

# LIBS=-lpistache -lpthread

# _DEPS = authentication.h
# DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# _OBJ = authentication.o main.o  
# OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# _SRCS = main.cpp authentication.cpp
# SRCS = $(patsubst %,$(SRCDIR)/%,$(_SRCS))

# $(ODIR):
# 	mkdir -p $(ODIR)

# $(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
# 	$(CXX) -c -o $@ $< $(CFLAGS)

# build: $(OBJ)
# 	$(CXX) -o $@ $^ $(LIBS)

# start: build
# 	./build

# .PHONY: clean

# clean:
# 	rm -f $(ODIR) build


IDIR=./include
CXX=g++ -std=c++11
CFLAGS=-Iinclude/investments -Iinclude/dbcommunication -Iinclude/webcommunication
SRCDIR=./src

ODIR=./obj
BUILDDIR=./build

INVESTMENTSDIR=investments
DBCOMMUNICATIONDIR=dbcommunication
WEBCOMMUNICATIONDIR=webcommunication

INVESTMENTSCPP=investment.cpp share.cpp
DBCOMMUNICATIONCPP=
WEBCOMMUNICATIONCPP=authentication.cpp

INVESTMENTSHEADERS=investment.h share.h
DBCOMMUNICATIONHEADERS=
WEBCOMMUNICATIONHEADERS=authentication.h

LIBS=-lpistache -lpthread


DEPS = $(patsubst %,$(IDIR)/$(INVESTMENTSDIR)/%,$(INVESTMENTSHEADERS)) \
	   $(patsubst %,$(IDIR)/$(DBCOMMUNICATIONDIR)/%,$(DBCOMMUNICATIONHEADERS)) \
	   $(patsubst %,$(IDIR)/$(WEBCOMMUNICATIONDIR)/%,$(WEBCOMMUNICATIONHEADERS))


_OBJ = $(INVESTMENTSCPP) $(WEBCOMMUNICATION) $(DBCOMMUNICATION)
OBJ = $(patsubst %,$(ODIR)/%,$(patsubst %.cpp,%.o,$(_OBJ)))


SRCS = $(SRCDIR)/main.cpp \
	   $(patsubst %,$(SRCDIR)/$(INVESTMENTSDIR)/%,$(INVESTMENTSCPP)) \
	   $(patsubst %,$(SRCDIR)/$(DBCOMMUNICATIONDIR)/%,$(DBCOMMUNICATIONCPP)) \
	   $(patsubst %,$(SRCDIR)/$(WEBCOMMUNICATIONDIR)/%,$(WEBCOMMUNICATIONCPP))

	   

$(ODIR):
	mkdir -p $(BUILDDIR)
	mkdir -p $(ODIR)

# Rule for building all obejct files needed to create executable file

$(ODIR)/%.o: $(SRCDIR)/$(INVESTMENTSDIR)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $^ $(CFLAGS)


build: $(OBJ)
	$(CXX) -o $@ $^ $(LIBS)

start: build
	./build

.PHONY: clean

clean:
	rm -rf $(ODIR) ./build