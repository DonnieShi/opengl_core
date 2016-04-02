#include "PxHashTable.h"

namespace px
{    
    template<>
    bool Equal__(const char * const & _value1, const char *const & _value2 )
    {
        return strcmp(_value1, _value2) == 0;
    }
    
    template<>
    bool Equal__(const char * const & _value1, const std::string& _value2 )
    {
        return strcmp(_value1, _value2.c_str()) == 0;
    }    
    template<>
    bool Equal__(const std::string& _value1, const char* const & _value2 )
    {
        return strcmp(_value1.c_str(), _value2 ) == 0;
    }
}
