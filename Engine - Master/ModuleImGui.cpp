#include "ModuleImGui.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_internal.h"
#include "ImGui/imgui_impl_opengl3.h"
#include <GL/glew.h>



ModuleImGui::ModuleImGui()
{
}


ModuleImGui::~ModuleImGui()
{
}

bool ModuleImGui::Init()
{
	LOG("Init ImGui");
	bool ret = true;

	//ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
	//ImGui_ImplOpenGL3_Init("#version 130");

	return ret;

}

bool ModuleImGui::CleanUp()
{
	//ImGui_ImplOpenGL3_Shutdown();
	return false;
}

