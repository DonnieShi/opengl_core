#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "./core/ViewOGL.h"
#include "./core/ShaderOGL.h"

#include "./cmn/PxHashTable.h"

class Application
{
public:
    Application();
    ~Application();
private:
    px::ViewOGL * view;
    px::ShaderOGL * shader;
    px::PxHashTable< const char *, const char *> hashTable;
public:
    void Start( void * _hwnd );
    void End();
    void OnRender( unsigned long _tick );
};

#endif // __APPLICATION_H__
