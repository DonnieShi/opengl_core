#ifndef __PX_VIEW_OGL_H__
#define __PX_VIEW_OGL_H__

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
        
        void Release();
    private:
        void * hwnd; // windows hwnd
        void * hdc;  // HDC
        void * hrc;  // OpenGL context
    };

    ViewOGL * CreateView( void * wnd );

}

#endif // __PX_VIEW_OGL_H__
