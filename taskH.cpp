#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  map<char, int> counts;
  for (char c : s) {
    counts[c]++;
  }

  string prefix = "";
  string middle = "";
  for (char c = 'A'; c <= 'Z'; ++c) {
    if (counts.count(c)) {
      int count = counts[c];
      if (count % 2 == 0) {
        for (int i = 0; i < count / 2; ++i) {
          prefix += c;
        }
      } else {
        for (int i = 0; i < (count - 1) / 2; ++i) {
          prefix += c;
        }
        if (middle == "") {
          middle = c;
        }
      }
    }
  }

  string suffix = prefix;
  reverse(suffix.begin(), suffix.end());

  cout << prefix + middle + suffix << endl;

  return 0;
}