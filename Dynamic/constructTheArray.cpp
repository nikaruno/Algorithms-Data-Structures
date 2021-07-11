constexpr int primeN  = 1000000007;
constexpr int primeN2 = 1000000005;

long exponentiation(long base, long  exp)
{
    if (exp == 0)
        return 1;
    
    if (exp == 1)
        return base % primeN;
    
    long t = exponentiation(base, exp/2);
    t = (t * t) % primeN;
    
    if (exp % 2 == 0)
        return t;
    
    return ((base % primeN) * t) % primeN;
}

long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    n = n - 2;
    
    if (n == 0){
        return 1;
    }
    
    long sum = 1LL;
    for(int i = 0; i<n; ++i){
        sum = (sum * (k-1)) % primeN;
    }
    
    long temp;
    long inv = exponentiation(k, primeN2);
    if (n%2 == 0){
        temp = ((sum-1)*inv)%primeN;
        if (x == 1){
            return (temp*(k-1))%primeN;
        }
        else{
            return (temp*(k-1)+1)%primeN;
        }
    }
    else{
        temp = ((sum+1)*inv)%primeN;
        if (x == 1){
            return (temp*(k-1))%primeN;
        }
        else{
            return (temp*(k-1)-1)%primeN;
        }        
    }
    
    return 0;
}
