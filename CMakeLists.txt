cmake_minimum_required(VERSION 3.24)
project(Algorithm)
set(TARGET Algorithm)

set(CMAKE_CXX_STANDARD 17)

include_directories(Base)
include_directories(mianshiJD150)
include_directories(common)

aux_source_directory(./ SRCS)
aux_source_directory(Base SRCS)
aux_source_directory(mianshiJD150 SRCS)


add_executable(${TARGET} ${SRCS})
