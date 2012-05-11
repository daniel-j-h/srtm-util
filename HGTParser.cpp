#include <iostream>
#include <string>
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

void HGTParser::convertEndianess() {
  std::for_each(height.get(), height.get() + (max * max), [](uint16_t& h){ h = (((h & 0xff) << 8) | ((h & 0xff00) >> 8)); });
}

int HGTParser::getHeightMin() const {
  return static_cast<int>(*std::min_element(height.get(), height.get() + (max * max)));
}

int HGTParser::getHeightMax() const {
  /* note: member var named 'max' */
  int heightMax = 0;

  /* filter void 0x8000 values */
  std::for_each(height.get(), height.get() + (max * max), [&heightMax](uint16_t& h){ if((h > heightMax) && (h != 0x8000)) heightMax = h; });

  return heightMax;
}
