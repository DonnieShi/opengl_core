#include "../cmn/PxLog.h"
#include "ShaderOGL.h"

px::ShaderOGL::ShaderOGL()
{
    m_vert = m_prog = m_frag = 0;
}

px::ShaderOGL::~ShaderOGL()
{
    
}


px::ShaderOGL* px::ShaderOGL::CreateShader( const char* _vert, const char* _frag)
{
    if( strlen(_vert) < 16 || strlen(_frag) < 16)
    {
        PXLOG_I("shader length too short!!! Maybe invalid shader source!");
    }
    
    px::ShaderOGL * shader = new px::ShaderOGL;
    shader->m_vert = glCreateShader( GL_VERTEX_SHADER );
    glShaderSource( shader->m_vert, 1, (const GLchar * const * )&_vert, NULL );
    glCompileShader( shader->m_vert );
    int compiled;
    
    glGetShaderiv( shader->m_vert, GL_COMPILE_STATUS, &compiled );
        if ( !compiled ) {
            GLint  logSize;
            glGetShaderiv( shader->m_vert, GL_INFO_LOG_LENGTH, &logSize );
            char* logMsg = new char[logSize];
            glGetShaderInfoLog( shader->m_vert, logSize, NULL, logMsg );
            PXLOG_I("shader error : %s", logMsg);
            delete [] logMsg;
            return NULL;
        }

    
    shader->m_frag = glCreateShader( GL_FRAGMENT_SHADER );
    glShaderSource( shader->m_frag, 1, (const GLchar * const * )&_frag, NULL );
    glCompileShader( shader->m_frag );
    
    glGetShaderiv( shader->m_frag, GL_COMPILE_STATUS, &compiled );
    if ( !compiled ) 
    {
        GLint  logSize;
        glGetShaderiv( shader->m_frag, GL_INFO_LOG_LENGTH, &logSize );
        char* logMsg = new char[logSize];
        glGetShaderInfoLog( shader->m_frag, logSize, NULL, logMsg );
        PXLOG_I("shader error : %s", logMsg);
        delete [] logMsg;
        return NULL;
    }
    shader->m_prog = glCreateProgram();
    glAttachShader( shader->m_prog, shader->m_vert );
    glAttachShader( shader->m_prog, shader->m_frag );
    glLinkProgram( shader->m_prog );

    int linked;
    glGetProgramiv(shader->m_prog, GL_LINK_STATUS, &linked);    
    if ( !linked ) 
    {
        GLint  logSize;
        glGetShaderiv( shader->m_prog, GL_INFO_LOG_LENGTH, &logSize );
        char* logMsg = new char[logSize];
        glGetProgramInfoLog( shader->m_prog, logSize, NULL, logMsg );
        PXLOG_I("link error : %s", logMsg);
        delete [] logMsg;
        return NULL;
    }
        
    glDeleteShader( shader->m_frag );
    glDeleteShader( shader->m_vert );
    
    return shader;
}

void px::ShaderOGL::Release()
{
    glDeleteProgram( m_prog );
    delete this;
}

void px::ShaderOGL::Bind()
{
    glUseProgram( m_prog );
}
