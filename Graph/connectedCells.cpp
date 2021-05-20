class Graph{
        int len;
        list<int>* adj;
        int DFSUtil(int n, bool* visited);
    public:
        Graph(int iLen) : len(iLen){
            adj = new list<int>[iLen];    
        };
        ~Graph(){
            delete[] adj;
        }
        void addEdge(int a, int b); 
        int connectedComponents();
        void print();
};

void Graph::addEdge(int a, int b){
    adj[a].push_back(b);
}

void Graph::print(){
    for(int i = 0; i<len; ++i){
        for(list<int>::iterator it = adj[i].begin(); it != adj[i].end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
}

int Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    int count = 1;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            count += DFSUtil(*i, visited);
            
    return count;
}

int Graph::connectedComponents()
{
    // Mark all the vertices as not visited
    bool* visited = new bool[len];
    int max = 0;
    for (int v = 0; v < len; ++v)
        visited[v] = false;
    
    int count = 0;
    for (int v = 0; v < len; ++v) {
        if (visited[v] == false) {
            // print all reachable vertices
            // from v
            count = DFSUtil(v, visited);
            if (count>max){
                max = count;
            }
        }
    }
    delete[] visited;
    return max;
}

int connectedCell(vector<vector<int>> matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    
    Graph aGraph(r*c);
    for (int i = 0; i<r; ++i){
        for (int j = 0; j<c; ++j){
            if (matrix[i][j] == 1){
                //If corner
                if (i == 0 && j == 0){
                    if (matrix[i+1][j] == 1){
                        aGraph.addEdge(i*c+j, (i+1)*c+(j));    
                    }
                    if (matrix[i][j+1] == 1){
                        aGraph.addEdge(i*c+j, (i)*c+(j+1));    
                    }
                    if (matrix[i+1][j+1] == 1){
                        aGraph.addEdge(i*c+j, (i+1)*c+(j+1));    
                    }
                }
                else if (i == 0 && j == (c-1)){
                    if (matrix[i+1][j] == 1){
                        aGraph.addEdge(i*c+j, (i+1)*c+(j));    
                    }
                    if (matrix[i][j-1] == 1){
                        aGraph.addEdge(i*c+j, (i)*c+(j-1));    
                    }
                    if (matrix[i+1][j-1] == 1){
                        aGraph.addEdge(i*c+j, (i+1)*c+(j-1));    
                    }
                }
                else if (i == (r-1) && j == 0){
                    if (matrix[i-1][j] == 1){
                        aGraph.addEdge(i*c+j, (i-1)*c+(j));    
                    }
                    if (matrix[i][j+1] == 1){
                        aGraph.addEdge(i*c+j, (i)*c+(j+1));    
                    }
                    if (matrix[i-1][j+1] == 1){
                        aGraph.addEdge(i*c+j, (i-1)*c+(j+1));    
                    }
                }
                else if (i == (r-1) && j == (c-1)){
                    if (matrix[i-1][j] == 1){
                        aGraph.addEdge(i*c+j, (i-1)*c+(j));    
                    }
                    if (matrix[i][j-1] == 1){
                        aGraph.addEdge(i*c+j, (i)*c+(j-1));    
                    }
                    if (matrix[i-1][j-1] == 1){
                        aGraph.addEdge(i*c+j, (i-1)*c+(j-1));    
                    }
                }                
                //If edge
                else if (i == 0){
                    if (matrix[i][j-1] == 1){
                        aGraph.addEdge(i*c+j, (i)*c+(j-1));    
                    }
                    if (matrix[i][j+1] == 1){
                        aGraph.addEdge(i*c+j, (i)*c+(j+1));    
                    }
                    if (matrix[i+1][j-1] == 1){
                        aGraph.addEdge(i*c+j, (i+1)*c+(j-1));    
                    }
                    if (matrix[i+1][j] == 1){
                        aGraph.addEdge(i*c+j, (i+1)*c+(j));    
                    }
                    if (matrix[i+1][j+1] == 1){
                        aGraph.addEdge(i*c+j, (i+1)*c+(j+1));    
                    }
                } 
                else if (i == (r-1)){
                    if (matrix[i][j-1] == 1){
                        aGraph.addEdge(i*c+j, (i)*c+(j-1));    
                    }
                    if (matrix[i][j+1] == 1){
                        aGraph.addEdge(i*c+j, (i)*c+(j+1));    
                    }
                    if (matrix[i-1][j-1] == 1){
                        aGraph.addEdge(i*c+j, (i-1)*c+(j-1));    
                    }
                    if (matrix[i-1][j] == 1){
                        aGraph.addEdge(i*c+j, (i-1)*c+(j));    
                    }
                    if (matrix[i-1][j+1] == 1){
                        aGraph.addEdge(i*c+j, (i-1)*c+(j+1));    
                    }
                }               
                else if (j == 0){
                    if (matrix[i-1][j] == 1){
                        aGraph.addEdge(i*c+j, (i-1)*c+(j));    
                    }
                    if (matrix[i+1][j] == 1){
                        aGraph.addEdge(i*c+j, (i+1)*c+(j));    
                    }
                    if (matrix[i-1][j+1] == 1){
                        aGraph.addEdge(i*c+j, (i-1)*c+(j+1));    
                    }
                    if (matrix[i][j+1] == 1){
                        aGraph.addEdge(i*c+j, (i)*c+(j+1));    
                    }
                    if (matrix[i+1][j+1] == 1){
                        aGraph.addEdge(i*c+j, (i+1)*c+(j+1));    
                    }
                }
                else if (j == (c-1)){
                    if (matrix[i-1][j] == 1){
                        aGraph.addEdge(i*c+j, (i-1)*c+(j));    
                    }
                    if (matrix[i+1][j] == 1){
                        aGraph.addEdge(i*c+j, (i+1)*c+(j));    
                    }
                    if (matrix[i-1][j-1] == 1){
                        aGraph.addEdge(i*c+j, (i-1)*c+(j-1));    
                    }
                    if (matrix[i][j-1] == 1){
                        aGraph.addEdge(i*c+j, (i)*c+(j-1));    
                    }
                    if (matrix[i+1][j-1] == 1){
                        aGraph.addEdge(i*c+j, (i+1)*c+(j-1));    
                    }
                } 
                //If mid 
                else{
                    if (matrix[i-1][j-1] == 1){
                        aGraph.addEdge(i*c+j, (i-1)*c+(j-1));    
                    } 
                    if (matrix[i-1][j] == 1){
                        aGraph.addEdge(i*c+j, (i-1)*c+(j));    
                    }  
                    if (matrix[i-1][j+1] == 1){
                        aGraph.addEdge(i*c+j, (i-1)*c+(j+1));    
                    }
                    if (matrix[i][j-1] == 1){
                        aGraph.addEdge(i*c+j, (i)*c+(j-1));    
                    } 
                    if (matrix[i][j+1] == 1){
                        aGraph.addEdge(i*c+j, (i)*c+(j+1));    
                    }
                    if (matrix[i+1][j-1] == 1){
                        aGraph.addEdge(i*c+j, (i+1)*c+(j-1));    
                    } 
                    if (matrix[i+1][j] == 1){
                        aGraph.addEdge(i*c+j, (i+1)*c+(j));    
                    }  
                    if (matrix[i+1][j+1] == 1){
                        aGraph.addEdge(i*c+j, (i+1)*c+(j+1));    
                    }                 
                }       
            }    
        }
    }
    
    return aGraph.connectedComponents();
}
