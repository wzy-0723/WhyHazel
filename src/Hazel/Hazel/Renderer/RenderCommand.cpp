#include "hzpch.h"
#include "RenderCommand.h"

#include "OpenGLRendererAPI.h"

namespace Hazel {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;


}