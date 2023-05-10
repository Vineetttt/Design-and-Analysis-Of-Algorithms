#include <stdio.h>
#include <limits.h>

void prims(int cost[10][10], int n){
    int no_edge,minCost=0;
  
    int selected[10];
    for(int i=0;i<n;i++)
        selected[i] = 0;

    no_edge = 0;
    selected[0] = 1;

    int x;  
    int y; 
    
    printf("Edge : Weight\n");
    while (no_edge < n - 1) {
        int min = INT_MAX;
        x = 0;
        y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
            for (int j = 0; j < n; j++) {
                if (!selected[j] && cost[i][j]) {  
                    if (min > cost[i][j]) {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
    }
    printf("%d - %d : %d\n", x, y, cost[x][y]);
    minCost+=cost[x][y];
    selected[y] = 1;
    no_edge++;
  }
  printf("Minimum Cost: %d",minCost);
}
int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    int cost[10][10];
    
    printf("Enter the cost matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            
            if(cost[i][i] == 0)
                cost[i][j] = INT_MAX;
        }
    }
    prims(cost,n);
    return 0;
}