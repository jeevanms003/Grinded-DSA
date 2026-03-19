class Solution {
public:

    void solve(int index, vector<int>& candidates, int target,
               vector<int>& temp, vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

        for(int i = index; i < candidates.size(); i++)
        {
            if(i > index && candidates[i] == candidates[i-1])
                continue;

            if(candidates[i] > target)
                break;

            temp.push_back(candidates[i]);

            solve(i + 1, candidates, target - candidates[i], temp, ans);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, candidates, target, temp, ans);

        return ans;
    }
};

Example for Recursion Tree
candidates = [10,1,2,7,6,1,5]
target = 8

After sorting:

[1,1,2,5,6,7,10]
Recursion Tree
solve(0,8)   []
│
├── take 1 → solve(1,7)   [1]
│   │
│   ├── take 1 → solve(2,6)   [1,1]
│   │   │
│   │   ├── take 2 → solve(3,4)   [1,1,2]
│   │   │   ├── 5 > 4 → break
│   │   │
│   │   ├── take 5 → solve(4,1)   [1,1,5]
│   │   │   ├── 6 > 1 → break
│   │   │
│   │   └── take 6 → solve(5,0)   [1,1,6] ✓
│   │
│   ├── take 2 → solve(3,5)   [1,2]
│   │   │
│   │   ├── take 5 → solve(4,0)   [1,2,5] ✓
│   │   └── 6 > 5 → break
│   │
│   ├── take 5 → solve(4,2)   [1,5]
│   │   ├── 6 > 2 → break
│   │
│   ├── take 6 → solve(5,1)   [1,6]
│   │   ├── 7 > 1 → break
│   │
│   └── take 7 → solve(6,0)   [1,7] ✓
│
├── skip duplicate 1
│
├── take 2 → solve(3,6)   [2]
│   │
│   ├── take 5 → solve(4,1)   [2,5]
│   │   ├── 6 > 1 → break
│   │
│   └── take 6 → solve(5,0)   [2,6] ✓
│
├── take 5 → solve(4,3)   [5]
│   ├── 6 > 3 → break
│
├── take 6 → solve(5,2)   [6]
│   ├── 7 > 2 → break
│
├── take 7 → solve(6,1)   [7]
│   ├── 10 > 1 → break
│
└── take 10 → solve(7,-2) ✗