// https://www.acmicpc.net/problem/
// by DevSusu

#include <stdio.h>

struct Node
{
   int val;
   Node *prev, *next;
   Node() : val(-1) {}
};

class Deque
{
public:
   int size;
   Node *front, *back;

   Deque()
   {
      Node *f = new Node;
      Node *b = new Node;

      f->next = b;
      b->prev = f;

      this->front = f;
      this->back = b;
      this->size = 0;
   }
   void push_f(int val)
   {
      this->front->val = val;

      Node *tmp = new Node;
      tmp->next = this->front;
      this->front->prev = tmp;
      this->front = tmp;
      this->size++;
   }
   void push_b(int val)
   {
      this->back->val = val;

      Node *tmp = new Node;
      tmp->prev = this->back;
      this->back->next = tmp;
      this->back = tmp;
      this->size++;
   }
   void pop_f()
   {
      this->size--;
      this->front = this->front->next;
      this->front->val = -1;
      delete this->front->prev;
   }
   void pop_b()
   {
      this->size--;
      this->back = this->back->prev;
      this->back->val = -1;
      delete this->back->next;
   }
} dq;

int main() {

   int T;
   scanf("%d", &T);

   char p[100000+1];
   int n, val, i;
   bool rev;

   for(;T>0;T--) {

      scanf("%s", p);
      scanf("%d\n", &n);

      if( n ) {
         scanf("[%d", &val);
         dq.push_b(val);

         for (i = 1; i < n; i++) {
            scanf(",%d", &val);
            dq.push_b(val);
         }
         scanf("]");
      }
      else {
         scanf("[]");
      }

      rev = false;
      for(i=0;p[i]!='\0';i++) {
         if( p[i] == 'R' ) {
            rev = !rev;
         }
         else {
            if( dq.size ) {
               rev ? dq.pop_b() : dq.pop_f();
            }
            else {
               printf("error\n");
               break;
            }
         }
      }

      if( p[i] == '\0' ) {
         Node *idx;
         printf("[");
         if( dq.size ) {
            if (!rev) {
               idx = dq.front->next;
               printf("%d", idx->val);
               do {
                  idx = idx->next;
                  if (idx == dq.back)
                     break;
                  printf(",%d", idx->val);
               } while (true);
            }
            else {
               idx = dq.back->prev;
               printf("%d", idx->val);
               do {
                  idx = idx->prev;
                  if (idx == dq.front)
                     break;
                  printf(",%d", idx->val);
               } while (true);
            }
         }
         printf("]\n");
      }

      while(dq.size>0) { dq.pop_f(); }

   }
   return 0;
}
