class Tree{
    int tSize;
    vector<pair<int, int>> *adjVec;
public:
    Tree(int t) : tSize{t}{
        adjVec = new vector<pair<int, int>>[tSize];
    }
    ~Tree(){
        delete[] adjVec;
    }
    void addEdge(int u, int v, int w){
        
        adjVec[u].push_back({v, w});
        adjVec[v].push_back({u, w});
    }
    bool *cutLeaf(vector<int> &keys);
    int findDistance(bool* remTree);
};
 
bool* Tree::cutLeaf(vector<int> &keys){
    
    bool* keyNodes = new bool[tSize];
    vector<int>::iterator it;
    
    for (int i = 0; i<tSize; ++i){
        keyNodes[i] = false;
    }
    
    for(it = keys.begin(); it != keys.end(); ++it){

        keyNodes[*it] = true;
    }
    
    int* edgeCount = new int[tSize];
    for(int i = 0; i<tSize; ++i){
        edgeCount[i] = adjVec[i].size();
        
    }
    
    queue<int> aQueue;
    bool* visited = new bool[tSize];
    
    for(int i = 0; i<tSize; ++i){
        visited[i] = false;
        if (!keyNodes[i] && edgeCount[i] == 1){
            aQueue.push(i);
        }
    }
    
    int node, next;
    vector<pair<int, int>>::iterator vIt;
    while(!aQueue.empty()){
        node = aQueue.front();
        visited[node] = true;
        aQueue.pop();
        for(vIt = adjVec[node].begin(); vIt != adjVec[node].end(); ++vIt){
            next = (*vIt).first;
            if(keyNodes[next]){
                break;
            }
            else if(!visited[next]){ 
                if (--edgeCount[next] == 1){
                    aQueue.push(next);
                    break;
                }
            }
        }
    }
    
    delete[] edgeCount;
    delete[] keyNodes;
    
    return visited;
    
}

int Tree::findDistance(bool* remTree){
    
    int node;
    for (int i = 0; i<tSize; ++i){
        if(!remTree[i]){
            node = i;
            break;
        }
    }

    for (int i = 0; i<tSize; ++i){
        if(!remTree[i]){
            cout << "Node: " << (i+1) << endl;
        }
    }
    
    bool* visited = new bool[tSize];
    for (int i = 0; i<tSize; ++i){
        visited[i] = false;
    }
    
    queue<int> aQueue;
    aQueue.push(node);
    visited[node] = true;
    
    vector<pair<int, int>>::iterator vIt;
    int next, start;
    
    while(!aQueue.empty()){
        node = aQueue.front();
        aQueue.pop();
        for(vIt = adjVec[node].begin(); vIt != adjVec[node].end(); ++vIt){
            next = (*vIt).first;
            if(!visited[next] && !remTree[next]){
                visited[next] = true;
                aQueue.push(next);
                start = next;
            }
        }
    }
    
    for (int i = 0; i<tSize; ++i){
        visited[i] = false;
    }
    
    queue<pair<int, int>> bQueue;
    bQueue.push({start, 0});
    visited[start] = true;
    int distance, nextDistance, maxDistance, totalDistance, weight;
    maxDistance = 0;
    totalDistance = 0;
    pair<int, int> p;
    while(!bQueue.empty()){
        p = bQueue.front();
        bQueue.pop();
        node = p.first;
        distance = p.second;
        //cout << "Node " << (node+1) << endl;
        for(vIt = adjVec[node].begin(); vIt != adjVec[node].end(); ++vIt){
            next = (*vIt).first;
            weight = (*vIt).second;
            if(!visited[next] && !remTree[next]){
                totalDistance += weight;
                nextDistance = distance + (*vIt).second;
                visited[next] = true;
                bQueue.push({next, nextDistance});
                if (nextDistance > maxDistance){
                    maxDistance = nextDistance;
                }
            }
        }
        
    }
    
    delete[] visited;
    
    //cout << totalDistance << endl;
    //cout << maxDistance << endl;
    
    return (2*totalDistance-maxDistance);
}

int jeanisRoute(vector<int> k, vector<vector<int>> roads) {
    
    int n = roads.size()+1;
    vector<vector<int>>::iterator it;
    
    Tree aTree{n};
    
    for(it = roads.begin(); it != roads.end(); ++it){
        aTree.addEdge((*it)[0]-1, (*it)[1]-1, (*it)[2]);
    }
    
    int m = k.size();
    for(int i = 0; i<m; ++i){
        --k[i];
    }
    
    bool* x = aTree.cutLeaf(k);
    
    return aTree.findDistance(x);
}
