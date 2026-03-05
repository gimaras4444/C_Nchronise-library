cmake_minimum_required(VERSION 3.10)
project(C_Nchronise VERSION 1.0.0)

add_library(C_Nchronise INTERFACE)

target_include_directories(C_Nchronise INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(C_Nchronise INTERFACE cxx_std_11)