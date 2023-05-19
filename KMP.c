#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPSArray(char* pattern, int m, int* lps) {
    int len = 0;  // Length of the previous longest prefix suffix
    int i;

    lps[0] = 0;  // lps[0] is always 0

    i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPMatch(char* text, char* pattern) {
    int m = strlen(pattern);
    int n = strlen(text);

    // Create lps[] that will hold the longest prefix suffix values for pattern
    int* lps = (int*)malloc(sizeof(int) * m);

    computeLPSArray(pattern, m, lps);

    int i = 0;  // Index for text[]
    int j = 0;  // Index for pattern[]

    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    free(lps);
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    KMPMatch(text, pattern);

    return 0;
}

