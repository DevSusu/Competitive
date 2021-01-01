// https://www.acmicpc.net/problem/4949
// by DevSusu

#include <stdio.h>
#include <string.h>

char map[100];

bool is_balanced(char* a) {
   char st[102];
   int top = -1, len = strlen(a);

   for( int i=0;i<len;i++ ) {
      if( a[i] == '(' || a[i] == '[' ) {
         st[++top] = a[i];
      }
      else if (a[i] == ')' || a[i] == ']') {
         if (top == -1 || map[a[i]] != st[top])
            return false;
         top--;
      }
   }

   return (top == -1);
}

int main() {
   map[')'] = '(';
   map[']'] = '[';

   char in[103];

   while(true) {
      fgets(in, 102, stdin);

      if( in[0] == '.' ) {
         break;
      }

      if( is_balanced(in) ) {
         printf("yes\n");
      }
      else {
         printf("no\n");
      }
   }
   return 0;
}
