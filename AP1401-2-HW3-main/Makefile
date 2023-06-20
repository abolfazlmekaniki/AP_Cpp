CXX = g++
CXXFLAGS = -std=c++20 -Wall -c
LXXFLAGS = -std=c++20
OBJECTS = main.o src/matrix.o src/unit_test.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET) -lgtest -lgtest_main -pthread
main.o: src/main.cpp src/unit_test.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp
hw1.o:src/hw2.cpp include/matrix.h
	$(CXX) $(CXXFLAGS) include/matrix.cpp
unit_test.o: include/unit_test.cpp
	$(CXX) $(CXXFLAGS) include/unit_test.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)