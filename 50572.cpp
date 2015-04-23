////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-04 16:43:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5057
////Problem Title: 
////Run result: Accept
////Run time:1156MS
////Run memory:8116KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
using namespace std;
int const uu[4] = {1,-1,0,0};
int const vv[4] = {0,0,1,-1};
typedef long long ll;
int const inf = 0x3f3f3f3f;
ll const INF = 0x7fffffffffffffffll;
double eps = 1e-10;
double pi = acos(-1.0);
#define rep(i,s,n) for(int i=(s);i<=(n);++i)
#define rep2(i,s,n) for(int i=(s);i>=(n);--i)
#define mem(v,n) memset(v,(n),sizeof(v))
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define lowbit(x) (x)&(-(x))
struct node1{
    int kind, L, R, D, P, pos, value; //kind=0,Q操作  kind=1,S操作
}O[100005];

int const maxn=100005;
int T,n,m;
int a[maxn], aa[maxn];
int C[maxn][10]; //第二维：位上的数字
int ans[maxn];


void update(int kind,int p,int x){ //x:位上的数字
    for(int i=p;i<=n;i+=lowbit(i)){
        if(kind==0)
            ++C[i][x];
        else
            --C[i][x];
    }
}

int sum(int p,int P){
    int ret=0;
    for(int i=p;i>0;i-=lowbit(i))
        ret+=C[i][P];
    return ret;
}

int query(int L,int R,int P){
    return sum(R,P)-sum(L-1,P);
}

int POW(int base,int k){
    int ret=1;
    while(k--) ret*=10;
    return ret;
}

int main(){
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);

        rep(i,1,n){
            scanf("%d",&a[i]);
            aa[i]=a[i];
        }

        char op[10];
        rep(kk,1,m){
            scanf("%s",op);
            int x,y,L,R,D,P;
            if(op[0]=='S'){
                scanf("%d%d",&x,&y);
                O[kk].kind=1, O[kk].pos=x, O[kk].value=y;
            }else{
                scanf("%d%d%d%d",&L,&R,&D,&P);
                O[kk].kind=0, O[kk].L=L, O[kk].R=R, O[kk].D=D, O[kk].P=P;
            }
        }

        rep(i,1,10){// 第i位
            mem(C,0);
            rep(j,1,n){
                a[j]=aa[j];
                int t1=a[j]/POW(10,i-1)%10; //第i位上的数字
                update(0,j,t1);
            }
            rep(j,1,m){
                if(O[j].kind==1){ //更改操作
                    int t1=a[O[j].pos]/POW(10,i-1)%10;
                        update(1, O[j].pos, t1);
                    int t2=O[j].value/POW(10,i-1)%10;
                        update(0, O[j].pos, t2);
                        a[O[j].pos]=O[j].value;
                }else{
                    if(O[j].D==i){ //查询操作
                        ans[j]=query(O[j].L,O[j].R,O[j].P);
                    }
                }
            }
        }
        rep(i,1,m) if(O[i].kind==0) printf("%d\n",ans[i]);
    }
    return 0;
}