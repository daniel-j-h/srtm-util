#ifndef SRTMMODEL_H
#define SRTMMODEL_H


namespace SRTMUtil {


/* available SRTM models */
enum class SRTMModel : long int {
  /*
   * model 1: U.S.,
   * sampled at one arc-second lat/long intervals, 3601 lines, 3601 samples
   */
  US = 3601L,

  /*
   * model 3: world,
   * sampled at three arc-second lat/long intervals, 1201, 1201 samples
   */
  WORLD = 1201L
};


} // namespace


#endif
