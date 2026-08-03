class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int stopage[1001]={};
        for(auto trip : trips) stopage[trip[1]]+=trip[0], stopage[trip[2]]-=trip[0];
        for(auto j=0; capacity >=0 && j<1001; ++j) capacity -=stopage[j];
        return capacity >=0;
    }
};