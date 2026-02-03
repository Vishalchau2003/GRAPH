#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();
        int val = image[sr][sc];
        if (val == color)
            return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    image[nrow][ncol] == val) {
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                    // You don’t need tp use vis[][] if you change the color
                    // immediately (because recolored cells won’t be revisited).
                   //agar color kar denge toh it wont match with [sr][sc] of given pixel so it wont be visited again
                }
            }
        }
        return image;
    }
};





int main() {

    int n;
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    
    Solution sol;
    cout << sol.orangesRotting(isConnected);

    return 0;
}
