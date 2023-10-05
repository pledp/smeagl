set( BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE )
set( GLFW_LIBRARY_TYPE SHARED )

add_subdirectory( glfw )
target_link_libraries(
    ${PROJECT_NAME}
        glfw
)