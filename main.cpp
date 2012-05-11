#include <iostream>
#include <algorithm>

#include "SRTMModel.h"
#include "HGTParser.h"
#include "TileExporter.h"
#include "TileSurface.h"

using std::string;
using std::cerr;
using std::endl;
using std::transform;

using SRTMUtil::HGTParser;
using SRTMUtil::SRTMModel;
using SRTMUtil::TileExporter;
using SRTMUtil::TileSurface;

using namespace std;


TileSurface getSurfaceFromArg(const string& file);


/* process .hgt input file and create visual representation */
int main(int argc, char** argv) {
  string infile;
  string outfile;

  if((argc == 3) && ((infile = string(argv[1])).size() > 4) && ((outfile = string(argv[2])).size() > 3) ) {

    HGTParser parser(infile, SRTMModel::US);
    TileExporter exporter(parser);

    exporter.writeSurface(outfile, getSurfaceFromArg(outfile));
  }
  else {
    cerr << "error: invalid arguments" << endl;
    cerr << "usage: ./srtm-util file.hgt tile[.png,.pdf,.ps,.svg]" << endl;
  }
}


/* image as default surface */
TileSurface getSurfaceFromArg(const string& file) {
  auto ext = file.substr(file.find_last_of(".") + 1);
  auto lower = [](string& s) { transform(s.begin(), s.end(), s.begin(), ::tolower); return s; };

  TileSurface surface = TileSurface::Image;

  if(lower(ext) == "pdf")
    surface = TileSurface::PDF;
  else if(lower(ext) == "ps")
    surface = TileSurface::PS;
  else if(lower(ext) == "svg")
    surface = TileSurface::SVG;

  return surface;
}
