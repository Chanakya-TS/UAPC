class Solution {
public:
    stack<int> topSort;
    vector<vector<int>> adj;
    vector<int> vis;
    void dfs(int cur){
        if(vis[cur]) return;
        vis[cur] = true;
        for(auto e: adj[cur]){
            dfs(e);
        }
        topSort.push(cur);
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        adj.resize(n);
        vis.resize(n, 0);
        // Generate if you can jump from pillar i to j for every i, j
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=max(0, i-d); j--){
                if(arr[j] < arr[i]){
                    adj[i].push_back(j);
                } else {
                    break;
                }
            }
            for(int j=i+1; j<min(n, i+d+1); j++){
                if(arr[j] < arr[i]) {
                    adj[i].push_back(j);
                } else {
                    break;
                }
            }
        }

        // Topological sort
        for(int i=0; i<n; i++){
            if(!vis[i]) dfs(i);
        }

        // DP
        vector<int> ans(n, 1);
        while(topSort.size()){
            int cur = topSort.top();
            topSort.pop();
            for(auto e: adj[cur]){
                ans[e] = max(ans[e], ans[cur] + 1);
            }
        }
        int fin_ans = 0;
        for(int i=0; i<n; i++){
            fin_ans = max(fin_ans, ans[i]);
        }
        return fin_ans;

    }
};
