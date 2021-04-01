unsigned int touint(string s){
    int k = s.size();
    unsigned int a = 0;
    for (int i = 0; i<k; i++){
        if (s.at(i) == '1'){
            a += i << (k-1-i);    
        }
    }    
    return a;
}
