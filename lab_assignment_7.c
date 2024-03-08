/*Amelia Dahn, COP3502, 3/7/2024
This code sorts two arrays using selection sort and bubble sort. It outputs how many times each number was swapped and the total number of swaps it took the whole array to be sorted.
*/

#include <stdio.h>
#include<stdlib.h>

// Function to perform Bubble Sort
int bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp, total_swaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps[arr[j]]++;
                swaps[arr[j+1]]++;
                total_swaps++; 
            }
        }
    }
    return total_swaps;
}

// Function to perform Selection Sort
int selectionSort(int arr[], int n, int swaps[]) {
    int i, j, min_idx, temp, total_swaps = 0;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        if(min_idx != i){
            swaps[arr[min_idx]]++;
            swaps[arr[i]]++;
            total_swaps++;
        }

    }
    return total_swaps;
}

// Function to print swaps for each value in an array
void printSwaps(int swaps[], int arr[]) {
    for (int i = 0; i < 9; i++) {
        for(int j = 0; j < 100; j++){
            if(j == arr[i]) 
                printf("%d: # of times %d is swapped\n", swaps[j], j);
        
        }
        
    }
}



int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int array10[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array20[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    int bubble_swaps1[100] = {0}; // Initialize array to store swaps for array1 bubble sort
    int bubble_swaps2[100] = {0}; // Initialize array to store swaps for array2 bubble sort
    
    int selection_swaps1[100] = {0}; // Initialize array to store swaps for array1 selection sort
    int selection_swaps2[100] = {0}; // Initialize array to store swaps for array2 selection sort
    
    int bubble_swaps_count1 = bubbleSort(array1, 9, bubble_swaps1);
    int bubble_swaps_count2 = bubbleSort(array2, 9, bubble_swaps2);
    
    int selection_swaps_count1 = selectionSort(array10, 9, selection_swaps1);
    int selection_swaps_count2 = selectionSort(array20, 9, selection_swaps2);

    printf("Array 1 using Selection Sort:\n");
    printSwaps(selection_swaps1, array1);
    printf("Total swaps: %d\n\n", selection_swaps_count1);
    printf("\n");
    
    printf("Array 1 using Bubble Sort:\n");
    printSwaps(bubble_swaps1, array10);
    printf("Total Swaps: %d\n\n", bubble_swaps_count1);
    printf("\n");
    
    printf("Array 2 using Selection Sort:\n");
    printSwaps(selection_swaps2, array2);
    printf("Total swaps: %d\n\n", selection_swaps_count2);
    printf("\n");
    
    printf("Array 2 using Bubble Sort:\n");
    printSwaps(bubble_swaps2, array20);
    printf("Total Swaps: %d\n\n", bubble_swaps_count2);
    
    return 0;
}