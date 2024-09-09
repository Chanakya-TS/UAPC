class StockSpanner {
public:
int prev;
    vector<int> nums;
    int ans;
    StockSpanner() {
        prev = 1e9;
        ans = 0;
    }
    
    int next(int price) {
        if(price < prev){
            ans = 1;
            nums.push_back(price);
        } else {
            while(ans <= nums.size() && nums[nums.size() - ans] <= price){
                ans++;
            }
            nums.push_back(price);
        }
        prev = price;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
