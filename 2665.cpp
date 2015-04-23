////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-28 21:43:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2665
////Problem Title: 
////Run result: Accept
////Run time:656MS
////Run memory:16292KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2104.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sun 28 Sep 2014 07:24:07 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define getmid(l,r) (l + (r - l) / 2)
const int RA = 100010;

int sorted[RA];

struct node{
    int val[RA]; //记录某一层所有数的值
    int num[RA]; //num[k]：某一层第k个数及其之前有多少个数划入左子树
}t[20];          //t只用开到足够层数即可，log(n)级别

void Build_ptree(int p,int l,int r){
    if(l == r)
        return;
    int mid = getmid(l,r);
    int isame = mid - l + 1; //isame：该层中与中值相等，且被划入左子树的元素个数
    int same = 0;               //记录当前与中值相等的元素个数
    for(int i = l; i <= r; ++i){
        if(t[p].val[i] < sorted[mid]) --isame; //处理后isame意义成立
    }
    int ls = l,rs = mid + 1;  //ls：左子树元素起始位置，rs：右子树元素起始位置
    for(int i = l; i <= r; ++i){
        t[p].num[i] = (i == l ? 0 : t[p].num[i - 1]);
        if(t[p].val[i] < sorted[mid]){         //比中值小的元素归入左子树
            t[p].num[i]++;
            t[p + 1].val[ls++] = t[p].val[i];
        }
        else if(t[p].val[i] > sorted[mid]){ //比中值大的元素归入右子树
            t[p + 1].val[rs++] = t[p].val[i];
        }
        else{                                //与中值相等，考虑same是否已经达到isame
            if(same < isame){                //未达到，归入左子树
                same++;
                t[p].num[i]++;
                t[p + 1].val[ls++] = t[p].val[i];
            }
            else{                            //已达到，归入右子树
                t[p + 1].val[rs++] = t[p].val[i];
            }
        }
    }
    Build_ptree(p + 1,l,mid);
    Build_ptree(p + 1,mid + 1,r);
}

int Query_ptree(int a,int b,int k,int p,int l,int r){
    if(l == r)
        return t[p].val[a];
    //ln（rn）：[a,b]中归入左（右）子树的元素个数
    //preln（prern）：[l,a - 1]中归入左（右）子树的元素个数
    int ln,rn,preln,prern,sum;
    int mid = getmid(l,r);
    ln = t[p].num[b] - (a == l ? 0 : t[p].num[a - 1]);
    preln = (a == l ? 0 : t[p].num[a - 1]);
    if(ln >= k){                           //[a,b]中划入左子树的元素 >= k，则递归进左子树
        a = l + preln;
        b = l + preln + ln - 1;
        return Query_ptree(a,b,k,p + 1,l,mid);
    }
    else{                                   //否则，递归进右子树，找第 k - ln 大的元素
        prern = a - l - preln;
        rn = b - a + 1 - ln;
        a = mid + 1 + prern;
        b = mid + 1 + prern + rn - 1;
        return Query_ptree(a,b,k - ln,p + 1,mid + 1,r);
    }
}

int main(){
    int T,n,m,a,b,k;
    scanf("%d",&T);
    while(T--){
        memset(t,0,sizeof(t));
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; ++i){
            scanf("%d",&sorted[i]);
            t[1].val[i] = sorted[i]; //注意在输入时要给划分树第一层初始化
        }
        sort(sorted + 1,sorted + n + 1);
        Build_ptree(1,1,n);
        while(m--){
            scanf("%d%d%d",&a,&b,&k);
            printf("%d\n",Query_ptree(a,b,k,1,1,n));
        }
    }
    return 0;
}
