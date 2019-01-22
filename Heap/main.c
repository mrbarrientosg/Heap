/**
 MIT License
 
 Copyright (c) 2018 Matias Barrientos.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int cmpMax(const void * p1, const void * p2) {
    const int * a = p1;
    const int * b = p2;
    return *b - *a;
}

int cmpMin(const void * p1, const void * p2) {
    const int * a = p1;
    const int * b = p2;
    return *a - *b;
}


int main(int argc, const char * argv[]) {
    
    heap *maxHeap = heap_init (12, cmpMax, NULL);
    heap *minHeap = heap_init (12, cmpMin, free);
    
    int *data;
    
    int i;
    
    for (i = 10; i >= 0; i--) {
        data = (int *) malloc (sizeof (int));
        *data = i;
        heap_push (maxHeap, data);
        heap_push (minHeap, data);
    }
    
    while (heap_peek (maxHeap)) {
        printf ("%d\n", *(int *) heap_peek (maxHeap));
        heap_pop (maxHeap);
    }
    
    printf("\n");
    
    while (heap_peek (minHeap)) {
        printf ("%d\n", *(int *) heap_peek (minHeap));
        heap_pop (minHeap);
    }
    
    heap_release (&maxHeap);
    heap_release (&minHeap);
    
    return 0;
}
