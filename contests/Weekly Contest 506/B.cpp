class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i=0;i<n;i++){
            unordered_map<int, int> count;
            unordered_map<int, int> freq_count;
            for(int j=i;j<n;j++){
                int val = nums[j];
                if(count[val] > 0){
                    freq_count[count[val]]--;
                    if(freq_count[count[val]] == 0) freq_count.erase(count[val]);
                }
                count[val]++;
                freq_count[count[val]]++;
                if(count.size() == 1) ans = max(ans, j-i+1);
                else if(freq_count.size() == 2){
                    auto it = freq_count.begin();
                    int f1 = it->first;
                    int f2 = (++it)->first;

                    if(min(f1, f2) * 2 == max(f1, f2)) ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};