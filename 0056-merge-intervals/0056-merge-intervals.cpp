class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         // If there are no intervals, return empty array
        if (intervals.empty()) {
            return {};
        }
        
        // Step 1: Sort intervals by their start time
        sort(intervals.begin(), intervals.end());
        
        // Step 2: Create result array and add first interval
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        
        // Step 3: Check each interval starting from the second one
        for (int i = 1; i < intervals.size(); i++) {
            // Get the last interval in our result
            vector<int>& last = merged.back();
            
            // If current interval overlaps with last interval in result
            if (intervals[i][0] <= last[1]) {
                // Merge them by updating the end time
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // No overlap, add current interval to result
                merged.push_back(intervals[i]);
            }
        }
        
        return merged;
    }
};