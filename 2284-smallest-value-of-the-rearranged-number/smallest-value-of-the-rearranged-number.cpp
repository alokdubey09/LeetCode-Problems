class Solution {
public:
    long long smallestNumber(long long num) {
        bool negNum = num<0;
        string s = to_string(negNum ? -num : num);

        if(negNum){
            sort(s.begin(), s.end(), std::greater<char>());
            return -stoll(s);
        }
        else {
            sort(s.begin(), s.end());
            if(s[0]=='0'){
                for(int i=1;i<s.length();i++){
                    if(s[i]!='0'){
                        swap(s[0], s[i]);
                        break;
                    }
                }
            }
            return stoll(s);
        }
    }
};