project(multi-process)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. DIR_SRCS)
add_executable(multi-process ${DIR_SRCS})

set (SRC_VERSION_MAJOR 1)
set (SRC_VERSION_MINOR 0)
set (SRC_VERSION_PATCH 1)
set (SRC_VERSION ${SRC_VERSION_MAJOR}.${SRC_VERSION_MINOR}.${SRC_VERSION_PATCH})
set (PROJECT_VERSION "${SRC_VERSION}")

#add_definitions(-DRUN_SYSTEM_APP)
add_definitions(-DINITROOT_STARTUP)

target_link_libraries(multi-process initroot_startup)

install(TARGETS multi-process DESTINATION bin)
