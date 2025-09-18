#include "scraper.hpp"
#include <cassert>
int main(){ auto proxies=scraper::fetch_proxies("../data/sources.txt"); assert(!proxies.empty()); return 0; }