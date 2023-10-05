cmake_minimum_required(VERSION 3.20)

# Set project name and version
project(sfml-timber VERSION 0.1)

set(WINDOW_SIZE_X 800)
set(WINDOW_SIZE_Y 450)
option(USE_INSTALL_RESOURCE_PATH "Set resource path to install location" OFF)
if (NOT USE_INSTALL_RESOURCE_PATH)
    set(RESOURCE_PATH "${PROJECT_SOURCE_DIR}/content/")
else()
    set(RESOURCE_PATH "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}/content/")
endif()

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

set(SOURCES 
    src/main.cpp
)

# Enable debug symbols by default
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# Generate config.h
configure_file(include/config.h.in config.h)

# Find SFML shared libraries
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Compile executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Set include directory search paths
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_BINARY_DIR})

# Link executable to required SFML libraries
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

# Install target
install(TARGETS ${PROJECT_NAME} DESTINATION "${PROJECT_BINARY_DIR}/build/bin")
