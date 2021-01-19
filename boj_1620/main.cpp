// https://www.acmicpc.net/problem/1620
// by DevSusu

#include <iostream>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

const int MOD = 1 << 16;
const int BIT = MOD - 1;
const int R = 127;

int hash(char* arr) {
   long long int mul = 1, res = 0;
   for(int i=0;arr[i];i++) {
      res = (res+mul*arr[i]) & BIT;
      mul = (mul*R) & BIT;
   }
   return res;
}
bool equals(char* a, char* b) {
   for(int i=0; a[i]||b[i] ;i++) {
      if( a[i] != b[i] ) return false;
   }
   return true;
}

struct Hmap {

   struct Node {
      char* name;
      int idx;
      Node *next;
      Node() {}
   };

   Node* map;
   Node* heap;
   int h_idx;

   Hmap() {
      map = new Node[MOD+1];
      heap = new Node[100000+1];
      h_idx=0;
   }

   void insert(char* arr, int idx) {
      int h = hash(arr);
      Node* curr = &map[h];
      Node* tmp = &heap[h_idx++];
      tmp->name = arr; tmp->idx = idx;
      tmp->next = curr->next;
      curr->next = tmp;
   }

   Node* get(char* arr) {
      int h = hash(arr);
      Node* curr = map[h].next;
      while(curr) {
         if(equals(curr->name, arr)) return curr;
         curr = curr->next;
      }
      return curr;
   }

};

int main() {

   fastio;

   int n, m;
   std::cin >> n >> m;
   int i,j;
   char in[100001][22], tmp[22];

   Hmap hh;

   for(i=0;i<n;i++) {
      std::cin >> in[i];
      hh.insert(in[i], i);
   }
   for(i=0;i<m;i++) {
      std::cin >> tmp;

      if('0' <= tmp[0] && tmp[0] <= '9') {
         for(j=0;tmp[j];j++) {}
         j--;
         int val=0;
         for(;j>=0;j--) {
            val = val*10 + (tmp[j]-'0');
         }
         std::cout << in[val-1] << '\n';
      }
      else {
         std::cout << hh.get(tmp)->idx+1 << '\n';
      }

      for(j=0;j<22;j++) tmp[j]='\0';
   }
   return 0;
}
