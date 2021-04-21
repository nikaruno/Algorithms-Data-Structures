long sumXor(long n) {
    int count = 0;
    while(n>0){
        if ((n%2) == 0){
            count++;
        }
        n >>= 1;
    }
    return pow(2, count);
}
