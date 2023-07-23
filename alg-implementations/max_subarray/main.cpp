
#include <iostream>
#include <vector>

using namespace std; 

struct subarray {
    int low;
    int high; 
    subarray(int low, int high) : low(low), high(high) {}

    friend ostream& operator<<(ostream& os, const subarray& x) {
        os << "Low: " << x.low << " High: " << x.high; 
        return os; 
    }

};


subarray find_max_mid_crossing(const vector<int>& A, const subarray& sa) {
    int mid = (sa.low + sa.high ) / 2; 
    subarray result(mid, mid); 
    int max = A[mid];
    int sum = 0; 
    for (int i = mid; i>= sa.low; i--) {
        sum += A[i];
        if (sum >= max) {
            max = sum;
            result.low = i;
        }
    }
    sum=0;
    max=A[mid+1];
    for (int i = mid+1; i<= sa.high; i++) {
        sum += A[i];
        if (sum >= max) {
            max = sum;
            result.high = i;
        }
    }
    return result; 

}

int get_sum(const vector<int>& A, const subarray& sa) {
    int sum = 0; 
    for (int i = sa.low; i<=sa.high; i++) sum += A[i];
    return sum; 
}

subarray max_subarray(const vector<int>& A, const subarray& sa) {
    // cout << "Call for: " << sa << endl;
    if (sa.low == sa.high) return sa;
    int mid = (sa.low + sa.high) / 2; 
    auto left = max_subarray(A, subarray(sa.low, mid));
    auto right = max_subarray(A, subarray(mid+1, sa.high));
    auto cross = find_max_mid_crossing(A, sa);
    auto leftsum = get_sum(A, left);
    auto rightsum = get_sum(A, right);
    auto crosssum = get_sum(A, cross);
    // cout << "Temp result: " << left << " "<< cross << " "<< right << endl;
    if (leftsum > crosssum && leftsum > rightsum) return left; 
    else if (rightsum > crosssum && rightsum > leftsum) return right; 
    else return cross; 

}
subarray max_subarray(const vector<int>& A) {
    return max_subarray(A, subarray(0, A.size() - 1));
}

int main() {
    cout << max_subarray(vector<int> {1,2,3}) << endl;;
    cout << max_subarray(vector<int> {-1,-2,-3}) << endl;
    cout << max_subarray(vector<int> {5,-1,-1}) << endl;
    cout << max_subarray(vector<int> {5,5,-1}) << endl;

    return 0; 
}