#include <stdio.h>

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int partition(int a[], int left, int right){
    int pivot = a[right];
    int i = left - 1;
    for(int j=left; j<right; j++){
        if(a[j] < pivot){
            i++;
            swap(a,i,j);
        }
    }
    swap(a,i+1,right);
    return i+1;
}
void quickSort(int a[], int left, int right){
    if(left < right){
        int pi = partition(a,left,right);
        quickSort(a,left,pi-1);
        quickSort(a,pi+1,right);
    }
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

    quickSort(a,0,n-1);

    printf("After Sorting: ");
    printArray(a,n);
}