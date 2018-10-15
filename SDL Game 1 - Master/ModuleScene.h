#pragma once
#include "Module.h"
#include "Globals.h"
#include "Glew/include/GL/glew.h"

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool Init();
	update_status Update();
	bool CleanUp();

public:
	GLuint vbo;
};
