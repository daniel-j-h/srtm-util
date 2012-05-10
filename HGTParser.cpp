#include <iostream>
#include <fstream>

#include "HGTParser.h"

using std::string;
using std::ifstream;
using std::ios_base;
using std::cerr;
using std::endl;

using namespace SRTMUtils;


HGTParser::HGTParser(const string& filename, const long int& maxx_, const long int& maxy_):
    maxx(maxx_), maxy(maxy_), height(new uint16_t[maxx_ * maxy_]()) {

  ifstream file;

  try {
    file.exceptions(ios_base::failbit | ios_base::badbit);
    file.open(filename, ios_base::in | ios_base::binary);
    file.read(reinterpret_cast<char*>(height), maxx * maxy * 2);
    file.exceptions(ios_base::goodbit);

  } catch(const ios_base::failure &e) {
    maxx = 0;
    maxy = 0;
    delete[] height;
    height = nullptr;

    cerr << "error: could not load file" << endl;
  }

  convertEndianess();
}

HGTParser::~HGTParser() {
  if(height != nullptr) {
    delete[] height;
    height = nullptr;
  }
}
