//
//  bugly_option.h
//  Bugly
//
//  Created by Hua Xiang on 2024/03/08.
//

#ifndef BUGLY_OPTION_H
#define BUGLY_OPTION_H

#include <string>

namespace bugly {

enum BUGLY_SDK_TYPE : uint32_t {
    BUGLY_WOA = 0,
    BUGLY_PRO,
    BUGLY_CLOUD,
    BUGLY_OVERSEA,
    
    BUGLY_SDK_TYPE_COUNT,
};

struct BuglyOption
{
    bool                            isDebug{false};
    bool                            isTestEnv{false};

    BUGLY_SDK_TYPE                  SDKType{BUGLY_SDK_TYPE::BUGLY_WOA};
    std::string                     userId;
    std::string                     appId;
    std::string                     appKey;

    std::string                     bundleId;
    std::string                     appName;
    std::string                     appVersion;
    std::string                     appChannel;
    std::string                     appBuildNumber;
    std::string                     appVersionMode;
    
    std::string                     buglyVersion;
    std::string                     launchId;

    std::string                     deviceId;
    std::string                     platform;
};

}

#endif //BUGLY_OPTION_H
