set( BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE )

add_subdirectory( glfw )
target_link_libraries(
    ${PROJECT_NAME}
        glfw
)