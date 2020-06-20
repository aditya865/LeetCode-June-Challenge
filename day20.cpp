/*
This problem is recursive like dynamic programming.
Kth Permutation sequence can be formed by choosing the 1st digit and then the rest of the digits one by one.
Visually:
1 + (permutations of rest of digits)
2 + (permutations of ...)
so on...

For N=3,
we have the permutations:
1|2,3
1|3,2
2|1,3
2|3,1
3|1,2
3|2,1

I put a bar "|" to separate first digit from the rest of digits.
There are a total of N! = 3! = 6 perms. Each 1st digit is "attached" to (n-1)! =2! = 2 permutations formed by rest of digits.
Thus , to choose 1st digit, simply calculate (k-1) / (n-1)! and use it to index into an array of digits 1,2,3,
Once 1st digit is chosen, we choose 2nd and so on recursively.

We remove 1st digit from the array of digits , so the remaining are the "rest of digits".
There are 2 ways to remove:

pull the chosen digit from its current place to the right place in the permutation and shift rest of digits accordingly. (this is the in-place method chosen in my code so left part is partially formed permuation and right part is the candidates)
mark the chosen digit as "used" so you don't use it again. (need an array of booleans to track)
Notice the candidates always remain sorted regardless of which digit is removed. This is an important property to solve the problem recursively.*/
class Solution {
public:
string getPermutation(int n, int k) {
    int i,j,f=1;
    // left part of s is partially formed permutation, right part is the leftover chars.
    string s(n,'0');
    for(i=1;i<=n;i++){
        f*=i;
        s[i-1]+=i; // make s become 1234...n
    }
    for(i=0,k--;i<n;i++){
        f/=n-i;
        j=i+k/f; // calculate index of char to put at s[i]
        char c=s[j];
        // remove c by shifting to cover up (adjust the right part).
        for(;j>i;j--)
            s[j]=s[j-1];
        k%=f;
        s[i]=c;
    }
    return s;
}
};