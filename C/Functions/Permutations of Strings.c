#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Difficulty Medium
 * Max Score 40
 * https://www.hackerrank.com/challenges/permutations-of-strings/
 */

void swap(char **x, char **y) {
    char *temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int next_permutation(int n, char **s) {
    /**
    * Complete this method
    * Return 0 when there is no next permutation and 1 otherwise
    * Modify array s to its next permutation
    * https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
    */
    int k = -1, l = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (strcmp(s[i], s[i + 1]) < 0) {
            k = i;
            break;
        }
    }
    if (k < 0) return 0;

    for (int i = n - 1; i > k; i--) {
        if (strcmp(s[k], s[i]) < 0) {
            l = i;
            break;
        }
    }
    if (l < 0) return 0;
    swap(&s[k], &s[l]);

    for (int low = k + 1, high = n - 1; low < high; low++, high--) {
        swap(&s[low], &s[high]);
    }

    return 1;
}

int main() {
    char **s;
    int n;
    scanf("%d", &n);
    s = calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++) {
        s[i] = calloc(11, sizeof(char));
        scanf("%s", s[i]);
    }
    do {
        for (int i = 0; i < n; i++)
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
    } while (next_permutation(n, s));
    for (int i = 0; i < n; i++)
        free(s[i]);
    free(s);
    return 0;
}