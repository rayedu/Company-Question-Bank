// FINDING PARENT OF A NODE
int find(int n, vector<int> &par) {
    int p = n;
    while(p!=par[p]) {
        // OPTIMIZATION
        par[p] = par[par[p]];
        p = par[p];
    }
    return p;
}

// UNION 2 COMPONENTS
unionF(int n1, int n2, vector<int> &par, vector<int> &rank) {
    int p1 = find(n1, par);
    int p2 = find(n2, par);

    // ELEMENTS HAVE SAME PARENT, SO REDUNDANT NODE FOUND, RETURN
    if(p1 == p2)
        return;

    // SMALLER RANK COMPONENT IS JOINED W/ HIGHER RANK COMPONENT
    if(rank[p1] > rank[p2]) {
        par[p2] = p1;
        rank[p1] += rank[p2];
    } else {
        par[p1] = p2;
        rank[p2] += rank[p1];
    }
}

bool cmp(vector<int> &a, vector<int> &b) {
    if(a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

int main() {
    
    int n=5, d=1;
    vector<int> x = {0,0,1,1,2};
    vector<int> y = {0,1,0,1,2};
    
    vector<int> par(n);
    vector<int> rank(n, 1);
    for(int i=0; i<n; i++) {
        par[i]=i;
    }
    vector<vector<int>> res;
    for(int i=0; i<n; i++) {
        res.push_back({x[i],y[i],i});
    }
    sort(res.begin(), res.end());
    for(int i=1; i<n; i++) {
        if(res[i][0] == res[i-1][0] && abs(res[i][1] - res[i-1][1])<=d)
            unionF(res[i][2], res[i-1][2], par, rank);
    }
    sort(res.begin(), res.end(), cmp);
    for(int i=1; i<n; i++) {
        if(res[i][1] == res[i-1][1] && abs(res[i][0] - res[i-1][0])<=d)
            unionF(res[i][2], res[i-1][2], par, rank);
    }
    unordered_set<int> s;
    for(int i=0; i<n; i++) {
        s.insert(par[i]);
    }
    cout<<s.size();
}
