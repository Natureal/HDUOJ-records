////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-05-09 22:25:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1115
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:444KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <iomanip>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define MAXN 1000000

typedef struct Triangle
{
    double gx,gy;
    double area;
}Tri;
Tri tri[MAXN + 5];

double cross(double x1,double y1,double x2,double y2,double x3,double y3)
{
    // S = 1/2 * (a ¡Á b)
    return ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
}

int main()
{
    double area_sum,grax,gray;
    int t,n;
    double x1,y1,x2,y2,x3,y3;
    scanf("%d",&t);
    //cin >> t;
    while(t --)
    {
        //memset(tri,0,sizeof(tri));
        area_sum = 0;
        grax = gray = 0;
        scanf("%d %lf %lf %lf %lf",&n,&x1,&y1,&x2,&y2);
        //cin >> n >> x1 >> y1 >> x2 >> y2;
        int i;
        for(i = 3; i <= n; i++)
        {
            scanf("%lf %lf",&x3,&y3);
            //cin >> x3 >> y3;
            tri[i - 2].gx = ( x1 + x2 + x3) / 3;
            tri[i - 2].gy = (y1 + y2 + y3) / 3;
            tri[i - 2].area = cross(x1,y1,x2,y2,x3,y3) / 2;
            //double cro = cross(x1,y1,x2,y2,x3,y3) / 2;

            grax += tri[i - 2].gx * tri[i - 2].area;
            gray += tri[i - 2].gy * tri[i - 2].area;

            area_sum += tri[i - 2].area;

            x2 = x3;
            y2 = y3;
        }
        //if(area_sum < 0)
            //area_sum = -area_sum;

        grax /= area_sum;
        gray /= area_sum;
        /*for(i = 1;i <= n - 2; i++)
        {
            grax += tri[i].gx * tri[i].area / area_sum;
            gray += tri[i].gy * tri[i].area / area_sum;
        }*/
        printf("%.2lf %.2lf\n",grax ,gray );
    }
    return 0;
}
