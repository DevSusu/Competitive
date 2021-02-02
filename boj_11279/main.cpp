// https://www.acmicpc.net/problem/11279
// by DevSusu

#include <iostream>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

void swap(int* arr, int x, int y) {
   int tmp;
   tmp=arr[x];arr[x]=arr[y];arr[y]=tmp;
}

struct Heap {
   int *h;
   int idx;

   Heap(int n) {
      h = new int[n*2+1];
      idx = 0;
   };

   void insert(int key) {
      h[++idx]=key;
      int curr=idx, next, tmp;
      while(curr>1) {
         next=curr/2;
         if(h[next]<key) {
            swap(h,next,curr);
         }
         curr=next;
      }
   }

   void pop() {
      std::cout<<h[1]<<'\n';
      if(idx==0)return;
      h[1]=h[idx];h[idx--]=0;

      int curr=1, next;
      while(curr<idx) {
         next=curr*2;
         if(h[next]<h[next+1]) {
            next++;
         }
         if(h[curr]<h[next]) {
            swap(h,next,curr);
            curr=next;
         }
         else break;
      }
   }
};

int main() {

   fastio;

   int n, cmd;
   std::cin>>n;
   Heap hh(n);

   while(n--) {
      std::cin>>cmd;
      if(cmd) {
         hh.insert(cmd);
      }
      else {
         hh.pop();
      }
   }

   return 0;
}
