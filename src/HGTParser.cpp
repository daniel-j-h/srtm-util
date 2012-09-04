#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include "HGTParser.h"
#include "SRTMModel.h"

using std::exit;
using std::string;
using std::ifstream;
using std::ios_base;
using std::unique_ptr;
using std::cerr;
using std::endl;
using std::for_each;

using namespace SRTMUtil;


HGTParser::HGTParser(const string& filename, SRTMModel model) :
  tileSize(static_cast<const long int>(model)),
  height(unique_ptr<uint16_t[]>(new uint16_t[tileSize * tileSize]())) {

  loadFile(filename);
  convertEndianess();
  calculateStatistics();
}

void HGTParser::loadFile(const string& filename) {
  ifstream file;

  try {
    file.exceptions(ios_base::failbit | ios_base::badbit);
    file.open(filename, ios_base::in | ios_base::binary);
    file.read(reinterpret_cast<char*>(height.get()), tileSize * tileSize * 2);
    file.exceptions(ios_base::goodbit);

  } catch(const ios_base::failure &e) {
    cerr << "error: could not load file" << endl;
    exit(EXIT_FAILURE);
  }
}

void HGTParser::convertEndianess() {
  for_each(height.get(), height.get() + (tileSize * tileSize), [](uint16_t& h){
    h = (((h & 0xff) << 8) | ((h & 0xff00) >> 8));
  });
}

void HGTParser::calculateStatistics() {
  /* filter void 0x8000 values */

  const auto begin = height.get();
  const auto end = height.get() + (tileSize * tileSize);

  heightMin = *std::min_element(begin, end, [](const uint16_t lhs, const uint16_t rhs){
    return (lhs < rhs) and (lhs != 0x8000);
  });

  heightMax = *std::max_element(begin, end, [](const uint16_t lhs, const uint16_t rhs){
    return (lhs < rhs) and (rhs != 0x8000);
  });
}
