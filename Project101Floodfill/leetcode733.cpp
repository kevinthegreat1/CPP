//
// Created by Kevin Yang on 3/4/21.
//

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        queue<int> q1, q2;
        q1.push(sr);
        q2.push(sc);
        while (!q1.empty()) {
            int x = q1.front();
            int y = q2.front();
            q1.pop();
            q2.pop();
            if (x + 1 < image.size()) {
                if (image[x + 1][y] == oldColor) {
                    image[x + 1][y] = newColor;
                    q1.push(x + 1);
                    q2.push(y);
                }
            }
            if (x > 0) {
                if (image[x - 1][y] == oldColor) {
                    image[x - 1][y] = newColor;
                    q1.push(x - 1);
                    q2.push(y);
                }
            }
            if (y + 1 < image[0].size()) {
                if (image[x][y + 1] == oldColor) {
                    image[x][y + 1] = newColor;
                    q1.push(x);
                    q2.push(y + 1);
                }
            }
            if (y > 0) {
                if (image[x][y - 1] == oldColor) {
                    image[x][y - 1] = newColor;
                    q1.push(x);
                    q2.push(y - 1);
                }
            }
        }
        return image;
    }
};