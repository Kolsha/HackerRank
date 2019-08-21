#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
 * Difficulty Medium
 * Max Score 25
 * https://www.hackerrank.com/challenges/frequency-of-digits-1/
 */

int main() {
    int df['9' - '0' + 1];
    for (int i = 0; i <= 9; i++) {
        df[i] = 0;
    }

    char ch = getchar();
    while (ch != EOF) {
        if (ch >= '0' && ch <= '9') {
            df[ch - '0']++;
        }
        ch = getchar();
    }
    for (int i = 0; i <= 9; i++) {
        printf("%d ", df[i]);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
