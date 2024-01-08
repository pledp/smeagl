set( BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE )

option(GLFW_BUILD_SHARED_LIBS "Build shared libs" ON)
option(GLM_SHARED_LIBS "Build shared libs" ON)

add_subdirectory( glfw )
add_subdirectory( glm )
target_link_libraries(
    ${PROJECT_NAME}
        glfw
        glm
)