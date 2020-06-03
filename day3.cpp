
 class Solution {
public:
    static bool sortByDiff (vector<int> & a, vector<int> & b){
        if(a[1]-a[0] > b[1]-b[0]){
            return true;
        }
        return false;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int l = costs.size();
        int sum = 0;
        sort(costs.begin(), costs.end(), sortByDiff);
        for(int i = 0; i < l; i++){
            if(i < l/2){
                sum += costs[i][0];
            }
            if(i >= l/2){
                sum += costs[i][1];
            }
        }
        return sum;
    }
};
       
    
