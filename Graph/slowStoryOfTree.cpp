class Graph{
    int gSize;
    list<int> dfsUtil(bool* visited, int node);
public:
    map<int, list<int>> *adjMap;
    Graph(int g) : gSize{g}{
        adjMap = new map<int, list<int>>[gSize * sizeof(map<int, list<int>>)];
    }    
    void addEdge(int u, int v){
        list<int> l1, l2;
        adjMap[u].insert({v, l1});   
        adjMap[v].insert({u, l2}); 
    }
    void dfs(int root);
    void print();
};

void Graph::dfs(int root){
    bool *visited = new bool[gSize * sizeof(bool)];
    for(int i = 0; i<gSize; ++i){
        visited[i] = false;        
    }
    visited[root] = true;
    map<int, list<int>>::iterator mIt;
    list<int> temp;

    for(mIt = adjMap[root].begin(); mIt != adjMap[root].end(); ++mIt){
        if (!visited[mIt->first]){
            temp                      = dfsUtil(visited, mIt->first);
            adjMap[mIt->first][root].insert(adjMap[mIt->first][root].begin(), temp.begin(), temp.end());   
        }     
    }
}

list<int> Graph::dfsUtil(bool *visited, int node){
    list<int> l, temp;
    l.push_back(node);
    visited[node] = true;
    
    map<int, list<int>>::iterator mIt;
    for(mIt = adjMap[node].begin(); mIt != adjMap[node].end(); ++mIt){
        if (!visited[mIt->first]){
            
            temp = dfsUtil(visited, mIt->first);
            l.insert(l.end(), temp.begin(), temp.end());  
            adjMap[mIt->first][node].insert(adjMap[mIt->first][node].begin(), temp.begin(), temp.end());   
        }
    }
    
    return l;    
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

void Graph::print(){
    map<int, list<int>>::iterator mIt;
    list<int>::iterator lIt;
    for(int i = 0; i<gSize; ++i){
        cout << "Node " << i << ": " << endl;
        for(mIt = adjMap[i].begin(); mIt != adjMap[i].end(); ++mIt){
            cout << "Neigh " << mIt->first << ": " << endl;
            for(lIt = (mIt->second).begin(); lIt != (mIt->second).end(); ++lIt){
                cout << *lIt << " ";    
            }
            cout << endl;   
        }
        cout << endl;
    }
}

string storyOfATree(int n, vector<vector<int>> edges, int k, vector<vector<int>> guesses){
    vector<vector<int>>::iterator it;
    Graph aGraph(n);
    
    for(it = edges.begin(); it != edges.end(); ++it){
        aGraph.addEdge((*it)[0]-1, (*it)[1]-1);   
    }
    
    aGraph.dfs(0);
    //aGraph.print();
    
    int a, b;
    map<int, int> m;
    map<int, int>::iterator mIt;
    list<int>::iterator lIt;
    for(it = guesses.begin(); it != guesses.end(); ++it){
        a = (*it)[0]-1;
        b = (*it)[1]-1;
        cout << a << " " << b << endl; 
        if(!aGraph.adjMap[a][b].empty()){
            for(lIt = aGraph.adjMap[a][b].begin(); lIt != aGraph.adjMap[a][b].end(); ++lIt){
                mIt = m.find(*lIt);
                if (mIt != m.end()){
                    ++m[*lIt];
                }
                else{
                    m.insert({*lIt, 1});
                }                
            }
        }
        else{
            for(int i = 0; i<n; ++i){
                mIt = m.find(i);
                if (mIt != m.end()){
                    ++m[i];
                }
                else{
                    m.insert({i, 1});
                }                
            }
            
            for(lIt = aGraph.adjMap[b][a].begin(); lIt != aGraph.adjMap[b][a].end(); ++lIt){
                --m[*lIt];  
            }
            
        }       
    }
    
    int count = 0;
    for(mIt = m.begin(); mIt != m.end(); ++mIt){
        if (mIt->second>=k){
            ++count;
        }
    }
    
    if (count == 0){
        return "0/1";
    }
    
    if (count == n){
        return "1/1";
    }
    
    int c = gcd(count, n);
    
    string s;
    s = to_string(count/c) + "/";
    s += to_string(n/c);
    return s;
}
