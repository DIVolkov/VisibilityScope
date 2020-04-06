# Feel free to edit this as needed
#
program = main

CXXFLAGS = -std=c++17 -Wall

SOURCES = main.cpp data.cpp

all: $(program)

$(program): 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $(SOURCES)

run: $(program)
	./$(program)

clean:
	$(RM) -f $(program)
