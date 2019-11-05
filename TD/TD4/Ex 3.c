#include <stdio.h>

int length(char s[]) {
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void copy(char dest[], char origin[]) {
    int i = 0;
    while (origin[i] != '\0') {
        dest[i] = origin[i];
        i++;
    }
}

void concatenate(char dest[], char origin[]) {
    int i = length(dest), j = 0;
    while (origin[i] != '\0') {
        dest[i] = origin[i];
        i++;
        j++;
    }
    dest[i] = '\0';
}

int compare(char one[], char two[]) {
    int i = 0;
    while (one[i] != '\0' && two[i] != '\0' && one[i] != two[i])
        i++;
    return one[i] - two[i];
}

int readLine(char s[], int size) {
    int i = 0;
    char c = 0;
    while (i < size - 1 && c != '\n') {
        scanf("%c", &c);
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}
