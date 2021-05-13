int activityNotifications(vector<int> expenditure, int d) {
    int countRange = 201;
    int countArray[202];
    int tempArray[202];
    
    int n = expenditure.size();
    
       
    for (int i = 0; i <= countRange; ++i)
        countArray[i] = 0;
   
    for (int i = 0; i < d; ++i)
        ++countArray[expenditure[i]];
    
    for (int i = 0; i <= countRange; ++i){
        tempArray[i] = countArray[i];
    }
    
    for (int i = 1; i <= countRange; ++i){
        tempArray[i] += tempArray[i-1];
    }
    
    int median1, median2, medianIndex;    
    for (int i = 0; i < d; ++i){
        if ((tempArray[expenditure[i]] - 1) == d/2){
            median1 = expenditure[i];  
        }
        else if ((tempArray[expenditure[i]] - 1) == (d/2-1)){
            median2 = expenditure[i];
        }
        --tempArray[expenditure[i]];        
    }
    
    int median;
    if (d%2 == 1){
        median = median1;
    }else{
        median = median1 + median2;
    }
    
  
    int count = 0;
    bool con1, con2;
    int y, z;

    for(int i = d; i<n; ++i){
        y = expenditure[i];
        //Compare current expenditure with the median 
        if (d%2 == 1){
            if (y>=(median*2)){
                ++count;
            }   
        }
        else {
            if (y>=median){
                ++count;
            }       
        }
        
        --countArray[expenditure[i-d]];
        ++countArray[y];
        
        for (int j = 0; j <= countRange; ++j){
            tempArray[j] = countArray[j];
        }
        
        for (int j = 1; j <= countRange; ++j){
            tempArray[j] += tempArray[j-1];
        }
        con1 = false;
        con2 = false;
        
        for (int j = 1; j <= countRange; ++j){
            if (d%2 == 0){
                if (tempArray[j] == (d/2)){
                    median1 = j;
                    con1 = true;
                } 
                else if (tempArray[j] > (d/2)){
                    if (!con1){
                        median1 = j;    
                    }
                    median2 = j;
                    break;    
                }               
            }
            else{
                if (tempArray[j] >= ((d+1)/2)){
                    median1 = j;
                    break;    
                }                
            }

        }          
        
        if (d%2 == 1){
            median = median1;
        }else{
            median = median1 + median2;
        }
        
    }
       
    return count;
}
