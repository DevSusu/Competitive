#include <bits/stdc++.h>

int T, tc;
char S[10000+1];
char A[10000+1];

int main() {

    scanf("%d", &T);

    int cnt[26], len = 0;
    for(tc=1;tc<=T;++tc) {
        memset(S, 0, len);
        memset(A, 0, len);

        scanf("%s", S);

        for(int i=0;i<26;i++)
            cnt[i] = 0;

        len = strlen(S);
        int max = 0;
        for(int i=0;i<len;i++) {
            cnt[S[i]-'a']++;
            if( max < cnt[S[i]-'a'] ) {
                ++max;
            }
            A[i] = S[i];
        }

        if(max*2 > len) {
            printf("Case #%d: IMPOSSIBLE\n", tc);
        }
        else {
            for(int i=0;i<len-1;i++) {
                if(A[i] != S[i]) continue;

                int j;
                for(j=i+1;j<len;j++) {
                    if(A[j] != S[i]) {
                        std::swap(A[i], A[j]);
                        // printf("%s\n",A);
                        break;
                    }
                }

                if(j==len) {
                    for(j=i-1;j>=0;j--) {
                        if(A[j] != S[i] && A[i] != S[j]) {
                            std::swap(A[i], A[j]);
                            // printf("%s\n",A);
                            break;
                        }
                    }
                }
            }

            if(A[len-1] == S[len-1]) {
                for(int j=len-2;j>=0;j--) {
                    if(A[j] != S[len-1] && A[len-1] != S[j]) {
                        std::swap(A[j], A[len-1]);
                        break;
                    }
                }
            }

            printf("Case #%d: %s\n", tc, A);
        }
    }
    return 0;
}
