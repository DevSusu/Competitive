// https://www.acmicpc.net/problem/5397
// by DevSusu

#include <iostream>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

struct LL
{
   struct Node
   {
      char val;
      Node *prev, *next;
      Node() {}
   };
   Node *head, *tail, *curr;
   Node *heap;
   int idx, size;

   LL() {
      idx = size = 0;
      heap = new Node[1000000+3];
      head = &heap[idx++];
      tail = &heap[idx++];
      head->next = tail;
      tail->prev = head;
      curr = tail;
   };

   void clear() {
      idx = size = 0;
      head = &heap[idx++];
      tail = &heap[idx++];
      head->next = tail;
      tail->prev = head;
      curr = tail;
   }

   void insert(char val)
   {
      Node *tmp = &heap[idx++];
      tmp->val = val;
      tmp->next = curr;
      tmp->prev = curr->prev;
      curr->prev->next = tmp;
      curr->prev = tmp;
      size++;
   }
   void erase()
   {
      if (curr->prev != head)
      {
         curr->prev->prev->next = curr;
         curr->prev = curr->prev->prev;
         size--;
      }
   }
   void left()
   {
      if (curr->prev != head)
      {
         curr = curr->prev;
      }
   }
   void right()
   {
      if (curr->next)
      {
         curr = curr->next;
      }
   }

   void print()
   {
      curr = head->next;
      char *buf = new char[size + 2];
      int b_idx = 0;
      while (curr)
      {
         buf[b_idx++] = curr->val;
         curr = curr->next;
      }
      buf[b_idx] = '\0';
      std::cout << buf << '\n';
   }
};

int main() {

   fastio;

   int T, i;
   char stroke[1000000+1];
   LL ll;

   std::cin >> T;
   for(;T>0;T--) {
      std::cin >> stroke;

      for(i=0;stroke[i]!='\0';i++) {
         switch (stroke[i])
         {
         case '<':
            ll.left();
            break;
         case '>':
            ll.right();
            break;
         case '-':
            ll.erase();
            break;

         default:
            ll.insert(stroke[i]);
         }
      }
      ll.print();
      ll.clear();
   }
   return 0;
}
