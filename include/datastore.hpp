#pragma once
#include <vector>
#include "proxy.hpp"

namespace datastore {
    void save_history(const std::vector<ProxyInfo>& proxies, const std::string& file="data/history.json");
    std::vector<ProxyInfo> load_history(const std::string& file="data/history.json");
}
