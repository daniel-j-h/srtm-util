#include <iostream>

#include "HGTParser.h"

using std::cout;
using std::cerr;
using std::endl;

using SRTMUtils::HGTParser;


int main(int argc, char** argv) {
  if(argc == 2) {
    /* model 1: 3601; U.S., sampled at one arc-second lat/long intervals, 3601 lines and 3601 samples */
    /* model 3: 1201; world, sampled at three arc-second lat/long intervals, 1201 lines and 1201 samples */

    HGTParser parser(argv[1], 3601, 3601); /* .hgt are tiles */

    /* coordinates on your tile, e.g. on tile N36W112 */
    cout << parser.getHeight(42, 42) << endl;
  }
  else {
    cerr << "error: invalid arguments" << endl;
    cerr << "usage: ./parser file mode" << endl;
    cerr << "file is your .hgt file and mode is the SRTM mode: 1 for U.S. and 3 for world" << endl;
  }
}
