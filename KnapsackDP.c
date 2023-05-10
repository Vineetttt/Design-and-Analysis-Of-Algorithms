#include <stdio.h>
 
int max(int a, int b){ return (a > b)? a : b; }

int knapsack(int W, int wt[], int val[], int n){
   int i, w;
   int K[n+1][W+1];
 
   for (i = 0; i <= n; i++){
        for (w = 0; w <= W; w++){
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
   return K[n][W];
}
 
int main()
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d",&n);
    int value[n],weight[n];
    for(int i=0;i<n;i++){
        printf("Enter value for Item %d: ",i+1);
        scanf("%d",&value[i]);
        printf("Enter weight for Item %d: ",i+1);
        scanf("%d",&weight[i]);
    }
    int  W;
    printf("Enter the capacity:");
    scanf("%d",&W);
    printf("\nValue = %d", knapsack(W, weight, value, n));
    return 0;
}