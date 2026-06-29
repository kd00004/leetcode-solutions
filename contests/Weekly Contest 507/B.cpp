class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> pref(n+1);
        int ans = 0;
        for(int i=0;i<n;i++){
            pref[i+1] = pref[i] + nums[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                long long sum = pref[j+1] - pref[i];
                int last = sum%10;
                int first = -1;
                while(sum > 0){
                    first = sum%10;
                    sum/=10;
                }
                if(x == first && x == last) ans++;
            }
        }
        return ans;
    }
};