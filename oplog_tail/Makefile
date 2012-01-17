CC=g++
CFLAGS=-c -Wall

INCLUDES=-I. -I/opt/local/mongodb/include/mongo
LDFLAGS=-L/opt/local/mongodb/lib -lmongoclient 

SOURCES=oplog_tail.cpp
EXECUTABLE=oplog_tail
OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o $(EXECUTABLE)

