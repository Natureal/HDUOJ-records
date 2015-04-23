////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-08 13:49:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5183
////Problem Title: 
////Run result: Accept
////Run time:1497MS
////Run memory:60692KB
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

inline int getint() {
    int ret=0;bool ok=0,neg=0;
    for(;;) {
        int c=getchar();
        if(c>='0'&&c<='9')ret=(ret<<3)+ret+ret+c-'0',ok=1;
        else if(ok)return neg?-ret:ret;
        else if(c=='-')neg=1;
    }
}

const int N=1010000;
set<ll> hs;
ll s[N];
int a[N],n,k,_,__;
bool check() {
    hs.clear();
    per(i,1,n+1) {
        hs.insert(s[i]);
        ll v=k;
        if (i%2==1) v*=-1;
        v+=s[i-1];
        if (hs.count(v)) return 1;
    }
    return 0;
}
int main() {
    for (_=getint();_;_--) {
        n=getint(); k=getint();
        rep(i,1,n+1) a[i]=getint();
        rep(i,1,n+1) {
            if (i%2==0) s[i]=s[i-1]+a[i];
            else s[i]=s[i-1]-a[i];
        }
        printf("Case #%d: ",++__);
        if (check()) puts("Yes.");
        else puts("No.");
    }
}