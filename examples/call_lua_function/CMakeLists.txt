cmake_minimum_required (VERSION 2.8.11)
project (call_lua_function)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.c)

configure_file(
	script3.lua
	${CMAKE_CURRENT_BINARY_DIR}/script3.lua
	COPYONLY
)

add_executable (${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME}
	${LUA_LIBRARIES}
)