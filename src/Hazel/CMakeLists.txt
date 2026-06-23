project(Hazel)

find_package(spdlog CONFIG REQUIRED)
find_package(glm REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)


add_definitions(-DHZ_BUILD_DLL)

file(GLOB_RECURSE source CONFIGURE_DEPENDS *.h *.cpp *.qrc *.ui *.shader)

source_group_by_dir(source "./")
add_library(${PROJECT_NAME} SHARED ${source})

target_include_directories(${PROJECT_NAME} PUBLIC 
	${src_dir_path}/Hazel
	${src_dir_path}/Hazel/Hazel
	${src_dir_path}/Hazel/Hazel/Events
	${src_dir_path}/Hazel/Hazel/ImGui
	${src_dir_path}/Hazel/Platform/Windows
	
)


target_link_libraries(${PROJECT_NAME} PUBLIC 
	spdlog::spdlog
	glfw 
	OpenGL::GL
	glad::glad
	imgui::imgui
)

# 设置预编译头 PRIVATE：仅 Hazel 内部源码包含 hzpch.h，外部Sandbox不强制
# target_precompile_headers(Hazel PRIVATE ${src_dir_path}/Hazel/hzpch.h)


config_output_paths(${PROJECT_NAME})