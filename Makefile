#
# srtm-util Makefile
#
CXX        ?= g++-4.7
CXXFLAGS   ?= -std=c++11 -Wall -Wextra -O2 -g
PKG_CONFIG ?= `pkg-config cairomm-1.0 --cflags --libs`
TARGET     ?= srtm-util

srtm-util: main.o HGTParser.o TileExporter.o
	$(CXX) $(CXXFLAGS) $(PKG_CONFIG) main.o HGTParser.o TileExporter.o -o $(TARGET)

main.o: main.cpp HGTParser.h TileExporter.h TileSurface.h SRTMModel.h
	$(CXX) $(CXXFLAGS) -c $<

HGTParser.o: HGTParser.cpp HGTParser.h SRTMModel.h
	$(CXX) $(CXXFLAGS) -c $<

TileExporter.o: TileExporter.cpp TileExporter.h TileSurface.h HGTParser.h
	$(CXX) $(CXXFLAGS) $(PKG_CONFIG) -c $<

clean:
	rm -f *.o $(TARGET)
