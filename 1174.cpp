////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-05-09 23:39:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1174
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>

double cal(double i,double j,double k)
{
    return sqrt(i * i + j * j + k * k);
}

int main()
{
    int t;
    double h1,r1,x1,y1,z1,h2,r2,x2,y2,z2,x3,y3,z3;
    scanf("%d",&t);
    while(t --)
    {
        scanf("%lf %lf %lf %lf %lf",&h1,&r1,&x1,&y1,&z1);
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&h2,&r2,&x2,&y2,&z2,&x3,&y3,&z3);
        double x4,y4,z4,ABn,absn;
        x4 = x1 - x2;
        y4 = y1 - y2;
        z4 = z1 + h1 - r1 - z2 - h2 * 0.9 + r2;
        ABn = cal((y4 * z3 - z4 * y3),(x4 * z3 - z4 * x3),(x4 * y3 - y4 * x3));
        absn = cal(x3,y3,z3);
        if(ABn / absn <= r2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
