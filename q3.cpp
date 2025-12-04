class Solution 
{
  public:
//   channel-> Coding at a Scale (Youtube)
//   Question: Minimum Window Subsequence (gfg)

    string minWindow(string S, string T) 
    {
        string window = "";
        int j = 0;
        int minLen = S.size() + 1;

        for (int  i = 0; i < S.size(); i++) 
        {
            if (S[i] == T[j]) 
            {
                j++;

                // Full T matched
                if (j == T.size()) 
                {
                    int  end = i+1;   // end index (exclusive)
                    j--;                 // move j to last char of T

                    // backward shrinking
                    while (j >= 0) 
                    {
                        if (S[i] == T[j])
                            j--;
                        i--;
                    }

                    j++;   // restore j
                    i++;   // move i to correct window start

                    int len = end - i;
                    if (len < minLen) 
                    {
                        minLen = len;
                        window = S.substr(i, len);
                    }
                }
            }
        }

        return window;
    }

};
