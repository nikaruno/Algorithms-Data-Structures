int shortPalindrome(string s) {
    int n = s.size();
    int nol = 26;
    int nol2 = nol*nol;
    
    vector<long> c1(nol);
    vector<long> c2(nol2);
    vector<long> c3(nol2);
    
    for(int i = 0; i<nol; ++i){
        c1[i] = 0;        
    }

    for(int i = 0; i<nol2; ++i){
        c2[i] = 0; 
        c3[i] = 0;       
    }
    
    int k, p, q;
    long count = 0;
    for(int i = 0; i<n; ++i){
        k = s[i] - 97;
        p = 26 * k - 1;
        q = k - 26;
        for(int j = 0; j<nol; ++j){
            q += 26;
            p += 1;
            count += c3[q] % 1000000007;
            c3[p] += c2[p] % 1000000007;
            c2[p] += c1[j] % 1000000007;    
        }    
        c1[k] += 1;
    }
    
    return (count % 1000000007);
    
}
