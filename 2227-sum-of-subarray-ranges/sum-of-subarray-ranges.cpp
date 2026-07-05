class Solution {
private:
   vector<int> NSE(vector<int> &arr){
    int n= arr.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        int currEle = arr[i];
        while(!st.empty() && arr[st.top()] >= currEle){
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }
    return ans;
   }
vector<int> NGE(vector<int> &arr){
    int n= arr.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        int  currEle = arr[i];
        while(!st.empty() && arr[st.top()] <= currEle){
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }
    return ans;
}
vector<int> PSE(vector<int> &arr){
    int n= arr.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        int currEle = arr[i];
        while(!st.empty() && arr[st.top()]> currEle){
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return ans;
}
vector<int> PGE(vector<int> &arr){
    int n= arr.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        int currEle = arr[i];
        while(!st.empty() && arr[st.top()] < currEle){
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return ans;
}
 long long sumMins(vector<int> &arr){
      vector<int> nse = NSE(arr);
      vector<int> pse = PSE(arr);
      int n= arr.size();
      long long sum =0;
      for(int i=0;i<n;i++){
        int left = i-pse[i];
        int right = nse[i]-i;

        long long freq = left*right*1LL;
        long long val = (freq*arr[i]*1LL);

        sum+=val;
      }
      return sum;
 }
 long long sumMaxs(vector<int> &arr){
    vector<int> nge = NGE(arr);
    vector<int> pge = PGE(arr);

    int n= arr.size();
    long long sum =0;

    for(int i=0;i<n;i++){
        int left = i-pge[i];
        int right = nge[i]-i;
        long long freq = left*right*1LL;
        long long val = (freq*arr[i]*1LL);
        sum+=val;
    }
    return sum;
 }
public:
    long long subArrayRanges(vector<int>& nums) {
        return (sumMaxs(nums)-sumMins(nums));
    }
};