class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        vector<pair<int, int>> vp;
        for(auto unit : units){
            sort(unit.begin(), unit.end());
            if(unit.size() > 1) vp.push_back({unit[0], unit[1]});
            else vp.push_back({unit[0], unit[0]});
        }
        sort(vp.begin(), vp.end());
        long long ssum = 0;
        for(int i=0;i<(int)vp.size(); i++){
            ssum += vp[i].second;
        }
        long long ans = -1;
        for(int i=0;i<(int)vp.size();i++){
            ans = max(ans, 1ll*(ssum - vp[i].second + vp[0].first));
        }
        return ans;
    }
};