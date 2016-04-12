#include "Application.h"
#include <assert.h>

#define SHADER_TEXT( T ) #T

const char * shader_vert = SHADER_TEXT(
    \x23version 410 core                                \n
    layout(location = 0) in vec3 position;              \n
                                                        \n
    void main(void)                                     \n
    {                                                   \n
        gl_Position = vec4(position, 1.0);              \n
    }                                                   \n
);

const char * shader_frag = SHADER_TEXT(

    \x23version 410 core                                \n
                                                        \n
    out vec4 color;                                     \n
                                                        \n
    void main(void)                                     \n
    {                                                   \n
        color = vec4(0, 0.8, 1.0, 1.0);                 \n
    }                                                   \n
);

GLuint vbo,ibo,vao;

float triangle[] = {
    -1.0, -1.0, 0.0,
    1.0, -1.0, 0.0,
    0, 1.0, 0.0
};

unsigned int indices[] = {
    0, 1, 2
};

px::VertexArray::Layout triLayout[] = {
{0, 3, GL_FLOAT, 0, 0},
{0,0,0,0,0}
};

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
    
    px::StaticIB * ib = px::StaticIB::New( indices, sizeof(indices) );
    px::StaticVB * vb = px::StaticVB::New( triangle, sizeof(triangle) );
    
    vao = px::VertexArray::New( vb, ib, &triLayout[0] );
    
    this->vao->Bind();
}

void Application::End()
{
    view->Release();
}

void Application::OnRender(unsigned long _tick)
{
    view->Begin();
    
    shader->Bind();

    this->vao->DrawTriangle( 3 );
    
    view->End();
}

px::ViewOGL * Application::GetView()
{
    return view;
}