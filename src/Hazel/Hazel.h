#pragma once
#include "Layer.h"
#include "Log.h"

#include "Timestep.h"
#include "Input.h"
#include "KeyCodes.h"
#include "MouseButtonCodes.h"

#include "ImGuiLayer.h"


// ---Renderer------------------------
#include "Renderer.h"
#include "RenderCommand.h"

#include "Buffer.h"
#include "Shader.h"
#include "Texture.h"

#include "VertexArray.h"

#include "OrthographicCamera.h"
// -----------------------------------


// 宏定义和头文件按序展开，包含Application必须在包含EntryPoint之前，否则Application未定义
#include "Application.h"
#include "EntryPoint.h"



