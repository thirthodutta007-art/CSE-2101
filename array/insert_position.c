#include <stdio.h>

int main() {
    int a[100], n, i, value, pos;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &value);
    scanf("%d", &pos);

    for(i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = value;
    n++;

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}