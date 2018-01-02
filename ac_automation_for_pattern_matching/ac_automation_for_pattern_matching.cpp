#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;

const int MAXQ = 500000+10;
const int MAXN = 1000000+10;
const int MAXK = 26; //�Զ������ַ����Ĵ�С��26��Ӣ����ĸ
struct TrieNode
{
       TrieNode* fail;
       TrieNode* next[MAXK];//�±��Ӧ26��Ӣ����ĸ��
                            //next[i]ָ������i�Ժ���ת�����Ǹ��ڵ�
       bool danger;   //�ýڵ��Ƿ�Ϊĳģʽ�����ս��
       int cnt;    //�Ըýڵ�Ϊ�ս���ģʽ������
       TrieNode()
       {
              fail = NULL;
              memset(next, NULL, sizeof(next));
              danger = false;
              cnt = 0;
       }
}*que[MAXQ], *root;

//�ı��ַ���
char msg[MAXN];
int   N;
void TrieInsert(char *s)//����һ��ģʽ�����γ��ֵ���
{
       int i = 0;
       TrieNode *ptr = root;
       while(s[i])
       {
              int idx = s[i]-'a';//���ַ���Ӧ����ֵ
              if(ptr->next[idx] == NULL)
                     ptr->next[idx] = new TrieNode();
              ptr = ptr->next[idx];
              i++;
       }
       ptr->danger = true;//�����ս��
       ptr->cnt++;//�ý���ģʽ������+1
}

void Init()
{
       int i;
       char s[100];
       root = new TrieNode();
       cout<<"������ģʽ������:";
       scanf("%d", &N);
       cout<<"������ģʽ����"<<endl;
       for(i = 0; i < N; i++)
       {
              scanf("%s", s);
              TrieInsert(s);//��ģʽ�����뺯��������
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
              cout<<"������Ŀ�괮:"<<endl;
              scanf("%s", msg);
              cout<<"ƥ�䵽�ĸ���:";
              printf("%d\n", AC_Search());
    return 0;
}
