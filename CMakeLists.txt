cmake_minimum_required (VERSION 2.8.11)

set(EXAMPLES "examples")

set(CMAKE_C_FLAGS "-Wall -std=c99 -ggdb ${CMAKE_C_FLAGS}")

find_package(Lua REQUIRED)

include_directories(
	${LUA_INCLUDE_DIR}
)

add_subdirectory(${EXAMPLES}/starting_lua_vm)
add_subdirectory(${EXAMPLES}/running_lua_code_from_string)
add_subdirectory(${EXAMPLES}/running_lua_code_from_file)
add_subdirectory(${EXAMPLES}/get_variable_from_lua)
add_subdirectory(${EXAMPLES}/exposing_variable_to_lua)
add_subdirectory(${EXAMPLES}/exposing_single_function_lua)
add_subdirectory(${EXAMPLES}/exposing_functions_namespace_lua)
add_subdirectory(${EXAMPLES}/call_lua_function_with_argument_return)
add_subdirectory(${EXAMPLES}/call_lua_function)