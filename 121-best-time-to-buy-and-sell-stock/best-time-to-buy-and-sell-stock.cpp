class Solution {
public:
    int maxProfit(vector<int>& prices){
        int buy=prices[0];
        int p=0;
        for(int i=1;i<prices.size();i++){
            if(buy>prices[i]){
                buy=prices[i];
            }
            p=max(p,prices[i]-buy);
        }
        return p;  
    }
};