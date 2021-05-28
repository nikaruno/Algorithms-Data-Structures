long long beautifulQuadruples(int a, int b, int c, int d) {
    /*
     * Write your code here.
     */
    long long totCount;
    
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    
    sort(v.begin(), v.end());
      
    vector<long long> c1, c2, c3, c4;
    c1.push_back(1);
    c2.push_back(1);
    c3.push_back(1);
    c4.push_back(1);
    
    for (long long i = 2; i <= v[3]; ++i){
        if (i <= v[0]){
            c1.push_back(i);
            c2.push_back(c2[i-2] + c1[i-1]);
            c3.push_back(c3[i-2] + c2[i-1]);
            c4.push_back(c4[i-2] + c3[i-1]);
        }    
        else if (i <= v[1]) {
            c2.push_back(c2[i-2] + c1[v[0]-1]);
            c3.push_back(c3[i-2] + c2[i-1]);
            c4.push_back(c4[i-2] + c3[i-1]);
        }
        else if (i <= v[2]){
            c3.push_back(c3[i-2] + c2[v[1]-1]); 
            c4.push_back(c4[i-2] + c3[i-1]);
        }
        else{
            c4.push_back(c4[i-2] + c3[v[2]-1]); 
        }
    }
    
    totCount = c4[v[3]-1];
    
    vector<long long> x;
    for(int i = 0; i<6000; ++i){
        x.push_back(0);
    }
    
    
    long long xorCount = 0;
    for (int i = 1; i<=v[2]; ++i){
        if (i <= v[1]){
            for (int k = 1; (k<=i && k<= v[0]); ++k){
                ++x[i^k];
            }
        }
        for (int j = i; j<=v[3]; ++j){
            xorCount += x[i^j];    
        }
    }

    return (totCount-xorCount);
}
