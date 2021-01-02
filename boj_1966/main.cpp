// https://www.acmicpc.net/problem/1966
// by DevSusu

#include <iostream>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

int main() {

   fastio;

   int t;
   std::cin >> t;

   int n, m;
   int pri[11], arr[101], front = 0;
   int i, max = 0, ans = 0;

   for(;t>0;t--) {
      std::cin >> n >> m;

      // initialize
      max = 0; ans = 0; front = 0;
      for ( i=1;i<=9;i++) {
         pri[i] = 0;
      }

      for( i=0;i<n;i++ ) {
         std::cin >> arr[i];
         pri[arr[i]]++;
         if( max < arr[i] ) max = arr[i];
      }

      while(1) {
         // highest priority in queue
         if( arr[front] == max ) {
            ans++;

            if( front == m ) {
               std::cout << ans << '\n';
               break;
            }

            if( --pri[arr[front]] == 0 ) {
               for(;pri[max]==0;max--);
            }
         }

         // loop through queue
         front = (front+1)%n;
      }
   }
   return 0;
}
