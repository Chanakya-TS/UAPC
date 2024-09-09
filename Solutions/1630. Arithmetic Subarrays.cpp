// Easier solution can be found in the forum
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> answer(m);
        for(int i=0; i<m; i++){
            multiset<int> range;
            for(int j=l[i]; j<= r[i]; j++){
                range.insert(nums[j]);
            }

            int ini = -1e9;
            int diff = -1e9;
            bool okay = true;
            for(auto e: range){
                if(ini == -1e9) ini = e;
                else if (diff == -1e9){
                    diff = e - ini;
                    ini = e;
                } else {
                    okay &= (e-ini) == diff;
                    ini = e;
                }
            }
            answer[i] = okay;
        }
        return answer;
    }
};
