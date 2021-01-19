// https://www.acmicpc.net/problem/15829
// by DevSusu

#include <iostream>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

#define MOD 1234567891
#define R 31

int hash(char* arr) {
   long long int res = 0, mul = 1;

   for(int i=0;arr[i];i++) {
      res = (res+mul*(arr[i]-'a'+1)) % MOD;
      mul = (mul*R)%MOD;
   }

   return res;
}

int main() {

   fastio;

   int l, res = 0;
   std::cin >> l;
   char* a = new char[l+1];
   std::cin >> a;

   std::cout << hash(a);
   return 0;
}
