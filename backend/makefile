# IDIR=./include
# CXX=g++ -std=c++11
# CPPFLAGS=-Iinclude/investments -Iinclude/dbcommunication -Iinclude/webcommunication -Iexternal/json/include
# SRCDIR=./src

# ODIR=./obj
# BUILDDIR=./build

# INVESTMENTSDIR=investments
# DBCOMMUNICATIONDIR=dbcommunication
# WEBCOMMUNICATIONDIR=webcommunication

# INVESTMENTSCPP=investment.cpp share.cpp
# DBCOMMUNICATIONCPP=
# WEBCOMMUNICATIONCPP=authentication.cpp

# INVESTMENTSHEADERS=investment.h share.h
# DBCOMMUNICATIONHEADERS=
# WEBCOMMUNICATIONHEADERS=authentication.h

# LIBS=-lpistache -lpthread


# DEPS = $(patsubst %,$(IDIR)/$(INVESTMENTSDIR)/%,$(INVESTMENTSHEADERS)) \
# 	   $(patsubst %,$(IDIR)/$(DBCOMMUNICATIONDIR)/%,$(DBCOMMUNICATIONHEADERS)) \
# 	   $(patsubst %,$(IDIR)/$(WEBCOMMUNICATIONDIR)/%,$(WEBCOMMUNICATIONHEADERS))


# _OBJ = $(INVESTMENTSCPP) $(DBCOMMUNICATIONCPP) $(WEBCOMMUNICATIONCPP)
# OBJ = $(ODIR)/main.o \
# 	  $(patsubst %,$(ODIR)/%,$(patsubst %.cpp,%.o,$(_OBJ)))


# SRCS = $(SRCDIR)/main.cpp \
# 	   $(patsubst %,$(SRCDIR)/$(INVESTMENTSDIR)/%,$(INVESTMENTSCPP)) \
# 	   $(patsubst %,$(SRCDIR)/$(DBCOMMUNICATIONDIR)/%,$(DBCOMMUNICATIONCPP)) \
# 	   $(patsubst %,$(SRCDIR)/$(WEBCOMMUNICATIONDIR)/%,$(WEBCOMMUNICATIONCPP))

	   

# $(ODIR):
# 	mkdir -p $(BUILDDIR)
# 	mkdir -p $(ODIR)

# # Rule for building all obejct files needed to create executable file

# # $(ODIR)/%.o: $(SRCDIR)/$(INVESTMENTSDIR)/%.cpp $(DEPS)
# # 	$(CXX) -c -o $@ $^ $(CPPFLAGS)

# $(ODIR)/%.o: $(SRCS) $(DEPS)
# 	echo $(CXX) -c -o $@ $^ $(CPPFLAGS)


# build: $(OBJ)
# 	$(CXX) -o $@ $^ $(LIBS)

# start: build
# 	./build

# .PHONY: clean

# clean:
# 	rm -rf $(ODIR) ./build

# show:
# 	echo $(OBJ)




IDIR=./include
CXX=g++ -std=c++11
CPPFLAGS=-Iinclude/investments -Iinclude/dbcommunication -Iinclude/webcommunication -Iexternal/json/include
SRCDIR=./src

ODIR=./obj
OBJ=
BUILDDIR=./build

INVESTMENTSDIR=investments
DBCOMMUNICATIONDIR=dbcommunication
WEBCOMMUNICATIONDIR=webcommunication

INVESTMENTSCPP=$(wildcard $(SRCDIR)/$(INVESTMENTSDIR)/*.cpp)
DBCOMMUNICATIONCPP=$(wildcard $(SRCDIR)/$(DBCOMMUNICATIONDIR)/*.cpp)
WEBCOMMUNICATIONCPP=$(wildcard $(SRCDIR)/$(WEBCOMMUNICATIONDIR)/*.cpp)

INVESTMENTSHEADERS=$(wildcard $(IDIR)/$(INVESTMENTSDIR)*.h)
DBCOMMUNICATIONHEADERS=$(wildcard $(IDIR)/$(DBCOMMUNICATIONDIR)*.h)
WEBCOMMUNICATIONHEADERS=$(wildcard $(IDIR)/$(WEBCOMMUNICATIONDIR)*.h)

LIBS=-lpistache -lpthread


DEPS = $(INVESTMENTSHEADERS) $(DBCOMMUNICATIONHEADERS) $(WEBCOMMUNICATIONHEADERS)


_OBJ = $(INVESTMENTSCPP) $(DBCOMMUNICATIONCPP) $(WEBCOMMUNICATIONCPP) $(SRCDIR)/main.cpp
OBJ = $(notdir $(_OBJ:.cpp=.o))


SRCS = $(SRCDIR)/main.cpp \
       $(_OBJ)

$(ODIR):
	mkdir -p $(BUILDDIR)
	mkdir -p $(ODIR)

# Rule for building all obejct files needed to create executable file

# $(ODIR)/%.o: $(SRCDIR)/$(INVESTMENTSDIR)/%.cpp $(DEPS)
# 	$(CXX) -c -o $@ $^ $(CPPFLAGS)

# $(ODIR)/%.o: $(_OBJ) $(DEPS)
# 	echo $(CXX) -c -o $@ $^ $(CPPFLAGS)


# $(wildcard $(OBJ)/*.o): $(wildcard $(_OBJ))
# 	$(CXX) -c -o $@ $^ $(CPPFLAGS)

$(ODIR)/%.o: $(wildcard $(_OBJ))
	$(CXX) -c -o $@ $^ $(CPPFLAGS)

build: $(ODIR)/$(OBJ)
	$(CXX) -o $@ $^ $(LIBS) $(CPPFLAGS)

start: build
	./build

.PHONY: clean

clean:
	rm -rf $(ODIR) ./build

show:
	echo $(ODIR)/$(OBJ)




