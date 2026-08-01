class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        for(char ch : s) mpp[ch]+=1;

        vector<vector<char>> bucket(n+1);
        for(auto [ch, f] : mpp)
              bucket[f].push_back(ch);

        string ans;
        for(int freq = n; freq>=1; --freq){
            for(char ch : bucket[freq]){
                ans.append(freq, ch);
            }
        }
        return ans;
    }
};