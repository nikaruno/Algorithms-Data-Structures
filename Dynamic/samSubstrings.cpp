constexpr long primeN = 1000000007;
int substrings(string s) {
    
    int n = s.size();
    
    long coef = 0;
    int c;
    long count = 0;
    int x = n;
    long jj = 1;
    for(int i = n; i>0; --i){
        coef = (coef + jj) % primeN; 
        c = s[i-1]-48;
        count = ((((coef*x) % primeN)*c % primeN) + count) % primeN;
        x--;
        jj   = ((jj*10) % primeN);
    }
    
    return count;
}
