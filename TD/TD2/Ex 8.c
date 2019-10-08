int sum1(int n) {
    if (n < 0) return sum1(-n);
    return n < 10 ? n : n % 10 + sum1(n / 10);
}

int sum2(int n) {
    if (n < 0) return sum2(-n);
    if (n < 10)
        return n;
    else
        return n % 10 + sum2(n / 10);
}
