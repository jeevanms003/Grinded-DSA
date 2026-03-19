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

        if(target < 0)
            return;

        for(int i = index; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]);

            solve(i, candidates, target - candidates[i], temp, ans);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, candidates, target, temp, ans);

        return ans;
    }
};

Recursion Tree
solve(0, target=7)  []
│
├── take 2 → solve(0,5)  [2]
│   │
│   ├── take 2 → solve(0,3)  [2,2]
│   │   │
│   │   ├── take 2 → solve(0,1)  [2,2,2]
│   │   │   │
│   │   │   ├── take 2 → solve(0,-1) ✗
│   │   │   ├── take 3 → solve(1,-2) ✗
│   │   │   ├── take 6 → solve(2,-5) ✗
│   │   │   └── take 7 → solve(3,-6) ✗
│   │   │
│   │   ├── take 3 → solve(1,0)  [2,2,3] ✓
│   │   │
│   │   ├── take 6 → solve(2,-3) ✗
│   │   └── take 7 → solve(3,-4) ✗
│   │
│   ├── take 3 → solve(1,2)  [2,3]
│   │   │
│   │   ├── take 3 → solve(1,-1) ✗
│   │   ├── take 6 → solve(2,-4) ✗
│   │   └── take 7 → solve(3,-5) ✗
│   │
│   ├── take 6 → solve(2,-1) ✗
│   └── take 7 → solve(3,-2) ✗
│
├── take 3 → solve(1,4)  [3]
│   │
│   ├── take 3 → solve(1,1)  [3,3]
│   │   │
│   │   ├── take 3 → solve(1,-2) ✗
│   │   ├── take 6 → solve(2,-5) ✗
│   │   └── take 7 → solve(3,-6) ✗
│   │
│   ├── take 6 → solve(2,-2) ✗
│   └── take 7 → solve(3,-3) ✗
│
├── take 6 → solve(2,1)  [6]
│   │
│   ├── take 6 → solve(2,-5) ✗
│   └── take 7 → solve(3,-6) ✗
│
└── take 7 → solve(3,0)  [7] ✓