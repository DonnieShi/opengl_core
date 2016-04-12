#ifndef __PX_MEM_H__
#define __PX_MEM_H__

#include <stdlib.h>

namespace px
{
	template< class T >
	class PxMem
	{
	private:
		class MemNode
		{
		public:
			static const int obj_size = (sizeof(T) + 3) & (~3);
			union Type
			{
				char				obj[obj_size];
				unsigned short 		next;
			};
			MemNode * 			next;
			unsigned short	  	size;
			unsigned short		free;
			unsigned short		curr;
			Type				cells[1];
		};
		
		MemNode* 		head;
		
		static MemNode* allocNode( size_t _size )
		{
			MemNode * node = (MemNode*)::malloc( sizeof(T) * (_size - 1) + sizeof(MemNode) );
			node->size = _size;
			node->free = _size;
			node->curr = 0;
			node->next = NULL;
			for( size_t i = 0; i<_size; ++i)
			{
				node->cells[i].next = i+1;
			}
			return node;
		}
		static void freeNode( MemNode * _node )
		{
			::free( _node );
		}
		static T* nodeAlloc( MemNode * _node )
		{
			if(_node->free == 0)
			{
				return NULL;
			}
			T* ptr = (T*)&_node->cells[_node->curr].obj;
			_node->curr = _node->cells[_node->curr].next;
			--_node->free;
			return ptr;
		}
		static bool nodeFree( MemNode * _node , T * _ptr )
		{
			if( _ptr >= (T*)&_node->cells[0].obj && _ptr <= (T*)_node->cells[_node->size - 1].obj)
			{
				unsigned short index = _ptr - (T*)&_node->cells[0].obj;
				_node->cells[index].next = _node->curr;
				_node->curr = index;
				++_node->free;
				return true;
			}
			else
			{
				return false;
			}
		}
	public:
		PxMem( size_t _nCell )
		{
			this->head = allocNode( _nCell );
		}
		~PxMem(){
			MemNode * currNode = this->head;
			while( currNode )
			{
				MemNode * t = currNode;
				currNode = currNode->next;
				freeNode( t );
			}
		}
		
		T * alloc()
		{
			MemNode * currNode = this->head;
			while( currNode )
			{
				if(currNode->free)
				{
					T* ptr = nodeAlloc(currNode);
					return ptr;
				}
				if(currNode->next){
					currNode = currNode->next;
				}else{
					currNode->next = allocNode(head->size);
					currNode = currNode->next;
				}
			}
			return NULL;
		}
		bool free( T * _ptr )
		{
			MemNode * currNode = this->head;
			while( currNode )
			{
				if( nodeFree( currNode, _ptr ))
				{
					return true;
				}
				currNode = currNode->next;
			}
			return false;
		}
	};
}

#endif // __PX_MEM_H__
