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

    /* copy, assign, move deleted for now, one parser per .hgt seems fine */
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

/* inlined, we need them often */
inline int HGTParser::getHeight(const long int& x, const long int& y) const {
  if(height.get() == nullptr)
    return 0; /* defaulted error height */
  else
    return static_cast<int>((height.get())[y * max + x]);
}

inline void HGTParser::convertEndianess() {
  std::for_each(height.get(), height.get() + (max * max), [](uint16_t& h){ h = (((h & 0xff) << 8) | ((h & 0xff00) >> 8)); });
}

inline int HGTParser::getHeightMin() const {
  return static_cast<int>(*std::min_element(height.get(), height.get() + (max * max)));
}

inline int HGTParser::getHeightMax() const {
  /* note: member var named 'max' */
  int heightMax = 0;

  /* filter void 0x8000 values */
  std::for_each(height.get(), height.get() + (max * max), [&heightMax](uint16_t& h){ if((h > heightMax) && (h != 0x8000)) heightMax = h; });

  return heightMax;
}


} // namespace


#endif
