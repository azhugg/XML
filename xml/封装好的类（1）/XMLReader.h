#pragma once
#include "SharedMethod.h"

class XMLReader
{
public:
	XMLReader(){  };
	
	///读取单个相机的内参数、畸变参数、误差参数、标定板外参数
	static bool readCamPara(std::string filename,CamPara& m_camPara);

	///读取相机组姿态参数，读取了Left_Mid、Right_Mid和Right_Left
	static bool readCamGroupPara(std::string filename,CamGroupPara& m_camGroupPara);

	///读取角点数据，包括图像尺寸、角点二维坐标、三维坐标（z=0)、每针角点数、图像索引
	static bool readCornerData(std::string filename, CalibrationData& m_cornerData);

	///读取三维点云数据
	static bool readPointsCloud(std::string filename, std::vector<cv::Point3f>& m_points);
	
	///读取光笔标定的结果
	static bool readLightPenPara(std::string filename,std::vector<TagPoint3f>& pnts,cv::Point3f& pnt);
	//读取光笔设计参数，各个特征点的三位信息
	//chengwei added
	//读取光笔特征点数据
	static bool readLightPenDotPara(std::string filename,std::vector<TagPoint3f>& pnts);
	//读取工作目录信息
	static bool readWorkplacePath(std::string filename,std::string& path);
private:
	

	///解析内参数元素
	static bool parseIntrinsicparametersElement(TiXmlHandle hDoc, CamPara& m_camPara);

	///解析畸变元素
	static bool parseDistortionsElement(TiXmlHandle hDoc, CamPara& m_camPara);

	///解析误差元素，不参与计算不需要解析
	static bool parseErrorElement(TiXmlHandle hDoc, CamPara& m_camPara);

	///解析图像尺寸元素
	static bool parseImageSizeElement(TiXmlHandle hDoc, CalibrationData& m_cornerData);

	///解析角点二维坐标元素
	static bool parseCornerPointsElement(TiXmlHandle hDoc,const vector<int>& CornerNumPerFrame,CalibrationData& m_cornerData);

	///解析角点三维点（z=0)元素
	static bool parseFeaturePointsElement(TiXmlHandle hDoc,const vector<int>& CornerNumPerFrame, CalibrationData& m_cornerData);

	///解析每针角点数元素
	static bool parseCornerNumPerFrameElement(TiXmlHandle hDoc, vector<int>& CornerNumPerFrame);

	///解析标定图片索引元素
	static bool parseFrameNumListElement(TiXmlHandle hDoc, CalibrationData& m_cornerData);

	///解析Left_Mid元素
	static bool parseLeftMidElement(TiXmlHandle hDoc, CamGroupPara& m_camGroupPara);

	///解析Right_Mid元素
	static bool parseRightMidElement(TiXmlHandle hDoc, CamGroupPara& m_camGroupPara);

	///解析Right_Left元素
	static bool parseRightLeftElement(TiXmlHandle hDoc, CamGroupPara& m_camGroupPara);

	///解析标定板外参数元素
	static bool parseImageRTElement(TiXmlHandle hDoc, CamPara& m_camPara);
	
};

