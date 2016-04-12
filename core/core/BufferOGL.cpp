#include "BufferOGL.h"

namespace px
{
    StaticVB* StaticVB::New(void* _data, size_t _size)
    {
        GLuint buffer;
        glGenBuffers(1, &buffer);
        __gl_check_error__
        glBindBuffer(GL_ARRAY_BUFFER, buffer );
        __gl_check_error__
        glBufferData( GL_ARRAY_BUFFER, _size, _data, GL_STATIC_DRAW );
        __gl_check_error__
        StaticVB * vb = new StaticVB;
        vb->buffer = buffer;
        vb->size = _size;
        return vb;
    }

    void StaticVB::Bind()
    {
        glBindBuffer( GL_ARRAY_BUFFER, buffer);
    }
    
    void StaticVB::Release()
    {
        glDeleteBuffers(1, &buffer);
        __gl_check_error__
        buffer = 0;
        size = 0;
        delete this;
    }
    
    StaticIB* StaticIB::New( void * _data, size_t _size )
    {
        GLuint buffer;
        glGenBuffers(1, &buffer);
        __gl_check_error__
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer );
        __gl_check_error__
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, _size, _data, GL_STATIC_DRAW );
        __gl_check_error__
        StaticIB * ib = new StaticIB;
        ib->buffer = buffer;
        ib->size = _size;
        return ib;
    }
    
    void StaticIB::Bind()
    {
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, buffer);
    }
    
    void StaticIB::Release()
    {
        glDeleteBuffers(1, &buffer);
        __gl_check_error__
        buffer = 0;
        size = 0;
        delete this;
    }
    
    
    VertexArray * VertexArray::New( StaticVB * _vb, StaticIB * _ib, VertexArray::Layout* _layout )
    {
        VertexArray * va = new VertexArray;
        glGenVertexArrays(1, &va->va);
        __gl_check_error__
        va->ib = ib;
        va->vb = vb;
        VertexArray::Layout * layout = _layout;
        va->layouts = _layout;
        va->nlayout = 0;
        while(layout->size != 0)
        {
            ++va.nlayout;
        }
    }
    
    void VertexArray::Bind()
    {
        glBindVertexArray( va );
        vb->Bind();
        ib->Bind();
        for(int i = 0; i<nlayout; ++i)
        {
            glEnableVertexAttribArray( layouts[i].index );
            glVertexAttribPointer(layouts[i].index, layouts[i].size,layouts[i].type,GL_FALSE, layouts[i].stride, layouts.offset );
        }
    }
    
    void VertexArray::DrawTriangle( GLsizei _nPoints )
    {
        glDrawElements( GL_TRIANGLES, _nPoints, GL_UNSIGNED_INT, NULL);
        glDeleteVertexArrays(1, &va);
        ib->Release();
        vb->Release();
        delete this;
    }
    
    void VertexArray::Release()
    {
        glBindVertexArray( 0 );
        glDeleteBuffers
    }

}

