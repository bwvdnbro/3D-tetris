add_subdirectory(pieces)
add_subdirectory(pieces3d)
add_subdirectory(gui)

aux_source_directory(. SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} pieces)
target_link_libraries(${PROJECT_NAME} pieces3d)
target_link_libraries(${PROJECT_NAME} gui)
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
