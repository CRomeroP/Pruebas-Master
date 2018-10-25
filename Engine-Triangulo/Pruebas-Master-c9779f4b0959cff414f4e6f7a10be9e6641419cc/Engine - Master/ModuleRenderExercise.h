#ifndef __ModuleRenderExercise_h__
#define __ModuleRenderExercise_h__

#include "Module.h"
#include "MathGeoLib\include\Math\float3.h"
#include "MathGeoLib\include\Math\float4x4.h"

class ModuleRenderExercise : public Module
{
public:
    ModuleRenderExercise();
    ~ModuleRenderExercise();

	bool            Init    ();
	update_status   Update  ();
	float4x4		LookAt  (float3 target, float3 eye, float3 up);
	bool            CleanUp ();

private:
    unsigned vbo        = 0;
	Frustum frustum;
};

#endif /* __ModuleRenderExercise_h__ */
