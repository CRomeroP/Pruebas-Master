#include "Application.h"

#include "ModuleRenderExercise.h"
#include "ModuleWindow.h"
#include "MathGeoLib.h"

#include "GL/glew.h"
#include "SDL.h"

ModuleRenderExercise::ModuleRenderExercise()
{
}

ModuleRenderExercise::~ModuleRenderExercise()
{
}

bool ModuleRenderExercise::Init()
{
    float vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
	};

	math::float3 target(0, 0, 0);
	math::float3 eye(0, 0, 9.0);
	math::float3 up(0, 1, 0);

	float4x4 ModelView = LookAt(target, eye, up);

	Frustum frustum;
	frustum.type = FrustumType::PerspectiveFrustum;
	frustum.pos = float3::zero;
	frustum.front = -float3::unitZ;
	frustum.up = float3::unitY;
	frustum.nearPlaneDistance = 0.1f;
	frustum.farPlaneDistance = 100.0f;
	frustum.verticalFov =  math::pi/ 4.0f;
	frustum.horizontalFov = 2.f * atanf(tanf(frustum.verticalFov * 0.5f) * (SCREEN_WIDTH / SCREEN_HEIGHT));
	math::float4x4 proj = frustum.ProjectionMatrix();

	math::float4x4 model = proj * ModelView;

	math::float4 VertexUno(vertex_buffer_data[0], vertex_buffer_data[1], vertex_buffer_data[2], 1);
	math::float4 VertexDos(vertex_buffer_data[3], vertex_buffer_data[4], vertex_buffer_data[5], 1);
	math::float4 VertexTres(vertex_buffer_data[6], vertex_buffer_data[7], vertex_buffer_data[8], 1);

	math::float4 AuxUno =  VertexUno * model;
	math::float4 AuxDos =  VertexDos * model;
	math::float4 AuxTres = VertexTres * model;

	/*vertex_buffer_data[0] = AuxUno.x / AuxUno.w;
	vertex_buffer_data[1] = AuxUno.y / AuxUno.w;
	vertex_buffer_data[2] = AuxUno.z / AuxUno.w;

	vertex_buffer_data[3] = AuxDos.x / AuxDos.w;
	vertex_buffer_data[4] = AuxDos.y / AuxDos.w;
	vertex_buffer_data[5] = AuxDos.z / AuxDos.w;

	vertex_buffer_data[6] = AuxTres.x / AuxTres.w;
	vertex_buffer_data[7] = AuxTres.y/ AuxTres.w;
	vertex_buffer_data[8] = AuxTres.z / AuxTres.w;*/

	math::float3 FinUno(AuxUno.x / AuxUno.w, AuxUno.y / AuxUno.w, AuxUno.z / AuxUno.w);
	math::float3 FinDos(AuxDos.x / AuxDos.w, AuxDos.y / AuxDos.w, AuxDos.z / AuxDos.w);
	math::float3 FinTres(AuxTres.x / AuxTres.w, AuxTres.y / AuxTres.w, AuxTres.z / AuxTres.w);

	float vertex_transformed_data[] = {
		FinUno.x, FinUno.y, FinUno.z,
		FinDos.x, FinDos.y, FinDos.z,
		FinTres.x, FinTres.y, FinTres.z,
	};

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return vbo;
}

float4x4 ModuleRenderExercise::LookAt(float3 target, float3 eye, float3 up)
{
	math::float3 f(target - eye);
	f.Normalize();
	math::float3 s(f.Cross(up));
	s.Normalize();
	math::float3 u(s.Cross(f));
	math::float4x4 matrix(0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 1);
	matrix[0][0] = s.x; matrix[0][1] = s.y; matrix[0][2] = s.z;
	matrix[1][0] = u.x; matrix[1][1] = u.y; matrix[1][2] = u.z;
	matrix[2][0] = -f.x; matrix[2][1] = -f.y; matrix[2][2] = -f.z;
	matrix[0][3] = -s.Dot(eye); matrix[1][3] = -u.Dot(eye); matrix[2][3] = f.Dot(eye);
	return matrix;
}

update_status ModuleRenderExercise::Update()
{
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(
            0,                  // attribute 0
            3,                  // number of componentes (3 floats)
            GL_FLOAT,           // data type
            GL_FALSE,           // should be normalized?
            0,                  // stride
            (void*)0            // array buffer offset
            );

    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle

    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

	return UPDATE_CONTINUE;
}

bool ModuleRenderExercise::CleanUp()
{
    if(vbo != 0)
    {
        glDeleteBuffers(1, &vbo);
    }

	return true;
}

