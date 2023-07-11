cmake_minimum_required(VERSION 3.11)

project(SDL2Test)

# Add include path
set(CMAKE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}")

# Set output directory of EXE file.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}")


# Include files that should be compiled.
file(GLOB_RECURSE SRC "src/*.cpp" "src/*.h" "Demo/src/*.cpp" "Demo/src/*.h")

message(STATUS "Add source files:")
foreach(SRC_FILE IN LISTS SRC)
    message(STATUS "${SRC_FILE}")
endforeach()
message(STATUS "")

add_executable(${PROJECT_NAME} ${SRC})

find_package(SDL2 REQUIRED)

# Include SDL2 and include directory
target_include_directories(
    ${PROJECT_NAME}
        PUBLIC Demo/include
        PUBLIC include/
        PUBLIC include/Graphics/
        PUBLIC include/Application/
        PUBLIC ${SDL2_INCLUDE_DIRS}
)

# Link SDL and mingw
target_link_libraries(
    ${PROJECT_NAME}
        mingw32
        SDL2main
        SDL2
)


# Copy assets to executable's directory
message(STATUS "Copying all assets to destination folder...")
file(
    COPY assets
    DESTINATION ${OUTPUT_DIR}
)

message(STATUS "Copying all dependencies to destination folder...")
file(GLOB PROJECT_DEPENDENCIES ${SDL2_LIBRARY}/*.dll)

foreach(Dependency IN LISTS PROJECT_DEPENDENCIES)
    file(
        COPY ${Dependency}
        DESTINATION ${OUTPUT_DIR}
    )
endforeach()