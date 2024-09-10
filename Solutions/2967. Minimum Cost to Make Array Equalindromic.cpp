vector<long long> gen;
    void gener(){
        static bool flag = false;
        if(flag) return;
        for(int i=0; i<=99999; i++){
            // make even palindrone
            string num = to_string(i);
            string numrev = num;
            reverse(numrev.begin(), numrev.end());
            string evenPalin = num + numrev;
            string oddPalin = num + numrev.substr(1);
            gen.push_back(stoll(evenPalin));
            gen.push_back(stoll(oddPalin));
        }
        sort(gen.begin(), gen.end());
        flag = true;
    }
class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        gener();
        int cur = -1;
        long long sum = 0;
        long long totalSum = 0;
        for(int i=0; i<nums.size(); i++){
            totalSum += nums[i];
        }
        sort(nums.begin(), nums.end());
        long long ans = 1e17;
        for(int i=0; i<gen.size(); i++){
            while(cur+1 < nums.size() && nums[cur+1] <= gen[i]){
                cur++;
                sum += nums[cur];
            }
            long long leftOver = totalSum - sum;
            long long temp = abs((cur+1) * gen[i] - sum);
            temp += abs(((int)nums.size() - (cur+1)) * gen[i] - leftOver);
            ans = min(ans, temp);
        }
        return ans;
    }
};
