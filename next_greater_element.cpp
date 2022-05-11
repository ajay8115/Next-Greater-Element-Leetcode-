#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums)
    {
        int n = nums.size();
        stack<int> s;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            while (s.size() && s.top() < nums[i])
            {
                m[s.top()] = nums[i];
                s.pop();
            }
            s.push(nums[i]);
        }

        vector<int> ans;
        for (int i = 0; i < findNums.size(); i++)
        {
            if (m.find(findNums[i]) != m.end())
            {
                ans.push_back(m[findNums[i]]);
            }
            else
            {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};