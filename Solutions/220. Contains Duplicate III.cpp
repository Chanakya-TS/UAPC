class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int rp = -1;
        multiset<int> vals;
        for(int i=0; i<nums.size(); i++){
            while(rp+1 < nums.size() && rp + 1 -i <= indexDiff){
                auto up = vals.upper_bound(nums[rp+1]);
                cout << nums[rp+1] << endl;
                if(up != vals.end()){
                    int pos1 = *up;
                    if(abs(nums[rp+1] - pos1) <= valueDiff) return true;
                }
                if(vals.size() && up != vals.begin()){
                    up = prev(up);
                    int pos2 = *up;
                    if(abs(nums[rp+1] - pos2) <= valueDiff) return true;
                }
                vals.insert(nums[rp+1]);
                rp++;
            }
            vals.extract(nums[i]);
        }
        return false;
    }
};
