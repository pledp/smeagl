set( BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE )

add_subdirectory( glfw )
find_package(glm CONFIG REQUIRED)
target_link_libraries(
    ${PROJECT_NAME}
        glfw
        glm::glm
)