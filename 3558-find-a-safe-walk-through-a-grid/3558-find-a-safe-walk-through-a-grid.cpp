class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row = grid.size();
        int col = grid[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>>
            q;
        vector<vector<int>> vis(row, vector<int>(col, 0));
        if (grid[0][0] == 1)
            q.push({health - 1, {0, 0}});
        else
            q.push({health, {0, 0}});
        vis[0][0] = 1;
        while (!q.empty()) {
            auto it = q.top();
            int val = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if (r == row - 1 && c == col - 1) {
                if (val >= 1)
                    return true;
            }
            q.pop();
            int dr[4] = {-1, 0, 1, 0};
            int dc[4] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];
                if (newr >= 0 && newr < row && newc >= 0 && newc < col &&
                    !vis[newr][newc] && grid[newr][newc] == 1) {
                    vis[newr][newc] = 1;
                    q.push({val - 1, {newr, newc}});
                } else if (newr >= 0 && newr < row && newc >= 0 && newc < col &&
                           !vis[newr][newc] && grid[newr][newc] == 0) {
                    vis[newr][newc] = 1;
                    q.push({val, {newr, newc}});
                }
            }
        }
        return false;
    }
};