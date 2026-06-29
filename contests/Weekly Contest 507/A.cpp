class Solution {
public:
    int maxDistance(string moves) {
        int cnt = 0, chx = 0, chy = 0;
        for(char ch : moves){
            if(ch == 'L') chx--;
            else if(ch == 'R') chx++;
            else if(ch == 'U') chy++;
            else if(ch == 'D') chy--;
            else if(ch == '_') cnt++;
        }
        return cnt + abs(chx) + abs(chy);
    }
};