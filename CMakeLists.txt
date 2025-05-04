cmake_minimum_required(VERSION 3.15)

project(
    application
    VERSION 0.0.1
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(application src/main.cpp)

include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
                              DOWNLOAD_EXTRACT_TIMESTAMP ON)
FetchContent_MakeAvailable(json)

find_package(diff REQUIRED)
find_package(iprocessable REQUIRED)
find_package(message_source REQUIRED)
find_package(link_gsm REQUIRED)
find_package(link_sat REQUIRED)
find_package(link_eth REQUIRED)

target_link_libraries(
    application
    diff::diff
    nlohmann_json::nlohmann_json
    iprocessable::iprocessable
    $<LINK_LIBRARY:WHOLE_ARCHIVE,message_source::message_source>
    $<LINK_LIBRARY:WHOLE_ARCHIVE,link_gsm::link_gsm>
    $<LINK_LIBRARY:WHOLE_ARCHIVE,link_sat::link_sat>
    $<LINK_LIBRARY:WHOLE_ARCHIVE,link_eth::link_eth>)
