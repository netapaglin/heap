#include <stdio.h>/* for prints*/
#include<stdlib.h>/* size_t malloc*/
#include "genHeap.h"
#include "Gvector.h"
#define PARENT( i ) ((i -1)/2)
#define LEFT( i ) (2*(i)+1)
#define RIGHT( i ) (2*(i) + 2)
#define TRUE 1
#define FALSE 0

static void Heapify(Heap* _heap, size_t _index);
static size_t FindEdgeIndex(Heap* _heap , size_t _index);
static void Swap( Heap* _heap, size_t _first, size_t _second );
static void BubbleUp(Heap * _heap);

struct Heap
{
	Vector* m_vec;
	size_t m_heapSize;
	LessThanComparator m_func;
};


Heap* HeapBuild(Vector* _vector, LessThanComparator _pfLess)
{
	size_t i;
	Heap* heap;
	if(_vector == NULL|| _pfLess == NULL)
	{
		return NULL;
	}
	heap = (Heap*)malloc(sizeof(Heap));
	if (heap == NULL)
	{
		return NULL;
	}
	heap -> m_vec = _vector;
	heap -> m_heapSize = VectorSize(heap -> m_vec);
	heap -> m_func = _pfLess;
	if (heap -> m_heapSize > 1)
	{
		i = PARENT(heap -> m_heapSize -1)+ 1;
		do
		{
			--i;
			Heapify(heap, i);
		}
		while(i > 0);
	}
	
	return heap;
}


Vector* HeapDestroy(Heap** _heap)
{
	Vector * vec;
	if(_heap != NULL && *_heap != NULL)
	{
		vec = (*_heap) -> m_vec;
		free(*_heap);
		*_heap = NULL;
		return vec;
	}
}

HeapResult HeapInsert(Heap* _heap, void* _element)
{
	VectorResult status;
	if(_heap == NULL || _element == NULL)
	{
		return HEAP_INPUT_ERROR;
	}
	if((status =VectorAppend(_heap -> m_vec, _element)) != VECTOR_SUCCESS)
	{
		switch( status )
		{
			case VECTOR_OVER_FLOW_ERROR:
				return HEAP_OVERFLOW;
				break;
			case VECTOR_REALLOCATION_ERROR:
				return HEAP_REALLOCATION_FAILED;
		}
	}
	_heap -> m_heapSize += 1;
	BubbleUp(_heap);
	return HEAP_SUCCESS;
}

const void* HeapPeek(const Heap* _heap)
{
	void * elem;
	if(_heap == NULL || _heap -> m_heapSize == 0)
	{
		return NULL;
	}
	if ( ( VectorGet( _heap->m_vec, 0, &elem ) ) != VECTOR_SUCCESS )
	{
		return NULL;
	}
	 return elem;
}

void* HeapExtract(Heap* _heap)
{
	void * elem;
	void * lastVal;
	if(_heap == NULL || _heap -> m_heapSize == 0)
	{
		return;
	}
	if ( ( VectorGet( _heap->m_vec, 0, &elem ) ) != VECTOR_SUCCESS )
	{
		return NULL;
	}
	VectorRemove(_heap->m_vec, &lastVal);
	-- _heap -> m_heapSize ;
	if(_heap -> m_heapSize  > 0)
	{
		VectorSet(_heap->m_vec, 0, lastVal);
		Heapify(_heap, 0);
	}
	return elem;
}

size_t HeapSize(const Heap* _heap)
{
	if(_heap == NULL)
	{
		return 0;
	}
	return _heap -> m_heapSize;
}

size_t HeapForEach(const Heap* _heap, ActionFunction _act, void* _context)
{
	void * elem;
	size_t index , count;
	size_t length = _heap -> m_heapSize;
	if(_heap == NULL || _act == NULL)
	{
		return;
	}
	for (index = 0; index < length ; ++index)
	{
		if(VectorGet( _heap->m_vec, index, &elem) != VECTOR_SUCCESS)
		{
			return 0;
		}
		if(_act(elem, _context) == 0)
		{
			break;
		}
		++count;
	}
	return count;
}

static void Heapify(Heap* _heap, size_t _index)
{
	size_t edgeIndex;
	if (LEFT(_index) >= _heap -> m_heapSize)
	{
		return;
	}
	edgeIndex = FindEdgeIndex(_heap ,  _index);
	if(edgeIndex != _index)
	{
		Swap( _heap, _index, edgeIndex );
		Heapify(_heap, edgeIndex);
	}
}

static void BubbleUp(Heap * _heap)
{
	size_t fatherIndex, sonIndex, length ;
	void* father;
	void* son;
	length = _heap -> m_heapSize;
	sonIndex = length -1 ;
	fatherIndex =PARENT(sonIndex);
    VectorGet(_heap -> m_vec , fatherIndex, &father);
	VectorGet(_heap -> m_vec, sonIndex, &son);
	while((_heap -> m_func(son , father)) && sonIndex > 0)
	{
		Swap(_heap, sonIndex , fatherIndex );
		sonIndex = fatherIndex;
		fatherIndex = PARENT(sonIndex);
		VectorGet(_heap -> m_vec , fatherIndex, &father);
	    VectorGet(_heap -> m_vec, sonIndex, &son);
	}
}


static size_t FindEdgeIndex(Heap* _heap , size_t _index)
{
	void* father;
	void* left;
	void* right;
	void* edge;
	size_t edgeIndex;
	HeapResult ifRight;  
	VectorGet(_heap ->m_vec , _index, &father);
	VectorGet(_heap ->m_vec  , LEFT(_index), &left) ;
	ifRight = VectorGet(_heap ->m_vec , RIGHT(_index) , &right);
	edge = father;
	edgeIndex = _index;
	if (ifRight  == HEAP_SUCCESS)
	{
		if (_heap -> m_func(right , father))
		{
			edge = right;
			edgeIndex =  RIGHT(_index);
		} 
	}
	if (_heap -> m_func(left , edge))
	{
		Swap( _heap, _index, edgeIndex);
		edgeIndex =  LEFT(_index);
	}
	return edgeIndex;
}


static void Swap( Heap* _heap, size_t _first, size_t _second )
{
	void * firstItem;
	void * secondItem;
	VectorGet ( _heap->m_vec, _first, &firstItem);
	VectorGet ( _heap->m_vec, _second, &secondItem);
	VectorSet ( _heap->m_vec, _first, secondItem);
	VectorSet ( _heap->m_vec, _second, firstItem);
	return;
}




