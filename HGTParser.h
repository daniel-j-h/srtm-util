#ifndef HGTPARSER_H
#define HGTPARSER_H

#include <cstdint>
#include <string>
#include <algorithm>


namespace SRTMUtils {


/* simple .hgt file parser */
class HGTParser {
  public:
    /* height data is initialized to 0, so in case of errors you get height data of value 0 */
    explicit HGTParser(const std::string& filename, const long int& maxx_, const long int& maxy_);
    ~HGTParser();

    /* TODO: copy and assignment operator */

    /* height or invalid point by specification */
    int getHeight(const long int& x, const long int& y) const;


  private:
    /* data is big endian encoded, we have to convert it */
    void convertEndianess();

    /* defined by the SRTM specification  */
    long int maxx;
    long int maxy;

    /* actual height data */
    uint16_t* height;
};

/* inlined, we need them often */
inline int HGTParser::getHeight(const long int& x, const long int& y) const {
  if(height == nullptr)
    return 0; /* defaulted error height */
  else
    return static_cast<int>(height[y * maxx + x]);
}

inline void HGTParser::convertEndianess() {
  std::for_each(height, height + (maxx * maxy), [](uint16_t& h){ h = (((h & 0xff) << 8) | ((h & 0xff00) >> 8)); });
}


} // namespace


#endif
