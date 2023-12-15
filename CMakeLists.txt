cmake_minimum_required(VERSION 3.24)
project(Algorithm)
set(TARGET Algorithm)

set(CMAKE_CXX_STANDARD 17)

include_directories(Base)
include_directories(common)
include_directories(MSJD150)
include_directories(bp_tx)


aux_source_directory(./ SRCS)
aux_source_directory(Base SRCS)
aux_source_directory(MSJD150 SRCS)
aux_source_directory(bp_tx SRCS)


add_executable(${TARGET} ${SRCS})
