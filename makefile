VECTOR_PATH =~/class/homeWork/GenericVector

TARGET= heap.out
CC= gcc
CFLAGS= -ansi -g -pedantic -I $(VECTOR_PATH)
OBJS= genHeap.o genHeapTest.o Gvector.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
	
genHeap.o: genHeap.h genHeap.c $(VECTOR_PATH)/Gvector.h
	$(CC) $(CFLAGS) -c genHeap.c
	
genHeapTest.o: genHeapTest.c genHeap.h $(VECTOR_PATH)/Gvector.h
	$(CC) $(CFLAGS) -c genHeapTest.c
	
Gvector.o: $(VECTOR_PATH)/Gvector.c $(VECTOR_PATH)/Gvector.h
	$(CC) $(CFLAGS) -c $(VECTOR_PATH)/Gvector.c
	
	
	
clean:
	rm -f $(TARGET) $(OBJS)

