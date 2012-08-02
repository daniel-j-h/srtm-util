#ifndef HGTPARSER_H
#define HGTPARSER_H

#include <cstdint>
#include <string>
#include <algorithm>
#include <memory>

#include "SRTMModel.h"


namespace SRTMUtil {


/* simple .hgt file parser */
class HGTParser {
  public:
    /* height data is initialized to 0, so in case of errors you get height data of value 0 */
    explicit HGTParser(const std::string& filename, SRTMModel model);
    ~HGTParser();

    /* todo: implement them */
    HGTParser(HGTParser const& other) = delete;
    HGTParser& operator=(HGTParser other) = delete;
    HGTParser(HGTParser&& other) = delete;

    /* height or invalid point by specification */
    int getHeight(const long int& x, const long int& y) const;
    int getHeightMin() const;
    int getHeightMax() const;

    /* dimension accessor */
    long int getMax() const { return max; }


  private:
    /* data is big endian encoded, we have to convert it */
    void convertEndianess();

    /* defined by the SRTM model specification  */
    long int max;

    /* actual height data */
    std::unique_ptr<uint16_t[]> height;
};


inline int HGTParser::getHeight(const long int& x, const long int& y) const {
  if(height.get() == nullptr)
    /* defaulted error height */
    return 0;
  else
    /* not cache-friendly, but the tiles are not that large, anyway */
    return static_cast<int>((height.get())[y * max + x]);
}


} // namespace


#endif
