#ifndef __PX_HASH_TABLE_H__
#define __PX_HASH_TABLE_H__

#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
#include "PxHash.h"
#include "PxUtils.h"

namespace px
{    
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
            size_t index = px::Hash( _key ) % listArray.size();
            Item *& item = listArray[index];
            Item * newItem = new Item;
            newItem->key = _key;
            newItem->value = _val;
            newItem->next = NULL;
            while(item)
            {
                if( px::Equal(_key, item->key ) )
                {
                    item->value = _val;
                    return ;
                }
                item = item->next;
            }
            item = newItem;
        }
        
        bool Get( const keyType& _key, valueType& _val)
        {
            size_t index = px::Hash( _key ) % listArray.size();
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
        
        void Set( const keyType&_key , const valueType& _val)
        {
            size_t index = px::Hash( _key) % listArray.size();
            Item *& item = listArray[index];
            Item * newItem = new Item;
            newItem->key = std::string(_key);
            newItem->value = _val;
            newItem->next = NULL;
            while(item)
            {
                if( px::Equal(_key, item->key ) )
                {
                    item->value = _val;
                    return ;
                }
                item = item->next;
            }
            item = newItem;
        }
        
        bool Get( const keyType & _key, valueType& _val)
        {
            size_t index = px::Hash( _key ) % listArray.size();
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
        
        void Set( const keyType&_key , const valueType& _val)
        {
            size_t index = px::Hash( _key ) % listArray.size();
            Item *& item = listArray[index];
            Item * newItem = new Item;
            newItem->key = _key;
            newItem->value = std::string(_val);
            newItem->next = NULL;
            while(item)
            {
                if( px::Equal(_key, item->key ) )
                {
                    item->value = _val;
                    return ;
                }
                item = item->next;
            }
            item = newItem;
        }
        
        bool Get( const keyType & _key, valueType& _val)
        {
            size_t index = px::Hash(_key) % listArray.size();
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
            size_t index = px::Hash( _key ) % listArray.size();
            Item *& item = listArray[index];
            Item * newItem = new Item;
            newItem->key = std::string(_key);
            newItem->value = std::string(_val);
            newItem->next = NULL;
            while(item)
            {
                if( px::Equal(_key, item->key ) )
                {
                    item->value = _val;
                    return ;
                }
                item = item->next;
            }
            item = newItem;
        }
        
        bool Get( const keyType & _key, valueType& _val)
        {
            size_t index = px::Hash( _key ) % listArray.size() ;
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
