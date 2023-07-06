cmake_minimum_required(VERSION 3.21)
project(Durak LANGUAGES CXX)


file(GLOB_RECURSE MY_SOURCES "src/**.cpp")

option(DISABLE_CONSOLE_AND_DEBUGGING "If true, will make for windows app instead of console app" OFF)

if(DISABLE_CONSOLE_AND_DEBUGGING)
    add_compile_definitions(DRK_NDBG)
    add_compile_options(-O3 -save-temps)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
else()
    add_compile_options(-g -O0 -Wall -Wextra -pedantic -save-temps)
endif()

add_executable(Durak ${MY_SOURCES})

target_include_directories(Durak PUBLIC ${CMAKE_SOURCE_DIR}/../dep/SFML2.6/include/*.hpp)

target_link_libraries(Durak PUBLIC ${CMAKE_SOURCE_DIR}/../dep/SFML2.6/lib/*.a)

target_compile_features(Durak PRIVATE cxx_std_20)

install(TARGETS Durak)