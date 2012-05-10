#include <iostream>
#include <string>
#include <fstream>

#include "HGTParser.h"

using std::string;
using std::ifstream;
using std::ios_base;
using std::cerr;
using std::endl;


HGTParser::HGTParser(const string& filename, const long int& maxx, const long int& maxy) {
  this->maxx = maxx;
  this->maxy = maxy;
  this->height = new uint16_t[maxx * maxy]();

  ifstream file;

  try {
    file.exceptions(ios_base::failbit | ios_base::badbit);
    file.open(filename, ios_base::in | ios_base::binary);
    file.read(reinterpret_cast<char*>(this->height), maxx * maxy * 2);
    file.exceptions(ios_base::goodbit);

  } catch(const ios_base::failure &e) {
    this->maxx = 0;
    this->maxy = 0;
    delete[] this->height;
    this->height = nullptr;

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
