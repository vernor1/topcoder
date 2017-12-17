#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class LexStringWriter {
public:
  int minMoves(const string& s) {
    vector<pair<int, int>> costs = {{0, 0}};
    for (char c = 'a'; c <= 'z'; ++c) {
      vector<int> group;
      for (int i = 0; i < s.size(); ++i) {
         if (s[i] == c) {
            group.push_back(i);
         }
      }
      if (group.empty()) {
        continue;
      }
      vector<pair<int, int>> inCosts;
      for (auto in : group) {
        pair<int, int> minCost = {-1, in};
        for (const auto& cost : costs) {
          int inCost = cost.first + labs(cost.second - in); 
          if (minCost.first == -1 || inCost < minCost.first) {
            minCost.first = inCost;
          }
        }
        inCosts.push_back(minCost);
      }
      costs.clear();
      for (auto out : group) {
        pair<int, int> minCost = {-1, out};
        for (const auto& inCost : inCosts) {
          if (group.size() > 1 && inCost.second == out) {
            continue;
          }
          int outCost = inCost.first
                      + *group.rbegin() - *group.begin()
                      + min(inCost.second, out) - *group.begin()
                      + *group.rbegin() - max(inCost.second, out)
                      + group.size();
          if (minCost.first == -1 || outCost < minCost.first) {
            minCost.first = outCost;
          }
        }
        costs.push_back(minCost);
      }
    }
    int minCost = -1; 
    for (const auto& cost : costs) {
      if (minCost == -1 || cost.first < minCost) {
        minCost = cost.first;
      }
    }
    return minCost;
  }
};

// BEGIN CUT HERE

// Unit Tests
// ----------------------------------------------------------------------------

#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing LexStringWriter (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1513548218;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LexStringWriter _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "aaa";
				_expected = 5;
				_received = _obj.minMoves(s); break;
			}
			case 1:
			{
				string s = "ba";
				_expected = 4;
				_received = _obj.minMoves(s); break;
			}
			case 2:
			{
				string s = "abba";
				_expected = 9;
				_received = _obj.minMoves(s); break;
			}
			case 3:
			{
				string s = "acbbc";
				_expected = 12;
				_received = _obj.minMoves(s); break;
			}
			/*case 4:
			{
				string s = ;
				_expected = ;
				_received = _obj.minMoves(s); break;
			}*/
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.minMoves(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.minMoves(s); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
