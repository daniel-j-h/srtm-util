#ifndef TILEEXPORTER_H
#define TILEEXPORTER_H

#include "HGTParser.h"
#include "TileSurface.h"


namespace SRTMUtil {


/* simple tile exporter */
class TileExporter {
  public:
    explicit TileExporter(const HGTParser& parser_) : parser(parser_) { }

    /* copy, assign, move deleted for now */
    TileExporter(TileExporter const& other) = delete;
    TileExporter& operator=(TileExporter other) = delete;
    TileExporter(TileExporter&& other) = delete;

    /* writes all the data from the parser onto the specified surface and into a file */
    void writeSurface(const std::string& filename, TileSurface surface) const;

  private:
    /* more should not be necessary */
    const HGTParser& parser;

    /* surface actors */
    void writeImage(const std::string& filename) const;
    void writePDF(const std::string& filename) const;
    void writePS(const std::string& filename) const;
    void writeSVG(const std::string& filename) const;
};


} // namespace


#endif
