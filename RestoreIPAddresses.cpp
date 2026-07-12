#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;

    bool isValid(string s){

        if(s[0] == '0' and s.size() > 1) return false;

        int num = stoi(s);
        return num >= 0 and num <= 255;
    }

    void solve(string s, string curr, int idx, int parts){

        if(parts == 4){
            if(idx == s.size()){
                curr.pop_back();
                ans.push_back(curr);
            }
            return;
        }

        if(idx < s.size()){
            string part = s.substr(idx,1);
            if(isValid(part)) solve(s,curr + part + ".",idx+1,parts+1);
        }

        if(idx + 1 < s.size()){
            string part = s.substr(idx,2);
            if(isValid(part)) solve(s,curr + part + ".",idx+2,parts+1);
        }

        if(idx + 2 < s.size()){
            string part = s.substr(idx,3);
            if(isValid(part)) solve(s,curr + part + ".",idx+3,parts+1);
        }

    }

    vector<string> restoreIpAddresses(string s) {
        
        if(s.size() > 12 or s.size() < 4) return {};
        solve(s,"",0,0);
        return ans;
    }
};

