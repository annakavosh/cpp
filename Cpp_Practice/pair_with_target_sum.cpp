using namespace std; // to avoid prefixing standard library types and functions 

#include <iostream>
#include <vector> // to use the vector container from the standard library

class Solution { // search for a pair of indices in the array that sums up to the target

  public:
  // search function takes two parameters, vector of integers and targetSum
  // a constantn reference to a vector of integers, which represents hte array to search through
  vector<int> search(const vector<int> &arr, int targetSum) {
    vector<int> res(2, -1);

    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if  (currentSum == targetSum) {
            vector<int> res(2, -1); // res vector is initialized with size 2 and both elements
            // set to -1 . it will store the indices of the two numbers that sum to the target
            res[0] = left;
            res[1] = right;
            return res; // if no pair is found the initial res [-1,-1] is returned
        }
    
    if (targetSum > currentSum)
        left++;
    else
        right--;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
    Solution sol;
    
    auto result = sol.search(vector<int>{1, 2, 3, 4, 6}, 6);
    cout << "pair with target sum: [ " << result[0] << ", " << result[1] << " ]"<< endl;
    result = sol.search(vector<int>{2, 6, 2, 5, 9}, 11);
    cout << "pair with target sum: [ " << result[0] << ", " << result[1] << " ]"<< endl;
}