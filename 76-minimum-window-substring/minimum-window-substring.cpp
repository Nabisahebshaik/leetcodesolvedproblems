class Solution {
public:
    string minWindow(string s, string t) {
        // If s is shorter than t, it's impossible to find the target
        if (s.length() < t.length() || t.length() == 0) return "";

        vector<int> t_count(128, 0); // Demand book for 128 ASCII characters
        int matched = 0;             // Keep track of how many required characters we found

        // 1. Record the required characters in our demand book
        for (int i = 0; i < t.length(); i++) {
            t_count[t[i]]++;
        }

        int left = 0;
        int minLen = INT_MAX; // Start with infinity as the minimum length
        int startIdx = 0;     // Starting index for our final scissors cut

        // 2. Expand the window by moving the right pointer
        for (int right = 0; right < s.length(); right++) {
            char ch = s[right]; 
            
            // If this character is useful (demand > 0)
            if (t_count[ch] > 0) {
                matched++; // Yay! We found a required piece
            }
            
            // Decrease demand for every character that enters the window
            t_count[ch]--; 

            // 3. When all characters are matched, start shrinking the window
            while (matched == t.length()) {
                
                // Update record: If current window is the smallest so far
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1; // New minimum length record
                    startIdx = left;           // Mark where to cut
                }

                // Grab the left character (getting ready to remove it)
                char leftChar = s[left];
                
                // Since it's leaving the window, increase its demand back in the book
                t_count[leftChar]++; 

                // Alarm check: If a required character was removed (demand > 0)
                if (t_count[leftChar] > 0) {
                    matched--; // Our 100% match is broken, exit the shrink loop
                }
                
                // Move left pointer forward to shrink the window
                left++; 
            }
        }

        // 4. Final check: If minLen never changed, no valid window was found
        if (minLen == INT_MAX) return "";

        // 5. Cut the exact piece from the string and return it
        return s.substr(startIdx, minLen);
    }
};