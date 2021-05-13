int calcMedian(queue<int> q1){
    queue<int> q = q1;
    int median;
    vector<int> v;
    while(!q.empty())
    {   
        v.push_back(q.front());
        q.pop();
    }
    sort(v.begin(), v.end());
    int n = v.size();
    if (n%2 == 1){
        return v[n/2];
    }
    return (v[n/2]+v[n/2-1]);
}
