#include <stdio.h>
void jobScheduling(int n,int deadline[],int profit[]){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(profit[j] > profit[i]){
                int temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
                
                temp = deadline[i];
                deadline[i] = deadline[j];
                deadline[j] = temp;
            }
        }
    }
    printf("Process Deadline Profit\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\n",i+1,deadline[i],profit[i]);
    }
    int timeSlot[n];
    for(int i=0;i<n;i++)
        timeSlot[i] = -1;
    int totalProfit = 0;
    for(int i=0;i<n;i++){
        for(int j=deadline[i]-1;j>=0;j--){
            if(timeSlot[j] == -1){
                timeSlot[j] = i+1;
                totalProfit += profit[i];
                break;
            }
        }
    }
    printf("Selected Jobs: \n");
    printf("Process Deadline Profit\n");
    for(int i=0;i<n;i++){
        if(timeSlot[i] != -1){
            printf("%d\t\t%d\t\t%d\n",timeSlot[i],deadline[i],profit[i]);
        }
    }
    printf("Total Profit: %d",totalProfit);
}
int main(){
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d",&n);
    int deadline[n],profit[n];
    for(int i=0;i<n;i++){
        printf("Enter Deadline and Profit for Job%d: ",i+1);
        scanf("%d %d",&deadline[i],&profit[i]);
    }
    jobScheduling(n,deadline,profit);
    return 0;
}