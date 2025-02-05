class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (const auto& b : buildings) {
            events.push_back({b[0], -b[2]}); 
            events.push_back({b[1], b[2]});  
        }
        sort(events.begin(), events.end());
        
        map<int, int> heights = {{0, 1}};
        vector<vector<int>> result;
        int prevMax = 0;
        
        for (const auto& event : events) {
            if (event.second < 0) {
                heights[-event.second]++;
            } else {
                if (--heights[event.second] == 0) {
                    heights.erase(event.second);
                }
            }
            
            int currMax = heights.rbegin()->first;
            if (currMax != prevMax) {
                result.push_back({event.first, currMax});
                prevMax = currMax;
            }
        }
        return result;
    }
};
