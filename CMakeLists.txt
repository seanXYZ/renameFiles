project(renameFiles)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS  "-g -Wall -O3 -Wno-unused-result")
set(CMAKE_C_FLAGS    "-g -Wall -O3 -Wno-unused-result")

message(STATUS "${PROJECT_SOURCE_DIR}")
message(STATUS "${CMAKE_BINARY_DIR}")

include_directories(
	${PROJECT_SOURCE_DIR}/lib_util )

#########################################################################
aux_source_directory(./lib_util        UTIL_SRCS)
aux_source_directory(.                 MAIN_SRCS)

message( STATUS "${UTIL_SRCS}")
message( STATUS "${MAIN_SRCS}")

#########################################################################
add_executable(renameFiles ${UTIL_SRCS}
			   ${MAIN_SRCS} )

###############################################################################
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/)
set(LIBRARY_OUTPUT_PATH    ${CMAKE_BINARY_DIR}/lib/)

message(STATUS "executable path is ${EXECUTABLE_OUTPUT_PATH}")
message(STATUS "library path is ${EXECUTABLE_OUTPUT_PATH}")

