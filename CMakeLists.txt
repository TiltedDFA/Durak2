cmake_minimum_required(VERSION 3.21)
project(Durak LANGUAGES CXX)
set(BUILD_SHARED_LIBS OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE MY_SOURCES "src/**.cpp")

option(ENABLE_CLANG_TIDY "Run Clang-Tidy with the build (default: OFF)" OFF)
if(ENABLE_CLANG_TIDY)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        find_program(CLANG_TIDY_EXE NAMES "clang-tidy" "clang-tidy-11" "clang-tidy-10" "clang-tidy-9" "clang-tidy-8" "clang-tidy-7" "clang-tidy-6.0" "clang-tidy-5.0" "clang-tidy-4.0")
        if(CLANG_TIDY_EXE)
            message(STATUS "Clang-Tidy found: ${CLANG_TIDY_EXE}")
            set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}" "--fix-errors" "-header-filter=.*")
        else()
            message(WARNING "Clang-Tidy not found.")
        endif()
    endif()
endif()

option(DISABLE_CONSOLE_AND_DEBUGGING "If true, will make for windows subsystem instead of console" OFF)
if(DISABLE_CONSOLE_AND_DEBUGGING)
    add_compile_definitions(DRK_NDBG)
    add_compile_options(-O3 -save-temps)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
else()
    add_compile_options(-g -O0 -Wall -Wextra -pedantic -save-temps)
endif()

add_executable(Durak ${MY_SOURCES})
target_link_libraries(Durak PRIVATE sfml-graphics)

target_compile_features(Durak PRIVATE cxx_std_20)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Durak POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Durak> $<TARGET_FILE_DIR:Durak> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Durak)