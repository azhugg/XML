#pragma once
#include "XMLReader.h"

//使用TinyXML
class XMLWriter 
{
public:
	XMLWriter(){};

	///保存单个相机的内参数、畸变参数、误差参数和标定图片外参数
	///保存点云数据
	static void writePointsCloudIndex(std::string filename, const std::vector<TDPoint>& points);
};

