project(Sandbox)
file(GLOB_RECURSE source CONFIGURE_DEPENDS *.h *.cpp *.qrc *.ui *.glsl)
set(src_dir_path ${CMAKE_HOME_DIRECTORY}/src)

include_directories(${src_dir_path}/Hazel)



link_directories(${lib_dir_path})
source_group_by_dir(source "./")
add_executable(${PROJECT_NAME} ${source})
target_link_libraries(${PROJECT_NAME} PRIVATE 
#自写库
	Hazel
#三方
	
)




#CMAKE_INSTALL_BINDIR
#RUNTIME_OUTPUT_DIRECTORY
#message(STATUS "RUNTIME_OUTPUT_DIRECTORY: ${RUNTIME_OUTPUT_DIRECTORY}")
#message(STATUS "projectDir: ${projectDir}")


#copy_dir_to_bin(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/assets assets)

config_output_paths(${PROJECT_NAME})

