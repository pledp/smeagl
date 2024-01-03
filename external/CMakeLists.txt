
add_subdirectory( glfw )
add_subdirectory( glm )
find_package(glm CONFIG REQUIRED)
target_link_libraries(
    ${PROJECT_NAME}
        glfw
        glm::glm
)