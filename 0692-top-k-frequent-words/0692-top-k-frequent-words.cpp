class Solution {
public:
     struct cmp{
        bool operator()(const pair<string, int>& a,const pair<string, int>& b){
            if(a.second==b.second){
               return a.first<b.first;
            }
            return a.second>b.second;
        }
     };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string, int> mp;
        for (string w : words) {
            mp[w]++;
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>,cmp>pq;
        for(auto it : mp){
            pq.push({it.first,it.second});
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string>ans;
        while(pq.size()>0){
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};