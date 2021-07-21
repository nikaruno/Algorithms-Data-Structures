int substringDiff(int k, string s1, string s2) {
    
    int n = s1.size();
    
    vector<vector<int>> totalUnmatch;
    
    for(int i = 0; i<=n; ++i){
        vector<int> v;
        for(int j = 0; j<=n; ++j){
            v.push_back(0);
        }    
        totalUnmatch.push_back(v);
    }
    
    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<=n; ++j){
            if (s1[i-1] != s2[j-1]){
                totalUnmatch[i][j] = totalUnmatch[i-1][j-1]+1;   
            }
            else{
                totalUnmatch[i][j] = totalUnmatch[i-1][j-1];
            }
        }    
    }    
        
    bool maxFound = false;
    int low  = 0;
    int high = n;
    int mid;
    int longest;
    while(!maxFound){
        
        mid = (low+high+1)/2;
        for(int i = mid; i<=n; ++i){
            for(int j = mid; j<=n; ++j){
                longest = totalUnmatch[i][j] - totalUnmatch[i-mid][j-mid];
                if (longest <= k){
                    low = mid;
                    break;    
                }
            }    
        }
        
        if(!(low == mid)){
            high = mid-1;;
        }
        
        if (low >= high){
            maxFound = true;
        }
        
    }
    return low;
}
