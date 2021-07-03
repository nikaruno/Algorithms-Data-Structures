int pylons(int k, vector<int> arr) {
    int pos = 0;
    
    int n = arr.size();
    int count = 0;
    int jj;
    int m = k-1;
    while (pos < n){
        ++count;
        //cout << count << endl;
        pos += m;
        jj = 0;
        while (arr[pos] != 1){
            --pos;
            if(pos<0){
                return -1;
            }
            if(jj == (k+m-1)){
                return -1;
            }
            ++jj;
        }
        pos += k;
        
    }
    return count;
    
}
