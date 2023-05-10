#include <stdio.h>

void merge(int a[], int start, int mid, int end){
    int merged[end-start+1];
    int index1 = start, index2 = mid+1, x=0;
    while(index1 <= mid && index2 <= end){
        if(a[index1] < a[index2]){
            merged[x++] = a[index1++];
        }else{
            merged[x++] = a[index2++];
        }
    }
    while(index1 <= mid){
        merged[x++] = a[index1++];
    }
    while(index2 <= end){
        merged[x++] = a[index2++];
    }
    for(int i=0,j=start;i<(end-start+1);i++,j++){
        a[j] = merged[i];
    }
}
void mergeSort(int a[], int start, int end){
    if(start >= end) return;

    int mid = start+ (end-start)/2;
    mergeSort(a,start,mid);
    mergeSort(a,mid+1,end);

    merge(a,start,mid,end);
}
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    printf("\n");
}
int main(){
    int n; 
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Before Sorting: ");
    printArray(a,n);

    mergeSort(a,0,n-1);

    printf("After Sorting: ");
    printArray(a,n);
}