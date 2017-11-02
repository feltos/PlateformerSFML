cmake_minimum_required(VERSION 3.9)
project(SFML_Box2D_Example)

file(GLOB_RECURSE SFML_Box2D_Example_SRC src/*.cpp include/*.h)

include_directories(include/)
add_executable(SFML_Box2D_Example ${SFML_Box2D_Example_SRC})
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/externals)

#SFML
set(SFML_DIR ${EXTERNAL_DIR}/SFML-2.4.2)
set(SFML_BUILD_EXAMPLES FALSE)
add_subdirectory(${SFML_DIR})
include_directories(${SFML_DIR}/include)
LIST(APPEND SFML_Box2D_Example_LIBRARIES
	sfml-system
	sfml-window
	sfml-graphics)
	
#Box2D
set(BOX2D_DIR ${EXTERNAL_DIR}/Box2D)
add_subdirectory(${BOX2D_DIR})
include_directories(${BOX2D_DIR}/)
LIST(APPEND SFML_Box2D_Example_LIBRARIES
	Box2D)
	
target_link_libraries(SFML_Box2D_Example ${SFML_Box2D_Example_LIBRARIES})