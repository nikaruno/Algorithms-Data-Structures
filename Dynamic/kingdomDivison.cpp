constexpr int primeN  = 1000000007;

void dfs(int node, bool* visited, vector<int>* adjVec, long* peace, long* war){
    
    visited[node] = true;
    
    war[node]   = 1LL;
    peace[node] = 1LL;
    
    for(auto next : adjVec[node]){
        if(!visited[next]){ 
            dfs(next, visited, adjVec, peace, war);
            peace[node] *= (2*peace[next]+war[next]);
            peace[node] %= primeN;
            war[node]   *= peace[next];
            war[node]   %= primeN;    
        }
    }  
      
    peace[node] -= war[node];
    peace[node] += primeN;
    peace[node] %= primeN;
    
}

int kingdomDivision(int n, vector<vector<int>> roads) {
    
    long* peace;
    long* war;
    bool* visited;
    vector<int>* adjVec;
    
    adjVec = new vector<int>[n];
    
    for(auto road : roads){
        adjVec[road[0]-1].push_back(road[1]-1);
        adjVec[road[1]-1].push_back(road[0]-1);
    }
    
    visited = new bool[n];
    for(int i = 0; i<n; ++i){
        visited[i] = false;
    }
    
    peace = new long[n];
    war   = new long[n];
    
    dfs(0, visited, adjVec, peace, war);
    
    return (2*peace[0])%primeN;
        
}
