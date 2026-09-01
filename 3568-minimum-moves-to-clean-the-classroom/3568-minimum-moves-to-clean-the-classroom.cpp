#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startX = -1, startY = -1;
        vector<pair<int, int>> litters;
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    startX = r;
                    startY = c;
                } else if (classroom[r][c] == 'L') {
                    litters.push_back({r, c});
                }
            }
        }
        
        int totalLitter = litters.size();
        int targetMask = (1 << totalLitter) - 1;
        
        if (targetMask == 0) return 0; // No litter to collect
        
        // Map (row, col) of litter to its bit index
        auto getLitterIndex = [&](int r, int c) {
            for (int i = 0; i < totalLitter; ++i) {
                if (litters[i].first == r && litters[i].second == c) return i;
            }
            return -1;
        };

        // max_energy[r][c][mask] stores maximum remaining energy
        vector<vector<vector<int>>> max_energy(
            m, vector<vector<int>>(n, vector<int>(1 << totalLitter, -1))
        );
        
        // Queue stores {row, col, mask, current_energy}
        queue<tuple<int, int, int, int>> q;
        
        q.push({startX, startY, 0, energy});
        max_energy[startX][startY][0] = energy;
        
        int moves = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, curEnergy] = q.front();
                q.pop();
                
                if (mask == targetMask) return moves;
                if (curEnergy == 0) continue; // Cannot move further without energy
                
                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;
                    
                    int nenergy = curEnergy - 1;
                    int nmask = mask;
                    
                    char cell = classroom[nr][nc];
                    if (cell == 'L') {
                        int idx = getLitterIndex(nr, nc);
                        if (idx != -1) nmask |= (1 << idx);
                    } else if (cell == 'R') {
                        nenergy = energy; // Reset to full capacity
                    }
                    
                    if (nenergy > max_energy[nr][nc][nmask]) {
                        max_energy[nr][nc][nmask] = nenergy;
                        q.push({nr, nc, nmask, nenergy});
                    }
                }
            }
            moves++;
        }
        
        return -1;
    }
};