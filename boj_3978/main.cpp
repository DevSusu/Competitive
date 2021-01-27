// https://www.acmicpc.net/problem/3978
// by DevSusu

#include <iostream>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

const int MOD = 1 << 20;
const int BIT = MOD - 1;

int N,M,K;
char in[10002], perm[101];
int rab[10002], mul[101];
bool gen_str(char* a, int val, int l);
bool ans(int l);
bool equals(char* a, char* b, int l);
void para();
void rabin(int l);

int main() {
   fastio;

   int T,i,j;
   std::cin >> T;
   for(;T>0;T--) {
      std::cin >> N >> M >> K >> in;

      // K진수 미리 계산
      mul[0]=1;
      for(i=1;i<M;i++) { mul[i]=(mul[i-1]*K)&BIT; }

      // para 필요 없음. 그냥 M에서는 무조건 답이 있으므로
      ans(M);
      std::cout << perm << '\n';
   }
   return 0;
}

bool equals(char* a, char* b, int l) {
   while(l--) {
      if(a[l]!=b[l]) return false;
   }
   return true;
}
bool gen_str(char* a, int val, int l) {
   a[l]='\0';
   for(int i=0;i<l;i++) {
      a[i] = val%K+'a';
      val /= K;
   }
   if(val) return false;
   return true;
}
bool ans(int l) {
   int val=0, i;
   rabin(l);
   while( gen_str(perm, val, l) ) {
      for(i=0;i<=N-l;i++) {
         if(rab[i]==val && equals(in+i,perm,l)) {
            break;
         }
      }
      if(i>N-l) { return true; }
      val++;
   }
   return false;
}
void rabin(int l) {
   int i,sum=0,mm=mul[l-1],j;
   for(i=0;i<l;i++) {
      sum=(sum+mul[i]*(in[i]-'a'))&BIT;
   }
   rab[0]=sum;
   for(i=0;i<N-l;i++) {
      rab[i+1]=( (rab[i]-in[i]+'a')/K + (in[i+l]-'a')*mm )&BIT;
   }
}
