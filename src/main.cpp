#include <iostream>
#include <string>

#include "SRTMModel.h"
#include "HGTParser.h"

using std::string;
using std::cerr;
using std::cout;
using std::endl;

using SRTMUtil::HGTParser;
using SRTMUtil::SRTMModel;


/* process .hgt input file and give some infos */
int main(int argc, char** argv) {
  string infile;

  if((argc == 2) && ((infile = string(argv[1])).size() > 4)) {
    HGTParser parser(infile, SRTMModel::US);

    cout << "height at (42, 42): " << parser.getHeight(42, 42) << endl;
    cout << "min height in this tile: " << parser.getHeightMin() << endl;
    cout << "max height in this tile: " << parser.getHeightMax() << endl;
  } else {
    cerr << "error: invalid arguments" << endl;
    cerr << "usage: ./srtm-util file.hgt" << endl;
  }
}
