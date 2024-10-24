CXX = g++

CXXFLAGS = -Wall -std=c++11

HFILES = arraylist.h
OBJECTS = main.o arraylist.o

TARGET = main.out

%.o : %.cpp $(HFILES) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET)

.PHONY : clean

clean :
	$(RM) $(TARGET) *.o core