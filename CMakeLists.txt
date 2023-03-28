cmake_minimum_required(VERSION 3.21)
project(Durak LANGUAGES CXX)
set(BUILD_SHARED_LIBS OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

file(GLOB MY_SOURCES "src/*.cpp")
add_compile_options(-O3 -Wall -Wextra -pedantic -save-temps)
add_executable(Durak ${MY_SOURCES})
target_link_libraries(Durak PRIVATE sfml-graphics)
target_compile_features(Durak PRIVATE cxx_std_20)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Durak POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Durak> $<TARGET_FILE_DIR:Durak> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Durak)