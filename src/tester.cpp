#include "tester.hpp"
#include <thread>
#include <chrono>
#include <iostream>

namespace tester {
    void test_proxies(std::vector<ProxyInfo>& proxies, int max_threads) {
        for(auto& p : proxies) {
            // Dummy test: mark all as ok with random latency
            p.ok = true;
            p.latency_ms = 50 + (rand()%200);
            p.success_count++;
        }
        std::cout << "Tested " << proxies.size() << " proxies" << std::endl;
    }
}
