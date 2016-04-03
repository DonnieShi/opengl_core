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
    
    glCreateBuffers(1, &vbo);
    glCreateBuffers(1, &ibo);
    glGenVertexArrays(1, &vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
      hashTable.Set("lixin", "view");
      const char * ptr;
      bool ret = hashTable.Get( "lixin",ptr);
//      const char * ssss = "lixin";
//     size_t hash = 0;
//    hash = px::HashFunc("lixin",64);
//     hash = px::HashFunc(ssss,64);
//      printf("%d",hash);
//    GLuint value;
   // bool ret = hashTable.Get("lixin", value);
}

void Application::End()
{
    view->Release();
}

void Application::OnRender(unsigned long _tick)
{
    view->Begin();
    
    shader->Bind();
    
    // 索引为1处的格式
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
    glEnableVertexAttribArray(0);
    
    glBindVertexArray( vao );
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    
    glDrawElements( GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);
    
    view->End();
}
