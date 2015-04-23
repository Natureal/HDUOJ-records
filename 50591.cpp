////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-06 12:48:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5059
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define lp (p << 1)
#define rp (p << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
#define MP(a,b) make_pair(a,b)
typedef long long ll;
const int INF = 1 << 30;

char s[200];
int a,b,flag;

int main(){
    while(gets(s)){
        scanf("%d%d",&a,&b);
        getchar();
        flag = 1;
        ll ans = 0;
        int i;
        if(s[0] == '-') i = 1;
        else i = 0;
        if(strcmp(s,"-0") == 0 || (s[i] == '0' && s[i + 1]) || !s[i]){
            printf("NO\n");
            continue;
        }
        for(; s[i]; ++i){
            if(s[i] < '0' ||s[i] > '9'){flag = 0; break;}
            ans = ans * 10 + s[i] - '0';
            if(ans > 1000000000){flag= 0; break;}
        }
        if(s[0] == '-') ans = -ans;
        if(flag && ans >= a && ans <= b) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
