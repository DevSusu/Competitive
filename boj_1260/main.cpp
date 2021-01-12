// https://www.acmicpc.net/problem/1260
// by DevSusu

#include <iostream>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

int N,M,V;
bool map[1002][1002], v1[1002], v2[1002];
int q[10002], f=0, b=-1;
int s[10002], t=-1;

void bfs() {
   q[++b] = V;
   int i, stat;
   while(f<=b) {
      stat = q[f++];
      if(v1[stat]) continue;
      v1[stat] = true;
      std::cout << stat << ' ';
      for(i=1;i<=N;i++) {
         if(map[stat][i] && !v1[i]) {
            q[++b] = i;
         }
      }
   }
}

void dfs() {
   s[++t] = V;
   int i, stat;
   while(t>=0) {
      stat = s[t--];
      if(v2[stat]) continue;
      v2[stat] = true;
      std::cout << stat << ' ';
      for(i=N;i>=1;i--) {
         if(map[stat][i] && !v2[i]) {
            s[++t] = i;
         }
      }
   }
   std::cout << '\n';
}

int main() {

   fastio;

   std::cin >> N >> M >> V;
   int i, u,v;
   for(i=0;i<M;i++) {
      std::cin >> u >> v;
      map[u][v] = map[v][u] = true;
   }

   dfs();
   bfs();

   return 0;
}
