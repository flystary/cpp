#include <stdio.h>

int main() {
    int a[5] = {1, 2, 4, 6, 7};

    // for(int i:a ) {
    //
    int len = sizeof(a)/sizeof(a[0]);

    for(int i = 0; i < len; i++) {

        printf("%d\n", a[i]);
    }

    return 0;
}
