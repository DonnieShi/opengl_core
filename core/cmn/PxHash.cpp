#include "PxHash.h"
#include <string.h>

namespace px
{
    template<>
    size_t HashFunc__( const char * const& _key)
    {
        size_t strLen = strlen(_key);
        size_t hash = strLen;
        for(size_t i = 0;i < strLen; ++i )
        {
            hash = ((hash << 5) ^ (hash >> 27)) ^ _key[i];
        }
        return hash;
    }

    template<>
    size_t HashFunc__( const std::string& _key )
    {
        size_t strLen = _key.length();
        size_t hash = strLen;
        for(size_t i = 0;i < strLen; ++i )
        {
            hash = ((hash << 5) ^ (hash >> 27)) ^ _key[i];
        }
        return hash;
    }
}