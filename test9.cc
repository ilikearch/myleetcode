class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n=skills.size();
        int cur=0;
        int cnt=0;
        while(cur<n){
            int next=cur+1;
            if(next==n){
                return cur;
            }
            while(next<n&&skills[cur]>skills[next]&&cnt<k){
                cnt++;
                next++;
            }
            if(next==n||cnt==k){
                return cur;
            }
            cnt=1;
            cur=next;
        }
        return cur;
    }
};
