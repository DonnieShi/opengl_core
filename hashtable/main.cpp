#include <stdio.h>
#include "PxHashTable.h"
int main()
{
    px::PxHashTable<int ,int> ht_ii(256);
    ht_ii.Set(1024, 123456789); 
    ht_ii.Set(123456789, 88888168);
    ht_ii.Set(1024, 87654321);
    int result;
    bool ret = ht_ii.Get(1024, result);
    printf("px::PxHashTable<int, int> : [%d] = %d\n", 1024, result);
    ret = ht_ii.Get(123456789, result);
    printf("px::PxHashTable<int, int> : [%d] = %d\n", 123456789, result);
    
    px::PxHashTable<int, const char *> ht_isz(256);
    ht_isz.Set(1024, "Hello,World!");
    const char * value;
    ret = ht_isz.Get(1024, value);
    printf("px::PxHashTable<int, const char *> : [%d] = %s\n", 1024, value);
    
    px::PxHashTable<const char *, float > ht_szi(256);
    ht_szi.Set("Hello,World!", 3.1415926f);
    float pi;
    ret = ht_szi.Get("Hello,World!",pi);    
    printf("px::PxHashTable<const char *, float> : [%s] = %f\n", "Hello,World!", pi);
    
    px::PxHashTable<const char *, const char *> ht_szsz(256);
    ht_szsz.Set("name","phantom");
    const char * name;
    ret = ht_szsz.Get("name", name);
    printf("px::PxHashTable<const char *, const char *> : [%s] = %s\n", "name", name);
    
    px::PxHashTable< std::string, std::string > ht_ss;
    ht_ss.Set( std::string("name"), std::string("phantom") );
    std::string strname;
    ret = ht_ss.Get( std::string("name"), strname );
    printf("px::PxHashTable< std::string, std::string > : [%s] = %s\n", "name", strname.c_str());
    
    return 0;
}