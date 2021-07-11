#include <iostream>

int len(char a[]) {
    int i = 0;
    for (i; a[i] != '\0'; i++) {
    }
    return i;
}

void changeCase(char A[]) {
    for (int i = 0; A[i] != '\0'; i++) {
        if (A[i] >= 65 && A[i] <= 90) {
            A[i] += 32;  // 32 is the difference btw 'A' to 'a'
        } else if ((A[i] >= 97) && A[i] <= 122) {
            A[i] -= 32;  // 32 is the difference btw 'A' to 'a'
        }
    }
}

void toLower(char A[]) {
    for (int i = 0; A[i] != '\0'; i++) {
        if (A[i] >= 65 && A[i] <= 90) {
            A[i] += 32;  // 32 is the difference btw 'A' to 'a'}
        }
    }
}

int* numOfVowelnConsonent(char A[]) {
    int* p = new int[2];
    toLower(A);
    char V[] = "aeiou";

    for (int i = 0; A[i] != '\0'; i++) {
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u')
            p[0]++;
        else if ((A[i] >= 97 && A[i] <= 122) || (A[i] >= 65 && A[i] <= 90))
            p[1]++;
    }

    return p;
}

int numOfWords(char A[]) {
    int words{1};
    for (int i = 0; A[i] != '\0'; i++) {
        if (A[i] == ' ' && A[i - 1] != ' ') words++;
    }
    return words;
}

void reverse(char A[]) {
    int i{0};
    int j = len(A) - 1;
    int x = (j + 1) / 2;

    for (i, j; i < x; i++, j--) {
        char tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
}

bool isPalindrome(char A[]) {
    int i{0};
    int j = len(A) - 1;
    int x = (j + 1) / 2;

    for (i, j; i < x; i++, j--)
        if (A[i] != A[j]) return 0;
    return 1;
}

bool isEqual(char A[], char B[]) {
    for (int i = 0; A[i] != '\0'; i++)
        if (A[i] != B[i]) return 0;
    return 1;
}

int nOfDuplicate(char A[]) {
    int r;
    return r;
}
bool isAnagram(char A[], char B[]) {
    // It's Time Complexity is O(n)
    int H[26] = {0};
    for (int i = 0; A[i] != '\0'; i++) {
        H[A[i] - 97] += 1;
    }
    for (int i = 0; A[i] != '\0'; i++) {
        H[A[i] - 97] -= 1;
        if (H[A[i] - 97] < 0) {
            return 0;
        }
    }

    return 1;
}

void permuationOnString() {}

int main() {
    char p[] = "pranjallajnarp";
    char q[] = "pranjallajnarp";
    char a[] = "pran";
    char m[] = "medical";
    char d[] = "decimal";

    // std::cout << len(p) << std::endl;
    // reverse(p);
    // std::cout << p << std::endl;
    // std::cout << std::boolalpha << isPalindrome(p) << std::endl;
    // std::cout << std::boolalpha << isEqual(p, q) << std::endl;
    // std::cout << std::boolalpha << isEqual(p, a) << std::endl;
    std::cout << std::boolalpha << isAnagram(d, m) << std::endl;
    return 0;
}

int A[] = {1, 5, 8, 14, 19, 25};

// 0142541992 814 815