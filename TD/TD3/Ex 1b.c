int pgcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void simplifie1(int *n, int *p) {
    int pgcd = pgcd(*n, *p);
    *n /= pgcd;
    *p /= pgcd;
}

int simplifie2(int *n, int *p) {
    if (*p == 0) return 0;
    int pgcd = pgcd(*n, *p);
    *n /= pgcd;
    *p /= pgcd;
    return 1;
}
