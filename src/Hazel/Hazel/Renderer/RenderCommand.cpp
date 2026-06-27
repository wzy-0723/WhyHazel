#include "hzpch.h"
#include "RenderCommand.h"

#include "OpenGLRendererAPI.h"

namespace Hazel 
{

	Scope<RendererAPI> RenderCommand::s_RendererAPI = CreateScope<OpenGLRendererAPI>();


}