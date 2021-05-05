string larrysArray(vector<int> A) {
    int count = 0;
    int n = A.size();
    for (int i = 0; i < n; i++){
        for (int j = (i+1); j < n; j++){
            if (A[i] > A[j]){
                count++;
            }
        }
    }
    
    if (count % 2 == 0){
        return "YES";    
    }
    
    return "NO";
}
