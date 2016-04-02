#ifndef __PX_HASH_TABLE_H__
#define __PX_HASH_TABLE_H__

#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
#include <string>
#include <type_traits>

namespace px
{
    #define LRSHIFT( V, OFFSET ) (V<<OFFSET | V>>(32-OFFSET) )
    
    template<class KEY >
    size_t HashFunc__( KEY& _key, const size_t _size ) ;
    
    template< class KEY >
    size_t HashFunc( KEY& _key, const size_t _size ) 
    {
        typedef typename std::decay<KEY>::type KEY_TYPE;
        const KEY_TYPE key = _key;
        return HashFunc__( key, _size );
    }
    
    template<class KEY >
    size_t HashFunc__( KEY& _key, const size_t _size ) 
    {
        size_t bytes = sizeof(_key);
        size_t hash = 0;        
        const unsigned char * ptr = reinterpret_cast<const unsigned char*>(&_key);
        for(size_t i = 0; i<bytes; ++i)
        {
            size_t t = LRSHIFT(ptr[i], (i * 4) % 32);
            hash += t;
        }
        return hash%_size;
    }
    
    template<>
    size_t HashFunc__( const char * const& _key, const size_t _size );
    template<>
    size_t HashFunc__( const std::string & _key, const size_t _size );
    
    
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
    
    template< class KEY, class VAL >
    class PxHashTable
    {
    public:
        typedef KEY            keyType;
        typedef VAL            valueType;
        struct Item
        {
            KEY     key;
            VAL     value;
            Item*   next;
        };
    public:
        PxHashTable()
        {
            listArray.resize(128);
            listArray.assign(128, NULL );
        }
        PxHashTable( size_t _arraysize )
        {
            listArray.resize(_arraysize);
            listArray.assign(_arraysize, NULL );
        }
        ~PxHashTable()
        {
            for_each( listArray.begin(), listArray.end(),[&](Item*& _item ){
                Item * item = _item;
                while( item )
                {
                    Item * next = item->next;
                    delete item;
                    item = next;
                }
            });
        }
        
        void Set( const  keyType& _key, const valueType& _val)
        {
            size_t sz = listArray.size();
            size_t index = HashFunc<keyType>( _key, sz );
            Item *& item = listArray[index];
            Item * newItem = new Item;
            newItem->key = std::forward<keyType>(_key);
            newItem->value = std::forward<valueType>(_val);
            newItem->next = NULL;
            while(item)
            {
                item = item->next;
            }
            item = newItem;
        }
        
        bool Get( const keyType&& _key, const valueType _val)
        {
            size_t index = HashFunc<keyType>( _key );
            Item *& item = listArray[index];
            while(item)
            {
                item = item->next;
                if( Equal(item->key, _key ) )
                {
                    _val = item->value;
                    return true;
                }
            }
            return false;
        }        
    private:
        std::vector<Item *>     listArray;
    };
    
    
    typedef const char * cstrptr;
    template< class VAL >
    class PxHashTable< cstrptr, VAL  >
    {
    public:
        typedef cstrptr         keyType;
        typedef VAL             valueType;
        struct Item
        {
            std::string     key;
            VAL             value;
            Item*           next;
        };
    public:
        PxHashTable()
        {
            listArray.resize(128);
            listArray.assign(128, NULL );
        }
        PxHashTable( size_t _arraysize )
        {
            listArray.resize(_arraysize);
            listArray.assign(_arraysize, NULL );
        }
        ~PxHashTable()
        {
            for_each( listArray.begin(), listArray.end(),[&](Item*& _item ){
                Item * item = _item;
                while( item )
                {
                    Item * next = item->next;
                    delete item;
                    item = next;
                }
            });
        }
        
        void Set( const keyType&_key ,  valueType& _val)
        {
            size_t index = HashFunc< const char * const >( _key, listArray.size());
            Item *& item = listArray[index];
            Item * newItem = new Item;
            newItem->key = std::string(_key);
            newItem->value = _val;
            newItem->next = NULL;
            while(item)
            {
                item = item->next;
            }
            item = newItem;
        }
        
        bool Get( const keyType & _key, valueType& _val)
        {
            size_t size = listArray.size();
            size_t index = HashFunc( _key, size );
            Item *& item = listArray[index];
            while(item)
            {
                if( Equal(item->key, _key ) )
                {
                    _val = item->value;
                    return true;
                }
                item = item->next;
            }
            return false;
        }
    private:
        std::vector<Item *>     listArray;
    };
    
    template< class KEY >
    class PxHashTable< KEY, cstrptr >
    {
    public:
        typedef KEY             keyType;
        typedef cstrptr         valueType;
        struct Item
        {
            keyType             key;
            std::string         value;
            Item*               next;
        };
    public:
        PxHashTable()
        {
            listArray.resize(128);
            listArray.assign(128, NULL );
        }
        PxHashTable( size_t _arraysize )
        {
            listArray.resize(_arraysize);
            listArray.assign(_arraysize, NULL );
        }
        ~PxHashTable()
        {
            for_each( listArray.begin(), listArray.end(),[&](Item*& _item ){
                Item * item = _item;
                while( item )
                {
                    Item * next = item->next;
                    delete item;
                    item = next;
                }
            });
        }
        
        void Set( const keyType&_key ,  valueType& _val)
        {
            size_t index = HashFunc< const char * const >( _key, listArray.size());
            Item *& item = listArray[index];
            Item * newItem = new Item;
            newItem->key = _key;
            newItem->value = std::string(_val);
            newItem->next = NULL;
            while(item)
            {
                item = item->next;
            }
            item = newItem;
        }
        
        bool Get( const keyType & _key, valueType& _val)
        {
            size_t size = listArray.size();
            size_t index = HashFunc( _key, size );
            Item *& item = listArray[index];
            while(item)
            {
                if( Equal(item->key, _key ) )
                {
                    _val = item->value.c_str();
                    return true;
                }
                item = item->next;
            }
            return false;
        }
    private:
        std::vector<Item *>     listArray;
    };
    
    template<>
    class PxHashTable< cstrptr, cstrptr >
    {
    public:
        typedef cstrptr         keyType;
        typedef cstrptr         valueType;
        struct Item
        {
            std::string         key;
            std::string         value;
            Item*               next;
        };
    public:
        PxHashTable()
        {
            listArray.resize(128);
            listArray.assign(128, NULL );
        }
        PxHashTable( size_t _arraysize )
        {
            listArray.resize(_arraysize);
            listArray.assign(_arraysize, NULL );
        }
        ~PxHashTable()
        {
            for_each( listArray.begin(), listArray.end(),[&](Item*& _item ){
                Item * item = _item;
                while( item )
                {
                    Item * next = item->next;
                    delete item;
                    item = next;
                }
            });
        }
        
        void Set( const keyType&_key , const valueType& _val)
        {
            size_t index = HashFunc< const char * const >( _key, listArray.size());
            Item *& item = listArray[index];
            Item * newItem = new Item;
            newItem->key = std::string(_key);
            newItem->value = std::string(_val);
            newItem->next = NULL;
            while(item)
            {
                item = item->next;
            }
            item = newItem;
        }
        
        bool Get( const keyType & _key, valueType& _val)
        {
            size_t size = listArray.size();
            size_t index = HashFunc( _key, size );
            Item *& item = listArray[index];
            while(item)
            {
                if( Equal(item->key, _key ) )
                {
                    _val = item->value.c_str();
                    return true;
                }
                item = item->next;
            }
            return false;
        }
    private:
        std::vector<Item *>     listArray;
    };
}

#endif // __PX_HASH_TABLE_H__
