#include "utils.hpp"
#include <iostream>
#include <ctime>

namespace utils {
    void log(const std::string& msg) {
        std::cout << "[" << timestamp() << "] " << msg << std::endl;
    }
    std::string timestamp() {
        std::time_t t = std::time(nullptr);
        char buf[64]; std::strftime(buf,sizeof(buf),"%F %T",std::localtime(&t));
        return buf;
    }
}
