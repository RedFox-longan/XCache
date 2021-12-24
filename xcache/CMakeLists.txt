cmake_minimum_required(VERSION 3.19)
project(xcache C CXX)

include_directories(include)

file(GLOB APP_SOURCES source/*.cpp source/*.c)
# file(GLOB APP_HEADERS include/*.hpp include/*.h) ${APP_HEADERS}
add_executable(xcache ${APP_SOURCES})

# 添加链接库文件(lib)
# target_link_libraries(demo
#         space-longan-renderer
#         gcc
#         mingw32
#         opengl32
#         )





