#ifndef __PX_LOG_H__
#define __PX_LOG_H__

#include <stdio.h>

#define PXLOG_I(...) printf(__VA_ARGS__)
#define PXLOG_W(...) printf(__VA_ARGS__)
#define PXLOG_E(...) printf(__VA_ARGS__)

namespace px
{

class PxLog
{
public:
    PxLog();
    ~PxLog();
};

}

#endif // __PX_LOG_H__
