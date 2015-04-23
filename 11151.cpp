////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-05-09 22:30:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1115
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
double cross(double x1,double y1,double x2,double y2,double x3,double y3)
{
    // S = 1/2 * (a × b)
    return ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
}
int main()
{
    double area_sum,grax,gray;
    int t,n;
    double x1,y1,x2,y2,x3,y3;
    scanf("%d",&t);
    while(t --)
    {
        area_sum = 0;
        grax = gray = 0;
        scanf("%d %lf %lf %lf %lf",&n,&x1,&y1,&x2,&y2);
        int i;
        for(i = 3; i <= n; i++)
        {
            scanf("%lf %lf",&x3,&y3);
            double tarea = cross(x1,y1,x2,y2,x3,y3) / 2; //计算面积
            grax += ( x1 + x2 + x3) * tarea / 3; //重心面积权
            gray +=  (y1 + y2 + y3) * tarea / 3;
            area_sum += tarea; //总面积
            x2 = x3;
            y2 = y3;
        }
        printf("%.2lf %.2lf\n", grax / area_sum , gray / area_sum);
    }
    return 0;
}
