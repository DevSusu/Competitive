// https://www.acmicpc.net/problem/1158
// by DevSusu

#include <stdio.h>

int K,N;

struct LL {
   struct Node {
      int val;
      Node *prev, *next;
      Node() : val(0), prev(0), next(0) {}
   };

   Node *head, *tail, *curr;
   Node *heap;
   int idx, size;

   LL(int ss) {
      idx=0;size=ss;
      heap = new Node[ss+3]; // pre-allocate
      head = &heap[idx++];
      tail = curr = head;
   };

   void erase() {
      printf("%d, ",curr->val);
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
      size--;
      // delete curr; // don't delete as its pre-allocated
   }
   void insert(int val) {
      // only inserts in tail
      Node* tmp = &heap[idx++];
      tmp->val = val;
      tmp->prev = tail;
      tail->next = tmp;
      tail = tmp;
   }
};

int main() {
   scanf("%d %d",&N,&K);

   LL ll(N);

   int i;
   for(i=1;i<=N;i++) {
      ll.insert(i);
   }
   ll.tail->next = ll.head->next;
   ll.head->next->prev = ll.tail;
   ll.curr = ll.head->next;

   printf("<");
   for(i=1;ll.size>1;i++) {
      if(i%K==0) {
         ll.erase();
      }
      ll.curr = ll.curr->next;
   }
   printf("%d>\n",ll.curr->val);
   return 0;
}
