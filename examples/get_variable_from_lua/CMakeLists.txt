cmake_minimum_required (VERSION 2.8.11)
project (get_variable_from_lua)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.c)

configure_file(
	script2.lua
	${CMAKE_CURRENT_BINARY_DIR}/script2.lua
	COPYONLY
)

add_executable (${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME}
	${LUA_LIBRARIES}
)