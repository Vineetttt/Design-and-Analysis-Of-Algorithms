#include<stdio.h>
#include<string.h>
char x[100000],y[100000],b[1000][1000];
int i,j,m,n,a,c[1000][1000];
void lcs_length(){
    m=strlen(x);
    n=strlen(y);
    for(i=0;i<=m;i++)
        c[i][0]=0;
    for(j=0;j<=n;j++)
        c[0][j]=0;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='c';//\directionarrow
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]='u';//|upperarrow
            }
            else{
                c[i][j]=c[i][j-1];
                b[i][j]='i';//__leftsidearrow}
            }
        }
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            printf("%d ",c[j][i]);
        }
        printf("\n");
    }
    print_lcs(m,n);
}
void print_lcs(int i,int j){
    if(i==0||j==0)
        return;
    if(b[i][j]=='c'){
        print_lcs(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j]=='u'){
        print_lcs(i-1,j);
    }
    else{
        print_lcs(i,j-1);
    }
}
int main(){
    printf("\nEnter 1st Sequence:");
    gets(x);
    printf("\nEnter 2nd Sequence:");
    gets(y);
    printf("\nLongest Common Subsequence Implementation results:\n");
    lcs_length();
}