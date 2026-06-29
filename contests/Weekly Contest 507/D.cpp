class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        int n = value.size();
        const int mod = 1e9+7;
        
        auto count_selection = [&] (int x){
            long long total = 0;
            for(int i=0;i<n;i++){
                if(value[i] >= x){
                    long long k = (value[i] - x)/decay[i] + 1;
                    total+=k;
                    if(total > m) return total;
                }
            }
            return total;
        };

        int st=0, end=1e9+1;
        int ansX = 0;
        while(st <= end){
            int mid = (st+end)/2;
            if(count_selection(mid) <= m){
                ansX = mid;
                end=mid-1;
            }
            else st=mid+1;
        }

        long long total_sum = 0, total_picked = 0;
        for(int i=0;i<n;i++){
            if(value[i] >= ansX){
                long long k = (value[i] - ansX)/decay[i] + 1;
                long long a = value[i];
                long long l = value[i] - (k-1)*decay[i];

                long long ap_sum = 1ll*(k*(a+l))/2;
                ap_sum %= mod;
                total_sum = (total_sum + ap_sum)%mod;
                total_picked += k;
            }
        }

        long long left = m - total_picked;
        if(ansX - 1 >= 1 && left > 0){
            long long left_value = (left * end)%mod;
            left_value %= mod;
            total_sum = (total_sum + left_value)%mod;
        }
        return total_sum;
    }
};