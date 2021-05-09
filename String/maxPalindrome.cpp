string sen;
vector<vector<int>> freq;
vector<long long> fact;
vector<long long> inv;
constexpr int primeN  = 1000000007;
constexpr int primeN2 = 1000000005;

/*
 * Complete the 'initialize' function below.
 *
 * The function accepts STRING s as parameter.
 */

long long exponentiation(long long base,
                        long long exp)
{
    if (exp == 0)
        return 1;
  
    if (exp == 1)
        return base % primeN;
    
    long int t = exponentiation(base, exp/2);
    t = (t * t) % primeN;
    
    if (exp % 2 == 0)
        return t;
    
    return ((base % primeN) * t) % primeN;
}

void initialize(string s) {
    // This function is called once before all queries.
    sen = s;
    int n = s.size();
    
    for(int i = 0; i<26; ++i){ 
        vector<int> v;
        for(int j = 0; j<=n; ++j){
            v.push_back(0);
        }
        freq.push_back(v);
    }
    
    freq[sen[0]-97][1] = 1;
    for(int i = 1; i<n; ++i){
        for(int j = 0; j<26; ++j){
            if (j == (sen[i]-97)){
                freq[j][i+1] = freq[j][i] + 1;
            }
            else{
                freq[j][i+1] = freq[j][i];
            }
        }    
    }
    
    int maxFact = 0;
    int maxIndFact = 0;
    for (int i = 0; i<26; ++i){
        maxFact += freq[i][n-1];
        if (freq[i][n-1]>maxIndFact){
            maxIndFact = freq[i][n-1];
        }
    }  
    
    long long factRes = 1;
    for (int i = 1; i<=maxFact; ++i){
        factRes = (factRes*i)%primeN;
        fact.push_back(factRes);
    }
    
    for (int i = 2; i<=maxIndFact; ++i){
        inv.push_back(exponentiation(fact[i-1], primeN2));    
    }
       
}

/*
 * Complete the 'answerQuery' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */

int answerQuery(int l, int r) {
    // Return the answer for this query modulo 1000000007.

    vector<int> dC;
    int temp;
    int cS = 0;
    for(int j = 0; j<26; ++j){
        temp = freq[j][r] - freq[j][l-1];
        if (temp >= 2){
            if (temp%2 == 1){
                ++cS;
            }
            dC.push_back(temp/2);    
        }else if (temp == 1){
            ++cS;    
        }   
    }
    
    
    int m = dC.size();
    long long result = 1;
    if (cS != 0){
        result = (cS % primeN);    
    }
    
    int count = 0; 
    for(int i = 0;i<m;++i){
        count += dC[i];
    }
        
    if (count > 1){
        result = (result * (fact[count-1] % primeN)) % primeN;
        
        for(int i = 0;i<m;++i){
            if (dC[i] > 1){
                result = ((result % primeN) * (inv[dC[i]-2] % primeN)) % primeN;
                
            }
        }
    }
    
    return static_cast<int>(result);
}
