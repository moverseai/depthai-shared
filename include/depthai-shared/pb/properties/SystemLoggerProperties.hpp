#pragma once

#include <nlohmann/json.hpp>

#include "depthai-shared/pb/common/CameraBoardSocket.hpp"
#include "depthai-shared/pb/common/CameraImageOrientation.hpp"

namespace dai {

/**
 * SystemLoggerProperties
 */
struct SystemLoggerProperties {
    /**
     * Rate at which the messages are going to be sent in hertz
     */
    float rateHz = 1.0f;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(SystemLoggerProperties, rateHz);

}  // namespace dai
