class Solution {
public:
    string reorganizeString(string s) {
        vector<int> hash(26);
        int maxCount=0;
        char maxVal=' ';
        for(auto ch:s){
            if(maxCount<++hash[ch-'a']){
                maxCount=hash[ch-'a'];
                maxVal=ch;
            }
        }
        int n=s.size();
        if(maxCount>(n+1)/2)return "";
        string ret(n,' ');
        int index=0;
         for(int i=0;i<maxCount;i++){
            ret[index]=maxVal;
            index+=2;
        }
        hash[maxVal-'a']=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<hash[i];j++){
                if(index>=n)index=1;
                ret[index]='a'+i;
                index+=2;
            }
        }
        return ret;
    }
};
