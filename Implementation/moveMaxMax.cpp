string organizingContainers(vector<vector<int>> container) {

    //Sort containers w.r.t their max element
    sort(container.begin(), container.end(),
        [](const std::vector<int>& a, const std::vector<int>& b) 
        {
            return *max_element(a.begin(), a.end()) > *max_element(b.begin(), b.end());
        });
    
    //debug monitor
    for(vector<vector<int>>::iterator it = container.begin(); it != container.end(); it++){
        for(vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++){
            cout << *it2 << " ";    
        }
        cout << "\n";
    }
    
    //transpose    
    vector<vector<int>> vm(container[0].size(),vector<int>(container.size()));
    for (std::vector<int>::size_type i = 0; i < container[0].size(); i++) 
        for (std::vector<int>::size_type j = 0; j < container.size(); j++) {
            vm[i][j] = container[j][i];
        }
    
     //Sort containers w.r.t their max element
    sort(vm.begin(), vm.end(),
        [](const std::vector<int>& a, const std::vector<int>& b) 
        {
            return *max_element(a.begin(), a.end()) > *max_element(b.begin(), b.end());
        });   
    
    //cout << "----------------------\n";
    
    //transpose
    vector<vector<int>> vm2(container[0].size(),vector<int>(container.size()));
    for (std::vector<int>::size_type i = 0; i < vm2[0].size(); i++) 
        for (std::vector<int>::size_type j = 0; j < vm2.size(); j++) {
            vm2[i][j] = vm[j][i];
        }
    
    //debug monitor
    for(vector<vector<int>>::iterator it = vm2.begin(); it != vm2.end(); it++){
        for(vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++){
            cout << *it2 << " ";    
        }
        cout << "\n";
    }
    
    return "done";
}
