class Graph{
    int gSize;
    vector<pair<int, int>> *adjVec;
    int *distance;
    bool *spt;
public:  
  Graph(int g) : gSize{g}{
      adjVec = new vector<pair<int, int>>[gSize];
      distance = new int[gSize];
      spt = new bool[gSize];
  }
  ~Graph(){
      delete[] distance;
      delete[] spt;
  }
  void addEdge(int u, int v, int w){
      adjVec[u].push_back({v, w});
      adjVec[v].push_back({u, w});
  }
  void findSpt(){
      for(int i = 0; i<gSize; ++i){
          spt[i] = false;
          distance[i] = INT_MAX;
      }
      
      int minNode, min, node, next, weight;
      minNode = 0;
      distance[minNode] = 0;
      vector<pair<int, int>>::iterator it;
      
      priority_queue<pair<int,int>> pq;
      
      for(int i = 0; i<gSize; ++i){
          
          node = minNode;
          spt[node] = true;
          
          for(it = adjVec[node].begin(); it != adjVec[node].end(); ++it){
              next   = it->first;
              weight = it->second;
              if (!spt[next]){
                  weight = distance[node] > weight ? distance[node] : weight;
                  if (weight < distance[next]){
                      distance[next] = weight;
                      pq.push({-weight, next});
                  }  
              }
          }
          
          minNode = (pq.top()).second;
          pq.pop();
          
      }
  }
  
  int getRes(){
      if (distance[gSize-1] == INT_MAX){
          return -1; 
      }
      return distance[gSize-1];
  }
};
