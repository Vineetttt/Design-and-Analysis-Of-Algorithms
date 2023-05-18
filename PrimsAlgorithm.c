#include <stdio.h>
#define max 99999
#define n 5
int minKey(int key[], int mstSet[]){
    int min = max,minIndex;
    for(int i=0;i<n;i++){
        if(mstSet[i] == 0 && key[i] < min){
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void printMST(int parent[],int graph[n][n]){
    printf("Edge  Weight\n");
    for(int i=1;i<n;i++){
        printf("%d-%d \t %d\n",parent[i],i,graph[i][parent[i]]);
    }
}
void Prims(int graph[n][n]){
    int parent[n],key[n],mst[n];
    for(int i=0;i<n;i++){
        key[i] = max;
        mst[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int count=0;count<n-1;count++){
        int u = minKey(key,mst);
        mst[u] = 1;
        for(int j=0;j<n;j++){
            if(graph[u][j] && mst[j] == 0 && graph[u][j] < key[j]){
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }
    printMST(parent,graph);
}
int main(){
    int graph[n][n] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
                        
    Prims(graph);
    return 0;
}