#include <iostream>
#include <fstream>

#include "HGTParser.h"
#include "SRTMModel.h"

using std::string;
using std::ifstream;
using std::ios_base;
using std::unique_ptr;
using std::cerr;
using std::endl;

using namespace SRTMUtil;


HGTParser::HGTParser(const string& filename, SRTMModel model) :
  max(static_cast<long int>(model)), height(unique_ptr<uint16_t[]>(new uint16_t[max * max]())) {

  ifstream file;

  try {
    file.exceptions(ios_base::failbit | ios_base::badbit);
    file.open(filename, ios_base::in | ios_base::binary);
    file.read(reinterpret_cast<char*>(height.get()), max * max * 2);
    file.exceptions(ios_base::goodbit);

  } catch(const ios_base::failure &e) {
    height.reset();
    max = 0;

    cerr << "error: could not load file" << endl;
  }
  convertEndianess();
}

HGTParser::~HGTParser() {
  height.reset();
}
