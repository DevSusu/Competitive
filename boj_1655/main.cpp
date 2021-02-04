// https://www.acmicpc.net/problem/1655
// by DevSusu

#include <iostream>

int heap1[100000*2+1], idx1; // max heap
int heap2[100000*2+1], idx2; // min heap

void swap(int* arr, int x, int y) {
   int tmp;
   tmp=arr[x];arr[x]=arr[y];arr[y]=tmp;
}

void insert1(int val) {
   heap1[++idx1]=val;
   int curr=idx1, parent;
   while(curr>1) {
      parent=curr/2;
      if(heap1[parent]<heap1[curr]) {
         swap(heap1, parent, curr);
      }
      curr=parent;
   }
}
void insert2(int val) {
   heap2[++idx2]=val;
   int curr=idx2, parent;
   while(curr>1) {
      parent=curr/2;
      if(heap2[parent]>heap2[curr]) {
         swap(heap2, parent, curr);
      }
      curr=parent;
   }
}
int pop1() {
   int res=heap1[1];
   heap1[1]=heap1[idx1]; heap1[idx1--]=-11000;

   if(idx1==0) return res;

   int curr=1, left;
   while(curr*2<=idx1) {
      left=curr*2;
      if(heap1[left]<heap1[left+1]) {
         left++;
      }
      if(heap1[curr]<heap1[left]) {
         swap(heap1, curr, left);
      }
      curr=left;
   }
   return res;
}
int pop2() {
   int res=heap2[1];
   heap2[1]=heap2[idx2]; heap2[idx2--]=11000;

   if(idx2==0) return res;

   int curr=1, left;
   while(curr*2<=idx2) {
      left=curr*2;
      if(heap2[left]>heap2[left+1]) {
         left++;
      }
      if(heap2[curr]>heap2[left]) {
         swap(heap2, curr, left);
      }
      curr=left;
   }
   return res;
}

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

int main() {

   fastio;

   int n,i,val,mid=0;
   std::cin >> n;
   for(i=0;i<=n*2;i++) { heap1[i]=-11000;heap2[i]=11000; }
   for(i=0;i<n;i++) {
      std::cin >> val;

      if( val < mid ) {
         insert1(val);
      }
      else {
         insert2(val);
      }

      if( idx1 < idx2 ) {
         insert1(pop2());
      }
      else if( idx1 > idx2+1 ) {
         insert2(pop1());
      }

      mid=heap1[1];
      std::cout << mid << '\n';
   }
   return 0;
}
