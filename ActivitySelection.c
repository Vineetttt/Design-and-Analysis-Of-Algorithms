#include <stdio.h>
void activitySelection(int n,int start[],int finish[]){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(finish[i] > finish[j]){
                int temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;
                
                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }
    printf("\nStartTime FinishTime\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t\t%d\n",start[i],finish[i]);
    }
    printf("\nFollowing activities are selected: ");
    int i =0 ;
    printf("\nStartTime FinishTime\n");
    printf("%d\t\t\t%d\n",start[i],finish[i]);
    for(int j=1;j<n;j++){
        if(start[j] > finish[i]){
            printf("%d\t\t\t%d\n",start[j],finish[j]);
            i = j;
        }
    }
}
int main(){
    int n;
    printf("Enter the number of activities: ");
    scanf("%d",&n);
    int startTime[n],finishTime[n];
    for(int i=0;i<n;i++){
        printf("Enter Start Time and Finish Time for Activity %d: ",i+1);
        scanf("%d %d",&startTime[i],&finishTime[i]);
    }
    activitySelection(n,startTime,finishTime);
    return 0;
}