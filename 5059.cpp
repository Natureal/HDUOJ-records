////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-06 12:42:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5059
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
const int INF = 2e9;
char s1[SIZE],s2[SIZE];
int get(char s[]){
    if(!s[0])return INF;
    if(s[0]=='0'&&!s[1])return 0;
    if(s[0]=='0')return INF;
    LL res=0;
    for(int i=0;s[i];i++){
        if(s[i]<'0'||s[i]>'9')return INF;
        res*=10;
        res+=s[i]-'0';
        if(res>1000000000)return INF;
    }
    return res;
}
int main(){
    while(gets(s1)!=NULL){
        gets(s2);
        int a,b;
        sscanf(s2,"%d%d",&a,&b);
        if(strcmp(s1,"-0")==0){
            puts("NO");
            continue;
        }
        int n=LEN(s1);
        bool no=false;
        int x;
        if(s1[0]=='-')x=-get(s1+1);
        else x=get(s1);
        if(x<a||x>b)puts("NO");
        else puts("YES");
    }
    return 0;
}