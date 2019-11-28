
IDIR=./include
CXX=g++ -std=c++17
CPPFLAGS=-Iinclude/investments -Iinclude/dbcommunication -Iinclude/webcommunication -Iinclude/common -Iexternal/json/include \
		 -I/usr/local/include/mongocxx/v_noabi -I/usr/local/include/libmongoc-1.0 -I/usr/local/include/bsoncxx/v_noabi \
		 -I/usr/local/include/libbson-1.0 -L/usr/local/lib
DBFLAGS=


ifneq (,$(filter $(DEBUGLEVEL),0 1 2 3 4))
	DBFLAGS=-DENABLE_LOGGER -DDEBUGLEVEL=$(DEBUGLEVEL)
	EXEC_NAME=finmap_debug
else
	EXEC_NAME=finmap
endif


SRCDIR=./src

ODIR=./obj
OBJ=
BUILDDIR=./build

INVESTMENTSDIR=investments
DBCOMMUNICATIONDIR=dbcommunication
WEBCOMMUNICATIONDIR=webcommunication
COMMONDIR=common

INVESTMENTSCPP=$(wildcard $(SRCDIR)/$(INVESTMENTSDIR)/*.cpp)
DBCOMMUNICATIONCPP=$(wildcard $(SRCDIR)/$(DBCOMMUNICATIONDIR)/*.cpp)
WEBCOMMUNICATIONCPP=$(wildcard $(SRCDIR)/$(WEBCOMMUNICATIONDIR)/*.cpp)
COMMONCPP=$(wildcard $(SRCDIR)/$(COMMONDIR)/*.cpp)

INVESTMENTSHEADERS=$(wildcard $(IDIR)/$(INVESTMENTSDIR)/*.h)
DBCOMMUNICATIONHEADERS=$(wildcard $(IDIR)/$(DBCOMMUNICATIONDIR)/*.h)
WEBCOMMUNICATIONHEADERS=$(wildcard $(IDIR)/$(WEBCOMMUNICATIONDIR)/*.h)
COMMONHEADERS=$(wildcard $(IDIR)/$(COMMONDIR)/*.h)

LIBS=-lpistache -lpthread -lmongocxx -lbsoncxx


DEPS = $(INVESTMENTSHEADERS) $(DBCOMMUNICATIONHEADERS) $(WEBCOMMUNICATIONHEADERS) $(COMMONHEADERS) 


_OBJ = $(INVESTMENTSCPP) $(DBCOMMUNICATIONCPP) $(WEBCOMMUNICATIONCPP) $(COMMONCPP) $(SRCDIR)/main.cpp
OBJ = $(addprefix $(ODIR)/,$(notdir $(_OBJ:.cpp=.o)))
OBJDEBUG = $(addprefix $(DEBUGDIR)/,$(notdir $(_OBJ:.cpp=.o)))


SRCS = $(SRCDIR)/main.cpp \
       $(_OBJ)


build: $(OBJ)
	@echo Creating an executable file...
	$(CXX) -o $(EXEC_NAME) $^ $(LIBS)


$(ODIR):
	mkdir -p $(BUILDDIR)
	mkdir -p $(ODIR)

# Rule for building all obejct files needed to create executable file

$(ODIR)/%.o: */*/%.cpp $(DEPS)
	@echo Compiling $<...
	@mkdir -p $(dir $@)
	$(CXX) $(DBFLAGS) -c -o $@ $< $(CPPFLAGS)

$(ODIR)/main.o: */main.cpp $(DEPS)
	@echo Compiling $<...
	@mkdir -p $(dir $@)
	$(CXX) $(DBFLAGS) -c -o $@ $< $(CPPFLAGS)

start: build
	./build

.PHONY: clean

clean:
	rm -rf $(ODIR) finmap finmap_debug logfile

show:
	echo $(DEPS)

help:
	@echo "To build executable without debug mode type: make"
	@echo "To build executable in debug mode type: make DEBUGLEVEL=Level"
	@echo "0 = DEBUG    1 = CONFIG    2 = INFO    3 = WARNING    4 = ERROR"



print:	*/*/*.cpp
	echo $^
