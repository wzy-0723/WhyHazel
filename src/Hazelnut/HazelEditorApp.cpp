#include "hzpch.h"
#include "Hazel.h"

#include "EditorLayer.h"
#include "EntryPoint.h"
namespace Hazel 
{

	class HazelEditor : public Application
	{
	public:
		HazelEditor()
			: Application("Hazel Editor")
		{
			PushLayer(new EditorLayer());
		}

		~HazelEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new HazelEditor();
	}

}