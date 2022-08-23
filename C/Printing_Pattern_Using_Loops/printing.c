#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n = 0;
    scanf("%d", &n);
    int tmp = n;
  	int arr_size = (n * 2) - 1;
    int** arr = (int**)calloc(sizeof(int*), arr_size);

    for(int i = 0; i < arr_size; ++i) {
        arr[i] = (int*)calloc(sizeof(int), arr_size);
    }


    for(int s = arr_size - 1; s >= 0; --s) {
        for(int i = s; i >= abs(n - tmp); --i) {
            for(int j = s; j >= abs(n - tmp); --j) {
                arr[i][j] = tmp;
            }
        }
        --tmp;
    }

    for(int i = 0; i < arr_size; ++i) {
        for(int j = 0; j < arr_size; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < arr_size; ++i) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}