CC=g++
CFLAGS=-c -Wall

INCLUDES=-I. -I/opt/local/luabind-0.9.1/include -I/opt/local/lua/include -I/opt/local/boost-1.49.0/include 
LDFLAGS=-L/opt/local/lua/lib -llua -L/opt/local/luabind-0.9.1/lib -lluabindd 

EXECUTABLES=lua_hello lua_functions lua_objects
SOURCES=$(EXECUTABLES:=.cpp)

all: $(EXECUTABLES)

$(EXECUTABLES): $(SOURCES)
	$(CC) $(INCLUDES) $@.cpp $(LDFLAGS) -o $@

clean:
	$(RM) *.o $(EXECUTABLES)

