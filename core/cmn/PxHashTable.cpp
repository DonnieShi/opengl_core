#include "PxHashTable.h"

namespace px
{
    template<>
    size_t HashFunc__<const char * const>( const char * const& _key, const size_t _size )
    {
        size_t strLen = strlen(_key);
        size_t hash = 0;
        for(size_t i = 0;i < strLen; ++i )
        {
            hash += _key[i];
        }
        hash = hash % _size;
        return hash;
    }
    
    template<>
    size_t HashFunc__( const std::string& _key, const size_t _size )
    {
        size_t strLen = strlen(_key.c_str());
        size_t hash = 0;
        const char * ptr = _key.c_str();
        for(size_t i = 0;i < strLen; ++i )
        {
            hash += ptr[i];
        }
        hash = hash % _size;
        return hash;
    }
    
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
