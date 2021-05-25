int vec2key(vector<int>& posts){
    int n = posts.size();
    int result = 0;
    for(int i = 0; i<n; ++i){
        result += posts[i] << 2*(n-1-i);    
    }
    return result;
}

vector<stack<int>> key2vec(int num, int n){
    vector<stack<int>> v;
    
    for(int i = 0; i<4; ++i){
        stack<int> s;
        v.push_back(s);    
    }
    
    int j;
    for(int i = (n-1); i>=0; --i){
        j = num % 4;
        num >>= 2;
        v[j].push(i);           
    }
    
    return v;
}

int stack2key(vector<stack<int>> v, int n){
    int j;
    int num = 0;
    for(int i = 0; i<4; ++i){
        while(!v[i].empty()){
            j = v[i].top();
            v[i].pop(); 
            num += i << 2*(n-1-j);       
        }        
    }
    return num;    
}

void printStacks(vector<stack<int>> v, int n){
    for (int i = 0; i<n; ++i){
        cout << "rod " << (i+1) << ": ";
        while(!v[i].empty()){
            cout << (v[i].top()+1) << " ";
            v[i].pop();
        }
        cout << endl;
    }    
}

int hanoi(vector<int> posts) {
    
    int n = posts.size();
    for(int i = 0; i<n; ++i){
        posts[i]--;
    }
    
    int key = vec2key(posts);
    
    vector<stack<int>> v = key2vec(key, n);
    pair<int, vector<stack<int>>> p(0, v); 
    queue<pair<int, vector<stack<int>>>> aQueue;
    aQueue.push(p);
    
    int vLen = 1;
    for(int i = 0; i<n; ++i){
        vLen *= 4;    
    }
    bool* visited = new bool[vLen];
    for(int i = 0; i<vLen; ++i){
        visited[i] = false;    
    }    
    int num = stack2key(v, n);
    visited[num] = true;
    int depth;
    while (!visited[0]){
        p = aQueue.front();
        aQueue.pop();
        depth = p.first;
        v = p.second;
        sort(v.begin()+1, v.end());        
        for(int i = 0; i<4; ++i){
            for(int j = 0; j<4; ++j){
                if (i == j || v[i].empty()){
                    continue;
                }else{
                    if (v[j].empty()){
                        vector<stack<int>> vNew = v;
                        vNew[j].push(v[i].top());
                        vNew[i].pop();
                        num = stack2key(vNew, n);
                        if (!visited[num]){
                            visited[num] = true;
                            aQueue.push(pair<int, vector<stack<int>>>(depth+1, vNew));
                        }    
                    } 
                    else if (v[i].top() < v[j].top()){
                        vector<stack<int>> vNew = v;
                        vNew[j].push(v[i].top());
                        vNew[i].pop();
                        num = stack2key(vNew, n);
                        if (!visited[num]){
                            visited[num] = true;
                            aQueue.push(pair<int, vector<stack<int>>>(depth+1, vNew));   
                        }                         
                    }   
                }
            }
        }        
    }
    
    
    return (depth+1);
}
