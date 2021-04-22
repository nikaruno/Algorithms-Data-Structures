int numberOfDivisors(int x){
    
    int y = static_cast<int>(round(sqrt(x)));
    
    vector<int> v;
    v.push_back(1);
    v.push_back(x);
    
    for (int i = 2; i<y; i++){
        if (x%i==0){
            v.push_back(i);
            v.push_back(x/i);
        }
    }
    
    sort(v.begin(), v.end());
    
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    
    return v.size();
    
}
