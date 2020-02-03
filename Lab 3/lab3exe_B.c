/* lab3exe_B.c
 * ENSF 337 Fall 2018, Lab 3 Exercise B
 */

#include <stdio.h>
#include <string.h>

int foo(const char *s1, int ch, char* s2);
void bar(const char *x, char *y, char c, int n, int *m);

int main(void)
{
    const char* str1 = "Banana Bread";
    char str2[7];
    unsigned long int n1 = strlen(str1);
    int n2 = sizeof(str1);

    printf("str1 is %d bytes, and its length is %lu\n", n2, n1);
    int c = 'a';
    printf("%s\n", str2);
    foo(str1, c, str2);
    printf("%lu     %d\n", n1, n2);

    int size_y = sizeof(str2) / sizeof(str2[0]);

    for(int i = 0; i<size_y; i++) {
      printf("y1 is %c\n", str2[i]);
    }
    return 0;
}

int foo(const char *s1, int ch, char* s2)
{
    int i, j;
    for(i = 0, j=0; s1[i]; i++) {
        bar(s1, s2, ch, i, &j );
    }
    // point two
    return 0;
}

void bar(const char *x, char *y, char c, int n, int *m) {
    if(x[n] != c) {
        y[*m] = x[n];

        printf("    %dy is %c\n", (sizeof(y) / sizeof(y[0])), y[*m]);  //str2 Bnn bred
        (*m)++;

        // point one - when program reaches this point for the first time
    }
}
