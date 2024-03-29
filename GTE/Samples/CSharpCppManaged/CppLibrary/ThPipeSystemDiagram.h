#pragma once
#include "stdafx.h"
#include "ThCppExport.h"

namespace gte
{
    class THMODULE_EXPORT ThPipeSystemDiagram
    {
    public:
        std::string ProcessGrouping(const std::string& geojson);
        std::string ProcessMainBranchs(const std::string& geojson);
    };
}
