SRTM Utilities
==============

Using the Shuttle Radar Topography Mission (SRTM) elevation models and related .hgt files for visualization and exploration


Description
-----------

The SRTM offers impressive height data, which is freely available in a custom .hgt format

So let's have fun with it

This repository is used to implement the basic handling (import, conversion, ...) of the downloadable .hgt files


Dependencies
------------

I'm using some new fancy __C++11__ features, so make sure to use an up to date compiler, e.g. g++-4.7 or clang-3.1


Compiling
---------

  * cd src
  * make
  * ./srtm-util N36W111.hgt


Overview
--------

  * HGTParser: Converts the raw .hgt file and provides the polished height data
  * SRTModel: Only SRTM model 1 and 3 ('U.S.' and 'World') are currently implemented
  * main: Usage example


External Sources
----------------

  * [.hgt files and further ressources](http://dds.cr.usgs.gov/srtm/)
  * [SRTM NASA](http://www2.jpl.nasa.gov/srtm/)
  * [CGIAR-CSI best global coverage](http://srtm.csi.cgiar.org/SELECTION/inputCoord.asp)
  * [SRTM Wikipedia](https://en.wikipedia.org/wiki/SRTM)

