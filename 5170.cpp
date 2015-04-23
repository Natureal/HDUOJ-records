////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-07 21:15:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5170
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1196KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=0;i<(n);++i)
#define REV(i,n) for(int i=(n-1);i>=0;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

double a,b,c,d;
double A,B;

int main(){
    while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d) != EOF){
        A = 1.0 * b * log(1.0 * a);
        B = 1.0 * d * log(1.0 * c);
        if(fabs(A - B) < 1e-10) printf("=\n");
        else if(A > B) printf(">\n");
        else printf("<\n");
    }
    return 0;
}