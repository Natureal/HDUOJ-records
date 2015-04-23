////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-08 21:28:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4819
////Problem Title: 
////Run result: Accept
////Run time:1092MS
////Run memory:36848KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = (1 << 30) - 1;

int T,N,Q,X1,X2,Y1,Y2;
int g[810][810];
int A,B;

struct SMT_2{
    int tmax[810 << 2][810 << 2];
    int tmin[810 << 2][810 << 2];
    void Build_y(int xp,int x,int p,int l,int r){
        if(l == r){
            tmax[xp][p] = tmin[xp][p] = g[x][l];
            return;
        }
        int mid = (l + r) >> 1;
        Build_y(xp,x,p << 1,l,mid);
        Build_y(xp,x,p << 1|1,mid + 1,r);
        tmax[xp][p] = max(tmax[xp][p << 1],tmax[xp][p << 1|1]);
        tmin[xp][p] = min(tmin[xp][p << 1],tmin[xp][p << 1|1]);
    }
    void Build_y_2(int xp,int p,int l,int r){
        tmax[xp][p] = max(tmax[xp << 1][p],tmax[xp << 1|1][p]);
        tmin[xp][p] = min(tmin[xp << 1][p],tmin[xp << 1|1][p]);
        if(l == r)
            return;
        int mid = (l + r) >> 1;
        Build_y_2(xp,p << 1,l,mid);
        Build_y_2(xp,p << 1|1,mid + 1,r);
    }
    void Build_x(int p,int l,int r){
        if(l == r){
            Build_y(p,l,1,1,N);
            return;
        }
        int mid = (l + r) >> 1;
        Build_x(p << 1,l,mid);
        Build_x(p << 1|1,mid + 1,r);
        Build_y_2(p,1,1,N);
    }
    void Query_y(int xp,int p,int l,int r){
        if(Y1 <= l && r <= Y2){
            A = tmax[xp][p],B = tmin[xp][p];
            return;
        }
        int mid = (l + r) >> 1;
        int t1 = 0,t2 = INF;
        if(Y1 <= mid) Query_y(xp,p << 1,l,mid),t1 = A > t1 ? A : t1,t2 = B < t2 ? B : t2;
        if(Y2 > mid) Query_y(xp,p << 1|1,mid + 1,r),t1 = A > t1 ? A : t1,t2 = B < t2 ? B : t2;
        A = t1,B = t2;
    }
    void Query_x(int p,int l,int r){
        if(X1 <= l && r <= X2){
            Query_y(p,1,1,N);
            return;
        }
        int mid = (l + r) >> 1;
        int t1 = 0,t2 = INF;
        if(X1 <= mid) Query_x(p << 1,l,mid),t1 = A > t1 ? A : t1,t2 = B < t2 ? B : t2;
        if(X2 > mid) Query_x(p << 1|1,mid + 1,r),t1 = A > t1 ? A : t1,t2 = B < t2 ? B : t2;
        A = t1,B = t2;
    }
    void Update_y(int xp,int c,int p,int l,int r){
        if(l == r){
            tmax[xp][p] = tmin[xp][p] = c;
            return;
        }
        int mid = (l + r) >> 1;
        if(Y1 <= mid) Update_y(xp,c,p << 1,l,mid);
        else Update_y(xp,c,p << 1|1,mid + 1,r);
        tmax[xp][p] = max(tmax[xp][p << 1],tmax[xp][p << 1|1]);
        tmin[xp][p] = min(tmin[xp][p << 1],tmin[xp][p << 1|1]);
    }
    void Update_y_2(int xp,int p,int l,int r){
        tmax[xp][p] = max(tmax[xp << 1][p],tmax[xp << 1|1][p]);
        tmin[xp][p] = min(tmin[xp << 1][p],tmin[xp << 1|1][p]);
        if(l == r)
            return;
        int mid = (l + r) >> 1;
        if(Y1 <= mid) Update_y_2(xp,p << 1,l,mid);
        else Update_y_2(xp,p << 1|1,mid + 1,r);
        tmax[xp][p] = max(tmax[xp][p << 1],tmax[xp][p << 1|1]);
        tmin[xp][p] = min(tmin[xp][p << 1],tmin[xp][p << 1|1]);
    }
    void Update_x(int c,int p,int l,int r){
        if(l == r){
            Update_y(p,c,1,1,N);
            return;
        }
        int mid = (l + r) >>1;
        if(X1 <= mid) Update_x(c,p << 1,l,mid);
        else Update_x(c,p << 1|1,mid + 1,r);
        Update_y_2(p,1,1,N);
    }
}smt;

int main(){
    int a,b,c;
    scanf("%d",&T);
    for(int tt =  1; tt <= T; ++tt){
        scanf("%d",&N);
        for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) scanf("%d",&g[i][j]);
        smt.Build_x(1,1,N);
        printf("Case #%d:\n",tt);
        scanf("%d",&Q);
        for(int i = 1; i <= Q; ++i){
            scanf("%d%d%d",&a,&b,&c);
            c >>= 1;
            X1 = a - c > 1 ? a - c : 1;
            X2 = a + c < N ? a + c : N;
            Y1 = b - c > 1 ? b - c : 1;
            Y2 = b + c < N ? b + c : N;
            smt.Query_x(1,1,N);
            X1 = a;
            Y1 = b;
            int ans = (A + B) >> 1;
            smt.Update_x(ans,1,1,N);
            printf("%d\n",ans);
        }
    }
    return 0;
}
