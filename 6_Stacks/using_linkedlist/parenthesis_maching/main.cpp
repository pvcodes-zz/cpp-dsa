#include <iostream>

// Here I could also use stack class which I have created but the only issue is template
#include <stack>

int main() {
    int t;
    std::cin >> t;
    for (int a = 0; a < t; a++) {
        int n;
        std::cin >> n;
        std::stack<char> S;
        char t;
        bool isparenthesised = true;
        for (int b = 0; b < n; b++) {
            std::cin >> t;
            if (t == '(') {
                S.push(t);
            } else if (t == ')') {
                if (!(S.empty())) {
                    S.pop();
                } else {
                    isparenthesised = false;
                    break;
                }
            }
        }
        std::cout << std::boolalpha << (isparenthesised) << std::endl;
    }

    return 0;
}