////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-24 00:16:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1736
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:280KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;
char s[200005];
int main()
{
    int len,flag = 0;
    string arr;

    while(gets(s)!=NULL){
        arr.clear();
        len = strlen(s);
        for(int i = 0; i < len; i++){
            switch(s[i]){
                case ',':{
                             string tem = "£¬";
                             arr += tem;
                             break;
                         }
                case '.':{
                             string tem = "¡£";
                             arr += tem;
                         }
                break;
                case '!':{
                             string tem = "£¡";
                             arr += tem;
                             break;
                         }
                case '"':{
                             string tem;
                             flag++;
                             //printf("%d flag:%d\n",i,flag);
                             if(flag%2){
                                 tem = "¡°";
                                 arr += tem;
                             }
                             else{
                                 tem = "¡±";
                                 arr += tem;
                             }
                             break;
                         }
                case '<':{
                             string tem = "¡¶";
                             if(s[i+1] == '<'){
                                 arr += tem;
                                 i ++;
                             }
                             else{
                                arr.push_back(s[i]);
                             }
                             break;
                         }
                case '>':{
                             string tem = "¡·";
                             if(i+1 < len && s[i+1] == '>'){
                                 arr += tem;
                                 i ++;
                             }
                             else{
                                 arr.push_back(s[i]);
                             }
                             break;
                         }
                case '?':{
                             string tem = "£¿";
                             arr += tem;
                             break;
                         }
                default:{
                            string tem = "";
                            tem = tem + s[i] + s[i+1];
                            if(tem == "¡°" || tem == "¡±"){
                                arr += tem;
                                i ++;//Because there is a i++ after,so i ++ is enough here!
                                flag ++;
                                //printf("flag:%d\n",flag);
                                break;
                            }
                            //string tem(1,s[i]);
                            arr.push_back(s[i]);
                            break;
                        }
            }
        }
        cout << arr << endl;
    }
    return 0;
}
