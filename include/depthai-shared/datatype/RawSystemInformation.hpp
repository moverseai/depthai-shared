#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <vector>

#include "DatatypeEnum.hpp"
#include "RawBuffer.hpp"
#include "depthai-shared/pb/common/ChipTemperature.hpp"
#include "depthai-shared/pb/common/CpuUsage.hpp"
#include "depthai-shared/pb/common/MemoryInfo.hpp"

namespace dai {
/**
 * System information of device
 *
 * Memory usage, cpu usage and chip temperature
 */
struct RawSystemInformation : public RawBuffer {
    /// DDR memory usage
    MemoryInfo ddrMemoryUsage;
    /// LeonCss heap usage
    MemoryInfo leonCssMemoryUsage;
    /// LeonMss heap usage
    MemoryInfo leonMssMemoryUsage;
    /// LeonCss cpu usage
    CpuUsage leonCssCpuUsage;
    /// LeonMss cpu usage
    CpuUsage leonMssCpuUsage;
    /// Chip temperatures
    ChipTemperature chipTemperature;

    void serialize(std::vector<std::uint8_t>& metadata, DatatypeEnum& datatype) override {
        nlohmann::json j = *this;
        metadata = nlohmann::json::to_msgpack(j);
        datatype = DatatypeEnum::SystemInformation;
    };

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(
        RawSystemInformation, ddrMemoryUsage, leonCssMemoryUsage, leonMssMemoryUsage, leonCssCpuUsage, leonMssCpuUsage, chipTemperature);
};

}  // namespace dai