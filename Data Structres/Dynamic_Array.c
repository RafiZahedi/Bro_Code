#include <stdio.h>
#include <stdlib.h>
// // Create an empty array with a small starting size
typedef struct {
    int *data;
    int size;
    int capacity;
} List;

// initialize array with small capacity
void initList (List *arr){
    arr->capacity =2;
    arr->size = 0;
    arr->data =(int *) malloc(arr->capacity * sizeof(int));
}


void appendOrInsert(List *arr, int index, int value){
    if (index < 0 || index > arr->size){ // index not given or out of bond
        index = arr->size;
    }

    // if List is full
    if(arr->size == arr->capacity){
        arr->capacity *= 2;
        int *new_data = (int *)malloc(arr->size * sizeof(int));

        for(int i = 0; i < arr->size; i++){
            new_data[i] = arr->data[i];
        }
        free(arr->data);
        arr->data = new_data;
    }
    // shif the elemtns to right;
    for(int i = arr->size -1 ; i = index; i--){
        arr->data[i + 1] = arr->data[i];
    }
    // insert the value
    arr->data[index] = value;
    arr->size++;
}


int main(){
    
    List arr;
    initList(&arr);


    appendOrInsert(&arr, -1, 10);

    // for(int i = 0; i < 5; i++){
    //     int input;
    //     scanf("%d", &input);
    //     append(&arr, input);
    // }

    for(int i = 0; i < arr.size; i ++){
        printf("%d ", arr.data[i]);
    }
    free(arr.data);
    return 0;
}



// // When adding a new item:
// IF array is full:
//     make a bigger array (usually double the size)
//     copy old items into the new array
//     delete the old array

// add the new item at the end
// increase the count of items

// // When getting or changing items:
// use the index to read or update the value

// // When done:
// free the memory used by the array
