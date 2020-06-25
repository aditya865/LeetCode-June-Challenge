class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n=arr.size();
        for (int i = 0; i < n; i++)             
    { 
        int index = arr[i] % n; 
        arr[index] += n; 
    } 
  
    // Now check which value exists more 
    // than once by dividing with the size 
    // of array 
    for (int i = 0; i < n; i++) 
    { 
        if ((arr[i]/n) > 1) 
            return i; 
    } 
        return 0;
}
};