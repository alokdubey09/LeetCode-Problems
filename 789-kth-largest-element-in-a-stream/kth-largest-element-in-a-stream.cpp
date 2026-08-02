class KthLargest {
    int n;
    priority_queue<int, vector<int>, greater<int>> minheap;
public:
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(auto num : nums){
            minheap.push(num);
            if(minheap.size()>k) minheap.pop();
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size() > n) minheap.pop();
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */