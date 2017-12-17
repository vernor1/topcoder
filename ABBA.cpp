#include <algorithm>
#include <string>

using namespace std;

class ABBA {
public:
    string canObtain(const string& initial, const string& target) {
        size_t begin_offset = 0;
        size_t end_offset = 0;
        bool is_reversed = false;
		for (size_t l = 0; l < target.length() - initial.length(); ++l) {
            char c;
            if (is_reversed) {
    	        c = target[begin_offset++];
            } else {
                c = target[target.length() - ++end_offset];
            }
            if (c == 'B') {
		is_reversed = !is_reversed;
            }
        }
        string test = target.substr(begin_offset, initial.length());
        if (is_reversed) {
            reverse(test.begin(), test.end());
        }
        return test == initial ? "Possible" : "Impossible";
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
		cout << "Testing ABBA (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1513547932;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ABBA _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string initial = "B";
				string target = "ABBA";
				_expected = "Possible";
				_received = _obj.canObtain(initial, target); break;
			}
			case 1:
			{
				string initial = "AB";
				string target = "ABB";
				_expected = "Impossible";
				_received = _obj.canObtain(initial, target); break;
			}
			case 2:
			{
				string initial = "BBAB";
				string target = "ABABABABB";
				_expected = "Impossible";
				_received = _obj.canObtain(initial, target); break;
			}
			case 3:
			{
				string initial = "BBBBABABBBBBBA";
				string target = "BBBBABABBABBBBBBABABBBBBBBBABAABBBAA";
				_expected = "Possible";
				_received = _obj.canObtain(initial, target); break;
			}
			case 4:
			{
				string initial = "A";
				string target = "BB";
				_expected = "Impossible";
				_received = _obj.canObtain(initial, target); break;
			}
			/*case 5:
			{
				string initial = ;
				string target = ;
				_expected = ;
				_received = _obj.canObtain(initial, target); break;
			}*/
			/*case 6:
			{
				string initial = ;
				string target = ;
				_expected = ;
				_received = _obj.canObtain(initial, target); break;
			}*/
			/*case 7:
			{
				string initial = ;
				string target = ;
				_expected = ;
				_received = _obj.canObtain(initial, target); break;
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
