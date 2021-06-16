typedef vector<vector<int>> mat2d;

class Graph{
    int gSize;
    bool *visited;
    public:
    mat2d cap;
    Graph(int g) : gSize{g}{
        visited = new bool[gSize];
        for(int i = 0; i<gSize; ++i){
            vector<int> v;
            for(int j = 0; j<gSize; ++j){
                v.push_back(0);
            }
            cap.push_back(v);
        }
    }
    void addEdge(int u, int v, int w){
        cap[u][v] = w;
    }
    void print();
    vector<int> bfs();
    int maxFlow();
};

void Graph::print(){
    
    for(int i = 0; i<gSize; ++i){
        cout << "Node " << i << ": ";
        for(int j = 0; j<gSize; ++j){
            if (cap[i][j]>0){
                cout << j << "(" << cap[i][j] << ") ";
            }    
        }
        cout << endl;
    }
    
}

vector<int> Graph::bfs(){
    vector<int> path;
    
    for(int i = 0; i<gSize; ++i){
        visited[i] = false;
    }
    
    path.push_back(0);
    visited[0] = true;
    
    queue<pair<int, vector<int>>> aQueue;
    aQueue.push({0, path});
    
    pair<int, vector<int>> p;
    
    int node;
    while(!aQueue.empty()){
        
        p = aQueue.front();
        aQueue.pop();
        node = p.first;
        path = p.second;
        
        for(int i = 0; i<gSize; ++i){
            if (i!=node && cap[node][i]>0){
                if (!visited[i]){
                    visited[i] = true;
                    vector<int> v = path;
                    v.push_back(i);
                    if (i == (gSize-1)){
                        return v;
                    }
                    aQueue.push({i, v});
                }
            }
        }
        
    }
    return path;
    
}

int Graph::maxFlow(){
    int flow = 0;
    
    vector<int> path = bfs();
    int n = path.size();
    int min;
    
    while(path[n-1] == (gSize-1)){
        //cout <<"--------------------" << endl;
        //for(int j = 0; j<(n-1); ++j){
        //    cout << path[j] << " ";    
        //}
        //cout << path[n-1] << endl;
        //cout << flow;
        
        min = INT_MAX;
        for(int j = 0; j<(n-1); ++j){
            if (min > cap[path[j]][path[j+1]]){
                min = cap[path[j]][path[j+1]];
            }    
        }    
        
        flow += min;
        
        for(int j = 0; j<(n-1); ++j){
            cap[path[j]][path[j+1]] -= min;
            cap[path[j+1]][path[j]] += min;   
        }    
        
        path = bfs();
        n = path.size();
        
    }
    
    return flow;
}


int crabGraphs(int n, int t, vector<vector<int>> graph) {

    Graph aGraph{2*n+2};
    
    vector<int> v;
    for(int i = 0; i<(n+1); ++i){
        v.push_back(0);
    }
    
    vector<vector<int>>::iterator it;
    for(it = graph.begin(); it != graph.end(); ++it){
        aGraph.addEdge((*it)[0], n+(*it)[1], 1);
        aGraph.addEdge((*it)[1], n+(*it)[0], 1);
        ++v[(*it)[0]];
        ++v[(*it)[1]];

    }
    
    for(int i = 1; i<=n; ++i){
        aGraph.addEdge(i+n, 2*n+1, 1);
    }
    
    for(int i = 1; i<=n; ++i){
        if (v[i] > 0){
            aGraph.addEdge(0, i, t<v[i]?t:v[i]);     
        }   
    }
    
    aGraph.print();
    
    return aGraph.maxFlow();
}
