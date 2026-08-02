class Solution {
public:
    string minWindow(string s, string t) {

        // If t is longer than s, answer is impossible
        if (t.size() > s.size())
            return "";

        // Frequency array to store required characters
        vector<int> freq(128, 0);

        // Store frequency of every character in t
        for (char ch : t)
            freq[ch]++;

        int left = 0;
        int right = 0;

        // Number of characters still needed
        int count = t.size();

        // Store minimum window information
        int minLen = INT_MAX;
        int startIndex = 0;

        while (right < s.size()) {

            // If current character is still needed
            if (freq[s[right]] > 0)
                count--;

            // Include current character into window
            freq[s[right]]--;

            // Expand window
            right++;

            // Window is valid
            while (count == 0) {

                // Update answer
                if (right - left < minLen) {
                    minLen = right - left;
                    startIndex = left;
                }

                // Remove left character from window
                freq[s[left]]++;

                // If it becomes required again,
                // window becomes invalid
                if (freq[s[left]] > 0)
                    count++;

                // Shrink window
                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(startIndex, minLen);
    }
};