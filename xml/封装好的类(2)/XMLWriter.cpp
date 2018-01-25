#pragma once
#include "stdafx.h"
#include "XMLWriter.h"
void XMLWriter::writePointsCloudIndex(std::string filename, const std::vector<TDPoint>& points)
{
	char text[100];
	char* segmentation = " ";
	TiXmlDocument doc;
	TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "", "" );
	doc.LinkEndChild( decl );

	TiXmlElement *Points_element = new TiXmlElement( "Points" );
	Points_element->SetAttribute("size",points.size());
	doc.LinkEndChild( Points_element );
	for(unsigned int i=0;i<points.size();i++)
	{
		sprintf(text, "%s%d", "p",i+1);
		//sprintf(text, "%s", "");
		TiXmlElement * index_element = new TiXmlElement( text );
		Points_element->LinkEndChild(index_element);

		sprintf(text, "%lf%s%lf%s%lf%s%lf", points[i].index,segmentation
									      , points[i].x,segmentation
									      , points[i].y,segmentation
									      , points[i].z,segmentation);
		TiXmlText *point_text = new TiXmlText( text );
		index_element->LinkEndChild( point_text );
	}

	doc.SaveFile( filename.c_str() );
}