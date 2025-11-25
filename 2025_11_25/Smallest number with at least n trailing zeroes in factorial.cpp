#include<iostream>

using namespace std;

class Solution {
  public:
 
    long long countZeros(long long x) {
        long long cnt = 0;
        while (x > 0) {
            x /= 5;
            cnt += x;
        }
        return cnt;
    }
    
    int findNum(int n) {
        if (n == 0) return 0; // 0! has 0 trailing zeroes
        
        long long low = 1, high = 5LL * n, ans = -1;
         
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long zeros = countZeros(mid);
            
            if (zeros >= n) {
                ans = mid;      
                high = mid - 1; 
            }
            else {
                low = mid + 1;   
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    int n;
    cin >> n;
    cout << obj.findNum(n);
    return 0;
}
