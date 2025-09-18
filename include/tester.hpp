#pragma once
#include <vector>
#include "proxy.hpp"

namespace tester {
    void test_proxies(std::vector<ProxyInfo>& proxies, int max_threads = 10);
}
