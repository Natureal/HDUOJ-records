////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-09 20:43:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1789
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct lesson
{
  int score,dead;
}lesson;
lesson les[1005];
bool cmp(lesson a,lesson b)
{
  return a.score > b.score;
}
int main()
{
  int t,n;
  scanf("%d",&t);
  int used[1005];
  while(t--)
  {
    int  i,j,sum = 0;
    memset(used,0,sizeof(used));
    scanf("%d",&n);
    for(i = 0;i < n;i ++)
    {
       scanf("%d",&les[i].dead);
    }
    for(i = 0;i < n;i ++)
    {
       scanf("%d",&les[i].score);
    }
    sort(les,les+n,cmp);
    for(i = 0;i < n;i ++)
    {
      for(j = les[i].dead;j >= 1;j --)
      {
         if(!used[j])
         {
            used[j] = 1;
            break;
         }
      }
      if(j == 0)
      {
         sum += les[i].score;
      }
    }
    printf("%d\n",sum);
  }
  return 0;
}