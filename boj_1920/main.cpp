// https://www.acmicpc.net/problem/1920
// by DevSusu

#include <iostream>
#include <algorithm>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

bool bs(int*arr, int s, int e, int val) {
   int m;
   while(s!=e-1) {
      m = (s+e)/2;
      if( arr[m] > val ) e = m;
      else s = m;
   }
   return arr[s] == val;
}

int main() {

   fastio;

   int n, i, arr[100000+1];
   std::cin >> n;
   for(i=0;i<n;i++) {
      std::cin >> arr[i];
   }
   std::sort(arr, arr+n);

   int m, val;
   std::cin >> m;
   for(i=0;i<m;i++) {
      std::cin >> val;
      std::cout << bs(arr, 0, n, val) << '\n';
   }
   return 0;
}
