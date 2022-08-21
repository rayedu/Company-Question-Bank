char findLongestSingleSlot(vector<vector<int>> leaveTimes) {
    int prev = 0, duration = 0, maxDuration = 0, id = 0;
    int n = leaveTimes.size();
    for(int i=0; i<n; i++) {
        duration = leaveTimes[i][1]-prev;
        prev = leaveTimes[i][1];
        if(duration > maxDuration) {
            maxDuration = duration;
            id = leaveTimes[i][0];
        }
    }
    return (char)(id+97);
}

int main() {
    vector<vector<int>> leaveTimes = {{0,3}, {2,5}, {0,9}, {1,15}};
    char ans = findLongestSingleSlot(leaveTimes);
    cout<<ans;
}
