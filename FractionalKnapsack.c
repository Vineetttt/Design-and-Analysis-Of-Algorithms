#include <stdio.h>
#include <stdlib.h>

void FractionalKnapsack(int n, float weight[], float profit[], float capacity){
    float selected[100];
    for(int i=0;i<n;i++)
        selected[i] = 0;
    float totalProfit = 0, currentWt = capacity;
    int i=0;
    for(i;i<n;i++){
        if(weight[i] > currentWt)
            break;
        else{
            selected[i] = 1;
            totalProfit += profit[i];
            currentWt -= weight[i];
        }
    }
    if(i < n){
        selected[i] = currentWt/weight[i];
    }
    totalProfit += selected[i]*profit[i];
    printf("\nThe result vector is:- \n");
    for (i = 0; i < n; i++)
        printf("%f\t", selected[i]);
    printf("\nMaximum profit: %f",totalProfit);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d",&n);
    float capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%f",&capacity);
    float weight[n], profit[n], ratio[n];
    for(int i=0;i<n;i++){
        printf("Item %d \n",i+1);
        printf("Weight and Profit: ");
        scanf("%f %f",&weight[i],&profit[i]);
    }
    for(int i=0;i<n;i++){
        ratio[i] = profit[i]/weight[i];
    }
    float temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ratio[j] > ratio[i]){
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
                
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }
    FractionalKnapsack(n,weight, profit,capacity);
    return 0;
}