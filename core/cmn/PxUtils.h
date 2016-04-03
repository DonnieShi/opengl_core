#ifndef __PX_UTILS_H__
#define __PX_UTILS_H__

#include <type_traits>
#include <string>

namespace px
{
    template<class T1, class T2>
    bool Equal__( T1& value1, T2& value2);
    template<class T1, class T2>
    bool Equal( T1& value1, T2& value2)
    {
        typedef typename std::decay<T1>::type TYPE1;
        typedef typename std::decay<T2>::type TYPE2;
        const TYPE1 t1 = value1;
        const TYPE2 t2 = value2;
        return Equal__( t1, t2 );
    } 

    template<class T1, class T2>
    bool Equal__( T1& value1, T2& value2)
    {
        return value1 == value2;
    }    
    template<>
    bool Equal__(const char * const & _value1, const char *const & _value2 );
    template<>
    bool Equal__(const char * const & _value1, const std::string& _value2 );
    template<>
    bool Equal__(const std::string& _value1, const char* const & _value2 );
}

#endif