#include "datastore.hpp"
#include <fstream>
#include <iostream>

namespace datastore {
    void save_history(const std::vector<ProxyInfo>& proxies, const std::string& file) {
        std::ofstream fout(file);
        fout << "[\n";
        for(size_t i=0;i<proxies.size();i++) {
            fout << "  {\"ip\": \"" << proxies[i].ip << "\", "
                 << "\"port\": " << proxies[i].port << ", "
                 << "\"latency\": " << proxies[i].latency_ms << " }";
            if(i+1<proxies.size()) fout << ",";
            fout << "\n";
        }
        fout << "]\n";
    }
    std::vector<ProxyInfo> load_history(const std::string& file) {
        return {}; // stub
    }
}
