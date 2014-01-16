#include <iostream>
#include <stack>
#include <memory.h>
using namespace std;
const int MAXN = 101;
const int MAXM = 10010;
struct QNode
{
     int x, y, step;
     int flag;
     QNode *pre;
}que[MAXM];//FLAG表示操作种类，pre指向前一个状态结点。

int A, B, C;
stack <int> st;//操作压站

int bfs(int x, int y)
{
      if(C == x || C == y) return 0;

      QNode cur, now;

      int hash[MAXN][MAXN];
      memset(hash, false, sizeof(hash));
      hash[x][y] = true;

      que[0].x = x;
      que[0].y = y;
      que[0].step = 0;
      que[0].flag = 0;
      que[0].pre = NULL;
      int front = 0, rear = 1;

      while(front < rear)
   {
           cur = que[front];
           now.pre = &que[front];
           now.step = cur.step + 1;

           for(int i = 1; i <= 6; i ++)
     {
                 now.flag = i;
                 switch(i)
     {
                      case 1 : now.x = A; now.y = cur.y; break;
                      case 2 : now.x = cur.x; now.y = B; break;
                      case 3 : now.x = 0; now.y = cur.y; break;
                      case 4 : now.x = cur.x; now.y = 0; break;
                      case 5 :
        {
                                if(cur.x + cur.y >= B)
         {
                                      now.x = cur.x + cur.y - B; now.y = B;
                                }
         else
         {
                                      now.x = 0; now.y = cur.x + cur.y;
                                }
                                break;
        }
                      case 6 :
        {
                                if(cur.x + cur.y >= A) {
                                      now.x = A; now.y = cur.x + cur.y - A;
                                }else {
                                      now.x = cur.x + cur.y; now.y = 0;
                                }
                                break;
                      }
                      default : break;
                 }
                 if(now.x == C || now.y == C)
               {
                      QNode nod = now;
                      while(nod.pre)
                  {
                            st.push(nod.flag);
                            nod = *(nod.pre);
                      }
                      return now.step;
                 }//压站
                 if(! hash[now.x][now.y]) {
                      hash[now.x][now.y] = true;
                      que[rear ++] = now;
                 }
           }
           front ++;
      }
      return -1;
}
int main()
{
      while(cin >> A >> B >> C)
   {
           int minimum = bfs(0, 0);

     if(minimum == -1)
                 cout << "impossible" << endl;
           else
     {
                 cout << minimum << endl;
                 while(! st.empty())
     {
                       int tag = st.top();
        st.pop();
                       switch(tag)
        {
                            case 1 : cout << "FILL(1)" << endl; break;
                            case 2 : cout << "FILL(2)" << endl; break;
                            case 3 : cout << "DROP(1)" << endl; break;
                            case 4 : cout << "DROP(2)" << endl; break;
                            case 5 : cout << "POUR(1,2)" << endl; break;
                            case 6 : cout << "POUR(2,1)" << endl; break;
                            default : break;
        }
                 }
           }
      }
      return(0);
}
