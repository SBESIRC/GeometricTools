#include "ThCableRouterMgd.h"
#include "ThWashInteropUtils.h"

namespace CLI
{
	String^ ThCableRouterMgd::RouteCable(String^ input, int loopMaxCnt)
	{
		if (String::IsNullOrEmpty(input))
			return String::Empty;

		std::string geojson;
		MarshalString(input, geojson);
		return MarshalNativeString(mInstance->Route(geojson, loopMaxCnt));
	}
}