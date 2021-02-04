// https://www.acmicpc.net/problem/17612
// by DevSusu

#include <iostream>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

int n,k;
long long int res;

struct Node {
   int a,b,c;
}tmp1;
void swap(Node& x, Node& y) {
   int tmp;
   tmp=x.a;x.a=y.a;y.a=tmp;
   tmp=x.b;x.b=y.b;y.b=tmp;
   tmp=x.c;x.c=y.c;y.c=tmp;
};
bool smaller(Node& l, Node& r) {
   return (l.a<r.a) || (l.a==r.a&&l.b<r.b);
}
struct Heap {
   int idx;
   Node arr[100000*2+1];

   void insert(int a, int b, int c) {
      arr[++idx].a=a;arr[idx].b=b;arr[idx].c=c;

      int curr=idx, par;
      while(curr>1) {
         par=curr/2;
         if( smaller(arr[curr], arr[par]) ) {
            swap(arr[curr], arr[par]);
         }
         curr=par;
      }
   }
   void pop() {
      arr[1].a=arr[idx].a;
      arr[1].b=arr[idx].b;
      arr[1].c=arr[idx].c;
      arr[idx].a=arr[idx].b=arr[idx].c=0;
      idx--;

      int curr=1,l;
      while(curr*2<=idx) {
         l=curr*2;
         if( arr[l+1].c && smaller(arr[l+1],arr[l]) ) {
            l++;
         }
         if( arr[l].c && smaller(arr[l],arr[curr]) ) {
            swap(arr[l],arr[curr]);
            curr=l;
         }
         else { break; }
      }
   }
} in_heap, out_heap;

int main() {

   fastio;

   int i, id, w;
   std::cin >> n >> k; // max 100000, 100000

   Node* tmp;

   for(i=1;i<=k;i++) {
      in_heap.idx++;
      tmp=&in_heap.arr[in_heap.idx];
      tmp->a=0;tmp->b=i;tmp->c=1;
   }

   for(i=0;i<n;i++) {
      std::cin >> id >> w;

      tmp=&in_heap.arr[1];
      tmp1.a=tmp->a+w;tmp1.b=tmp->b;tmp1.c=tmp->c;

      in_heap.pop();
      in_heap.insert(tmp1.a, tmp1.b, tmp1.c);
      out_heap.insert(tmp1.a, k-tmp1.b, id);
   }

   for(i=1;i<=n;i++) {
      tmp=&out_heap.arr[1];
      res += i*tmp->c;
      std::cout << tmp->c << " came out from line " << k-tmp->b << " at " << tmp->a << '\n';
      out_heap.pop();
   }

   std::cout << res;
   return 0;
}

/*
10 3
123 4
21 5
34 14
56 1
45 7
723 5
55 7
13 5
910 10
73 3

7 3
1 2
2 4
3 3
4 1
5 3
6 1
7 2
*/
