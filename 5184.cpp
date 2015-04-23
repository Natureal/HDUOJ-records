////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-08 17:28:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5184
////Problem Title: 
////Run result: Accept
////Run time:764MS
////Run memory:19648KB
//////////////////System Comment End//////////////////
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <complex>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
#define TWO(x) (1<<(x))
#define TWOL(x) (1ll<<(x))
#define clr(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (0<=(x)&&(x)<n&&0<=(y)&&(y)<m)
#define PRINTC(x) cout<<"Case #"<<++__<<": "<<x<<endl 
#define POP(x) (__builtin_popcount(x))
#define POPL(x) (__builtin_popcountll(x))
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010000;
int cnt,x,y,l,n;
char s[N];
ll f[N],g[N];
bool valid() {
    if (n%2==1) return 0;
    cnt=0;  x=n/2; y=n/2;
    l=strlen(s);
    rep(i,0,l) {
        if (s[i]=='(') cnt++,x--;
        else cnt--,y--;
        if (cnt<0) return 0;
    }
    if (x<0||y<0) return 0;
    return 1;
}
ll binom(ll x,ll y) {
    assert(y>=0&&y<=x);
    return f[x]*g[y]%mod*g[x-y]%mod;
}
int main() {
    f[0]=g[0]=1;
    rep(i,1,1000001) f[i]=f[i-1]*i%mod;
    g[1000000]=powmod(f[1000000],mod-2);
    per(i,0,1000000) g[i]=g[i+1]*(i+1)%mod;
    while (scanf("%d",&n)!=EOF) {
        scanf("%s",s);
        if (!valid()) puts("0");
        else {
            if (x==0) puts("1");
            else {
                printf("%d\n",(int)((binom(x+y,x)-binom(x+y,x-1)+mod)%mod));
            }
        }
    }
}