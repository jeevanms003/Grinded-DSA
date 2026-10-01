class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> left(n);
        vector<int> right(n);
        vector<int> result(n);

        // left array
        left[0] = 1;
        for(int i = 1; i < n; i++){
            left[i] = left[i-1] * nums[i-1];
        }

        // right array
        right[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            right[i] = right[i+1] * nums[i+1];
        }

        // final result
        for(int i = 0; i < n; i++){
            result[i] = left[i] * right[i];
        }

        return result;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> result(n);

        // left products
        result[0] = 1;
        for(int i = 1; i < n; i++) {
            result[i] = result[i-1] * nums[i-1];
        }

        // right products
        int rightProduct = 1;
        for(int i = n-1; i >= 0; i--) {
            result[i] = result[i] * rightProduct;
            rightProduct *= nums[i];
        }

        return result;
    }
};
