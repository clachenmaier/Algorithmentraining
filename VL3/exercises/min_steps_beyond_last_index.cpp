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

/************** begin assignment **************/
// The input is an array of n unsigned integers, where A[i] denotes the maximum
// you can advance from index i.
// Write a function to compute the minimum number
// of steps needed to advance beyond the last index of an array. If it's
// impossible to go beyond the last index of an array, your function should
// return 0.
// Optimal: O(n) time, O(1) space

// EXAMPLES
// Input: < 4, 1, 2, 3, 0, 2, 0 >
// Output: 3

// Input: < 4, 1, 2, 3, 0, 1, 0 >
// Output: 0


size_t min_steps_beyond_last_index(const vector<size_t> &A) {
  int n = A.size();
  if (n <= 1){
    return 0;
  }
  if (A[0]==0){
    return 0;
  }

  int maximal = A[0];
  int step = A[0];
  int jump = 1;
  for (int i = 1 ; i < n; i++){
    if (i == n-1){
      return jump;
    }
    maximal = (maximal > i + A[i]) ? maximal : i + A[i];
    --step;
    if (step == 0){
      jump++;
      if (i>=maximal){
        return -1;
      }
      step = maximal -i;
    }
  }
  return 0;
  /*
  int prev = 0, curr = 0, jumps = 1;
  for (int i=0; i< A.size()-1; i++){
    if  (i > prev) {
      prev=curr;
      jumps += 1;
    }
    int temp = i + A[i];
    curr = max(curr, temp);
  }
  cout << jumps << endl; 
  return jumps;*/
}
/*************** end assignment ***************/

int main() {
  /*{
    vector<size_t> v;
    assert(min_steps_beyond_last_index(v) == 0);
  }
  {
    vector<size_t> v = {1};
    assert(min_steps_beyond_last_index(v) == 1);
  }
  {
    vector<size_t> v = {0};
    assert(min_steps_beyond_last_index(v) == 0);
  }*/
  {
    vector<size_t> v = {3, 3, 1, 0, 2, 0, 1};
    assert(min_steps_beyond_last_index(v) == 4);
  }
  /*
  {
    vector<size_t> v = {3, 3, 1, 0, 2, 0, 0};
    assert(min_steps_beyond_last_index(v) == 0);
  }
  {
    vector<size_t> v = {3, 2, 0, 0, 2, 0, 1};
    assert(min_steps_beyond_last_index(v) == 0);
  }*/
  {
    vector<size_t> v = {2, 4, 1, 1, 0, 2, 3};
    assert(min_steps_beyond_last_index(v) == 3);
  }
  {
    vector<size_t> v = {2, 1, 1, 3, 0, 2, 0};
    assert(min_steps_beyond_last_index(v) == 4);
  }
  /*
  {
    vector<size_t> v = {4, 1, 2, 3, 0, 1, 0};
    assert(min_steps_beyond_last_index(v) == 0);
  }*/
  {
    vector<size_t> v = {4, 1, 2, 3, 0, 2, 0};
    assert(min_steps_beyond_last_index(v) == 3);
  }
  /*
  {
    vector<size_t> v = {1, 1, 5, 1, 1, 1, 1, 4, 1, 1, 1};
    assert(min_steps_beyond_last_index(v) == 4);
  }*/
  {
    vector<size_t> v = {3, 0, 0, 4, 1, 1, 1, 4, 1, 1, 1};
    assert(min_steps_beyond_last_index(v) == 3);
  }
  cout << "all tests passed" << endl;
}
