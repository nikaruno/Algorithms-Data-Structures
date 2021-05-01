int surfaceArea(vector<vector<int>> A) {
    int nrow = A.size();
    int ncol = A[0].size();
    int count = 0;
    int n1, n2, n3, n4;
    
    if (nrow == 1 && ncol == 1){
        return 2+4*A[0][0];
    }
    
    if (nrow == 1){
        count += 2;
        count += 3*A[0][0];
        if (A[0][0]>A[0][1]){
            count += (A[0][0]-A[0][1]);
        }
        
        count += 2;
        count += 3*A[0][ncol-1];
        if (A[0][ncol-1]>A[0][ncol-2]){
            count += (A[0][ncol-1]-A[0][ncol-2]);
        }
        
        for(int j = 1; j<(ncol-1); j++){
            count += 2;
            count += A[0][j]*2;
            n1 = A[0][j] - A[0][j-1];
            n2 = A[0][j] - A[0][j+1];
            if (n1>0){
                count += n1;
            }
            if (n2>0){
                count += n2;
            }
        }
        return count;
    }
    
    if (ncol == 1){
        count += 2;
        count += 3*A[0][0];
        if (A[0][0]>A[1][0]){
            count += (A[0][0]-A[1][0]);
        }
        
        count += 2;
        count += 3*A[nrow-1][0];
        if (A[nrow-1][0]>A[nrow-2][0]){
            count += (A[nrow-1][0]-A[nrow-2][0]);
        }
        
        for(int i = 1; i<(nrow-1); i++){
            count += 2;
            count += A[i][0]*2;
            n1 = A[i][0] - A[i-1][0];
            n2 = A[i][0] - A[i+1][0];
            if (n1>0){
                count += n1;
            }
            if (n2>0){
                count += n2;
            }
        }
        return count;
    }
    
    for(int i = 0; i<nrow; i++){
        for(int j = 0; j<ncol; j++){
            count += 2; //For top and bottom faces
            //Corners
            if(i == 0 && j == 0){
                count += 2*A[i][j];
                n1 = A[i][j] - A[i+1][j];
                n2 = A[i][j] - A[i][j+1];
                if (n1>0){
                    count += n1;
                }
                if (n2>0){
                    count += n2;
                }        
            }
            else if(i == 0 && j == (ncol-1)){ 
                count += 2*A[i][j]; 
                n1 = A[i][j] - A[i+1][j];
                n2 = A[i][j] - A[i][j-1];
                if (n1>0){
                    count += n1;
                }
                if (n2>0){
                    count += n2;
                }
            }
            else if(i == (nrow-1) && j == (ncol-1)){ 
                count += 2*A[i][j];
                n1 = A[i][j] - A[i-1][j];
                n2 = A[i][j] - A[i][j-1];
                if (n1>0){
                    count += n1;
                }
                if (n2>0){
                    count += n2;
                } 
            }
            else if(i == (nrow-1) && j == 0){
                count += 2*A[i][j]; 
                n1 = A[i][j] - A[i-1][j];
                n2 = A[i][j] - A[i][j+1];
                if (n1>0){
                    count += n1;
                }
                if (n2>0){
                    count += n2;
                }    
            }             
            //Edges
            else if (i == 0){
                count += A[i][j]; 
                n1 = A[i][j] - A[i+1][j];
                n2 = A[i][j] - A[i][j-1];
                n3 = A[i][j] - A[i][j+1];
                if (n1>0){
                    count += n1;
                }
                if (n2>0){
                    count += n2;
                } 
                if (n3>0){
                    count += n3;
                }   
            }
            else if (j == 0){
                count += A[i][j];
                n1 = A[i][j] - A[i+1][j];
                n2 = A[i][j] - A[i-1][j];
                n3 = A[i][j] - A[i][j+1];
                if (n1>0){
                    count += n1;
                }
                if (n2>0){
                    count += n2;
                } 
                if (n3>0){
                    count += n3;
                }     
            }
            else if (i == (nrow-1)){
                count += A[i][j];  
                n1 = A[i][j] - A[i-1][j];
                n2 = A[i][j] - A[i][j-1];
                n3 = A[i][j] - A[i][j+1];
                if (n1>0){
                    count += n1;
                }
                if (n2>0){
                    count += n2;
                } 
                if (n3>0){
                    count += n3;
                }    
            }
            else if (j == (ncol-1)){
                count += A[i][j];
                n1 = A[i][j] - A[i][j-1];
                n2 = A[i][j] - A[i-1][j];
                n3 = A[i][j] - A[i+1][j];
                if (n1>0){
                    count += n1;
                }
                if (n2>0){
                    count += n2;
                } 
                if (n3>0){
                    count += n3;
                }     
            }
            else{
                n1 = A[i][j] - A[i][j-1];
                n2 = A[i][j] - A[i-1][j];
                n3 = A[i][j] - A[i+1][j];
                n4 = A[i][j] - A[i][j+1];
                if (n1>0){
                    count += n1;
                }
                if (n2>0){
                    count += n2;
                } 
                if (n3>0){
                    count += n3;
                } 
                if (n4>0){
                    count += n4;
                }               
            }
        }
    }
    
    return count;
}
