string abbreviation(string a, string b) {

    int n = a.size();
    int m = b.size();
        
    vector<vector<int>> dp;
    
    for(int i = 0; i<=n; ++i){
        vector<int> v;
        for(int j = 0; j<=m; ++j){
            v.push_back(0);
        }    
        dp.push_back(v);
    }
    
    for(int j = 0; j<=m; ++j){
        dp[0][j] = 0;    
    }
    
    for(int i = 0; i<=n; ++i){
        dp[i][0] = 1;    
    }    
    
    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<=m; ++j){
            if (a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else if (a[i-1] > 96){
                if ((a[i-1]-32) == b[j-1]){
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-1]; 
                }
                else{
                    dp[i][j] = dp[i-1][j];    
                }    
            }
            else{
                dp[i][j] = 0;
            }
        }    
    }
    
    if (dp[n][m]){
        return "YES";
    }
    
    return "NO";
    
}
