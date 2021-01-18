// https://www.acmicpc.net/problem/2983
// by DevSusu

#include <iostream>
#include <algorithm>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

int N, K;
char jumps[100000+2];
bool visited[100001];
int map1[100001], map2[100001];

struct leaf {
   int x, y, idx, val;
   leaf *prev, *next;
   leaf() {};
};

bool comp(leaf& a, leaf& b) {
   if(a.val<b.val) return true;
   else if(a.val>b.val) return false;

   return a.x<b.x;
};

int main() {

   fastio;

   std::cin >> N >> K;
   std::cin >> jumps;

   leaf* lad = new leaf[N];
   leaf* lbc = new leaf[N];

   int i, a, b;
   for(i=0;i<N;i++) {
      std::cin >> a >> b;
      lad[i].x = a;
      lad[i].y = b;
      lad[i].idx = i;
      lad[i].val = a - b;

      lbc[i].x = a;
      lbc[i].y = b;
      lbc[i].idx = i;
      lbc[i].val = a + b;
   }

   std::sort(lad, lad+N, comp);
   std::sort(lbc, lbc+N, comp);

   for(i=0;i<N;i++) {
      lad[i].next = &lad[i+1];
      map1[lad[i].idx]=i;
      map2[lbc[i].idx]=i;
   }

   for(i=0;i<N-1;i++) {
      lad[i].next = &lad[i+1];
      lad[N-1-i].prev = &lad[N-2-i];
      lbc[i].next = &lbc[i+1];
      lbc[N-1-i].prev = &lbc[N-2-i];
   }

   int stat=0;
   int idx1, idx2;
   for (i=0;jumps[i]!='\0';i++) {
      visited[stat] = true;

      idx1=map1[stat];
      idx2=map2[stat];
      if(lad[idx1].next) lad[idx1].next->prev = lad[idx1].prev;
      if(lad[idx1].prev) lad[idx1].prev->next = lad[idx1].next;
      if(lbc[idx2].next) lbc[idx2].next->prev = lbc[idx2].prev;
      if(lbc[idx2].prev) lbc[idx2].prev->next = lbc[idx2].next;

      leaf* next;
      switch (jumps[i])
      {
      case 'A':
         next=lad[idx1].next;
         while(next && next->val==lad[idx1].val) {
            if(!visited[next->idx]) {
               stat=next->idx;
               break;
            }
            next=next->next;
         }
         break;
      case 'D':
         next=lad[idx1].prev;
         while(next && next->val==lad[idx1].val) {
            if(!visited[next->idx]) {
               stat=next->idx;
               break;
            }
            next=next->prev;
         }
         break;
      case 'B':
         next=lbc[idx2].next;
         while(next && next->val == lbc[idx2].val) {
            if(!visited[next->idx]) {
               stat=next->idx;
               break;
            }
            next=next->next;
         }
         break;
      case 'C':
         next=lbc[idx2].prev;
         while(next && next->val==lbc[idx2].val) {
            if(!visited[next->idx]) {
               stat=next->idx;
               break;
            }
            next=next->prev;
         }
         break;
      }
   }

   stat = map1[stat];
   std::cout << lad[stat].x << ' ' << lad[stat].y << '\n';

   return 0;
}
