vector<int> maximize_value(vector<int>&arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if(n<=2) {
        return arr;
    }
    vector<int> ans;
    int k = 0, j = 0;
    if(n % 2 == 0) {
        j = (n-1) / 2;
    } 
    else {
        j=n/2;
    }
    ans.push_back(arr[j++]);
    ans.push_back(arr[j++]);
    for(int i = 2; i<n ; i++) {
        if(i % 2 == 0) {
            ans.push_back(arr[k++]);
        } 
        else {
            ans.push_back(arr[j++]);
        }
    }
    return ans;
}

int main() {
    vector<int>arr={21,9,7,5,34};
    vector<int>ans=maximize_value(arr);
    for(auto &x:ans){
        cout<<x<<" ";
    }
    return 0;
}
