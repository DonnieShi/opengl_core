#ifndef __PX_SHADER_OGL_H__
#define __PX_SHADER_OGL_H__

#include <gl/gl3w.h>

namespace px
{

class ShaderOGL
{
public:
    ShaderOGL();
    ~ShaderOGL();
    
    void Bind();
    void Release();
private:
    GLuint      m_vert;
    GLuint      m_frag;
    GLuint      m_prog;
public:
    static ShaderOGL * CreateShader( const char * _vert, const char * _frag );
};

}

#endif // __PX_SHADER_OGL_H__
