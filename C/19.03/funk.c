#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int pn_str_len(const char *str) {
    if (str == NULL) {
        return -1;
    }
    return strlen(str);
}

bool pn_str_cmp(const char *a, const char *b) {
    if (a == NULL || b == NULL) return false;
    int i = 0;
    while (a[i] != 0) {
        if (b[i] == 0) return false;
        if (a[i] != b[i]) return false;
        i++;
    }
    if (a[i] == b[i]) return true;
    return false;
}

void pn_str_capitalize(char *str) {
    if (str == NULL) {
        return;
    }
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 32;
    }
}

void pn_str_trim(char *str) {
    int i = pn_str_len(str) - 1;
    for (i; str[i] == ' '; i--) {
        str[i] = 0;
    }
    int j = 0;
    for (j; str[j] == ' '; j++);
    int k = j;
    for (k; str[k] != 0; k++) {
        str[k-j] = str[k];
    }
    str[k-j] = '\0';
}

void pn_str_rev(char *str) {
    if (str==NULL) return -1;
    int len = pn_str_len (str);
    for (int i = 0; i < pn_str_len(str) /2; i++) {
        char tmp = str[i];
        str[i] = str[len-1 - i];
        str[len-1 - i] = tmp;
    }
}














int main() {
    const char *str = "   Hello, world!  ";
    printf("Długość: %d\n", pn_str_len(str));
    char *a = "aaa";
    char *b = "bbb";
    printf("%d\n", pn_str_cmp(a,b));
    printf("pn_str_capitalize: ");
    char wyrazek[] = "wyraz";
    pn_str_capitalize(wyrazek);
    printf("%s\n", wyrazek);
    printf("pn_str_trim:  |");
    char testStr2[] = " te st ";
    pn_str_trim(testStr2);
    printf("%s", testStr2);
    printf("|\n");
}
