#include <stdio.h>
#include "genHeap.h"
#include "Gvector.h"
#define SIZE 10
#define BLOCK_SIZE 3
#define TRUE 1
#define FALSE 0

void testHeapBuildReturn();
void testHeapBuildNormalFromBig();
void testHeapBuildNormalFromSmall();
void testHeapBuildVectorNull();
void testHeapBuildCompareNull();

void testHeapDoubleDestroy();
void testHeapBuildDestroy();

void testHeapHeapInsert();
void testHeapHeapNull();
void testInserHeapNull();
void testHeapElementNull();
void testInsertOverFlow();

void testHeapPeekNormal();
void testPeekHeapNULL();
void testPeekSizeZero();

void testHeapHeapSize();

void testHeapExtractNormal();
void testExtractHeapNull();
void testExtractHeapSizeZero();

int CompareIntFromBig(const void *_left, const void *_right);
int CompareIntFromSmall(const void *_left, const void *_right);
int PrintInt(const void *_elem, void * _context);


int main (void)
{
	testHeapBuildReturn();
	 testHeapBuildNormalFromBig();
	testHeapBuildNormalFromSmall();
	testHeapBuildVectorNull();
	testHeapBuildCompareNull();
	
	testHeapDoubleDestroy();
	testHeapBuildDestroy();
	
	testHeapHeapInsert();
	testInserHeapNull();
	testHeapElementNull();
	testInsertOverFlow();
	
	testHeapPeekNormal(); 
	testPeekHeapNULL();
	testPeekSizeZero();
	
	testHeapExtractNormal();
	testExtractHeapNull();
	testExtractHeapSizeZero();
	
	testHeapHeapSize();
	
	return 1;
}

int CompareIntFromBig(const void *_left, const void *_right)
{
	if (*(int*) _left >= *(int*) _right)
	{
		return TRUE;
	}
	return FALSE;
}

int CompareIntFromSmall(const void *_left, const void *_right)
{
	if (*(int*) _left <= *(int*) _right)
	{
		return TRUE;
	}
	return FALSE;
}


void testHeapHeapSize()
{
	Vector* v;
	Heap * h;

	int a = 1, b = 5 , c = 3, d = 8, e = 4;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	VectorAppend(v, &a);
	VectorAppend(v, &b);
	VectorAppend(v, &c);
	VectorAppend(v, &d);
	VectorAppend(v, &e);
	h= HeapBuild(v , CompareIntFromBig);
	if (HeapSize(h) == 5)
	 {
	 	printf("heap Size - PASS\n");
	 }else
	 {
	 	printf("heap Size- FAIL\n");
	 }
	 
	HeapDestroy(&h);
}

void testExtractHeapSizeZero()
{
	Vector* v;
	Heap * h;
	int* x;
	int a = 1, b = 5 , c = 3, d = 8, e = 4;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	h= HeapBuild(v , CompareIntFromBig);
	if ((int*)HeapExtract(h)==  NULL )
	 {
	 	printf("heap Peek size zero - PASS\n");
	 }else
	 {
	 	printf("heap Peek size zero - FAIL\n");
	 }
	HeapDestroy(&h);
}


void testExtractHeapNull()
{
	Vector* v;
	Heap * h;
	int* x;
	int a = 1, b = 5 , c = 3, d = 8, e = 4;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	VectorAppend(v, &a);
	VectorAppend(v, &b);
	VectorAppend(v, &c);
	VectorAppend(v, &d);
	VectorAppend(v, &e);
	h= HeapBuild(v , CompareIntFromBig);
	if ((int*)HeapExtract(NULL)==  NULL )
	 {
	 	printf("heap Peek heap null - PASS\n");
	 }else
	 {
	 	printf("heap Peek heap null - FAIL\n");
	 }
	HeapDestroy(&h);
}


void testHeapExtractNormal()
{
	Vector* v;
	Heap * h;
	int* x;

	int a = 1, b = 5 , c = 3, d = 8, e = 4;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	VectorAppend(v, &a);
	VectorAppend(v, &b);
	VectorAppend(v, &c);
	VectorAppend(v, &d);
	VectorAppend(v, &e);
	h= HeapBuild(v , CompareIntFromBig);
	x = (int*)HeapExtract(h);
	if (*x ==  8 && HeapSize(h) == 4)
	 {
	 	printf("heap Peek Extract- PASS\n");
	 }else
	 {
	 	printf("heap Peek Extract- FAIL\n");
	 }
	
	HeapDestroy(&h);
}

void testPeekSizeZero()
{
	Vector* v;
	Heap * h;
	int* x;
	int a = 1, b = 5 , c = 3, d = 8, e = 4;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	h= HeapBuild(v , CompareIntFromBig);
	if ((int*)HeapPeek(h) == NULL )
	 {
	 	printf("heap Peek size zero - PASS\n");
	 }else
	 {
	 	printf("heap Peeksize zero- FAIL\n");
	 }
	
	HeapDestroy(&h);
}


void testPeekHeapNULL()
{
	Vector* v;
	Heap * h;
	int* x;
	int a = 1, b = 5 , c = 3, d = 8, e = 4;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	VectorAppend(v, &a);
	VectorAppend(v, &b);
	VectorAppend(v, &c);
	VectorAppend(v, &d);
	VectorAppend(v, &e);
	h= HeapBuild(v , CompareIntFromBig);
	if ((int*)HeapPeek(NULL) == NULL )
	 {
	 	printf("heap Peek heap Null - PASS\n");
	 }else
	 {
	 	printf("heap Peek heap Null - FAIL\n");
	 }
	
	HeapDestroy(&h);
}

void testHeapPeekNormal()
{
	Vector* v;
	Heap * h;
	int* x;
	int a = 1, b = 5 , c = 3, d = 8, e = 4;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	VectorAppend(v, &a);
	VectorAppend(v, &b);
	VectorAppend(v, &c);
	VectorAppend(v, &d);
	VectorAppend(v, &e);
	h= HeapBuild(v , CompareIntFromBig);
	x = (int*)HeapPeek(h);
	if (*x ==  8)
	 {
	 	printf("heap Peek Normal- PASS\n");
	 }else
	 {
	 	printf("heap Peek Normal- FAIL\n");
	 }
	
	HeapDestroy(&h);
}

void testInsertOverFlow()
{
	Vector* v;
	Heap * h;
	int y = 20;
	int  x = 9;
	int a = 1, b = 5 , c = 3, d = 8, e = 4;
	v = VectorCreate(3, 0);
	VectorAppend(v, &a);
	VectorAppend(v, &b);
	VectorAppend(v, &c);
	h= HeapBuild(v , CompareIntFromBig);
	if (HeapInsert(h,&x) == HEAP_OVERFLOW)
	 {
	 	printf("insert over flow  - PASS\n");
	 }else
	 {
	 	printf("insert  over flow  - FAIL\n");
	 }
	HeapDestroy(&h);
}



void testHeapElementNull()
{
	Vector* v;
	Heap * h;
	int y = 20;
	int  x = 9;
	int a = 1, b = 5 , c = 3, d = 8, e = 4;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	VectorAppend(v, &a);
	VectorAppend(v, &b);
	VectorAppend(v, &c);
	VectorAppend(v, &d);
	VectorAppend(v, &e);
	h= HeapBuild(v , CompareIntFromBig);
	
	if (HeapInsert(h, NULL) == HEAP_INPUT_ERROR)
	 {
	 	printf("insert element null   - PASS\n");
	 }else
	 {
	 	printf("insert element null  - FAIL\n");
	 }
	HeapDestroy(&h);
}

void testInserHeapNull()
{
	Vector* v;
	Heap * h;
	int y = 20;
	int  x = 9;
	int a = 1, b = 5 , c = 3, d = 8, e = 4;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	VectorAppend(v, &a);
	VectorAppend(v, &b);
	VectorAppend(v, &c);
	VectorAppend(v, &d);
	VectorAppend(v, &e);
	h= HeapBuild(v , CompareIntFromBig);
	
	if (HeapInsert(NULL, &x) == HEAP_INPUT_ERROR)
	 {
	 	printf("insert heap null   - PASS\n");
	 }else
	 {
	 	printf("insert heap null  - FAIL\n");
	 }
	HeapDestroy(&h);
}



void testHeapHeapInsert()
{
	Vector* v;
	Heap * h;
	int y = 20;
	int  x = 9;
	int  z = 25;
	
	int a = 1, b = 5 , c = 3, d = 8, e = 4;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	VectorAppend(v, &a);
	VectorAppend(v, &b);
	VectorAppend(v, &c);
	VectorAppend(v, &d);
	VectorAppend(v, &e);
	h= HeapBuild(v , CompareIntFromBig);
	HeapInsert(h, &x);
	HeapInsert(h, &y);
	printf("test insert : ");
	HeapForEach(h, PrintInt, NULL);
	printf("\n");
	HeapDestroy(&h);
}


void testHeapBuildDestroy()
{
	Vector* v;
	Heap * h;
	int a = 1, b = 5 , c = 3, d = 8, e = 4;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	VectorAppend(v, &a);
	VectorAppend(v, &b);
	VectorAppend(v, &c);
	VectorAppend(v, &d);
	VectorAppend(v, &e);
	h= HeapBuild(v , CompareIntFromBig);
	HeapDestroy(&h);
	if (h == NULL)
	 {
	 	printf("heap destroy   - PASS\n");
	 }else
	 {
	 	printf("heap destroy  - FAIL\n");
	 }
}


void testHeapDoubleDestroy()
{
	Vector* v;
	Heap * h;
	int a = 1;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	VectorAppend(v, &a);
	h= HeapBuild(v , CompareIntFromBig);
	HeapDestroy(&h);
	HeapDestroy(&h);
	printf("heap double destroy- PASS\n");
}




int PrintInt(const void *_elem, void * _context)
{
	if (_elem == NULL)
	{
		return 0;
	}
	printf("%d ,", *(int*)_elem);
	return 1;
}

void testHeapBuildReturn()
{
	Vector* v;
	Heap * h;
	int a = 1, b = 5 , c = 3, d = 8, e = 4;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	VectorAppend(v, &a);
	VectorAppend(v, &b);
	VectorAppend(v, &c);
	VectorAppend(v, &d);
	VectorAppend(v, &e);
	h= HeapBuild(v , CompareIntFromBig);
	if (h != NULL)
	 {
	 	printf("heap build  Null- PASS\n");
	 }else
	 {
	 	printf("heap build  Null- FAIL\n");
	 }
	HeapDestroy(&h);
}


void testHeapBuildCompareNull()
{
	Vector* v;
	Heap * h;
	int a = 1, b = 5 , c = 3, d = 8, e = 4, f= 9,  g = 4, i =2;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	VectorAppend(v, &a);
	VectorAppend(v, &b);
	VectorAppend(v, &c);
	VectorAppend(v, &d);
	VectorAppend(v, &e);
	h= HeapBuild(v , NULL);
	if (h == NULL)
	 {
	 	printf("heap build compare  Null- PASS\n");
	 }else
	 {
	 	printf("heap build compare  Null- FAIL\n");
	 }
	HeapDestroy(&h);
}

void testHeapBuildVectorNull()
{
	Vector* v;
	Heap * h;
	int a = 1, b = 5 , c = 3, d = 8, e = 4, f= 9,  g = 4, i =2;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	VectorAppend(v, &a);
	VectorAppend(v, &b);
	VectorAppend(v, &c);
	VectorAppend(v, &d);
	VectorAppend(v, &e);
	h= HeapBuild(NULL , CompareIntFromBig);
	if (h == NULL)
	 {
	 	printf("heap build vector  Null- PASS\n");
	 }else
	 {
	 	printf("heap build vector  Null- FAIL\n");
	 }
	HeapDestroy(&h);
}


void testHeapBuildNormalFromBig()
{
	Vector* v;
	Heap * h;
	int a = 1, b = 5 , c = 3, d = 8, e = 4, f= 9,  g = 4, i =2;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	VectorAppend(v, &a);
	VectorAppend(v, &b);
	VectorAppend(v, &c);
	VectorAppend(v, &d);
	VectorAppend(v, &e);
	VectorAppend(v, &f);
	VectorAppend(v, &g);
	VectorAppend(v, &i);
	h= HeapBuild(v , CompareIntFromBig);
	HeapForEach(h, PrintInt, NULL);
	printf("\n");
	HeapDestroy(&h);
}

void testHeapBuildNormalFromSmall()
{
	Vector* v;
	Heap * h;
	int a = 1, b = 5 , c = 3, d = 8, e = 4, f= 9, g = 4, i =2;
	v = VectorCreate(SIZE, BLOCK_SIZE);
	VectorAppend(v, &a);
	VectorAppend(v, &b);
	VectorAppend(v, &c);
	VectorAppend(v, &d);
	VectorAppend(v, &e);
	VectorAppend(v, &f);
	VectorAppend(v, &g);
	VectorAppend(v, &i);
	h= HeapBuild(v , CompareIntFromSmall);
	HeapForEach(h, PrintInt, NULL);
	printf("\n");
	HeapDestroy(&h);
}





