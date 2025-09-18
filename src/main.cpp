#include <iostream>
#include <vector>
#include "scraper.hpp"
#include "tester.hpp"
#include "tui.hpp"
#include "datastore.hpp"

int main() {
    std::cout << "Starting yetanotherproxy..." << std::endl;
    auto proxies = scraper::fetch_proxies("data/sources.txt");
    tester::test_proxies(proxies);
    datastore::save_history(proxies);
    tui::run(proxies);
    return 0;
}
