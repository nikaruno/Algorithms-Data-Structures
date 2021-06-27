#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsInHackerland' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY roads
 */

typedef pair<int, pair<int, int>> edge;

class Graph{
    int gSize, numEdges;
    vector<edge> edges;
    int* root;
    int* rank;
public:
    Graph(int g, int n) : gSize{g}, numEdges{n}{
        root = new int[gSize];
        rank = new int[gSize];
        for(int i = 0; i<gSize; ++i){
            rank[i] = 0;
            root[i] = i;
        }
    }
    
    ~Graph(){
        delete[] root;
        delete[] rank;
    }
    
    void addEdge(int u, int v, int w){
        edges.push_back({w, {u, v}});
    }
    
    int find(int u){
        if (root[u] != u){
            root[u] = find(root[u]);
        }    
        return root[u];
    }
    
    void munion(int u, int v){
        int uroot = find(u);
        int vroot = find(v);
        
        if(rank[u]<rank[v]){
            root[u] = v;
        }
        else if (rank[v] < rank[u]){
            root[v] = u;
        }
        else{
            root[v] = u;
            ++rank[u];
        }
    }
    
    vector<edge> mst(){
        
        vector<edge> mstEdges;
        sort(edges.begin(), edges.end());
        
        int count = 0;
        int ii = 0;
        int u, v;
        
        while( count < (gSize-1)){
            
            u = edges[ii].second.first;
            v = edges[ii].second.second;
            
            u = find(u);
            v = find(v);
            
            if (u != v){
                mstEdges.push_back(edges[ii]);
                ++count;
                munion(u, v);
            }
            
            ++ii;
            
        }
        
        return mstEdges;
        
    }

};

int dfs(int u, bool* visited, vector<pair<int, int>>* adjVec, unsigned int* edgeCoef, int n){
    
    int count  = 1;
    int temp;
    visited[u] = true;
    
    vector<pair<int, int>>::iterator it;
    
    for(it = adjVec[u].begin(); it != adjVec[u].end(); ++it){
        if (!visited[(*it).first]){
            temp = dfs((*it).first, visited, adjVec, edgeCoef, n);
            edgeCoef[(*it).second] += temp*(n-temp);
            count += temp;
        }
    }
    
    return count;
}

stringstream roadsInHackerland(int n, vector<vector<int>> roads) {
    
    int m = roads.size();
    Graph aGraph{n, m};
    
    
    for(int i = 0; i<m; ++i){
        aGraph.addEdge(roads[i][0]-1, roads[i][1]-1, roads[i][2]);
    }
    
    vector<edge> mstEdges = aGraph.mst();
    
    vector<pair<int, int>>* adjVec = new vector<pair<int, int>>[n];
    
    int u, v, w;
    for(int i = 0; i<(n-1); ++i){
        u = mstEdges[i].second.first; 
        v = mstEdges[i].second.second;
        w = mstEdges[i].first; 
        adjVec[u].push_back({v, w});
        adjVec[v].push_back({u, w});      
    }
    
    bool* visited = new bool[n];
    for(int i = 0; i<n; ++i){
        visited[i] = false;
    }
    int m2 = 2*m;
    
    unsigned int* edgeCoef = new unsigned int[m2];
    int* binary  = new int[m2];
    for(int i = 0; i<(m2); ++i){
        edgeCoef[i] = 0;    
        binary[i] = 0;
    }
    
    dfs(0, visited, adjVec, edgeCoef, n);
    
    
    
    unsigned int x;
    int j, k;
    for(unsigned int i = 0; i<m2; ++i){
        x = edgeCoef[i];
        j = i;
        if (x != 0){
           while (x>0){
               if (x % 2 == 1){
                   k = j;
                   if (binary[k] == 0){
                       binary[k] = 1;
                   }
                   else{
                       while(binary[k] == 1){
                           binary[k] = 0;
                           ++k;
                       }
                       binary[k] = 1;                       
                   }
               }
               x >>= 1;
               ++j;
           } 
        }   
        
    }   
    
    
    std::stringstream buffer; 
    
    int z;
    
    for(int i = (m2-1); i>=0; --i){
        if (binary[i] == 1){
            z = i;
            break;
        }   
    }
    for(int i = z; i>=0; --i){
        if (binary[i] == 1){
            buffer << "1";
            //result += "1";    
        }
        else{
            buffer << "0";
            //result += "0";  
        }    
    }
    
    return buffer;  
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    fout.precision(200000);

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> roads(m);

    for (int i = 0; i < m; i++) {
        roads[i].resize(3);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int roads_row_item = stoi(roads_row_temp[j]);

            roads[i][j] = roads_row_item;
        }
    }

    
    
    std::stringstream ss = roadsInHackerland(n, roads);
    
    fout << ss.rdbuf();

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
