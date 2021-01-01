// https://www.acmicpc.net/problem/10828
// by DevSusu

#include <iostream>

struct Stack
{
    int top;
    int arr[10000];
} st;

int main() {
    int n;
    char cmd[16];
    std::cin >> n;

    int val;

    st.top = -1;

    for( ;n>0;n-- ) {
        std::cin >> cmd;

        switch (cmd[0])
        {
        case 'p':
            if( cmd[1] == 'u' ) {
                std::cin >> val;
                st.arr[++st.top] = val;
            }
            else {
                if (st.top == -1)
                    std::cout << "-1\n";
                else
                    std::cout << st.arr[st.top--] << "\n";
            }

            break;

        case 's':
            std::cout << (st.top+1) << "\n";
            break;

        case 'e':
            std::cout << (int)(st.top == -1) << "\n";
            break;

        case 't':
            if (st.top == -1)
                std::cout << "-1\n";
            else
                std::cout << st.arr[st.top] << "\n";
            break;
        }
    }
    return 0;
}
