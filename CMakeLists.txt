cmake_minimum_required(VERSION 3.10)
project(UlillilliaisticAimTrainer)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# sdl docs recommended that I do this
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#set(FREETYPE_ROOT "C:/Users/s5pajo02/freetype")
#set(FREETYPE_INCLUDE_DIR "${FREETYPE_ROOT}/include")
#set(FREETYPE_LIBRARY "${FREETYPE_ROOT}/release static/vs2015-2022/win64/freetype.lib")

#set(FREETYPE_INCLUDE_DIRS ${FREETYPE_INCLUDE_DIR})
#set(FREETYPE_LIBRARIES ${FREETYPE_LIBRARY})

#link_directories("${FREETYPE_ROOT}/release static/vs2015-2022/win64")
#include_directories("${FREETYPE_INCLUDE_DIR}")

add_subdirectory(lib/SDL/ EXCLUDE_FROM_ALL)
add_subdirectory(lib/SDL_image/ EXCLUDE_FROM_ALL)
add_subdirectory(lib/SDL_ttf/ EXCLUDE_FROM_ALL)

file(GLOB SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})

add_custom_target(CopyResources ALL
    COMMAND ${CMAKE_COMMAND}    -D SRC=${CMAKE_CURRENT_SOURCE_DIR}/res
                                -D DST=${CMAKE_BINARY_DIR}/res
                                -P ${CMAKE_CURRENT_SOURCE_DIR}/copy_res.cmake
    COMMENT "Syncing resources res/"
    VERBATIM
)

add_dependencies(${PROJECT_NAME} CopyResources)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3_ttf::SDL3_ttf SDL3_image::SDL3_image SDL3::SDL3)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
#target_link_libraries(${PROJECT_NAME} PRIVATE SDL3_ttf::SDL3_ttf SDL3_image::SDL3_image SDL3::SDL3 ${FREETYPE_LIBRARIES})
