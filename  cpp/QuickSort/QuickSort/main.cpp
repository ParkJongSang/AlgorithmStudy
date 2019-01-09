//
//  main.cpp
//  QuickSort
//
//  Created by 박종상 on 09/01/2019.
//  Copyright © 2019 박종상. All rights reserved.
//

#include <iostream>

#define MAXSIZE 200;

using namespace std;

void quickSort(int arr[], int start, int end);
int sort(int arr[], int start, int end);
void swap(int arr[], int a, int b);

int main(int argc, const char * argv[]) {
    // insert code here...
    int tempArr[10] = {1, 0, 9, 0, 1, 2, 3, 7, 10, 5};
    
    quickSort(tempArr, 0, 9);
    
    for(int i = 0; i < 10; i++){
        cout << tempArr[i] << " ";
    }
    
    return 0;
}

 void quickSort(int arr[], int start, int end){
    if(start >= end){
        return;
    }else{
        int pivot = sort(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}

int sort(int arr[], int start, int end){
    int pivot = arr[start];
    int left = start+1;
    int right = end;
    
    while(left < right){
        if(pivot < arr[left] && pivot >= arr[right]){
            swap(arr, left, right);
            left++;
            right--;
        }else if(pivot >= arr[left] && pivot >= arr[right]){
            left++;
        }else if(pivot < arr[left] && pivot < arr[right]){
            right--;
        }else{
            left++;
            right--;
        }
    }
    
    if(arr[start] > arr[left])
        swap(arr, start, left);
    
    return left;
}

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

