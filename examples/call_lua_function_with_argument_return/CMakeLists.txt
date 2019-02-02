cmake_minimum_required (VERSION 2.8.11)
project (call_lua_function_with_argument_return)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.c)

configure_file(
	script4.lua
	${CMAKE_CURRENT_BINARY_DIR}/script4.lua
	COPYONLY
)

add_executable (${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME}
	${LUA_LIBRARIES}
)