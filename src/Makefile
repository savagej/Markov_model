CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp read_write.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=markov

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o markov
