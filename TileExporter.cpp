#include <cmath>
#include <iostream>
#include <string>
#include <fstream>

#include <cairommconfig.h>
#include <cairomm/context.h>
#include <cairomm/surface.h>

#include "TileExporter.h"
#include "TileSurface.h"
#include "HGTParser.h"

/* feel free to remove surfaces you do not need anyway (enum and this exporter) */

#ifndef CAIRO_HAS_PNG_FUNCTIONS
#error Cairo: PNG support missing
#endif
#ifndef CAIRO_HAS_PDF_SURFACE
#error Cairo: PDF support missing
#endif
#ifndef CAIRO_HAS_PS_SURFACE
#error Cairo: PS support missing
#endif
#ifndef CAIRO_HAS_SVG_SURFACE
#error Cairo: SVG Support missing
#endif

using std::string;
using std::cerr;
using std::endl;

using Cairo::Context;
using Cairo::FORMAT_ARGB32;
using Cairo::ImageSurface;
using Cairo::PdfSurface;
using Cairo::PsSurface;
using Cairo::SvgSurface;


using namespace SRTMUtil;


/* each actor is different in some way, just look at them */
void TileExporter::writeSurface(const string& filename, TileSurface surface) const {

  switch(surface) {
    case TileSurface::Image:
      writeImage(filename);
      break;
    case TileSurface::PDF:
      writePDF(filename);
      break;
    case TileSurface::PS:
      writePS(filename);
      break;
    case TileSurface::SVG:
      writeSVG(filename);
      break;
    default:
      cerr << "error: could not write surface" << endl;
      break;
  }
}

void TileExporter::writeImage(const std::string& filename) const {
  auto surface = ImageSurface::create(FORMAT_ARGB32, parser.getMax(), parser.getMax());
  auto context = Context::create(surface);

  context->save();
  context->set_source_rgb(1.0, 1.0, 1.0);
  context->paint();
  context->restore();

  /* */
  context->set_antialias(Cairo::ANTIALIAS_NONE);
  context->set_line_width(1.0);

  surface->write_to_png(filename);
}

void TileExporter::writePDF(const std::string& filename) const {
  auto surface = PdfSurface::create(filename, parser.getMax(), parser.getMax());
  auto context = Context::create(surface);

  context->save();
  context->set_source_rgb(0.5, 0.5, 0.5);
  context->paint();
  context->restore();

  context->show_page();
}

void TileExporter::writePS(const std::string& filename) const {
  auto surface = PsSurface::create(filename, parser.getMax(), parser.getMax());
  auto context = Context::create(surface);

  context->save();
  context->set_source_rgb(0.5, 0.5, 0.5);
  context->paint();
  context->restore();

  context->show_page();
}

void TileExporter::writeSVG(const std::string& filename) const {
  auto surface = SvgSurface::create(filename, parser.getMax(), parser.getMax());
  auto context = Context::create(surface);

  context->save();
  context->set_source_rgb(0.5, 0.5, 0.5);
  context->paint();
  context->restore();

  context->show_page();
}
