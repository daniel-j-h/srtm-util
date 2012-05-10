#include <iostream>
#include <string>
#include <fstream>

#include <cairommconfig.h>
#include <cairomm/context.h>
#include <cairomm/surface.h>

#include "TileExporter.h"
#include "TileSurface.h"
#include "HGTParser.h"

using std::string;


using namespace SRTMUtil;


void TileExporter::writeSurface(const string& filename, TileSurface surface) const {
  switch(surface) {
    case TileSurface::Image:
      ;
      break;
    case TileSurface::PDF:
      ;
      break;
    case TileSurface::PS:
      ;
      break;
    case TileSurface::SVG:
      ;
      break;
    default:
      break;
  }
}
