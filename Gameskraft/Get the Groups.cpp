int find(int n, vector<int> &par) {
    int p = n;
    while(p!=par[p]) {
        // OPTIMIZATION
        par[p] = par[par[p]];
        p = par[p];
    }
    return p;
}

void Union(int n1, int n2, vector<int> &par, vector<int> &rank) {
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

vector<int> getTheGroups(int n, vector<string> queryType, vector<int> students1, vector<int> students2) {
    int q = queryType.size();
    vector<int> ans;
    vector<int> par(n+1);
    vector<int> rank(n+1,1);
    for(int i=0; i<=n; i++) {
        par[i] = i;
    }
    int current = 0;
    for(int i=0; i<q; i++) {
        if(queryType[i] == "Friend") {
            Union(students1[i], students2[i], par, rank);
        } else {
            int x = find(students1[i], par);
            int y = find(students2[i], par);
            if(x==y) ans.push_back(rank[x]);
            else ans.push_back(rank[x] + rank[y]);
        }
    }
    return ans;
}

int main() {
    int n = 4;
    vector<string> queryType = {"Friend", "Friend", "Total"};
    vector<int> students1 = {1,2,1};
    vector<int> students2 = {2,3,4};
    vector<int> res = getTheGroups(n, queryType, students1, students2);
    for(int i=0; i<res.size(); i++) {
        cout<<res[i];
    }
}
