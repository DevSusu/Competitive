// https://www.acmicpc.net/problem/17219
// by DevSusu

#include <iostream>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

#define N 1000000

const int MOD = 1 << 16;
const int BIT = MOD-1;
const int R = 127;

int hash(char* dns) {
   int h=0, mul=1;
   for(int i=0;dns[i];i++) {
      h = (h+dns[i]*mul) & BIT;
      mul = (mul*R) & BIT;
   }
   return h;
}
bool equals(char*a, char*b) {
   for(int i=0;a[i]||b[i];i++){
      if(a[i]!=b[i]) return false;
   }
   return true;
}

struct Hmap {
   struct Node {
      Node* next;
      char* dns, *pass;
   };

   Node map[MOD];
   Node* heap;
   int idx;

   Hmap() {
      heap = new Node[N+1];
      idx = 0;
   }

   void insert(char* dns, char* pass) {
      Node* curr = &map[hash(dns)];
      Node* tmp = &heap[idx++];
      tmp->dns=dns;tmp->pass=pass;
      tmp->next=curr->next;curr->next=tmp;
   }

   Node* get(char* dns) {
      Node *curr = map[hash(dns)].next;
      while(curr) {
         if(equals(curr->dns,dns)) return curr;
         curr = curr->next;
      }
      return curr;
   }
};

char dns[N][22];
char pass[N][22];
char tmp[N][22];

int main() {

   fastio;

   int n,m,i,j;

   std::cin >> n >> m;

   // char **dns = new char*[n];
   // char **pass = new char*[n];
   // char **tmp = new char*[n];
   // for(i=0;i<n;i++) {
   //    dns[i] = new char[22];
   //    pass[i] = new char[22];
   //    tmp[i] = new char[22];
   // }

   Hmap hh;

   for(i=0;i<n;i++) {
      std::cin >> dns[i] >> pass[i];
      hh.insert(dns[i], pass[i]);
   }

   for(i=0;i<m;i++) {
      std::cin >> tmp[i];
      std::cout << hh.get(tmp[i])->pass << '\n';
   }

   return 0;
}
