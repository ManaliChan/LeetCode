//Solution by disjoint set

class DisjointSet {
public:

    vector<int> parent, size;

    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int findpar(int node)
    {
        if(parent[node]==node)
            return node;

        return parent[node]=findpar(parent[node]);
    }

    void unite(int x,int y)
    {
        int px=findpar(x);
        int py=findpar(y);

        if(px==py) return;

        if(size[px]<size[py])
        {
            parent[px]=py;
            size[py]+=size[px];
        }
        else
        {
            parent[py]=px;
            size[px]+=size[py];
        }
    }
};

class Solution {
public:

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        DisjointSet ds(n*m);

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0) continue;

                int node=i*m+j;

                for(int k=0;k<4;k++)
                {
                    int nr=i+dr[k];
                    int nc=j+dc[k];

                    if(nr>=0 && nr<n && nc>=0 && nc<m &&
                       grid[nr][nc]==1)
                    {
                        int adj=nr*m+nc;
                        ds.unite(node,adj);
                    }
                }
            }
        }

        unordered_map<int,int> freq;
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    int root = ds.findpar(i * m + j);
                    freq[root]++;
                    ans = max(ans, freq[root]);
                }
            }
        }

        return ans;
    }
};