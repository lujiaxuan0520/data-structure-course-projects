#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;

const int MAXQ = 500000+10;
const int MAXN = 1000000+10;
const int MAXK = 26; //自动机里字符集的大小，26个英文字母
struct TrieNode
{
       TrieNode* fail;
       TrieNode* next[MAXK];//下标对应26个英文字母，
                            //next[i]指向输入i以后跳转到的那个节点
       bool danger;   //该节点是否为某模式串的终结点
       int cnt;    //以该节点为终结点的模式串个数
       TrieNode()
       {
              fail = NULL;
              memset(next, NULL, sizeof(next));
              danger = false;
              cnt = 0;
       }
}*que[MAXQ], *root;

//文本字符串
char msg[MAXN];
int   N;
void TrieInsert(char *s)//传入一个模式串，形成字典树
{
       int i = 0;
       TrieNode *ptr = root;
       while(s[i])
       {
              int idx = s[i]-'a';//该字符对应的数值
              if(ptr->next[idx] == NULL)
                     ptr->next[idx] = new TrieNode();
              ptr = ptr->next[idx];
              i++;
       }
       ptr->danger = true;//到达终结点
       ptr->cnt++;//该结点的模式串个数+1
}

void Init()
{
       int i;
       char s[100];
       root = new TrieNode();
       cout<<"请输入模式串个数:";
       scanf("%d", &N);
       cout<<"请输入模式串："<<endl;
       for(i = 0; i < N; i++)
       {
              scanf("%s", s);
              TrieInsert(s);//把模式串传入函数构造树
       }
}

void Build_AC_Automation()
{
       int rear = 1, front = 0, i;
       que[0] = root;
       root->fail = NULL;
       while(rear != front)
       {
              TrieNode *cur = que[front++];
              for(i = 0; i < 26; i++)
                     if(cur->next[i] != NULL)
                     {
                            if(cur == root)
                                   cur->next[i]->fail = root;
                            else
                            {
                                   TrieNode *ptr = cur->fail;
                                   while(ptr != NULL)
                                   {
                                          if(ptr->next[i] != NULL)
                                          {
                                                 cur->next[i]->fail = ptr->next[i];
                                                 if(ptr->next[i]->danger == true)
                                                        cur->next[i]->danger = true;
                                                 break;
                                          }
                                          ptr = ptr->fail;
                                   }
                                   if(ptr == NULL) cur->next[i]->fail = root;
                            }
                            que[rear++] = cur->next[i];
                     }
       }
}
int AC_Search()
{
       int i = 0, ans = 0;
       TrieNode *ptr = root;
       while(msg[i])
       {
              int idx = msg[i]-'a';
              while(ptr->next[idx] == NULL && ptr != root) ptr = ptr->fail;
              ptr = ptr->next[idx];
              if(ptr == NULL) ptr = root;
              TrieNode *tmp = ptr;
              while(tmp != NULL && tmp->cnt != -1)
              {
                     ans += tmp->cnt;
                     tmp->cnt = -1;
                     tmp = tmp->fail;
              }
              i++;
       }
       return ans;
}

int main()
{
              Init();
              Build_AC_Automation();
              cout<<"请输入目标串:"<<endl;
              scanf("%s", msg);
              cout<<"匹配到的个数:";
              printf("%d\n", AC_Search());
    return 0;
}
