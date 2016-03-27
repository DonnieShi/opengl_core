#ifndef __PX_BASE_H__
#define __PX_BASE_H__

#define OGL_MAJOR 4
#define OGL_MINOR 1

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
}

#endif // __PX_BASE_H__
