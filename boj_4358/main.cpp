// https://www.acmicpc.net/problem/4358
// by DevSusu

#include <cstdio>

int total;

struct Node {
   int cnt;
   Node* next[95];
   Node() { cnt=0; }
};

struct Trie {
   Node* head;
   Node* heap;
   int idx;

   Trie() {
      heap = new Node[31*10000];
      idx=0;
      head = &heap[idx++];
   }

   bool insert(char* name) {
      int i,n_i;
      Node* curr = head;
      for(i=0;name[i]&&name[i]!='\n';i++) {
         n_i=name[i]-' ';
         if(!curr->next[n_i]) {
            curr->next[n_i]=&heap[idx++];
         }
         curr=curr->next[n_i];
      }
      name[i]='\0';
      curr->cnt++;
      return curr->cnt==1;
   }
} tr;

void print(char* out, int idx, Node* curr) {
   int i;
   if(curr->cnt) {
      out[idx]=0;
      printf("%s %.4f\n",out, (double)(curr->cnt*100)/total);
   }
   for(i=0;i<95;i++) {
      if(curr->next[i]) {
         out[idx]=i+' ';
         print(out, idx+1, curr->next[i]);
      }
   }
}

int main() {

   int i;
   // 126 - 32 = 94
   // for(i=' ';i<='~';i++) { conv[i]=i-' '; toc[conv[i]]=i; }

   char name[32]; i=0;
   while(fgets(name, 32, stdin) != NULL) {
      total++;
      tr.insert(name);
      i++;
   }

   print(name, 0, tr.head);
   return 0;
}
