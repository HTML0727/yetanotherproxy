cmake_minimum_required(VERSION 3.10)
project(yetanotherproxy LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CURL REQUIRED)

if(WIN32)
    find_library(PDCURSES_LIB pdcurses)
    set(EXTRA_LIBS ${PDCURSES_LIB})
else()
    find_library(NCURSES_LIB ncurses)
    set(EXTRA_LIBS ${NCURSES_LIB})
endif()

add_executable(yetanotherproxy
    src/main.cpp
    src/scraper.cpp
    src/tester.cpp
    src/tui.cpp
    src/datastore.cpp
    src/utils.cpp
)

target_include_directories(yetanotherproxy PRIVATE include ${CURL_INCLUDE_DIRS})
target_link_libraries(yetanotherproxy PRIVATE ${CURL_LIBRARIES} ${EXTRA_LIBS})
