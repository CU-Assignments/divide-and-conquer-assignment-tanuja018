class Solution {
public:
    vector<int> tree;
    int size;
    
    Solution(int n = 100000) {
        size = n;
        tree.resize(4 * n, 0);
    }
    
    void update(int index, int l, int r, int pos, int val) {
        if (l == r) {
            tree[index] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * index, l, mid, pos, val);
        else
            update(2 * index + 1, mid + 1, r, pos, val);
        
        tree[index] = max(tree[2 * index], tree[2 * index + 1]);
    }
    
    int query(int index, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && qr >= r) return tree[index];
        int mid = (l + r) / 2;
        return max(query(2 * index, l, mid, ql, qr), query(2 * index + 1, mid + 1, r, ql, qr));
    }
    
    void update(int pos, int val) {
        update(1, 1, size, pos, val);
    }
    
    int query(int ql, int qr) {
        return query(1, 1, size, ql, qr);
    }
    
    int lengthOfLIS(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        size = maxVal;
        tree.assign(4 * maxVal, 0);
        int res = 0;
        
        for (int num : nums) {
            int left = max(1, num - k);
            int right = num - 1;
            int bestPrev = query(left, right);
            int currLen = bestPrev + 1;
            update(num, currLen);
            res = max(res, currLen);
        }   
        return res;
    }
};
