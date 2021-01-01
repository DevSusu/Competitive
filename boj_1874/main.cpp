// https://www.acmicpc.net/problem/1874
// by DevSusu

#include <stdio.h>

#define MAX_N 100000
char buf[MAX_N * 4 + 4];
int st[MAX_N + 1], top = -1, curr = 0, idx = -1;

int push() {
   st[++top] = ++curr;
   buf[++idx] = '+';
   buf[++idx] = '\n';
   return 0;
}
int pop() {
   top--;
   buf[++idx] = '-';
   buf[++idx] = '\n';
   return 0;
}

int main(int argc, char** argv) {

   int n, m;
   scanf("%d",&n);

   for(;n>0;n--) {
      scanf("%d",&m);

      if( m > curr ) {
         // m is not yet pushed to stack
         while(curr<m) {
            push();
         }
         pop();
      }
      else {
         // m is already pushed to stack
         if( top >= 0 && st[top] == m ) {
            pop();
         }
         else {
            printf("NO");
            return 0;
         }
      }
   }

   printf("%s", buf);
   return 0;
}
