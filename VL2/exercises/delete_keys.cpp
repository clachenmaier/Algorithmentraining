// enable assertions in release build
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <cassert>
#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

/************** begin assignment **************/
// Implement a function which takes as input an sorted array and a key, and
// updates the array so that all occurrences of the input key have been removed
// and the remaining elements have been shifted left to fill the emptied
// indices. Return the number of remaining elements. Values beyond the last
// valid element are the same as in the original array.
// (Requirements: O(1) space, O(n) time)


int binarySearch(vector<int> &arr, int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
    return binarySearch(arr, low, (mid - 1), key);
}

inline size_t delete_keys(vector<int> &v, const int key) {
  int high = v.size();
  if (high == 0){
    return 0;
  }
  int result = binarySearch(v, 0, high, key );
  if (result == -1){
    return high; 
  }
  int left = result, right = result; 
  while ( v[left - 1] >= 0 && v[left - 1] == key ){
    left--;
    
  }
  while (v[right + 1] <= v.size() && v[right + 1 ] == key){
    right++; 
    
  }
  int increment = right - left + 1; 
  for (int i = left ; i< high - increment ; i++){
    v[i] = v [i + increment]; 
  }
  return high - increment;
}

/*************** end assignment ***************/

int main() {
  
  {
    vector<int> v;
    vector<int> vresult;
    int key = 1;
    
    auto valid_entries = delete_keys(v, key);
    assert(v == vresult);
    assert(valid_entries == 0);
  }
  {
    vector<int> v{1};
    vector<int> vresult{1};
    int key = 2;
    auto valid_entries = delete_keys(v, key);
    assert(v == vresult);
    assert(valid_entries == 1);
  }
  {
    vector<int> v{1};
    vector<int> vresult{1};
    int key = 1;
    auto valid_entries = delete_keys(v, key);
    assert(v == vresult);
    assert(valid_entries == 0);
  }
  {
    vector<int> v{1, 2, 3};
    vector<int> vresult{2, 3, 3};
    int key = 1;
    auto valid_entries = delete_keys(v, key);
    assert(v == vresult);
    assert(valid_entries == 2);
  }
  {
    vector<int> v{1, 2, 2, 3};
    vector<int> vresult{1, 3, 2, 3};
    int key = 2;
    auto valid_entries = delete_keys(v, key);
    assert(v == vresult);
    assert(valid_entries == 2);
  }
  {
    vector<int> v{1, 2, 2, 3, 3};
    vector<int> vresult{1, 3, 3, 3, 3};
    int key = 2;
    auto valid_entries = delete_keys(v, key);
    assert(v == vresult);
    assert(valid_entries == 3);
  }
  {
    vector<int> v{2, 3, 5, 5, 7, 11, 11, 11, 13};
    vector<int> vresult{2, 3, 5, 5, 11, 11, 11, 13, 13};
    int key = 7;
    auto valid_entries = delete_keys(v, key);
    assert(v == vresult);
    assert(valid_entries == 8);
  }
  cout << "all tests passed" << endl;
}
