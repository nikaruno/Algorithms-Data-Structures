int getMinimumCost(int k, vector<int> c) {

    int n = c.size();
    
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    
    int count = 0;
    int ii = 0;
    int coef = 0;
    for(int cost : c){
        if (ii % k == 0){
            ++coef;
        }
        ++ii;
        count += cost*coef;
        
    }
    return count;

}
