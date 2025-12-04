class Solution 
{ 
    // time->O(N+M)
    // Question:76. Minimum Window Substring(Leetcode)
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char,int> mp;
        int n = s.size(), m = t.size();
        if (m == 0 || n == 0) return "";

        // frequency map of t
        for (int i = 0; i < m; i++) 
        {
            mp[t[i]]++;
        }

        int l = 0, r = 0, count = 0;
        int minLen = INT_MAX, startIndex = -1;

        while (r < n) 
        {
            char c = s[r];

            // if this char is needed, we reduce remaining count
            if (mp[c] > 0) 
            {
                count++;
            }
            mp[c]--;  // we took this char into the window

            // when all m chars are matched
            while (count == m) 
            {
                // update answer before shrinking
                if (r - l + 1 < minLen) 
                {
                    minLen = r - l + 1;
                    startIndex = l;
                }

                char left = s[l];
                mp[left]++;          // removing left from window
                if (mp[left] > 0) 
                {  // now we need this char again
                    count--;
                }
                l++;
            }

            r++;
        }

        if (startIndex == -1) return "";
        return s.substr(startIndex, minLen);
    }
};
