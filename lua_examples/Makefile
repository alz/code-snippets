CC=g++
CFLAGS=-c -Wall

INCLUDES=-I. -I/opt/local/lua/include
LDFLAGS=-L/opt/local/lua/lib -llua -ldl

EXECUTABLES=lua_hello lua_functions
SOURCES=$(EXECUTABLES:=.cpp)

all: $(EXECUTABLES)

$(EXECUTABLES): $(SOURCES)
	$(CC) $(INCLUDES) $@.cpp $(LDFLAGS) -o $@

clean:
	$(RM) *.o $(EXECUTABLES)

