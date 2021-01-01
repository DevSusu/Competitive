// https://www.acmicpc.net/problem/18258
// by DevSusu

#include <iostream>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

struct Queue
{
   int front, back;
   int arr[2000001];
} q;

int main()
{
   fastio;

   q.front = 0;
   q.back = -1;

   int n, val;
   char cmd[16];
   std::cin >> n;

   for (; n > 0; n--)
   {
      std::cin >> cmd;

      switch (cmd[0])
      {
      case 'p':
         if (cmd[1] == 'u')
         {
            std::cin >> val;
            q.arr[++q.back] = val;
         }
         else
         {
            if (q.back < q.front)
               std::cout << "-1\n";
            else
               std::cout << q.arr[q.front++] << "\n";
         }

         break;

      case 's':
         std::cout << (q.back - q.front + 1) << "\n";
         break;

      case 'e':
         std::cout << (int)(q.back < q.front) << "\n";
         break;

      case 'f':
         if (q.back < q.front)
            std::cout << "-1\n";
         else
            std::cout << q.arr[q.front] << "\n";
         break;

      case 'b':
         if (q.back < q.front)
            std::cout << "-1\n";
         else
            std::cout << q.arr[q.back] << "\n";
         break;
      }
   }
   return 0;
}
