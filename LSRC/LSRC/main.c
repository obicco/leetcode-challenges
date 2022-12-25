//
//  main.c
//  LSRC
//
//  Created by Oskar BICH on 28/10/22.
//

#include <stdio.h>
#include <stdlib.h>
int LSRC(char *s) {
    int16_t *bunch = malloc(95*sizeof(*bunch));
    int8_t max = 0, start = 0, i = 0;
    for(int16_t *x = bunch; x != bunch+95 ; x++) *x = -1;
    for (char *p = s; *p != '\0'; p++, i++) {
        start = (bunch[(*p)-32] != -1 && bunch[(*p)-32] >= start) ? bunch[(*p)-32] +1 : start;
        bunch[(*p)-32] = i;
        max = (max < i - start +1) ? i - start + 1 : max;
    }
    return max;
}

int main(int argc, const char * argv[]) {
    printf("%d", LSRC("hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"));
    return 0;
}

