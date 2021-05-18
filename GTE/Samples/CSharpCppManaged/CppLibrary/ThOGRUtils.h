#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>

class OGRPolygon;
class OGRGeometry;
class OGRLinearRing;
class OGRMultiPolygon;

namespace THOGR
{
	class ThOGRUtils
	{
	public:
		static OGRPolygon* CreatePolygon();
		static OGRLinearRing* CreateLinearRing();
		static OGRMultiPolygon* CreateMultiPolygon();
		static void ReleaseGeometry(OGRGeometry* geometry);
	public:
		static OGRLinearRing* ToOGRLinearRing(const std::vector<double>& coords);
		static void ToCoordinates(const OGRLinearRing* ring, std::vector<double>& coordinates);
	public:
		static std::string ToWKT(OGRGeometry* geometry);
		static OGRGeometry* FromWKT(const std::string& wkt);

		static std::vector<unsigned char> ToWKB(OGRGeometry* geometry);
		static OGRGeometry* FromWKB(const std::vector<unsigned char>& wkb);
	};
}
