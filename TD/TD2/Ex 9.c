int pow1(int n, int p) {
    return p > 0 ? n * pow1(n, p - 1) : 1;
}

int pow2(int n, int p) {
    if (p > 0)
        return n * pow2(n, p - 1);
    else
        return 1;
}
