////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-05-20 20:17:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4826
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:316KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int gra[105][105],dp[105][105];
int main(){
    int Case,t,n,m;
    scanf("%d",&Case);
    for(t = 1; t <= Case; t++){
        scanf("%d %d",&m,&n);
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                scanf("%d",&gra[i][j]);
                gra[i][j] += gra[i - 1][j];
            }
        }
        for(int r = 1; r <= m; r++){
            dp[r][1] = gra[r][1] ;
        }
        for(int l = 2; l <= n; l++){
            for(int r = 1; r <= m; r++){
                dp[r][l] = dp[r][l - 1] + gra[r][l] - gra[r - 1][l];//包括图中自己
            }
            for(int r = 1; r <= m; r++){
                int tmax = -10000000;
                if(r > 1) for(int i = 1; i < r; i ++){
                    tmax = max(tmax,dp[i][l - 1] + gra[i][l] - gra[i - 1][l] + gra[r][l] - gra[i][l]);
                }
                if(r < m) for(int i = r + 1; i <= m; i++){
                    tmax = max(tmax,dp[i][l - 1] + gra[i][l] - gra[i - 1][l] + gra[i - 1][l] - gra[r - 1][l]);
                }
                dp[r][l] = max(dp[r][l],tmax);
            }
        }
        printf("Case #%d:\n",t);
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
