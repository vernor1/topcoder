#include <string>
#include <vector>

using namespace std;

class MagicNaming {
private:
	string magic_name_;
	vector<size_t> reindeers_;
public:
  int maxReindeers(string magicName) {
    magic_name_ = magicName;
    reindeers_.resize(magicName.length(), 0);
    return GetReindeers(0);
  }
private:
  size_t GetReindeers(size_t pos) {
    size_t max_reindeers = 0;
    for (size_t i = pos + 1; i < magic_name_.length(); ++i) {
      auto l = magic_name_.length() - i;
      if (magic_name_.compare(pos, l, magic_name_, i, l) <= 0) {
        if (reindeers_[i] == 0) {
          reindeers_[i] = GetReindeers(i);
        }
        max_reindeers = max(max_reindeers, reindeers_[i]);
      }
    }
    return max_reindeers + 1;
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
		cout << "Testing MagicNaming (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1514569741;
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
		MagicNaming _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string magicName = "aba";
				_expected = 2;
				_received = _obj.maxReindeers(magicName); break;
			}
			case 1:
			{
				string magicName = "babbaba";
				_expected = 2;
				_received = _obj.maxReindeers(magicName); break;
			}
			case 2:
			{
				string magicName = "philosophersstone";
				_expected = 5;
				_received = _obj.maxReindeers(magicName); break;
			}
			case 3:
			{
				string magicName = "knuthmorrispratt";
				_expected = 7;
				_received = _obj.maxReindeers(magicName); break;
			}
			case 4:
			{
				string magicName = "acrushpetrtourist";
				_expected = 7;
				_received = _obj.maxReindeers(magicName); break;
			}
			case 5:
			{
				string magicName = "zzzzz";
				_expected = 5;
				_received = _obj.maxReindeers(magicName); break;
			}
			/*case 6:
			{
				string magicName = ;
				_expected = ;
				_received = _obj.maxReindeers(magicName); break;
			}*/
			/*case 7:
			{
				string magicName = ;
				_expected = ;
				_received = _obj.maxReindeers(magicName); break;
			}*/
			/*case 8:
			{
				string magicName = ;
				_expected = ;
				_received = _obj.maxReindeers(magicName); break;
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
