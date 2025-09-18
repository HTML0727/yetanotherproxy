#pragma once
#include <string>

struct ProxyInfo {
    std::string ip;
    int port = 0;
    bool ok = false;
    double latency_ms = 0;
    int success_count = 0;
    int fail_count = 0;
    double score = 0;
};
