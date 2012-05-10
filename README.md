SRTM Utilities
==============

Using the Shuttle Radar Topography Mission (SRTM) elevation models and related .hgt files for visualization and exploration


Description
-----------

The SRTM offers impressive height data, which is freely available in a custom .hgt format

So let's have fun with it

This repository is used to implement the basic handling (import, conversion, ...) of the downloadable .hgt files.
Furthermore there will be some sort of fancy implementation in the future, like a OpenGL renderer, a height map generator for game maps, or some point cloud trickery


Compiling
---------

This project uses new __C++11__ language features, so make sure to use an up to date compiler

make
./srtm-util N36W111.hgt


Sources
-------

  * [.hgt files and further ressources](http://dds.cr.usgs.gov/srtm/)
  * [SRTM NASA](http://www2.jpl.nasa.gov/srtm/)
  * [CGIAR-CSI best global coverage](http://srtm.csi.cgiar.org/SELECTION/inputCoord.asp)
  * [SRTM Wikipedia](https://en.wikipedia.org/wiki/SRTM)


Overview
--------

  * HGTParser: Converts the raw .hgt file and provides the polished height data
  * main: Usage example; will be extended
