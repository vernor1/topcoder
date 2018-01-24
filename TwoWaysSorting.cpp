#include <string>
#include <vector>

using namespace std;

class TwoWaysSorting {
public:
  string sortingMethod(const vector<string>& stringList) {
    bool isLex = true;
    bool isLen = true;
    string prev = stringList.front();
    for (size_t i = 1; i < stringList.size() && (isLex || isLen); ++i) {
      if (isLex) {
        isLex = prev < stringList[i];
      }
      if (isLen) {
        isLen = prev.length() < stringList[i].length();
      }
      prev = stringList[i];
    }
    if (isLex && isLen) {
      return "both";
    } else if (isLex) {
      return "lexicographically";
    } else if (isLen) {
      return "lengths";
    }
    return "none";
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
		cout << "Testing TwoWaysSorting (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1516755737;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TwoWaysSorting _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string stringList[] = {"a", "aa", "bbb"};
				_expected = "both";
				_received = _obj.sortingMethod(vector <string>(stringList, stringList+sizeof(stringList)/sizeof(string))); break;
			}
			case 1:
			{
				string stringList[] = {"c", "bb", "aaa"};
				_expected = "lengths";
				_received = _obj.sortingMethod(vector <string>(stringList, stringList+sizeof(stringList)/sizeof(string))); break;
			}
			case 2:
			{
				string stringList[] = {"etdfgfh", "aio"};
				_expected = "none";
				_received = _obj.sortingMethod(vector <string>(stringList, stringList+sizeof(stringList)/sizeof(string))); break;
			}
			case 3:
			{
				string stringList[] = {"aaa", "z"};
				_expected = "lexicographically";
				_received = _obj.sortingMethod(vector <string>(stringList, stringList+sizeof(stringList)/sizeof(string))); break;
			}
			case 4:
			{
				string stringList[] = {"z"};
				_expected = "both";
				_received = _obj.sortingMethod(vector <string>(stringList, stringList+sizeof(stringList)/sizeof(string))); break;
			}
			case 5:
			{
				string stringList[] = {"abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder"};
				_expected = "lexicographically";
				_received = _obj.sortingMethod(vector <string>(stringList, stringList+sizeof(stringList)/sizeof(string))); break;
			}
			/*case 6:
			{
				string stringList[] = ;
				_expected = ;
				_received = _obj.sortingMethod(vector <string>(stringList, stringList+sizeof(stringList)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string stringList[] = ;
				_expected = ;
				_received = _obj.sortingMethod(vector <string>(stringList, stringList+sizeof(stringList)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string stringList[] = ;
				_expected = ;
				_received = _obj.sortingMethod(vector <string>(stringList, stringList+sizeof(stringList)/sizeof(string))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
