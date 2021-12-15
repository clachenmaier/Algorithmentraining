// enable assertions in release build
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstddef>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

// helper macros for timings
#define TIMERSTART(label)                                                      \
  std::chrono::time_point<std::chrono::system_clock> a##label, b##label;       \
  a##label = std::chrono::system_clock::now();

#define TIMERSTOP(label)                                                       \
  b##label = std::chrono::system_clock::now();                                 \
  std::chrono::duration<double> delta##label = b##label - a##label;            \
  std::cout << #label << ": " << std::setprecision(4) << delta##label.count()  \
            << " seconds" << std::endl;

// parse input file and create baskets vector
vector<set<string>> get_baskets(const string &file_name) {
  ifstream ifs(file_name);
  if (ifs.fail()) {
    cerr << "failed to open " << file_name << endl;
    exit(-1);
  }
  string line;
  string word;
  vector<set<string>> baskets;
  while (getline(ifs, line)) {
    stringstream iss(line);
    set<string> basket;
    while (iss >> word)
      basket.insert(word);
    baskets.push_back(basket);
  }
  return baskets;
}

// count the common items between two sets of words
size_t intersection_count(const set<string> &b1, const set<string> &b2) {
  vector<string> v;
  set_intersection(begin(b1), end(b1), begin(b2), end(b2),
                   std::back_inserter(v));
  return v.size();
}

/************** begin assignment **************/
// The "vector baskets" contains 5000 baskets of fruits, for example baskets[5]
// contains the following fruits {Coconut, Watermelon, Apricot}.
// The "vector preferences" contains preferences for fruits of 1000 people, for
// example the person in preferences[2] prefers {Strawberry, Melon, Avocado,
// Jackfruit}. Count the baskets for each person that have at least 3 fruits of
// a person's preferences. A basket can contain 3 to 7 different (unique)
// fruits. Also the preferences of the persons are between 3 to 7 different
// (unique) fruits. There are only 28 different fruits.

// A naive solution uses sets of strings to compute intersections between
// baskets and preferences.
// It also iterates over all baskets for each user.
vector<size_t> count_matches_naive(const vector<set<string>> &baskets,
                                   const vector<set<string>> &preferences) {
  // matches_count contains the matches count for each person
  vector<size_t> matches_count(
      preferences.size()); // create vector of all zeros
  // iterate over all persons
  for (size_t i = 0; i < preferences.size(); ++i) {
    // iterate over all possible baskets
    for (const auto &basket : baskets) {
      // if a basket contains at least 3 fruits of a person's preferences, then
      // we have a match
      if (intersection_count(preferences[i], basket) >= 3) {
        matches_count[i]++;
      }
    }
  }
  return matches_count;
}

// TODO: implement a "fast matches counter" using bit operations
// Voluntary (not required): If you are really interested in speeding up the
// code, also develop a strategy to avoid iterating over all the baskets each
// time. (In a real speed competition this would be essential for winning!)
vector<size_t> count_matches_fast(const vector<set<string>> &baskets,
                                  const vector<set<string>> &preferences) {
  vector<size_t> matches_count(preferences.size());
  map<string, int> fruittypes;
  vector<bitset<28> > basketset(baskets.size());
  vector<bitset<28> > preferencesset(preferences.size());
  int i = 0;
  for (const auto &basket : baskets) {    
    for (const auto &fruit : basket) {
        if (fruittypes.count(fruit)==0){
          fruittypes.insert({fruit, fruittypes.size()-1});
          cout << fruit << ' ' << fruittypes.size()-1 << endl;
        }
        cout << basketset[i] << endl;
        cout << fruittypes[fruit] << endl;
      basketset[i][fruittypes[fruit]]=1;

    }
    i++;
  }
  i=0;
  for (const auto &preference : preferences) {
    
    for (const auto &fruit : preference) {
      cout << preferencesset[i] << endl;
      preferencesset[i][fruittypes[fruit]]=1;
    }
    i++;
  }
  
  
  


  return matches_count;
}
/*************** end assignment ***************/

int main() {
  //map<string, int> fruittypes;
  //fruittypes.insert({"Bananan", 1});
  //cout << fruittypes["Bananan"] << endl;
  //cout << fruittypes["apple"]<< endl;
  //vector <set<int>> baskets; 
  
  vector<set<string>> baskets = get_baskets("baskets.txt");
  vector<set<string>> preferences = get_baskets("preferences.txt");
  count_matches_fast(baskets, preferences);
  /*
  TIMERSTART(naive)
  auto results_naive = count_matches_naive(baskets, preferences);
  TIMERSTOP(naive)

  TIMERSTART(fast)
  auto results_fast = count_matches_fast(baskets, preferences);
  TIMERSTOP(fast)

  assert(results_naive == results_fast);
  
  cout << "all tests passed" << endl;*/
}
