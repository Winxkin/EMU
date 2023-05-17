cmake_minimum_required(VERSION 3.16.3)
project(EMU)


# set CMAKE_CXX_FLAGS variable
set(CMAKE_CXX_FLAGS "-g -Wall -O")

# add include file and source file
file(GLOB INCLUDE_FILE
    "${PROJECT_SOURCE_DIR}/inc/*.h")
file(GLOB SOURCE_FILE
    "${PROJECT_SOURCE_DIR}/src/*.cpp")

message("${INCLUDE_FILE}")
message("${SOURCE_FILE}")

# include directory
file(GLOB INC_PATHS "${PROJECT_SOURCE_DIR}/inc")

# add static library from source file
set(STATIC_LIB "${PROJECT_NAME}")
add_library(${STATIC_LIB} STATIC ${SOURCE_FILE} ${INCLUDE_FILE})
target_include_directories(${STATIC_LIB}
    PUBLIC
    ${INC_PATHS})

# check app directory
file(GLOB APP_FILE "${PROJECT_SOURCE_DIR}/app/*.cpp")

message("${APP_FILE}")
foreach(A ${APP_FILE})
    get_filename_component(TARGET "${A}" NAME_WLE)
    add_executable(${TARGET} ${A})
    target_link_libraries(${TARGET} PUBLIC ${STATIC_LIB})
endforeach()

