#pragma once
#include <string>
#include <vector>
#include "tinyxml.h"
#include "tinystr.h"
class TDPoint
{
public:
	TDPoint()
	{
		index= 0;
		x=0;
		y=0;
		z=0;
	}
	TDPoint(double _index,double _x,double _y,double _z)
	{
		index= _index;
		x=_x;
		y=_y;
		z=_z;
	}
public:
	double index;
	double x;
	double y;
	double z;
};
class XMLReader
{
public:
	XMLReader(){  };
	static bool readPointsCloudIndex(std::string filename, std::vector<TDPoint>& m_points);
private:
	static std::vector<std::string> split(std::string str, std::string pattern);
};

