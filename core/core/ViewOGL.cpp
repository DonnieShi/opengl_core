#include <windows.h>
#include <gl/gl3w.h>
#include "ViewOGL.h"
#include <gl/gl.h>
#include <stdio.h>

px::ViewOGL::ViewOGL()
{
}

px::ViewOGL::~ViewOGL()
{
}


px::ViewOGL* px::ViewOGL::CreateView(void* _wnd)
{
    ViewOGL * viewOGL = new ViewOGL;
    
    if(!_wnd)
		return NULL;
		
	HWND hwnd = (HWND)_wnd;
	
	HDC hdc = GetDC(hwnd); // Get the device context for our window
	
	viewOGL->hwnd = hwnd;
	viewOGL->hdc = hdc;

	PIXELFORMATDESCRIPTOR pfd; // Create a new PIXELFORMATDESCRIPTOR (PFD)
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR)); // Clear our  PFD
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR); // Set the size of the PFD to the size of the class
	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW; // Enable double buffering, opengl support and drawing to a window
	pfd.iPixelType = PFD_TYPE_RGBA; // Set our application to use RGBA pixels
	pfd.cColorBits = 32; // Give us 32 bits of color information (the higher, the more colors)
	pfd.cDepthBits = 32; // Give us 32 bits of depth information (the higher, the more depth levels)
	pfd.iLayerType = PFD_MAIN_PLANE; // Set the layer of the PFD

	int nPixelFormat = ChoosePixelFormat(hdc, &pfd); // Check if our PFD is valid and get a pixel format back
	if (nPixelFormat == 0) // If it fails
			return NULL;

	bool bResult = SetPixelFormat(hdc, nPixelFormat, &pfd); // Try and set the pixel format based on our PFD
	if (!bResult) // If it fails
		return NULL;
	
	HGLRC tempOpenGLContext = wglCreateContext(hdc); // Create an OpenGL 2.1 context for our device context
	wglMakeCurrent(hdc, tempOpenGLContext); // Make the OpenGL 2.1 context current and active
    
	viewOGL->hrc = (void *)tempOpenGLContext;
    
    // init opengl core profile
    
    if (gl3wInit()) {
		fprintf(stderr, "failed to initialize OpenGL\n");
	}
        
    int major = 4, minor = 5;
	if (!gl3wIsSupported( major, minor )) {
		fprintf(stderr, "OpenGL %d.%d not supported\n", major, minor );
	}
    
	printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION),
	       glGetString(GL_SHADING_LANGUAGE_VERSION));
    
    return viewOGL;
}

void px::ViewOGL::Begin()
{
    static const GLfloat red[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glClearBufferfv(GL_COLOR, 0, red);
    
}

void px::ViewOGL::End()
{
    SwapBuffers( (HDC)hdc );
}

void px::ViewOGL::Release()
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext( (HGLRC)this->hrc );
    ReleaseDC( (HWND)this->hwnd , (HDC)this->hdc );
    delete this;
}

void px::ViewOGL::Resize(int _w, int _h)
{
    viewport.w = _w;
    viewport.h = _h;
}
