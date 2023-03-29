# target: dependencies
# 	action

CXX = g++
CXXFLAGS = -std=c++11

output: problem1.o 
	$(CXX) $(CXXFLAGS) problem1.o -o output

problem1.o: problem1.cpp
	$(CXX) $(CXXFLAGS) -c problem1.cpp

clean:
	rm *.o output