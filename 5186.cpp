////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-14 22:08:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5186
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:1624KB
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
#define REP(i,n) for(int i=1;i<=(n);++i)
#define REV(i,n) for(int i=(n);i>=1;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int main()
{
    int n,b;
    while(scanf("%d%d",&n,&b)!=EOF)
    {
        char ch[500];
        int ans[500]={0},a[500]={0};
        while(n--)
        {
            MEM(a,0);
            scanf("%s",ch+1);
            int len=strlen(ch+1);
            for(int i=1;i<=len;i++)
            {
                if('0'<=ch[i]&& ch[i]<='9')a[len-i+1]=ch[i]-'0';
                else a[len-i+1]=ch[i]-'a'+10;
            }
            for(int i=1;i<=max(len,ans[0]);i++)
            {
                ans[i]=(ans[i]+a[i])%b;
            }
            ans[0]=max(ans[0],len);
        }
        while(ans[ans[0]]==0 &&ans[0]>=2)ans[0]--;
        for(int i=ans[0];i>=1;i--)
        {
            if(ans[i]>=10)printf("%c",'a'+ans[i]-10);
            else printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}