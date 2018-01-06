#include <string>

using namespace std;

class GoodString {
public:
  string isGood(string s) {
    size_t count = 0;
    auto b_it = s.begin();
    while (b_it != s.end()) {
      while (b_it != s.end() && *b_it != 'b') {
        ++b_it;
      }
      if (b_it == s.end()) {
        break;
      }
      string::reverse_iterator a_it(b_it);
      while (a_it != s.rend() && *a_it != 'a') {
        ++a_it;
      }
      if (a_it == s.rend()) {
        return "Bad";
      }
      *a_it = ' ';
      *b_it = ' ';
      count += 2;
      ++b_it;
    }
    return count == s.size() ? "Good" : "Bad";
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
		cout << "Testing GoodString (444.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1515191387;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 444.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GoodString _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "ab";
				_expected = "Good";
				_received = _obj.isGood(s); break;
			}
			case 1:
			{
				string s = "aab";
				_expected = "Bad";
				_received = _obj.isGood(s); break;
			}
			case 2:
			{
				string s = "aabb";
				_expected = "Good";
				_received = _obj.isGood(s); break;
			}
			case 3:
			{
				string s = "ababab";
				_expected = "Good";
				_received = _obj.isGood(s); break;
			}
			case 4:
			{
				string s = "abaababababbaabbaaaabaababaabbabaaabbbbbbbb";
				_expected = "Bad";
				_received = _obj.isGood(s); break;
			}
			case 5:
			{
				string s = "aaaaaaaabbbaaabaaabbabababababaabbbbaabbabbbbbbabb";
				_expected = "Good";
				_received = _obj.isGood(s); break;
			}
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.isGood(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.isGood(s); break;
			}*/
			/*case 8:
			{
				string s = ;
				_expected = ;
				_received = _obj.isGood(s); break;
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
