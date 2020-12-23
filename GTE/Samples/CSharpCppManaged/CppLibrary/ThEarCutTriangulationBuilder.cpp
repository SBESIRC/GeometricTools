#include <array>
#include <vector>
#include "earcut.hpp"
#include "ThEarCutTriangulationBuilder.h"
using namespace gte;

ThEarCutTriangulationBuilder::ThEarCutTriangulationBuilder()
{
	//
}

//����㼯[x0,y0,x1,y1,x2,y2,...]����ĸ���numPoints��ָ�꼯[N,M,P,...]��ָ�����numindices
void ThEarCutTriangulationBuilder::EarCut(double const* points, int numPoints, int const* indices, int numIndices)
{
	std::vector<std::vector<Point>> polygon;

	// Parse inputs
	int i = 0;
	for (int j = 0; j < numIndices; j++)
	{
		std::vector<Point> polyline;
		for (; i < indices[j]; i++)
		{
			Point point = Point{ points[2 * i], points[2 * i + 1] };
			polyline.push_back(point);
		}
		polygon.push_back(polyline);
	}
	std::vector<Point> polyline;
	for (; i < numPoints; i++)
	{
		Point point = Point{ points[2 * i], points[2 * i + 1] };
		polyline.push_back(point);
	}
	polygon.push_back(polyline);

	// Run tessellation
	// Returns array of indices that refer to the vertices of the input polygon.
	// e.g: the index 6 would refer to {25, 75} in this example.
	// Three subsequent indices form a triangle. Output triangles are clockwise.
	Results = mapbox::earcut<N>(polygon);
}
