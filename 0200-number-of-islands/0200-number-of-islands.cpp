class Solution {
public:
    vector<int> parent;

    int findPar(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = findPar(parent[x]);
    }

    void unite(int x, int y) {
        int px = findPar(x);
        int py = findPar(y);

        if (px != py)
            parent[px] = py;
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        parent.resize(m * n);

        for (int i = 0; i < m * n; i++)
            parent[i] = i;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '0')
                    continue;

                int idx1 = i * n + j;

                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && ni < m &&
                        nj >= 0 && nj < n &&
                        grid[ni][nj] == '1') {

                        int idx2 = ni * n + nj;
                        unite(idx1, idx2);
                    }
                }
            }
        }

        unordered_set<int> st;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1')
                    st.insert(findPar(i * n + j));
            }
        }

        return st.size();
    }
};