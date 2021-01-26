// https://www.acmicpc.net/problem/5588
// by DevSusu

#include <iostream>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

const int MOD = 1 << 14;
const int BIT = MOD - 1;
const int R_1 = 19421, R_2 = 50101;
const int P = 13;

int hash(int x,int y) {
   return ( (x&BIT)*R_1+(y&BIT)*R_2 )&BIT;
}

struct Node {
   int x,y,hash;
   Node* next;
} mm[201], nn[1001];

struct Hmap {
   Node map[MOD];
   Hmap() {}
   void insert(Node& a) {
      Node* curr = &map[a.hash];
      a.next = curr->next;
      curr->next = &a;
   }
   Node* get(int x, int y) {
      int h=hash(x,y);
      Node *curr = map[h].next;
      while(curr) {
         if( curr->x == x && curr->y == y ) break;
         curr = curr->next;
      }
      return curr;
   }
} hh;

int main() {

   fastio;

   int m,n,i;
   int x,y;
   std::cin >> m;
   for(i=0;i<m;i++) {
      std::cin >> x >> y;
      mm[i].x=x;mm[i].y=y;
   }

   std::cin >> n;
   for(i=0;i<n;i++) {
      std::cin >> x >> y;
      nn[i].x=x;nn[i].y=y;nn[i].hash=hash(x,y);
      hh.insert(nn[i]);
   }

   Node tmp;
   int dx, dy, j;
   for(i=0;i<n;i++) {
      dx = nn[i].x - mm[0].x;
      dy = nn[i].y - mm[0].y;
      for(j=1;j<m;j++) {
         if( !hh.get(mm[j].x+dx,mm[j].y+dy) ) break;
      }
      if(j==m) {
         std::cout << dx << ' ' << dy;
      }
   }
   return 0;
}
