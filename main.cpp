#include <iostream>
#include <fstream>

#include "SRTMModel.h"
#include "HGTParser.h"
#include "TileExporter.h"
#include "TileSurface.h"

using std::cout;
using std::cerr;
using std::endl;

using SRTMUtil::HGTParser;
using SRTMUtil::SRTMModel;
using SRTMUtil::TileExporter;
using SRTMUtil::TileSurface;

using namespace std;


int main(int argc, char** argv) {
  if(argc == 2) {
    HGTParser parser(argv[1], SRTMModel::US);
    TileExporter exporter(parser);

    exporter.writeSurface("out.jpg", TileSurface::Image);
  }
  else {
    cerr << "error: invalid arguments" << endl;
    cerr << "usage: ./srtm-util file.hgt" << endl;
  }
}
