#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// ARRAY LIST V2
// Structure Definition
#define MAX 100
typedef struct {
    char elems[MAX];
    int count;
} *ListPtr;

