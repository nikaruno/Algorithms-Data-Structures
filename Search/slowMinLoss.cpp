int minimumLoss(vector<long> price) {

    int n = price.size();
    
    list<long> aList;
    list<long>::iterator it;
    
    long min = -9223372036854775807;
    
    if (price[0]>price[1]){
        aList.push_back(price[1]);
        aList.push_back(price[0]);
        if ((price[1]-price[0])>min){
            min = (price[1]-price[0]);
        }
    }
    else{
        aList.push_back(price[0]);
        aList.push_back(price[1]);        
    }
    
    
    int next;
    int i, j, mid;
    for (int k = 2; k<n; ++k){
        next = price[k];
        if (next < aList.front()){
            if (next - aList.front()>min){
                min = next - aList.front();
            }
            aList.push_front(next);
        }
        else if ( next > aList.back()){
            aList.push_back(next);
        }
        else{
            i = 0, j = k, mid = 0;
            while (i < j) {
                mid = (i + j) / 2;
                it = aList.begin();
                advance(it, mid);
                if (next < *it) {
                    --it;
                    if (mid>0 && next > *it){                        
                        ++it;
                        if ((next - *it) > min){
                            min = (next - *it);
                        }
                        aList.insert(it, next);
                        break;
                    }
                    j = mid;    
                }
                else{
                    ++it;
                    if (mid < (n - 1) && next < *it){
                        if ((next - *it) > min){
                            min = (next - *it);
                        }                        
                        aList.insert(it, next);
                        break;                        
                    }
                    i = mid + 1;    
                }    
            }    
        }


    }
    

    
    return (-min);
}
