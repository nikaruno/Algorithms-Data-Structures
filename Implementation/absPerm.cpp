vector<int> absolutePermutation(int n, int k) {
    vector<int> v;
    if (k == 0){
        for (int i = 0; i<n; i++){
            v.push_back(i+1);
        } 
        return v;
    }
    int m = 2*k;
    if ((n % 2 == 1) || (n/m)*m != n){
        v.push_back(-1);
        return v;
    }
    int l = 0;
    while(n>0){
        for (int i = k; i<m; i++){
            v.push_back(l*m+i+1);   
        }
        for (int i = 0; i<k; i++){
            v.push_back(l*m+i+1);    
        }
        l++;
        n -= m;    
    }
    return v;
}
