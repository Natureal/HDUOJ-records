////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-22 22:31:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5071
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:308KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

int T,n,sz,altop,alpos;
struct node{
	int p,w;
}no[10010];

int main(){
	int a;
	char s[20];
	scanf("%d",&T);
	while(T--){
		memset(no,0,sizeof(no));
		sz = 0;
		altop = alpos = 0;
		scanf("%d",&n);
		for(int Case = 1; Case <= n; ++Case){
			printf("Operation #%d: ", Case);  
			scanf("%s",s);
			if(s[0] == 'A'){	//Add
				scanf("%d",&a);
				int flag = 0;
				for(int i = 1; i <= sz; ++i) if(no[i].p == a){
					flag = 1; break;
				}
				if(flag){ //已经存在
					printf("same priority.\n");
					continue;
				}
				++sz;
				no[sz].p = a;
				no[sz].w = 0;
				printf("success.\n");
			}
			else if(s[0] == 'C' && s[1] == 'l'){  //Close
				scanf("%d",&a);
				int pos = 0;
				for(int i = 1; i <= sz; ++i) if(no[i].p == a){
					pos = i;
					break;
				}
				if(pos == 0){ //不存在
					printf("invalid priority.\n");
					continue;
				}
				printf("close %d with %d.\n",no[pos].p,no[pos].w);
				if(alpos > pos)
					--alpos;
				for(int i = pos + 1; i <= sz; ++i)
					no[i - 1] = no[i];
				--sz;
				if(altop == a)
					altop = alpos = 0;
			}
			else if(s[0] == 'C' && s[1] == 'h' && s[2] == 'a'){ //Chat
				scanf("%d",&a);
				if(sz == 0){
					printf("empty.\n");
					continue;
				}
				if(altop)	no[alpos].w += a;
				else	no[1].w += a;
				printf("success.\n");
			}
			else if(s[0] == 'R'){	//Rotate
				scanf("%d",&a);
				if(a < 1 || a > sz){
					printf("out of range.\n");
					continue;
				}
				if(alpos && alpos <= a){
					if(alpos == a)	alpos = 1;
					else	alpos++;
				}
				node tmp = no[a];
				for(int i = a; i > 1; --i)
					no[i] = no[i - 1];
				no[1] = tmp;
				printf("success.\n");
			}
			else if(s[0] == 'P'){	//Prior
				if(sz == 0){
					printf("empty.\n");
					continue;
				}
				int pos = 1;
				for(int i = 1; i <= sz; ++i)
					if(no[i].p > no[pos].p)
						pos = i;
				if(alpos && alpos <= pos){
					if(alpos == pos)	alpos = 1;
					else	alpos++;
				}
				node tmp = no[pos];
				for(int i = pos; i > 1; --i)
					no[i] = no[i - 1];
				no[1] = tmp;
				printf("success.\n");
			}
			else if(s[0] == 'C' && s[1] == 'h' && s[2] == 'o'){ //Choose
				scanf("%d",&a);
				int pos = 0;
				for(int i = 1; i <= sz; ++i) if(no[i].p == a){
					pos = i;
					break;
				}
				if(pos == 0){ //不存在
					printf("invalid priority.\n");
					continue;
				}
				if(alpos && alpos <= pos){
					if(alpos == pos)	alpos = 1;
					else	alpos++;
				}
				node tmp = no[pos];
				for(int i = pos; i > 1; --i)
					no[i] = no[i - 1];
				no[1] = tmp;
				printf("success.\n");
			}
			else if(s[0] == 'T'){ //Top
				scanf("%d",&a);
				int pos = 0;
				for(int i = 1; i <= sz; ++i) if(no[i].p == a){
					pos = i;
					break;
				}
				if(pos == 0){ //不存在
					printf("invalid priority.\n"); 
					continue;
				}
				altop = a;
				alpos = pos;
				printf("success.\n");
			}
			else{ //Untop
				if(alpos == 0){
					printf("no such person.\n");	
					continue;
				}
				altop = alpos = 0;
				printf("success.\n");
			}
		}
		if(alpos && no[alpos].w)
			printf("Bye %d: %d\n",altop,no[alpos].w);
		for(int i = 1; i <= sz; ++i){
			if(no[i].w && no[i].p != altop)
				printf("Bye %d: %d\n",no[i].p,no[i].w);
		}
	}
	return 0;
}
		
