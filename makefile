CXX = g++
CXXFLAGS = -g -Wall

OBJECTS = parse.o param.o

myshell: $(OBJECTS) myshell.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) *.o myshell