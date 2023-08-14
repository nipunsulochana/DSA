#pragma once

#include <vector>
#include <string>

namespace re {
    bool kmpSearch(const std::string& text, const std::string& pattern);
    std::vector<int> makeHash(const std::string& pattern);
    bool strSearch(const std::string& text, const std::string& pattern);
}
