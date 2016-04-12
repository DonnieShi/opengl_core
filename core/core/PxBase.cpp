#include "PxBase.h"
#include "../cmn/PxLog.h"


void px::glErrorHandler(GLenum _error, const char* _file, int _line)
{
    const char * szError=NULL;
    switch( _error )
    {
        case GL_INVALID_ENUM:
        {
            szError = "GL_INVALID_ENUM";
            break;
        }
        case GL_INVALID_VALUE:
        {
            szError = "GL_INVALID_OPERATION";
            break;
        }
        case GL_INVALID_OPERATION:
        {
            szError = "GL_INVALID_OPERATION";
            break;
        }
        case GL_STACK_OVERFLOW:
        {
            szError = "GL_STACK_OVERFLOW";
            break;
        }
        case GL_STACK_UNDERFLOW:
        {
            szError = "GL_STACK_UNDERFLOW";
            break;
        }
        case GL_OUT_OF_MEMORY:
        {
            szError = "GL_OUT_OF_MEMORY";
            break;
        }
    }
    PXLOG_E("error : %s \n file=%s : %d", szError, _file, _line);
}
