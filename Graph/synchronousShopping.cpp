static int powArr[10] ={2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

class Graph {
    int gSize, fishTypes, fSize;
    std::vector<std::pair<int, int>> *adjVec;
    vector<vector<int>> dist;
    int *fishes;
    public:
    Graph(int g, int k) : gSize{ g }, fishTypes{ k } {
        adjVec    = new std::vector<std::pair<int, int>>[gSize * sizeof(std::vector<std::pair<int, int>>)];
        fishes    = new int[gSize * sizeof(int)];
        fSize     = powArr[fishTypes-1];
        for(int i = 0; i < gSize; ++i){
            vector<int> v;
            for(int j = 0; j < fSize; ++j){
                v.push_back(INT_MAX);
            }
            dist.push_back(v);
        }
    }
    ~Graph() {
        delete[] adjVec;
        delete[] fishes;
    }
    void addEdge(int u, int v, int w) {
        adjVec[u].push_back(std::pair<int, int>(v, w));
        adjVec[v].push_back(std::pair<int, int>(u, w));
    }
    void addFish(int u, int n, std::vector<int> v);
    int fillDist();
    void print();
};

void Graph::print() {
    std::vector<std::pair<int, int>>::iterator it;
    for (int i = 0; i < gSize; ++i) {
        std::cout << "Node " << i << ": ";
        for (it = adjVec[i].begin(); it != adjVec[i].end(); ++it) {
            std::cout << (*it).first << "(" << (*it).second << ") ";
        }
        std::cout << std::endl;
    }
    
    for (int i = 0; i < gSize; ++i) {
        std::cout << "Node " << i << ": " << fishes[i] << std::endl;
    }
}

void Graph::addFish(int u, int n, std::vector<int> v) {
    static int arr[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    if (n != 0){
        fishes[u] = arr[v[1]-1];
        for (int i = 2; i <= n; ++i) {
            fishes[u] |= arr[v[i]-1];
        }            
    }
    else{
        fishes[u] = 0; 
    }

}

int Graph::fillDist(){
    
  queue<pair<int, pair<int, int>>> aQueue;
  dist[0][fishes[0]] = 0;
  aQueue.push({dist[0][fishes[0]], {0, fishes[0]}});
  
  int node, time, fish, adNode, weight, adFish;
  pair<int, pair<int, int>> p;  
  vector<pair<int, int>>::iterator it;
  
  while(!aQueue.empty()){
      
      p = aQueue.front();
      aQueue.pop();
      
      node = p.second.first;
      fish = p.second.second;
      time = p.first;
      
      for(it = adjVec[node].begin(); it != adjVec[node].end(); ++it){
            adNode = (*it).first;
            weight = (*it).second;
            adFish = fish | fishes[adNode];
            if ((time + weight) < dist[adNode][adFish]){
                dist[adNode][adFish] = time + weight; 
                aQueue.push({dist[adNode][adFish], {adNode, adFish}});   
            }     
        }
      
    }
    int min = INT_MAX;
    vector<pair<int, int>> v;
    if (dist[gSize-1][fSize-1] != INT_MAX){
        min = dist[gSize-1][fSize-1];
    }
    for (int j = 0; j<(fSize-1); ++j){
        if (dist[gSize-1][j] != INT_MAX){
            v.push_back({j, dist[gSize-1][j]});  
        }
    }
    
    int n = v.size();
    int maxi;
    for(int i = 0; i<n; ++i){
        for(int j = i+1; j<n; ++j){   
            if ((v[i].first | v[j].first) == (fSize-1)){
                maxi = v[i].second > v[j].second ? v[i].second : v[j].second;
                if (maxi < min){
                    min = maxi;
                }    
            }   
        } 
    }
    
    return min;
        
}

vector<int> stringToVec(string s){
    
    int n = s.size();
    
    int b, e;
    b = 0;
    vector<int> res;
    for(int i = 0; i<n; ++i){
        if (s[i] == ' '){
            e = i;
            res.push_back(stoi(s.substr(b, e-b)));
            b = i+1;    
        }
        else if (i == (n-1)){
            e = i + 1;
            res.push_back(stoi(s.substr(b, e-b)));
        }
    }
    return res;
}

int shop(int n, int k, vector<string> centers, vector<vector<int>> roads) {
    Graph aGraph(n, k);
    
    vector<vector<int>>::iterator rIt;
    
    for (rIt = roads.begin(); rIt != roads.end(); ++rIt){
        aGraph.addEdge((*rIt)[0]-1, (*rIt)[1]-1, (*rIt)[2]);
    }
    
    int nof;
    vector<string>::iterator cIt;
    vector<int> tFishes;
    int m = 0;
    for(cIt = centers.begin(); cIt != centers.end(); ++cIt){
        tFishes = stringToVec(*cIt);
        if (tFishes[0] != 0){
            aGraph.addFish(m, tFishes[0], tFishes);     
        }
        else{
            aGraph.addFish(m, 0, tFishes); 
        }
        
        ++m;  
    }

    //aGraph.print();
    
    
    return aGraph.fillDist();     
}
