#include "tester.hpp"
#include <vector>
int main(){ std::vector<ProxyInfo> v; v.push_back({"127.0.0.1",8080}); tester::test_proxies(v); return 0; }