SRTM Utilities
==============

Using the Shuttle Radar Topography Mission (SRTM) elevation models and related .hgt files for visualization and exploration


Description
-----------

The SRTM offers impressive height data, which is freely available in a custom .hgt format

So let's have fun with it

This repository is used to implement the basic handling (import, conversion, ...) of the downloadable .hgt files.
Furthermore there will be some sort of fancy implementation in the future, like a OpenGL renderer, a height map generator for game maps, or some point cloud trickery


Dependencies
------------

I'm using some new fancy __C++11__ features, so make sure to use an up to date compiler, e.g. g++-4.7.
The exporter uses the graphics library Cairo. I'm using [__cairo-1.12.2__](http://cairographics.org/download/) and the C++ bindings [__cairomm-1.10.0__](http://cairographics.org/cairomm/), compiled from git; which is quite nice to build, so you can do it too (or if you have Debian Squeeze you have to, nonetheless).


Compiling
---------

  * CXX="g++-4.7" make
  * ./srtm-util N36W111.hgt


Overview
--------

  * HGTParser: Converts the raw .hgt file and provides the polished height data
  * SRTModel: Only SRTM model 1 and 3 ('U.S.' and 'World') are currently implemented
  * TileExporter: Exports the height data from the parser, by using the graphics library Cairo
  * TileSurface: Available export surfaces, like image, pdf, svg
  * main: Usage example; visualizes a .hgt file


External Sources
----------------

  * [.hgt files and further ressources](http://dds.cr.usgs.gov/srtm/)
  * [SRTM NASA](http://www2.jpl.nasa.gov/srtm/)
  * [CGIAR-CSI best global coverage](http://srtm.csi.cgiar.org/SELECTION/inputCoord.asp)
  * [SRTM Wikipedia](https://en.wikipedia.org/wiki/SRTM)
