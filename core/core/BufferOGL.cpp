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
        VertexArray * _va = new VertexArray;
        glGenVertexArrays(1, &_va->va);
        __gl_check_error__
        _va->ib = _ib;
        _va->vb = _vb;
        VertexArray::Layout * layout = _layout;
        _va->layouts = _layout;
        _va->nlayout = 0;
        while(layout->size != 0)
        {
            ++_va->nlayout;
            ++layout;
        }
        return _va;
    }
    
    void VertexArray::Bind()
    {
        glBindVertexArray( va );
        vb->Bind();
        ib->Bind();
        for(int i = 0; i<nlayout; ++i)
        {
            glEnableVertexAttribArray( layouts[i].index );
            glVertexAttribPointer(layouts[i].index, layouts[i].size,layouts[i].type,GL_FALSE, layouts[i].stride, layouts[i].offset );
        }
    }
    
    void VertexArray::DrawTriangle( GLsizei _nPoints )
    {
        glDrawElements( GL_TRIANGLES, _nPoints, GL_UNSIGNED_INT, NULL);
    }
    
    void VertexArray::Release()
    {
        glBindVertexArray( 0 );
        glDeleteVertexArrays(1, &va);
        ib->Release();
        vb->Release();
        delete this;
    }

}

