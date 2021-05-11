int steadyGene(string gene) {
    //A: 65, C: 67, G: 71, T: 84
    int n = gene.size();
    int m = n/4;
    vector<int> counts{0, 0, 0, 0};
    
    for (int i = 0; i<n; ++i){
        if (gene[i] == 65){
            ++counts[0];        
        }
        else if (gene[i] == 67){
            ++counts[1]; 
        }
        else if (gene[i] == 71){
            ++counts[2];
        }
        else{
            ++counts[3];
        }
    } 
    
    int i{0};
    int j{0};
    
    int min{500001};
    
    while(i<n && j<n){
        if(counts[0]>m || counts[1]>m || counts[2]>m || counts[3]>m){
            if (gene[i] == 65){
                --counts[0];        
            }
            else if (gene[i] == 67){
                --counts[1]; 
            }
            else if (gene[i] == 71){
                --counts[2];
            }
            else{
                --counts[3];
            }
            ++i;
        }else{
            min = min<(i-j) ? min : (i-j);
            if (gene[j] == 65){
                ++counts[0];        
            }
            else if (gene[j] == 67){
                ++counts[1]; 
            }
            else if (gene[j] == 71){
                ++counts[2];
            }
            else{
                ++counts[3];
            }
            ++j;    
        }
    }
    
    return min;
}
