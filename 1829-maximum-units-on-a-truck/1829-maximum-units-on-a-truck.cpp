class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
    return a[1] > b[1];
}
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int ans=0;
        int count=0;int i=0;
        while(count<truckSize && i<boxTypes.size()){
            // cout<<boxTypes[i][0]<<" "<<boxTypes[i][1]<<endl;
            if(count+boxTypes[i][0]<=truckSize){
                  ans+=boxTypes[i][0]*boxTypes[i][1];
                  count+=boxTypes[i][0];
            }
            else{
                 ans+=boxTypes[i][1]*(truckSize-count);
                 break;
            }
            i++;
        }
        return ans;
    }
};