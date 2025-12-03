// solved on "Code 360"
// Question: Longest Substring with At Most K Distinct Characters
#include<bits/stdc++.h>

int kDistinctChars(int k, string &str)
{
    // Write your code here
    unordered_map<int,int>mp;
    int ans=0;
    
    int l=0,r=0,n=str.size();
    while(r < n)
    {
        mp[str[r]]++;

        if(mp.size() > k)
        {
            mp[str[l]]--;
            if(mp[str[l]]==0)
            {
                mp.erase(str[l]);
            }
            l++;
        }
        ans=max(ans,(r-l+1));
        r++;
    }
    return ans;
}


