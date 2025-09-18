#include "scraper.hpp"
#include <fstream>
#include <iostream>

namespace scraper {
    std::vector<ProxyInfo> fetch_proxies(const std::string& sources_file) {
        std::vector<ProxyInfo> proxies;
        std::ifstream fin(sources_file);
        std::string line;
        while(std::getline(fin, line)) {
            ProxyInfo p;
            size_t pos = line.find(':');
            if(pos != std::string::npos) {
                p.ip = line.substr(0,pos);
                p.port = std::stoi(line.substr(pos+1));
                proxies.push_back(p);
            }
        }
        return proxies;
    }
}
