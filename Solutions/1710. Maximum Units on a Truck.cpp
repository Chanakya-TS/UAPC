class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Swap elements to make code easier
        int n = boxTypes.size();
        for(int i=0; i<n; i++){
            swap(boxTypes[i][0], boxTypes[i][1]);
        }
        // Sort boxes based on number of units per box, descending order
        sort(boxTypes.begin(), boxTypes.end());
        reverse(boxTypes.begin(), boxTypes.end());

        // Iterate through boxes, and add as many as possible
        int ans = 0;
        for(int i=0; i<n; i++){
            int boxesToAdd = min(truckSize, boxTypes[i][1]);
            ans += boxesToAdd * boxTypes[i][0];
            truckSize -= boxesToAdd;
        }
        return ans;
    }
};
