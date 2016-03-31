#ifndef __PX_VIEW_OGL_H__
#define __PX_VIEW_OGL_H__

#include "opengl_conf.h"
#include "PxBase.h"

namespace px
{

    class ViewOGL
    {
    public:
        friend ViewOGL * CreateView( void * wnd );
        
        ViewOGL();
        ~ViewOGL();
        
        void Begin();
        void End();
        
        void Resize( int _w, int _h );
        void Release();
    private:
        void * hwnd; // windows hwnd
        void * hdc;  // HDC
        void * hrc;  // OpenGL context
        
        PxRect viewport;
    public:
    
    static ViewOGL * CreateView( void * wnd );
    };

    

}

#endif // __PX_VIEW_OGL_H__
