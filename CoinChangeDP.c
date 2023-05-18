#include <stdio.h>
#define max 10
int dp[max][max];

int coinChange(int coins[], int n, int amt){
    if(amt == 0)
        return 1;
    if(amt < 0)
        return 0;
    if(n <= 0 && amt > 0)
        return 0;
    if(dp[n][amt] != 0)
        return dp[n][amt];
    dp[n][amt] = coinChange(coins,n-1,amt) + coinChange(coins,n,amt-coins[n-1]);
    return dp[n][amt];
}

int main(){
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
            dp[i][j] = 0;
        }
    }
    int n;
    printf("Enter the number of coins: ");
    scanf("%d",&n);
    int coins[n];
    printf("Enter the coins: ");
    for(int i=0;i<n;i++){
        scanf("%d",&coins[i]);
    }
    int value;
    printf("Enter the amount you want to form: ");
    scanf("%d",&value);
    int ans = coinChange(coins,n,value);
    printf("%d",ans);
    printf("\nDP Table\n");
    for(int i=0;i<=n;i++){
        for(int j=0;j<=value;j++){
            printf("%d  ",dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}