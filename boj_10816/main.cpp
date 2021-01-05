// https://www.acmicpc.net/problem/10816
// by DevSusu

#include <iostream>
#include <algorithm>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

int bs_lower(int *arr, int s, int e, int val)  {
   int m;
   while (s<e) {
      m = (s+e)/2;
      if (arr[m] < val)
         s = m+1;
      else
         e = m;
   }
   return s;
}
int bs_upper(int *arr, int s, int e, int val) {
   int m;
   while (s<e) {
      m = (s+e)/2;
      if (arr[m] > val)
         e = m;
      else
         s = m+1;
   }
   return s;
}

int main() {

   fastio;

   int n, i, m, val;
   int arr[500001];
   // int arr[101];
   std::cin >> n;
   for(i=0;i<n;i++) {
      std::cin >> arr[i];
   }

   std::sort(arr, arr+n);

   std::cin >> m;
   for(i=0;i<m;i++) {
      std::cin >> val;
      int u = bs_upper(arr, 0, n, val);
      int l = bs_lower(arr, 0, n, val);

      std::cout << u-l << ' ';
   }
   return 0;
}
