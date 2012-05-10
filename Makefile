# srtm-util Makefile
CXX        = g++-4.7
CXXFLAGS   = -std=c++11 -Wall -Wextra -O2
TARGET     = srtm-util

srtm-util: main.o HGTParser.o
	$(CXX) $(CXXFLAGS) main.o HGTParser.o -o $(TARGET)

main.o: main.cpp HGTParser.h
	$(CXX) $(CXXFLAGS) -c $<

HGTParser.o: HGTParser.cpp HGTParser.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
