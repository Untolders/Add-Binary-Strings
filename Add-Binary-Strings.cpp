###############################################################################################################################################################  Question ###################

Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

Input: s1 = "1101", s2 = "111"
Output: 10100
Explanation:
 1101
+ 111
10100
Input: s1 = "00100", s2 = "010"
Output: 110
Explanation: 
  100
+  10
  110
Constraints:
1 ≤s1.size(), s2.size()≤ 106

###############################################################################################################################################################  Solution ###################
  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
    
      int ind1=s1.size()-1;
        int ind2=s2.size()-1;
        int carry=0;
        string ans="";
        
        while(ind1 >= 0 && ind2 >= 0){
            int a = s1[ind1]-'0';
            int b = s2[ind2]-'0';
            
            int val = a^b^carry;
            if(carry == 0){
                if(a == 1 && b == 1){
                    carry=1;
                }
            }else{
                if(a == 0 && b == 0){
                    carry=0;
                }
            }
            
            ans=to_string(val)+ans;
            ind1--;
            ind2--;
        }
        
        while(ind1 >= 0){
            int a = s1[ind1]-'0';
            int val = a^carry;
            ans=to_string(val)+ans;
            if(carry == 1 && a == 1){
                carry=1;
            }else{
                carry=0;
            }
            ind1--;
        }
        
        while(ind2 >= 0){
            int a = s2[ind2]-'0';
            int val = a^carry;
            ans=to_string(val)+ans;
            if(carry == 1 && a == 1){
                carry=1;
            }else{
                carry=0;
            }
            ind2--;
        }
        if(carry){
            ans='1'+ans;
        }
        string newans="";
        int ind=-1;
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='1'){
                ind=i;
                break;
            }
        }
       
        if(ind!=-1){
            for(int i=ind;i<ans.size();i++){
                newans+=ans[i];
            }
        }
        
        
        return newans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
