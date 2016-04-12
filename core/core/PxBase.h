#ifndef __PX_BASE_H__
#define __PX_BASE_H__

#include <gl/gl3w.h>

#define __gl_check_error__  {\
    GLenum error = glGetError();\
    if( error != GL_NO_ERROR )\
        glErrorHandler( error, __FILE__, __LINE__ );\
}

namespace px
{
    struct PxPoint
    {
        float x;
        float y;
        PxPoint():x(0), y(0){}
    };
    
    struct PxSize
    {
        float w;
        float h;
        PxSize():w(0), h(0){}
    };
    
    struct PxRect
    {
        float x;
        float y;
        float w;
        float h;
        PxRect():x(0), y(0), w(0), h(0){}
    };
    
    void glErrorHandler( GLenum _error, const char * _file, int _line );
}

#endif // __PX_BASE_H__
