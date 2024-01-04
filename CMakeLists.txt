cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 20)

cmake_policy(SET CMP0079 NEW)

project(pledGL)

# Add include path
set(CMAKE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/Core/include)
set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}")

# Set output directory of EXE file.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
file(GLOB_RECURSE LIBSRC "Core/src/*.cpp" "Core/src/*.h" "external/glad/*.c" "external/glad/*.h" "external/stb/*.h" "external/stb/*.cpp")
add_library(pledGL SHARED ${LIBSRC})
target_include_directories(
    pledGL
        PUBLIC Core/include/
        PUBLIC external/glad/include/
        PUBLIC external/glm/
        PUBLIC External/
        PUBLIC ${SDL2_INCLUDE_DIRS}
)
target_link_libraries(
    pledGL
        SDL2main
        SDL2
)

# Include files that should be compiled.
file(GLOB_RECURSE SRC "Demo/src/*.cpp" "Demo/src/*.h")

message(STATUS "Add source files:")
foreach(SRC_FILE IN LISTS SRC)
    message(STATUS "${SRC_FILE}")
endforeach()
message(STATUS "")

add_executable(pledGLDemo ${SRC})

add_subdirectory("external")


# Include SDL2 and include directory
target_include_directories(
    pledGLDemo
        PUBLIC Demo/include/
        PUBLIC Core/include/
)
target_link_libraries(
    pledGLDemo
        pledGL
)

# Copy assets to executable's directory
message(STATUS "Copying all assets to destination folder...")
file(
    COPY assets
    DESTINATION ${OUTPUT_DIR}
)