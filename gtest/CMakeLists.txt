cmake_minimum_required (VERSION 2.6)

project (gtest-test)

add_executable(Tutorial
	gtest.cpp
)


find_package(PkgConfig)
pkg_check_modules(GTEST REQUIRED gtest>=1.7.0)
pkg_check_modules(GMOCK REQUIRED gmock>=1.7.0)

target_link_libraries(Tutorial gtest gmock pthread)

include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
)
