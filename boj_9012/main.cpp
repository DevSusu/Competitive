// https://www.acmicpc.net/problem/9012
// by DevSusu

#include <stdio.h>

bool is_vps(char* in) {
   int top = -1;
   for( int i=0;in[i]!='\0';i++ ) {
      if( in[i] == '(' ) {
         top++;
      }
      else {
         if( top == -1 ) {
            return false;
         }
         top--;
      }
   }
   return top == -1;
}

int main() {
   int t;
   char in[50+2];
   scanf("%d", &t);

   for(;t>0;t--) {
      scanf("%s", in);

      if( is_vps(in) ) {
         printf("YES\n");
      }
      else {
         printf("NO\n");
      }
   }
   return 0;
}
