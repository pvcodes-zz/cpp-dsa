#include <iostream>
#include <stack>

bool isOperand(char a) {
    if (a == '+' || a == '-' || a == '*' || a == '/') {
        return 0;
    } else {
        return 1;
    }
}

int precedence(char a) {
    if (a == '+' || a == '-') {
        return 1;
    } else if (a == '*' || a == '/') {
        return 2;
    }
    return 0;
}

int main() {
    char A[] = "a+b*c-d/e";
    int a_len = 9;

    char res[a_len + 1];
    int res_curr{0};  // res current length counter
    std::stack<char> stk;

    int i = 0;
    while (A[i] != '\0') {
        if (isOperand(A[i])) {
            res[res_curr++] = A[i++];
        } else {
            if (stk.empty()) {
                stk.push(A[i++]);
            } else if (precedence(A[i]) <= precedence(stk.top())) {
                res[res_curr++] = stk.top();
                stk.pop();
                stk.push(A[i++]);
            } else {
                stk.push(A[i++]);
            }
        }
    }

    while (!(stk.empty())) {
        res[res_curr++] = stk.top();
        stk.pop();
    }

    for (auto &&i : res) {
        std::cout << i;
    }
    puts("");

    return 0;
}