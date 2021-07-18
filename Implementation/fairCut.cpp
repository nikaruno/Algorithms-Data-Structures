long fairCut(int k, vector<long> arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int m = n - k;

    vector<int> rank1, rank2;
    for(int i = 0; i<k; ++i){
        rank1.push_back(k-2*i-1);
    }
    for(int i = 0; i<m; ++i){
        rank2.push_back(m-2*i-1);
    }
    
    vector<int> karr;
    vector<int> marr;
    
    int ii = 0;
    int kk = 0;
    int mm = 0;
    
    while(kk<k && mm<m){
        if(rank1[kk] > rank2[mm]){
            karr.push_back(arr[ii]);
            ++kk;
        }
        else{
           marr.push_back(arr[ii]);
           ++mm; 
        }
        ++ii;
    }
    
    if(kk == k){
        while(ii<n){
            marr.push_back(arr[ii]);
            ++ii;    
        }
    }
    
    if(mm == m){
        while(ii<n){
            karr.push_back(arr[ii]);
            ++ii;    
        }
    }
    
    long sum = 0;   
    for(auto kk : karr){
        for(auto mm : marr){
            sum += abs(kk-mm);
        }
    } 
    
    return sum;
}
