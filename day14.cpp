class Solution {
public:
   /* int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
    //1. Create an Adjacency List
        vector<vector<vector<int>>> adjList(101);
        //101 bcoz, n is given not to exceed 100
        
        //example :
        //0 : {1, 100, 0}, {2, 500, 0}
        //1 : {2, 100, 0}
        //2 : 
        
        
        for(auto f : flights) {
            int from = f[0];
            int to = f[1];
            int cost = f[2];
            adjList[from].push_back({to, cost, 0});
            //from : source
            //to : dest 
            //cost: cost from 'from' to 'to'
            //0: number of stops between 'from' and 'to'
        }
        
        
    //2. Create a queue for performing BFS
        queue<vector<int>> q;
        
     //3. Push source in q as {src, money spent so far, number of stops b/w current city and source}
        q.push({src, 0, -1});
        //Note : if {A, B} are two directly connected cities, then number of stops b/w them is Zero,
        //so for convenience i'm assuming number of stops b/w A and A as -1
        
     int minCost = INT_MAX;   //this keeps track of minimum cost
    
        
     while(!q.empty()) {
            vector<int> curStation = q.front(); q.pop();
         
            int curCity = curStation[0];
            int curCost = curStation[1];
            int curK = curStation[2];      //this is the number of stops seen so far from source to current city
         
            if(curCity == dst) {
              minCost = min(minCost, curCost);
              continue;  
            }
             
         
            for(auto p : adjList[curCity]) {
                //we include a city in our route only if :
                // > it doesn't exceed number of stops alloted
                // > it keeps cost less than mincost
                //***
                if(curK+1 <= k and curCost + p[1] < minCost)
                q.push({p[0], p[1] + curCost, curK+1});
            } 
         
     }   
        
     return minCost==INT_MAX?-1:minCost;   
    }*/
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {        
        vector<vector<int>> dp(K+2, vector<int>(n, INT_MAX));
        
        //dp[i][j] = Dist to reach j using atmost i edges from src
        
        for(int i = 0; i <= K+1; i++)
        {
            dp[i][src] = 0; // Dist to reach src always zero
        }
        
        for(int i = 1; i <= K+1; i++)
        {
            for(auto &f: flights)
            {
                //Using indegree
                int u = f[0];
                int v = f[1];
                int w = f[2];
                
                if(dp[i-1][u] != INT_MAX)
                    dp[i][v] = min(dp[i][v], dp[i-1][u] + w);
            }
        }
        
        return (dp[K+1][dst] == INT_MAX)? -1: dp[K+1][dst];
    }
};