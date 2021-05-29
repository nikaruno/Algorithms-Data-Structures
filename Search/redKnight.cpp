bool isMovePossible(int i, int j, int n){
    if (i < 0 || j < 0 || i >= n || j >= n){
        return false;
    }
    return true;
}

void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    // Print the distance along with the sequence of moves.
    vector<vector<bool>> visited;
    for (int i = 0; i<n; ++i){
        vector<bool> v;
        for (int j = 0; j<n; ++j){
            v.push_back(false);  
        }
        visited.push_back(v);
    }
    
    pair<pair<int,int>, pair<int, string>> pos;
    int moves = 0;
    queue<pair<pair<int,int>, pair<int, string>>> aQueue;
    aQueue.push(pair<pair<int,int>, pair<int, string>>(pair<int, int>(i_start, j_start), pair<int, string>(moves, "")));
    visited[i_start][j_start] = true;
    int i, j;
    string s;
    while(!aQueue.empty()){
        pos = aQueue.front();
        aQueue.pop();
        i = pos.first.first;
        j = pos.first.second;
        moves = pos.second.first;
        s = pos.second.second;
        
        if (i == i_end && j == j_end){
            cout << moves << endl;
            cout << s << endl;
            return;
        }
        
        //UL
        if (isMovePossible(i-2, j-1, n)){
            if (!visited[i-2][j-1]){
                visited[i-2][j-1] = true; 
                aQueue.push(pair<pair<int,int>, pair<int, string>>(pair<int, int>(i-2, j-1), pair<int, string>(moves+1,s+"UL ")));   
            } 
        }
        //UR
        if (isMovePossible(i-2, j+1, n)){
            if (!visited[i-2][j+1]){
                visited[i-2][j+1] = true; 
                aQueue.push(pair<pair<int,int>, pair<int, string>>(pair<int, int>(i-2, j+1), pair<int, string>(moves+1, s+"UR ")));   
            }            
        }        
        //R
        if (isMovePossible(i, j+2, n)){
            if (!visited[i][j+2]){
                visited[i][j+2] = true; 
                aQueue.push(pair<pair<int,int>, pair<int, string>>(pair<int, int>(i, j+2), pair<int, string>(moves+1, s+"R ")));   
            }            
        }        
        //LR
        if (isMovePossible(i+2, j+1, n)){
            if (!visited[i+2][j+1]){
                visited[i+2][j+1] = true; 
                aQueue.push(pair<pair<int,int>, pair<int, string>>(pair<int, int>(i+2, j+1), pair<int, string>(moves+1 ,s+"LR ")));   
            }            
        }        
        //LL
        if (isMovePossible(i+2, j-1, n)){
            if (!visited[i+2][j-1]){
                visited[i+2][j-1] = true; 
                aQueue.push(pair<pair<int,int>, pair<int, string>>(pair<int, int>(i+2, j-1), pair<int, string>(moves+1 ,s+"LL ")));   
            }            
        }        
        //L
        if (isMovePossible(i, j-2, n)){
            if (!visited[i][j-2]){
                visited[i][j-2] = true; 
                aQueue.push(pair<pair<int,int>, pair<int, string>>(pair<int, int>(i, j-2), pair<int, string>(moves+1,s+"L ")));
            }            
        }        
        
    }
    
    cout << "Impossible" << endl; 
    
}
