project(WhyUtil)



file(GLOB_RECURSE source CONFIGURE_DEPENDS *.h *.cpp *.qrc *.ui *.shader)

source_group_by_dir(source "./")
add_library(${PROJECT_NAME} STATIC ${source})

config_output_paths(${PROJECT_NAME})