cmake_minimum_required(VERSION 3.10)

set(TARGET_NAME hlimgui)
set(TARGET_EXT .hdll)

project(${TARGET_NAME})

file(GLOB SOURCES "*.cpp")
file(GLOB IMGUI_SOURCES "imgui/*.cpp")

add_library(${TARGET_NAME}${TARGET_EXT} SHARED ${SOURCES} ${IMGUI_SOURCES})

set_target_properties(${TARGET_NAME}${TARGET_EXT}
    PROPERTIES
    PREFIX ""
    OUTPUT_NAME ${TARGET_NAME}
    SUFFIX ${TARGET_EXT}
)

IF (WIN32)
target_include_directories(${TARGET_NAME}${TARGET_EXT} PUBLIC $ENV{HASHLINKPATH}/include)
target_link_libraries(${TARGET_NAME}${TARGET_EXT} $ENV{HASHLINKPATH}/libhl.lib)
ENDIF()

add_custom_command(TARGET ${TARGET_NAME}${TARGET_EXT} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}${TARGET_EXT}> ../..
)
