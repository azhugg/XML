#pragma once
#include "XMLReader.h"

//ʹ��TinyXML
class XMLWriter 
{
public:
	XMLWriter(){};

	///���浥��������ڲ���������������������ͱ궨ͼƬ�����
	///�����������
	static void writePointsCloudIndex(std::string filename, const std::vector<TDPoint>& points);
};

