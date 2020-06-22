class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int table[amount+1];
        memset(table,0,sizeof(table));
        table[0]=1;
        for(int i=0; i<n; i++)
        {
        for(int j=coins[i];j<=amount; j++) 
        table[j] += table[j-coins[i]]; 
        for(int k=0;k<amount+1;k++)
        {
            cout<<table[k];

        }
            cout<<endl;
        }
    return table[amount];
    }
};