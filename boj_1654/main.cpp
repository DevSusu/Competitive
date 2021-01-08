// https://www.acmicpc.net/problem/1654
// by DevSusu

#include <iostream>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

int k,n;
long long int arr[10000+1];

long long int eval(long long int val) {
   int i;
   long long int sum = 0;
   for(i=0;i<k;i++) {
      sum += arr[i]/val;
   }
   return sum;
}
void para() {
   long long int s=1,e=0x7fffffff, m; e++;
   long long int ev;
   while(s<e-1){
      m=(s+e)/2;
      ev=eval(m);
      if(ev<n) {
         e=m;
      }
      else {
         s=m;
      }
   }
   std::cout << s;
}

int main() {

   fastio;

   std::cin >> k >> n;

   int i;
   for(i=0;i<k;i++) {
      std::cin >> arr[i];
   }

   para();
   return 0;
}
