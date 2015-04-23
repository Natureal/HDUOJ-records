////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-05-10 18:23:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1411
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:292KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    double l,m,n,p,q,r,ans;
    double n1,n2,n3,n4,n5,n6,n7,n8,n9;
    while(cin >> r >> q >> p >> l >> m >> n)
    {
        n1 = p * p;
        n2 = (p * p + q * q - n * n) / 2;
        n3 = (p * p + r * r - m * m) / 2;
        n4 = n2;
        n5 = q * q;
        n6 = (q * q + r * r - l * l) / 2;
        n7 = n3;
        n8 = n6;
        n9 = r * r;
        double t1 = n1 * (n5 * n9 - n6 * n8);
        double t2 = n2 * (n4 * n9 - n6 * n7);
        double t3 = n3 * (n4 * n8 - n5 * n7);
        ans = sqrt(t1 - t2 + t3) / 6;
        printf("%.4lf\n",ans);
    }
    return 0;
}
