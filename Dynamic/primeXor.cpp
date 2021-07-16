vector<int> primesOfInterest;
constexpr int maxXorNum = 8192;
constexpr int primeN    = 1000000007;

vector<int> primeInRange(int L, int R)
{
    int flag;
    vector<int> primes;
    // Traverse each number in the
    // interval with the help of for loop
    for (int i = L; i <= R; i++) {
 
        // Skip 0 and 1 as they are
        // neither prime nor composite
        if (i == 1 || i == 0)
            continue;
 
        // flag variable to tell
        // if i is prime or not
        flag = 1;
 
        // Iterate to check if i is prime
        // or not
        for (int j = 2; j <= i / 2; ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
 
        // flag = 1 means i is prime
        // and flag = 0 means i is not prime
        if (flag == 1)
            primes.push_back(i);
    }
    return primes;
}

int primeXor(vector<int> a) {
    
    int* countArray = new int[1001]; //4500-3500+1 unique elements
    
    for(int i = 0; i<1001; ++i){
        countArray[i] = 0;
    }
    
    for(auto num : a){
        ++countArray[num-3500];        
    }
    
    //Even number appearance of an element in a multiset does not change the xor sum.
    //Odd number appearance of an element in a multiset can be nulled
    
    vector<vector<long>> dp;
    
    for(int i = 0; i<1001; ++i){
        vector<long> v;
        for(int j = 0; j<8192; ++j){
            v.push_back(0);
        }
        dp.push_back(v);
    }
    
    for(int i = 0; i<1001; ++i){
        for(int j = 0; j<8192; ++j){
            dp[i][j] = 0;
        }
    } 
        
    dp[0][0]    = (countArray[0]+2)/2;
    dp[0][3500] = (countArray[0]+1)/2;
    

    for(int i = 1; i<1001; ++i){
        for(int j = 0; j<8192; ++j){
            dp[i][j] = (dp[i-1][j]*((countArray[i]+2)/2) + dp[i-1][j^(i+3500)]*((countArray[i]+1)/2)) % primeN;
        }        
    }
    
    
    long total = 0;
    
    for(auto prime : primesOfInterest){
        total = (total + dp[1000][prime]) % primeN;
    }
    
    return static_cast<int>(total);
}
