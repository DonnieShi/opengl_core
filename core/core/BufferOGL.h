#ifndef __PX_BUFFER_OGL_H__
#define __PX_BUFFER_OGL_H__

#include "PxBase.h"

namespace px
{
    class StaticVB
    {
    private:
        GLuint      buffer;
        size_t      size;
    public:
        static StaticVB* New( void * _data, size_t _size );
        void Bind();
        void Release();
    };
    
    class StaticIB
    {
    private:
        GLuint      buffer;
        size_t      size;
    public:
        static StaticIB* New( void * _data, size_t _size );
        void Bind();
        void Release();
    };
    
    class VertexArray
    {
    public:
        struct Layout
        {
            GLuint      index;
            GLint       size;
            GLenum      type;
            GLsizei     stride;
            GLvoid*     offset;
        };
    private:
        GLuint          va;
        StaticVB *      vb;
        StaticIB *      ib;
        Layout *        layouts;
        unsigned short  nlayout;
    public:
        VertexArray * New( StaticVB * _vb, StaticIB * _ib, VertexArray::Layout* _layout );
        void Bind();
        void DrawTriangle( GLsizei _nPoints );
        void Release();
    };
}

#endif // __PX_BUFFER_OGL_H__
