class Solution {
public:
    int dfs(vector<vector<int>>& dp, vector<vector<int>>& grid, vector<vector<int>>& v, int n, int m, int i, int j){
        v[i][j] = 1;
        int nrow[] = {1,0,-1,0};
        int ncol[] = {0,-1,0,1};
        int temp = 0;
        
        for(int k = 0; k < 4; k++){
            int nr = i + nrow[k];
            int nc = j + ncol[k];
            
            // Check bounds
            if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                // Strictly increasing condition
                if(grid[nr][nc] > grid[i][j]){
                    if(v[nr][nc]){
                        temp = max(temp, dp[nr][nc]); // Use memoized result
                    } else {
                        dp[nr][nc] = dfs(dp, grid, v, n, m, nr, nc); // Compute result
                        temp = max(temp, dp[nr][nc]);
                    }
                }
            }
        }
        return 1 + temp;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        
        vector dp(n, vector<int>(m, 1));
        vector vis(n, vector<int>(m, 0));
        int ans = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    dp[i][j] = dfs(dp, matrix, vis, n, m, i, j);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};