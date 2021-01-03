// https://www.acmicpc.net/problem/10866
// by DevSusu

#include <iostream>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

#define MAX_N 10000

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

   Deque () {
      Node* f = new Node;
      Node* b = new Node;

      f->next = b;
      b->prev = f;

      this->front = f;
      this->back = b;
      this->size = 0;
   }
   void f() {
      std::cout << this->front->next->val << '\n';
   }
   void b() {
      std::cout << this->back->prev->val << '\n';
   }
   void push_f(int val) {
      this->front->val = val;

      Node* tmp = new Node;
      tmp->next = this->front;
      this->front->prev = tmp;
      this->front = tmp;
      this->size++;
   }
   void push_b(int val) {
      this->back->val = val;

      Node *tmp = new Node;
      tmp->prev = this->back;
      this->back->next = tmp;
      this->back = tmp;
      this->size++;
   }
   void pop_f() {
      this->f();

      if( this->size ) {
         this->size--;
         this->front = this->front->next;
         this->front->val = -1;
         delete this->front->prev;
      }
   }
   void pop_b() {
      this->b();

      if( this->size ) {
         this->size--;
         this->back = this->back->prev;
         this->back->val = -1;
         delete this->back->next;
      }
   }
   void empty() {
      std::cout << (this->size == 0) << '\n';
   }
   void s() {
      std::cout << this->size << '\n';
   }
}dq;

int main() {

   fastio;

   int t;
   std::cin >> t;

   int val;
   char cmd[16];

   for(;t>0;t--) {
      std::cin >> cmd;

      switch (cmd[0]) {
      case 'p':
         if (cmd[1] == 'u') {
            std::cin >> val;
            if (cmd[5] == 'b') dq.push_b(val);
            else dq.push_f(val);
         }
         else {
            if (cmd[4] == 'b') dq.pop_b();
            else dq.pop_f();
         }
         break;

      case 's': dq.s(); break;
      case 'e': dq.empty(); break;
      case 'f': dq.f(); break;
      case 'b': dq.b(); break;
      }
   }

   return 0;
}
