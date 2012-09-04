#ifndef HGTPARSER_H
#define HGTPARSER_H

#include <cstdint>
#include <string>
#include <memory>

#include "SRTMModel.h"


namespace SRTMUtil {


/* simple .hgt file parser */
class HGTParser final {
  public:
    /* height data is initialized to 0, so in case of errors you get height data of value 0 */
    explicit HGTParser(const std::string& filename, SRTMModel model);
    ~HGTParser() = default;

    /* XXX */
    HGTParser(HGTParser const& other) = delete;
    HGTParser& operator=(HGTParser other) = delete;
    HGTParser(HGTParser&& other) = delete;
    HGTParser& operator=(HGTParser&& other) = delete;

    /* height or invalid point by specification */
    int getHeight(const long int x, const long int y) const;
    int getHeightMin() const { return heightMin; }
    int getHeightMax() const { return heightMax; }

    /* dimension accessor */
    long int getTileSize() const { return tileSize; }


  private:
    /* load data from .hgt file */
    void loadFile(const std::string& filename);

    /* data is big endian encoded, we have to convert it */
    void convertEndianess();

    /* get useful statistics */
    void calculateStatistics();

    /* defined by the SRTM model specification  */
    const long int tileSize;

    /* min height in this tile */
    int heightMin;

    /* max height in this tile */
    int heightMax;

    /* actual height data */
    std::unique_ptr<uint16_t[]> height;
};


inline int HGTParser::getHeight(const long int x, const long int y) const {
  if(height.get() == nullptr)
    /* defaulted error height */
    return 0;
  else
    /* not cache-friendly, but the tiles are not that large, anyway */
    return static_cast<int>((height.get())[y * tileSize + x]);
}


} // namespace


#endif
