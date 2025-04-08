#include <stdio.h>
#include <string.h>

int main() {
    char s[1001];
    char n;  
    int palindrome = 1;
    for (int i = 0;i<=2;i++) {  
        scanf(" %c", &n);  
        s[i] = n;
    }

    for (int j = 0;j<=2;j++) {
        if (s[j] != s[2-j]) {
            palindrome = 0;
            break;
        }
    }

    if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2]) {
        palindrome = 1;
    }

    if (palindrome == 1) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return 0;
}
