// enable assertions in release build
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <vector>
#include <iostream>

using namespace std;


// Dynamic programming is a very important problem solving strategy in
// competitive programming problems.
//
// In the backtracking assignment you had to work with code you didn't write.
// In this assignment you write everything yourself from the beginning.
//
// TODO: Read chapter 7 from the "Competitive Programmer’s Handbook"
// https://cses.fi/book/book.pdf --> pp. 65 - 76
// TODO: Choose one of the three following problems presented in the book:
//       - Longest increasing subsequence
//       - Paths in a grid
//       - Knapsack (all possible sums)
//       Implement for your chosen problem with dynamic programming 
//       1. an iterative solution
//                and
//       2. a recursive solution
//       Test your implementations thoroughly. Start by writing your test cases
//       before you implement the algorithms.
//       Document your solutions thoroughly by writing meaningful comments.
int longest_increasing_element(vector<int> &A){
    int n = A.size();
    if (n<1){
        return 0;
    }
    vector<int> increasing(n);
    increasing[0]=1;
    for (int i = 1; i<n; i++){
        increasing[i]=1;
        for (int j=0; j<i ; j++){
            if (increasing[j]>increasing[i]&&A[j]<A[i]){
                increasing[i]=increasing[j]+1;
            }
        }
    }
    return *max_element(increasing.begin(), increasing.end());

}
int main() {
    
    {
    vector<int> v;
    assert(longest_increasing_element(v) == 0);
  }
  {
    vector<int> v = {1};
    assert(longest_increasing_element(v) == 1);
  }
  {
    vector<int> v = {0};
    assert(longest_increasing_element(v) == 1);
  }
  
  {
    vector<int> v = {3, 5, 2, 1, 8};
    assert(longest_increasing_element(v) == 3);
  }
  
  {
    vector<int> v = {1,2,3,4};
    assert(longest_increasing_element(v) == 4);
  }
  {
    vector<int> v = {12,3, 10, 7, 11, 13};
    assert(longest_increasing_element(v) == 4);
  }
  cout << "all tests passed" << endl;
}
