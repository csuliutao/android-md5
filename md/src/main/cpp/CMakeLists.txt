cmake_minimum_required(VERSION 3.4.1)

include_directories(./)
aux_source_directory(./ SRC_PATH)
add_library(md5 SHARED ${SRC_PATH})

target_link_libraries(md5)