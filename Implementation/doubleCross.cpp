int twoPluses(vector<string> grid) {
    
    int r = grid.size();
    int c = grid[0].size();
    
    int mind, minr, minc;
    vector<Node> maxx;
    int maxc;
    int count;
    int maxcount;
    
    //check if r and c are 2
    if (r == 2 && c == 2){
        count = 0;
        
        if (grid[0][0] == 'G'){
            count++;
        }
        if (grid[0][1] == 'G'){
            count++;
        }
        if (grid[1][0] == 'G'){
            count++;
        }
        if (grid[1][1] == 'G'){
            count++;
        }
        
        if (count >= 2){
            return 1;
        }else{
            return 0;
        }
    }
        
    for (int i = 1; i<(r-1); i++){
        for (int j = 1; j<(c-1); j++){
            
            //check if it is G
            if (grid[i][j] != 'G'){
                continue;
            }
            else{
                //check distance to the outside
                minr = i<(r-i-1) ? i : (r-i-1);
                minc = j<(c-j-1) ? j : (c-j-1);
                mind = minr<minc ? minr : minc;
                count = 0;
                maxc = 1 + count*4;
                maxx.push_back(Node(i,j,maxc));
                for(int k = 1; k<=mind; k++){
                   if ((grid[i+k][j] == 'G') && (grid[i-k][j] == 'G') && (grid[i][j+k] == 'G') && (grid[i][j-k] == 'G')){
                       count++;
                       maxc = 1 + count*4;
                       maxx.push_back(Node(i,j,maxc));    
                   }else{
                       break;
                   } 
                }
            }
        }
    }
    maxcount = 1;
    int temp;
    int n;
    int minx;
    int intr;
    int intc;
    int max1i, max1j, max2i, max2j;
    
    if (maxx.size() >= 2){
        sort(maxx.begin(), maxx.end());
        reverse(maxx.begin(), maxx.end());
        
        for (vector<Node>::iterator it = maxx.begin(); it != maxx.end(); it++){
            cout << it->row << ", " << it->col << ": " << it->area << endl;    
        }
        
        n = maxx.size();
        for (int i = 0; i<n; i++){
            for (int j = i+1; j<n; j++){
                //check if overlap
                mind = (maxx[i].area-1)/4 + (maxx[j].area-1)/4;
                if (maxx[i].row == maxx[j].row){
                    if (abs(maxx[i].col-maxx[j].col) > mind){
                        temp = maxx[i].area*maxx[j].area;
                        if (temp>maxcount){
                            maxcount = temp;
                            max1i = maxx[i].row;
                            max2i = maxx[j].row;
                            max1j = maxx[i].col;
                            max2j = maxx[j].col;                            
                        }     
                    }
                }else if (maxx[i].col == maxx[j].col){
                    if (abs(maxx[i].row-maxx[j].row) > mind){
                        temp = maxx[i].area*maxx[j].area;
                        if (temp>maxcount){
                            maxcount = temp;
                            max1i = maxx[i].row;
                            max2i = maxx[j].row;
                            max1j = maxx[i].col;
                            max2j = maxx[j].col; 
                        }     
                    }                    
                }else{
                    intr = abs(maxx[i].row-maxx[j].row);
                    intc = abs(maxx[i].col-maxx[j].col);
                    minx = (maxx[i].area-1)/4;
                    mind = (maxx[j].area-1)/4;
                    if ((intr <= mind) && (intc <= minx)){
                        continue;
                    }
                    if ((intr <= minx) && (intc <= mind)){
                        continue;    
                    }
                    if ((intc <= mind) && (intr <= minx)){
                        continue;    
                    }
                    if ((intc <= minx) && (intr <= mind)){
                        continue;    
                    }
                    temp = maxx[i].area*maxx[j].area; 
                    if (temp>maxcount){
                        maxcount = temp;
                        max1i = maxx[i].row;
                        max2i = maxx[j].row;
                        max1j = maxx[i].col;
                        max2j = maxx[j].col; 
                    }
                       
                }    
            }
        }
    }
    cout << maxcount << ", " << max1i << ", " << max1j << ", " << max2i << ", " << max2j << endl;
    //Check edge case if only the boundary contains G's return 1 
    
    
    return maxcount;
}
