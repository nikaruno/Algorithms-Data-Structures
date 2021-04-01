int onecount(unsigned int x){
    int count = 0;
    if (x & (1u)){
        count++;
    }
    if (x & (2u)){
        count++;
    }
    if (x & (4u)){
        count++;
    }
    if (x & (8u)){
        count++;
    } 
    if (x & (16u)){
        count++;
    } 
    return count;  
}
