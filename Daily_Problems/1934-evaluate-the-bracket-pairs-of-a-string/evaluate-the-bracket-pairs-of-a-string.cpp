class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
       unordered_map<string,string> mp;

        for(int i = 0; i< knowledge.size(); i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        int i = 0;
        string ans = "";
        while(i<s.size()){
            if(s[i] != '('){
                ans += s[i];
                i++;
            }

            else{
                int j  = i;
                while(s[j]!=')'){
                    j++;
                }
                string key = s.substr(i+1,j-i-1);
                if(mp.find(key)!=mp.end()){
                    ans += mp[key];
                } else{
                    ans += '?';
                }
                i = j+1;
            }
        }

        return ans;
    }
};