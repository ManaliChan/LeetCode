class Solution {
public:

    int dissolve(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return 0;
        }
        if(!grid[i][j]){
            return 0;
        }
        grid[i][j]=0;
        return (1 + dissolve(grid, i, j+1)+ dissolve(grid, i, j-1)+ dissolve(grid, i+1, j)+ dissolve(grid, i-1, j));
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    int temp=dissolve(grid, i, j);
                    ans=max( temp, ans);
                }
            }
        }
        return ans;
    }
};