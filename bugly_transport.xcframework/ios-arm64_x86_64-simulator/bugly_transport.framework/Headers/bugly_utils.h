//
//  bugly_utils.h
//  Bugly
//
//  Created by Hua Xiang on 2024/02/21.
//

#ifndef BUGLY_UTILS_H
#define BUGLY_UTILS_H

#include <vector>
#include <string>

namespace bugly {
std::vector<std::string> split(const std::string& s, const std::string& delimiter);

std::string zipString(const std::string& str);

std::string makeUUID();

uint64_t getCurrentTime();
}


#endif //BUGLY_UTILS_H