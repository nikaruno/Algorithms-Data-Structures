vector<int> rustMurdered(int n, int s, vector<vector<int>> roads) {
    /*
     * Write your code here.
     */
    vector<int>* adjVec = new vector<int>[n];
     
    vector<vector<int>>::iterator it;
    int u, v;
    for(it = roads.begin(); it != roads.end(); ++it){
        u = (*it)[0]-1;
        v = (*it)[1]-1;
        adjVec[u].push_back(v);
        adjVec[v].push_back(u);
    }
    
    for(int i = 0; i<n; ++i){
        sort(adjVec[i].begin(), adjVec[i].end());
    }
     
    set<int> undiscovered;
     
    vector<int> distance_node(n);
    for (int i = 0; i < n; i++) {
        undiscovered.insert(i);
    }
    
    int start = s-1; 
    undiscovered.erase(start);
    distance_node[start] = 0;
    queue<pair<int, int>> q;
    q.push({start, 0});
    
    pair<int, int> p; 
    int node, ii, vlen, distance;
    while(undiscovered.size() && !q.empty()){
        
        p = q.front();
        node = p.first;
        distance = p.second;
        q.pop();
        
        vector<int> complement;
        
        ii = 0;
        bool eq;
        vlen = adjVec[node].size(); 
        for (int next : undiscovered){
            if (ii<vlen){
                if (next < adjVec[node][ii]){
                    complement.push_back(next);        
                }
                else if (next > adjVec[node][ii]){
                    eq = false;
                    while (next >= adjVec[node][ii]){
                        if (next == adjVec[node][ii]){
                            eq = true;
                        }
                        ++ii;
                    }
                    if (!eq){
                        complement.push_back(next); 
                    }
                }
                else{
                    ++ii;    
                }                    
            }
            else{
                complement.push_back(next);    
            }
        }
        
        //cout << node+1 << ": ";
        for (int next : complement) {
            q.push({next, distance+1});
            undiscovered.erase(next);
            //cout << next+1 << " ";    
            distance_node[next] = distance+1;
        }
        //cout << endl;
        
    } 
    
    vector<int> res;
    for(int i = 0; i<n; ++i){
        if (i != start){
            res.push_back(distance_node[i]);
        }
    }
    
    return res;
}
