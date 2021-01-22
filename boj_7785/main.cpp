// https://www.acmicpc.net/problem/7785
// by DevSusu

#include <iostream>

#define fastio                        \
   std::ios_base::sync_with_stdio(0); \
   std::cin.tie(NULL);                \
   std::cout.tie(NULL)

const int MOD = 1 << 21;
const int BIT = MOD-1;
const int R = 53;
const int P = 7;
int mul[5];
int conv[130];
int rev[55];

int hash(char* name) {
   int i, h=0;
   for(i=0;name[i];i++) {
      h += mul[i]*conv[name[i]];
   }
   return h;
}
void print_rev(int val) {
   char a[6],i;
   for(i=4;val;i--) {
      a[i] = rev[val%R];
      val /= R;
   }
   a[5]='\0';
   std::cout << a << '\n';
}
bool equals(char*a, char*b) {
   for(int i=0;a[i]||b[i];i++) {
      if(a[i]!=b[i]) return false;
   }
   return true;
}

struct Node {
   int hash;
   char *name;
   Node *next;
};

struct Hmap {
   int map[MOD];

   void insert(int val, int hash) {
      for(;map[hash];hash=(hash+P)&BIT);
      map[hash]=val;
   }
   void erase(int val, int hash) {
      for(;map[hash] != val;hash=(hash+P)&BIT);
      map[hash]=0;
   }
} hh;

int partition(int* arr, int s, int e) {
   int piv = arr[s];
   int i=s, j, tmp;
   for(j=s+1;j<e;j++) {
      if(arr[j]<=piv) {
         tmp=arr[i];arr[i]=arr[j];arr[j]=tmp;
         i++;
      }
   }
   tmp=arr[i];arr[i]=arr[s];arr[s]=tmp;
   return i;
}
void qsort(int* arr, int s, int e) {
   if( s<e ) {
      int p = partition(arr, s, e);
      qsort(arr, s, p);
      qsort(arr, p+1, e);
   }
}

int* sort_tmp;
void msort(int* arr, int s, int e) {
   if( s<e-1 ) {
      int l=s, m=(s+e)/2, r=m, i;
      msort(arr,l,m); msort(arr,m,e);
      for(i=s;i<e;i++) {
         if( r==e || (l < m && arr[l]<arr[r]) ) {
            sort_tmp[i]=arr[l++];
         }
         else {
            sort_tmp[i]=arr[r++];
         }
      }
      for(i=s;i<e;i++) arr[i]=sort_tmp[i];
   }
}

int main() {
   char l;
   mul[4]=1;
   for(l=3;l>=0;l--) mul[l]=mul[l+1]*R;
   for(l='a';l<='z';l++) { conv[l]=l-'a'+27; rev[conv[l]]=l; }
   for(l='A';l<='Z';l++) { conv[l]=l-'A'+1; rev[conv[l]]=l; }
   rev[0]='\0';

   fastio;

   int T,i,cnt=0;
   std::cin >> T;

   char** name = new char*[T];
   char cmd[7];

   for(i=0;i<T;i++) {
      name[i] = new char[7];

      std::cin >> name[i] >> cmd;
      int h=hash(name[i]);
      if(cmd[0]=='e') {
         hh.insert(h, h&BIT);
         cnt++;
      }
      else {
         hh.erase(h, h&BIT);
         cnt--;
      }
   }

   int* arr = new int[cnt];
   int idx=0;

   for(i=0;i<MOD;i++) {
      if (hh.map[i]) {
         arr[idx++] = hh.map[i];
      }
   }

   sort_tmp = new int[idx+1];
   msort(arr, 0, idx);

   for(i=idx-1;i>=0;i--) {
      print_rev(arr[i]);
   }
   return 0;
}
