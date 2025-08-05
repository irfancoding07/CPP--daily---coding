  #include <iostream>
using namespace std;

int countDistinctWaytoclimbstair(int n) {

    if(n < 0)
    return 0;
    
    if(n == 0)
    return 1;

   int ans = countDistinctWaytoclimbstair(n-1) + countDistinctWaytoclimbstair(n-2);
   
    return ans;
}

int main() {
    int n ;
    cin >> n;
    int ans = countDistinctWaytoclimbstair( n);
    cout << ans << endl;
    return 0;
}
