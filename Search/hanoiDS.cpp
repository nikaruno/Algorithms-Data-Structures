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
    cout << key << endl;
    
    vector<stack<int>> v = key2vec(key, n);
    
    printStacks(v, 4);
    cout << stack2key(v, n) << endl;
    
    return -1;
}
