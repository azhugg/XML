#include "stdafx.h"
#include "XMLReader.h"

bool XMLReader::readPointsCloudIndex(std::string filename, std::vector<TDPoint>& m_points)
{
	char* segmentation = " ";
	TiXmlDocument doc;
	if( !doc.LoadFile( filename.c_str()) )
	{
		return false;
	}
	TiXmlHandle hDoc(&doc);
	TiXmlElement* pElem;
	pElem = hDoc.FirstChild("Points").Element();
	if( pElem->ValueTStr() == "Points" )
	{
		TiXmlElement* tElem;
		tElem = pElem->FirstChildElement();
		//const char* jj = tElem->Value();
		for(tElem;tElem;tElem=tElem->NextSiblingElement())
		{
			std::vector<std::string> nums = split( tElem->GetText(),segmentation); 
			float point[4];
			sscanf( nums[0].c_str(), "%f", &point[0] );
			sscanf( nums[1].c_str(), "%f", &point[1] );
			sscanf( nums[2].c_str(), "%f", &point[2] );
			sscanf( nums[3].c_str(), "%f", &point[3] );
			m_points.push_back(TDPoint(point[0],point[1],point[2],point[3]));
		}
	}
	else
	{
		return false;
	}
	return true;
}
std::vector<std::string> XMLReader::split(std::string str, std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;            //扩展字符串以方便操作
	unsigned int size = str.size();

	for (unsigned int i = 0; i < size; i++)
	{
		pos = str.find(pattern, i);
		if (pos < size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}