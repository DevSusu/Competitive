#include<bits/stdc++.h>

#define MAX 1000001

int DP[MAX];

int solve(int n) {
    if(DP[n])
        return DP[n];

    int max = 0;
    for(int i=2;i<=n/3;i++) {
        if(n%i == 0) {
            max = std::max(max, solve(n/i - 1));
        }
    }

    DP[n] = max + 1;
    return DP[n];
}

int main() {

    int T, tc, n; scanf("%d", &T);

    for(tc=1;tc<=T;++tc) {
        scanf("%d", &n);

        int ans = 0;
        for(int i=3;i<=n/3;i++) {
            if(n%i == 0) {
                ans = std::max(ans, solve(n/i - 1));
            }
        }

        printf("Case #%d: %d\n", tc, ans + 1);
    }

    return 0;
}
