cmake_minimum_required(VERSION 3.19)
project(main C CXX)


# C++17 - 32bit static libgcc
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-m32")
set(CMAKE_CXX_FLAGS "-static")

# set(CMAKE_CXX_FLAGS "-libgcc")

# win32窗口、win32控制台
# add_executable(space-longan-renderer WIN32 source/main.cpp)

# 输出操作系统平台信息
math(EXPR TARGET_BITS "8 * ${CMAKE_SIZEOF_VOID_P}")
if (WIN32)
    message(STATUS "Building on Windows platform.")
elseif (APPLE)
    message(STATUS "Building on MacOS platform.")
    add_compile_definitions(TARGET_OS_MAC)
elseif (UNIX)
    message(STATUS "Building on UNIX-like OS platform.")
elseif (MinGW)
    message(STATUS "Building on UNIX-like OS platform.")
endif ()

# 输出编译器信息
if (MSVC)
    # MSVC utf-8
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")
    message(STATUS "${TARGET_BITS}bit MSVC target: MSVC ${MSVC_VERSION}")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    # GNU utf-8
    add_compile_options("$<$<C_COMPILER_ID:GNU>:-fexec-charset=GBK>")
    add_compile_options("$<$<CXX_COMPILER_ID:GNU>:-fexec-charset=GBK>")
    add_compile_options("$<$<C_COMPILER_ID:GNU>:-finput-charset=utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:GNU>:-finput-charset=utf-8>")
    message(STATUS "${TARGET_BITS}bit GNU target: GCC ${CMAKE_C_COMPILER_VERSION}")
else ()
    if (CMAKE_CXX_COMPILER_ID)
        message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
    else ()
        message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER}")
    endif ()
endif ()

# 添加头文件(*/include)
include_directories(xcache/include)
# include_directories(demo/include)

# 添加创建库文件的子目录
add_subdirectory(xcache)
# add_subdirectory(demo)


