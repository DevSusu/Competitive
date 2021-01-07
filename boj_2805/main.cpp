// https://www.acmicpc.net/problem/2805
// by DevSusu

#include <iostream>
#include <algorithm>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

#define MAX_N 1000000

long long int d[MAX_N + 2];
long long int n, m, arr[MAX_N + 1];

int bs_lower(int val) {
   int l=0,r=n, mid;
   while(l<r) {
      mid = (l+r)/2;
      if( arr[mid] < val ) {
         l = mid+1;
      }
      else {
         r = mid;
      }
   }
   return l;
}
long long int eval(int h) {
   int idx = bs_lower(h);
   return (d[n]-d[idx])-(n-idx)*h;
}
void para() {
   int s=0,e=1e9+1;
   int mid;
   long long int ev;
   while(s<e-1) {
      mid=(s+e)/2;
      // mid가 작아지면 eval은 커진다.
      // eval이 m과 같다면 그 중에서 mid는 큰 것을 출력한다
      ev = eval(mid);
      if(ev<m) {
         e = mid;
      }
      else {
         s = mid;
      }
   }
   std::cout << s;
}

int main() {
   fastio;

   std::cin >> n >> m;
   int i;
   for(i=0;i<n;i++) {
      std::cin >> arr[i];
   }

   std::sort(arr, arr+n);

   d[0] = 0;
   d[1] = arr[0];
   for(i=2;i<=n;i++){
      d[i] = d[i-1]+arr[i-1];
   }

   para();
   return 0;
}

/*
10 2000000000
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
*/
