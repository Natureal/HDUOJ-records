////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-07 00:58:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4790
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:232KB
//////////////////System Comment End//////////////////
/* ***********************************************
Author        :kuangbin
Created Time  :2013-11-16 13:20:40
File Name     :E:\2013ACM\专题强化训练\区域赛\2013成都\1010.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

long long gcd(long long a,long long b)
{
    if(b == 0)return a;
    return gcd(b,a%b);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long a,b,c,d,p,m;
    int T;
    int iCase = 0;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&d,&p,&m);
        long long ans = 0;
        if(b+c <= a+d)
        {
            long long t1 = (a+c)%p;
            long long add = (m - t1 + p)%p;
            long long cnt1 = (a+c + add-m)/p;
            //cout<<t1<<" "<<add<<endl;
            long long t2 = (b+c-1)%p;
            long long sub = (t2 - m + p)%p;
            long long cnt2 = (b+c-1-sub-m)/p;
            //cout<<t2<<" "<<sub<<endl;
            ans += (cnt2 - cnt1 + 1)*(1+add) + (cnt2 - cnt1 + 1)*(cnt2 - cnt1)/2 * p;
            //printf("%I64d %I64d  %I64d\n",cnt1,cnt2,ans);
            t1 = (b+c)%p;
            add = (m - t1 + p)%p;
            cnt1 = (b+c+add-m)/p;
            t2 = (a+d)%p;
            sub = (t2 - m + p)%p;
            cnt2 = (a+d-sub-m)/p;
            ans += (cnt2 - cnt1 + 1)*(b-a+1);
            t1 = (a+d+1)%p;
            add = (m - t1 + p)%p;
            cnt1 = (a+d+1+add-m)/p;
            t2 = (b+d)%p;
            sub = (t2 - m + p)%p;
            cnt2 = (b+d-sub-m)/p;
            ans += (cnt2 - cnt1 + 1)*(1+sub) + (cnt2 - cnt1 + 1)*(cnt2 - cnt1)/2*p;
        }
        else
        {
            long long t1 = (a+c)%p;
            long long add = (m - t1 + p)%p;
            long long cnt1 = (a+c + add-m)/p;
            long long t2 = (a+d-1)%p;
            long long sub = (t2 - m + p)%p;
            long long cnt2 = (a+d-1-sub-m)/p;
            ans += (cnt2 - cnt1 + 1)*(1+add) + (cnt2 - cnt1 + 1)*(cnt2 - cnt1)/2 * p;
            t1 = (a+d)%p;
            add = (m - t1 + p)%p;
            cnt1 = (a+d+add-m)/p;
            t2 = (b+ c)%p;
            sub = (t2 - m + p)%p;
            cnt2 = (b+c-sub-m)/p;
            ans += (cnt2 - cnt1 + 1)*(d-c+1);
            t1 = (b+c+1)%p;
            add = (m - t1 + p)%p;
            cnt1 = (b+c+1+add-m)/p;
            t2 = (b+d)%p;
            sub = (t2 - m + p)%p;
            cnt2 = (b+d - sub-m)/p;
            ans += (cnt2 - cnt1 + 1)*(1+sub) + (cnt2 - cnt1 + 1)*(cnt2 - cnt1)/2*p;
        }
        long long tot = (b-a+1)*(d-c+1);
        long long GCD = gcd(ans,tot);
        ans /= GCD;
        tot /= GCD;
        printf("Case #%d: %I64d/%I64d\n",iCase,ans,tot);
    }
    return 0;
}