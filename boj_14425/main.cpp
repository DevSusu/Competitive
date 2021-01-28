// https://www.acmicpc.net/problem/14425
// by DevSusu

#include <cstdio>

struct Trie {
   struct Node {
      bool is_end;
      Node* next[26];
   };

   Node* head;
   Node* heap;
   int idx;

   Trie(int n) {
      idx=0;
      heap = new Node[n*510];
      head = &heap[idx++];
   }

   void insert(char* in, int l) {
      Node* curr = head;
      int i;
      for(i=0;i<l;i++) {
         if(!curr->next[in[i]-'a']) {
            curr->next[in[i]-'a']=&heap[idx++];
         }
         curr=curr->next[in[i]-'a'];
      }
      curr->is_end=true;
   }

   bool exists(char* in, int l) {
      Node* curr = head;
      int i;
      for(i=0;i<l;i++) {
         if(!curr) return false;
         curr=curr->next[in[i]-'a'];
      }
      return curr && curr->is_end;
   }
};

int main() {

   int n,m,cnt=0,i;
   char in[502], cc;

   scanf("%d%d\n",&n,&m);
   Trie tr(n);
   while(n--) {
      for(i=0;;i++) {
         cc = getchar();
         if( cc < 'a' ) { break; }
         in[i]=cc;
      }
      in[i]='\0';
      tr.insert(in,i);
   }

   while(m--) {
      for(i=0;;i++) {
         cc = getchar();
         if( cc < 'a' ) { break; }
         in[i]=cc;
      }
      in[i]='\0';
      cnt += tr.exists(in,i);
   }

   printf("%d",cnt);
   return 0;
}
