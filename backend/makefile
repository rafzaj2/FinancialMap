
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
OBJ = $(addprefix $(ODIR)/,$(notdir $(_OBJ:.cpp=.o)))


SRCS = $(SRCDIR)/main.cpp \
       $(_OBJ)

$(ODIR):
	mkdir -p $(BUILDDIR)
	mkdir -p $(ODIR)

# Rule for building all obejct files needed to create executable file

$(ODIR)/%.o: */*/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $< -o $@ $(CPPFLAGS)

$(ODIR)/main.o: */main.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $< -o $@ $(CPPFLAGS)


build: $(OBJ)
	$(CXX) -o $@ $^ $(LIBS) $(CPPFLAGS)

start: build
	./build

.PHONY: clean

clean:
	rm -rf $(ODIR) ./build

show:
	echo $(OBJ)

print:	*/*/*.cpp
	echo $^
