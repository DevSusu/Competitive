// https://www.acmicpc.net/problem/1406
// by DevSusu

#include <iostream>
#include <string.h>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

struct LL {
   struct Node {
      char val;
      Node *prev, *next;
      Node() {}
   };
   Node *head, *tail, *curr;
   Node *heap;
   int idx,size;

   LL(int l) {
      idx = size = 0;
      heap = new Node[l];
      head = &heap[idx++];
      tail = &heap[idx++];
      head->next = tail;
      tail->prev = head;
      curr = tail;
   };

   void insert(char val) {
      Node *tmp = &heap[idx++];
      tmp->val = val;
      tmp->next = curr;
      tmp->prev = curr->prev;
      curr->prev->next = tmp;
      curr->prev = tmp;
      size++;
   }
   void erase() {
      if(curr->prev != head) {
         curr->prev->prev->next = curr;
         curr->prev = curr->prev->prev;
         size--;
      }
   }
   void left() {
      if( curr->prev != head ) {
         curr = curr->prev;
      }
   }
   void right() {
      if( curr->next ) {
         curr = curr->next;
      }
   }

   void print() {
      curr = head->next;
      char *buf = new char[size+1];
      int b_idx = 0;
      while( curr ) {
         buf[b_idx++] = curr->val;
         curr = curr->next;
      }
      buf[b_idx]='\0';
      std::cout << buf;
   }
};

int main() {

   char in[100000+2];
   std::cin >> in;

   int n, l;
   char cmd, val;
   std::cin >> n;

   LL ll(n + strlen(in) + 2);

   for(l=0;in[l]!='\0';l++) {
      ll.insert(in[l]);
   }
   ll.curr = ll.tail;

   for(;n;n--) {
      std::cin >> cmd;
      if( cmd == 'P' ) {
         std::cin >> val;
         ll.insert(val);
      }
      else if( cmd == 'L' ) {
         ll.left();
      }
      else if (cmd == 'D') {
         ll.right();
      }
      else {
         ll.erase();
      }
   }

   ll.print();
   return 0;
}
