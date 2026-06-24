class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> candidates, others;
        multiset<int> initialCandidates, initialOthers;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for(int i=0;i<max(0, n-k);i++) initialOthers.insert(sorted[i]);
        for(int i=max(0, n-k); i<n; i++) initialCandidates.insert(sorted[i]);
        long long ans = INT_MIN;

        for(int start = 0; start < n; start++){
            candidates = initialCandidates;
            others = initialOthers;

            long long currSum = 0;

            for(int end = start; end < n; end++){
                if(!others.empty()){
                    // if nums[end] is in others we need to take max element from 
                    // candidates, but this nums[end] could be useful later so we 
                    // put it in candidates
                    auto it = others.find(nums[end]);
                    if(it != others.end()){
                        others.erase(it);
                        candidates.insert(nums[end]);
                    }
                    // if nums[end] is in candidates take the max in others and place it in
                    // candidates since it could be useful. We already have one element from
                    // candidates in the current subarray so we are saving one swap
                    else{
                        auto it2 = prev(others.end());
                        candidates.insert(*it2);
                        others.erase(it2);
                    }
                }
                
                auto itMax = prev(candidates.end());
                currSum += *itMax;
                candidates.erase(itMax);
                ans = max(ans, currSum);
            }
        }

        return ans;
    }
};