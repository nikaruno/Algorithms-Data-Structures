int sherlockAndAnagrams(string s) {
    int n = s.size();
    
    map<vector<int>, int> m;
    map<vector<int>, int>::iterator it;
    
    string s1;
    for (int i = 0; i<n; ++i){
        //create substring
        s1 = s.substr(i, 1);
        //make the key of the created substring
        vector<int> v {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,                        0, 0, 0, 0};
        ++v[s1[0]-97];
        //check if it exists in the map of substrings
        it = m.find(v);
        if (it != m.end()){
            //increase if the same substring was encountered before
            ++it->second; 
        }else{
            m.insert(pair<vector<int>, int>(v, 1)); 
        }
        
        
        for (int j = (i+1); j<n; j++){
            s1 = s.substr(i, j-i+1);
            //make the key of the created substring
            vector<int> v {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,                           0, 0, 0, 0, 0};
            for(int k = 0; k<s1.size(); ++k){
                ++v[s1[k]-97];
            }
            //check if it exists in the map of substrings
            it = m.find(v);
            if (it != m.end()){
                //increase if the same substring was encountered before
                ++it->second; 
            }else{
                m.insert(pair<vector<int>, int>(v, 1)); 
            } 
        }
    }
    
    int count = 0;
    int temp;
    for (it = m.begin(); it != m.end(); ++it){
        if (it->second>1){
            temp = it->second;
            
            count += (temp*(temp-1))/2;

            
        }
    }
    
    return count;
}
