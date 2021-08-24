#include <bits/stdc++.h>

int T, tc;

// how many cuts you need for R * C with K len cut
int inner(int R, int C, int K) {
    if(R == 1 && C == 1) return 0;

    int ans = 0;
    if(R >= C) {
        int half = R / 2;
        ans += (C-1)/K+1;

        if(R % 2 == 0) {
            ans += 2 * inner(half, C, K);
        }
        else {
            ans += inner(half, C, K);
            ans += inner(R - half, C, K);
        }
    }
    else {
        int half = C / 2;
        ans += (R-1)/K+1;

        if(C % 2 == 0) {
            ans += 2 * inner(R, half, K);
        }
        else {
            ans += inner(R, half, K);
            ans += inner(R, C - half, K);
        }
    }
    return ans;
}

int main () {

    scanf("%d", &T);

    int R, C, K;
    int x1, y1, x2, y2;
    int ans;

    for(tc=1;tc<=T;tc++) {
        scanf("%d %d %d", &R, &C, &K);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        int w = (y2 - y1 + 1), h = (x2 - x1 + 1);

        if(K==1) {
            ans = (w+1)*h + w*(h+1);
            ans += std::min( std::min(x1-1, R-x2), std::min(y1-1, C-y2) );

            if(x1-1 == 0) {
                ans -= w;
            }
            if(R-x2 == 0) {
                ans -= w;
            }
            if(y1-1 == 0){
                ans -= h;
            }
            if(C-y2 == 0) {
                ans -= h;
            }
        }
        else {
            int W = (w-1)/K+1, H = (h-1)/K+1;
            int HH1 = (w+x1-1-1)/K+1, HH2 = (w+R-x2-1)/K+1;
            int WW1 = (h+y1-1-1)/K+1, WW2 = (h+C-y2-1)/K+1;

            ans = std::min(
                std::min(
                    WW1 + W + 2*H,
                    WW2 + W + 2*H
                ),
                std::min(
                    HH1 + W*2 + H,
                    HH2 + W*2 + H
                )
            );

            if(x1-1 == 0) {
                ans -= W;
            }
            if(R-x2 == 0) {
                ans -= W;
            }
            if(y1-1 == 0){
                ans -= H;
            }
            if(C-y2 == 0) {
                ans -= H;
            }

            int tmp = inner(h, w, K);
            // printf("inner R:%d, C:%d = %d\n", h, w, tmp);

            ans += tmp;
        }

        printf("Case #%d: %d\n", tc, ans);
    }
    return 0;
}
