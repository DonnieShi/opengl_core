#ifndef __PX_HASH_H__
#define __PX_HASH_H__

#include <stdlib.h>
#include <type_traits>
#include <string>

namespace px
{
    //#define LRSHIFT( V, OFFSET ) (V<<OFFSET | V>>(32-OFFSET) )
    template<class KEY >
    size_t HashFunc__( KEY& _key);
    
    template< class KEY >
    size_t Hash(KEY& _key)
    {
        typedef typename std::decay<KEY>::type KEY_TYPE;
        const KEY_TYPE key = _key;
        return HashFunc__( key );
    }
    
    template<class KEY >
    size_t HashFunc__( KEY& _key )
    {
        size_t bytes = sizeof(_key);
        const unsigned char * ptr = reinterpret_cast<const unsigned char*>(&_key);
        size_t hash = bytes;
        for(size_t i = 0;i < bytes; ++i )
        {
            hash = ((hash << 5) ^ (hash >> 27)) ^ ptr[i];
        }
        return hash;
    }
    
    template<>
    size_t HashFunc__( const char * const& _key);
    template<>
    size_t HashFunc__( const std::string & _key);
}

#endif