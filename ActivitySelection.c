#include <stdio.h>

struct activity{
    int startTime,finishTime;
};
void sort(struct activity a[], int n){
    struct activity temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i].finishTime > a[j].finishTime){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void display(struct activity a[], int n){
    printf("Start Time \t Finish Time\n");
    for(int i=0;i<n;i++){
        printf("%d \t\t\t\t %d \n",a[i].startTime,a[i].finishTime);
    }
}
void activitySelection(struct activity a[], int n){
    printf("Following activities are selected: \n");
    int i=0;
    printf("Start Time \t Finish Time\n");
    printf("%d \t\t\t\t %d \n",a[i].startTime,a[i].finishTime);
    for(int j=1;j<n;j++){
        if(a[j].startTime >= a[i].finishTime){
            printf("%d \t\t\t\t %d \n",a[j].startTime,a[j].finishTime);
            i=j;
        }
    }
}
int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d",&n);
    
    struct activity a[n];
    for(int i=0;i<n;i++){
        printf("Activity %d \n",i+1);
        printf("Start time: ");
        scanf("%d",&a[i].startTime);
        printf("Finish time: ");
        scanf("%d",&a[i].finishTime);
    }
    
    sort(a,n);
    display(a,n);
    activitySelection(a,n);
    return 0;
}