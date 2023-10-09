set( BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE )
set( GLFW_LIBRARY_TYPE SHARED )

add_subdirectory( glfw )
add_subdirectory( glm )
target_link_libraries(
    ${PROJECT_NAME}
        glfw
        glm
)