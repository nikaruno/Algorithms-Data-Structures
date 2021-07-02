int maxMin(int k, vector<int> arr) {
    
    int n = arr.size();
    
    sort(arr.begin(), arr.end());
    

    int ii = 0;
    int jj = k-1;
    
    int temp;
    int min = INT_MAX;
    for(int i = 0; i<(n-k+1); ++i){
        ii = i;
        jj = i + k - 1;
        temp = arr[jj] - arr[ii];
        if (temp < min){
            min = temp;
        }
    }
    return min;
}
