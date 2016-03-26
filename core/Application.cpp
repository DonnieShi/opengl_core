#include "Application.h"
#include <assert.h>

#define SHADER_TEXT( T ) #T

const char * shader_vert = SHADER_TEXT(
    
    \x23version 450 core                                \n
                                                        \n
    void main(void)                                     \n
    {                                                   \n
        // Declare a hard-coded array of positions      \n
        const vec4 vertices[] = vec4[](                 \n
            vec4(0.25, -0.25, 0.5, 1.0),                \n
            vec4(-0.25, -0.25, 0.5, 1.0),               \n
            vec4(0.25, 0.25, 0.5, 1.0)                  \n
        );                                              \n
        // Index into our array using gl_VertexID       \n
        gl_Position = vertices[gl_VertexID];            \n
    }                                                   \n
);

const char * shader_frag = SHADER_TEXT(

    \x23version 450 core                                \n
                                                        \n
    out vec4 color;                                     \n
                                                        \n
    void main(void)                                     \n
    {                                                   \n
        color = vec4(0, 0.8, 1.0, 1.0);                 \n
    }                                                   \n
);


Application::Application()
{
    
}

Application::~Application()
{
    
}

void Application::Start(void* _hwnd)
{
    view = px::ViewOGL::CreateView( _hwnd );
    shader = px::ShaderOGL::CreateShader( shader_vert, shader_frag );
    assert( view && shader );
}

void Application::End()
{
    view->Release();
}

void Application::OnRender(unsigned long _tick)
{
    view->Begin();
    
    shader->Bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    view->End();
}
