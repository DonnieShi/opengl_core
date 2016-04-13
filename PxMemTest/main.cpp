#include <stdio.h>
#include "PxMem.h"

struct render_block
{
	enum block_type
	{
		type_text,
		type_image,
		type_br,
	};
	render_block(){}
	render_block(render_block::block_type _type ){
		type = _type;
	}
	int		type;
};

int main(int argc, char **argv)
{
	render_block* array[256];
	px::PxMem<render_block> miniPool(32);
	for(int i = 0;i<256; ++i)
	{
		array[i] = miniPool.alloc();
	}
	for(int i = 0; i<256;++i)
	{
		miniPool.free( array[i] );
	}
	for(int i = 0;i<256; ++i)
	{
		array[i] = miniPool.alloc();
	}
	for(int i = 0; i<256;++i)
	{
		miniPool.free( array[i] );
	}
	miniPool.fit();
	return 0;
}
