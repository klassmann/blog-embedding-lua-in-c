cmake_minimum_required (VERSION 2.8.11)
project (starting_lua_vm)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.c)

add_executable (${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME}
	${LUA_LIBRARIES}
)