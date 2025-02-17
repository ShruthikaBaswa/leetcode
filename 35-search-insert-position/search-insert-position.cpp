class Solution {
public:
    int searchInsert(vector<int>& n, int k) {
        int l=0;
        int h=n.size()-1;
        while(l<=h){
            int m=(l+h)/2;
            if(n[m]==k){
                return m;
            }
            else if(n[m]<k){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return l;
    }
};