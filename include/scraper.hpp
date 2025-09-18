#pragma once
#include <vector>
#include <string>
#include "proxy.hpp"

namespace scraper {
    std::vector<ProxyInfo> fetch_proxies(const std::string& sources_file);
}
