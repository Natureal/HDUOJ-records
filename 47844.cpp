////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-07 23:49:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4784
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:6332KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 201;

inline int Read(){
       int x = 0;char ch = getchar();
       while(ch < '0' || ch > '9'){ch = getchar();}
       while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
       return x;
}

struct node{
    int a,b,c,d;
    node(int ta,int tb,int tc,int td) : a(ta),b(tb),c(tc),d(td) {}
    bool operator < (const node &x) const{
        return d < x.d;
    }
};

int C,T,N,M,B,K,R,ans;
int pri[6][101];
int dp[101][6][6][201];
int inq[101][6][6][201];
int first[maxn],next[maxn],ver[maxn],tim[maxn],fee[maxn],ecnt;
priority_queue<node> Q;

void Init(){
    memset(inq,0,sizeof(inq));
    memset(first,-1,sizeof(first));
    memset(dp,0,sizeof(dp));
    while(!Q.empty()) Q.pop();
    ans = -1;
    ecnt = 0;
}

void Add_edge(int u,int v,int t,int f){
    next[++ecnt] = first[u];
    ver[ecnt] = v;
    tim[ecnt] = t;
    fee[ecnt] = f;
    first[u] = ecnt;
}

void Bfs(){
    int v,tt,tf,nextk;
    dp[1][0][0][T] = R;
    Q.push(node(1,0,0,T));
    inq[1][0][0][T] = 1;
    while(!Q.empty()){
        node x = Q.top();
        Q.pop();
        //inq[x.a][x.b][x.c][x.d] = 0;
        int tmp = dp[x.a][x.b][x.c][x.d];
        nextk = (x.c + 1) % K;
        for(int i = first[x.a]; i != -1; i = next[i]){
            v = ver[i];
            tt = tim[i];
            tf = fee[i];
            if(x.d >= tt && tmp >= tf){ //能去下一点
                if(v == 1 && x.c != 0)
                    continue;
                if(v == N){
                    if(x.c == 0)
                        ans = max(ans,tmp - tf);
                }
                else{
                    if(tmp - tf > dp[v][x.b][x.c][x.d - tt]){
                        //去下点，不行动
                        dp[v][x.b][x.c][x.d - tt] = tmp - tf;
                        if(!inq[v][x.b][x.c][x.d - tt]){
                            Q.push(node(v,x.b,x.c,x.d - tt));
                            inq[v][x.b][x.c][x.d - tt] = 1;
                        }
                    }
                    if(v != 1&& x.b < B  &&tmp - tf - pri[x.c][v] > dp[v][x.b + 1][x.c][x.d - tt]){
                        //去下点，买
                        dp[v][x.b + 1][x.c][x.d - tt] = tmp - tf - pri[x.c][v];
                        if(!inq[v][x.b + 1][x.c][x.d - tt]){
                            Q.push(node(v,x.b + 1,x.c,x.d - tt));
                            inq[v][x.b + 1][x.c][x.d - tt] = 1;
                        }
                    }
                    if(v != 1 && x.b > 0 && tmp - tf + pri[x.c][v] > dp[v][x.b - 1][x.c][x.d - tt]){
                        //去下点，卖
                        dp[v][x.b - 1][x.c][x.d - tt] = tmp - tf + pri[x.c][v];
                        if(!inq[v][x.b - 1][x.c][x.d - tt]){
                            Q.push(node(v,x.b - 1,x.c,x.d - tt));
                            inq[v][x.b - 1][x.c][x.d - tt] = 1;
                        }
                    }
                }
            }
        }
        if(x.d > 0 && x.a != 1 ){
            if(tmp >dp[x.a][x.b][nextk][x.d - 1]){
                //去下个宇宙，不行动
                dp[x.a][x.b][nextk][x.d - 1] = tmp;
                if(!inq[x.a][x.b][nextk][x.d - 1]){
                    Q.push(node(x.a,x.b,nextk,x.d - 1));
                    inq[x.a][x.b][nextk][x.d - 1] = 1;
                }
            }
            if(x.b < B &&  tmp - pri[nextk][x.a] > dp[x.a][x.b + 1][nextk][x.d - 1]){
                //去下个宇宙，买
                dp[x.a][x.b + 1][nextk][x.d - 1] = tmp - pri[nextk][x.a];
                if(!inq[x.a][x.b + 1][nextk][x.d - 1]){
                    Q.push(node(x.a,x.b + 1,nextk,x.d - 1));
                    inq[x.a][x.b + 1][nextk][x.d - 1] = 1;
                }
            }
            if(x.b > 0 &&  tmp + pri[nextk][x.a] > dp[x.a][x.b - 1][nextk][x.d - 1]){
                //去下个宇宙，卖
                dp[x.a][x.b - 1][nextk][x.d - 1] = tmp + pri[nextk][x.a];
                if(!inq[x.a][x.b - 1][nextk][x.d - 1]){
                    Q.push(node(x.a,x.b - 1,nextk,x.d - 1));
                    inq[x.a][x.b - 1][nextk][x.d - 1] = 1;
                }
            }
        }
    }
}

int main(){
    int a,b,c,d;
    scanf("%d",&C);
    for(int Case = 1; Case <= C; ++Case){
        Init();
        N = Read(); M = Read(); B = Read(); K = Read(); R = Read(); T = Read();
        for(int i = 0; i < K; ++i)
            for(int j = 1; j <= N; ++j)
                pri[i][j] = Read();
        for(int i = 1; i <= M; ++i){
            a = Read(); b = Read(); c = Read(); d = Read();
            Add_edge(a,b,c,d);
        }
        Bfs();
        printf("Case #%d: ",Case);
        if(ans == -1) printf("Forever Alone\n");
        else    printf("%d\n",ans);
    }
    return 0;
}
