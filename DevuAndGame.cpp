#include <string>
#include <vector>

using namespace std;

class DevuAndGame {
public:
  string canWin(const vector<int>& nextLevel) {
    vector<bool> visited(nextLevel.size());
    int i = 0;
    while (nextLevel[i] != -1 && !visited[i]) {
      visited[i] = true;
      i = nextLevel[i];
    }
    return nextLevel[i] == -1 ? "Win" : "Lose";
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
		cout << "Testing DevuAndGame (222.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1515190361;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 222.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DevuAndGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int nextLevel[] = {1, -1};
				_expected = "Win";
				_received = _obj.canWin(vector <int>(nextLevel, nextLevel+sizeof(nextLevel)/sizeof(int))); break;
			}
			case 1:
			{
				int nextLevel[] = {1, 0, -1};
				_expected = "Lose";
				_received = _obj.canWin(vector <int>(nextLevel, nextLevel+sizeof(nextLevel)/sizeof(int))); break;
			}
			case 2:
			{
				int nextLevel[] = {0, 1, 2};
				_expected = "Lose";
				_received = _obj.canWin(vector <int>(nextLevel, nextLevel+sizeof(nextLevel)/sizeof(int))); break;
			}
			case 3:
			{
				int nextLevel[] = {29,33,28,16,-1,11,10,14,6,31,7,35,34,8,15,17,26,12,13,22,1,20,2,21,-1,5,19,9,18,4,25,32,3,30,23,10,27};
				_expected = "Win";
				_received = _obj.canWin(vector <int>(nextLevel, nextLevel+sizeof(nextLevel)/sizeof(int))); break;
			}
			case 4:
			{
				int nextLevel[] = {17,43,20,41,42,15,18,35,-1,31,7,33,23,33,-1,-1,0,33,19,12,42,-1,-1,9,9,-1,39,-1,31,46,-1,20,44,41,-1,-1,12,-1,36,-1,-1,6,47,10,2,4,1,29};
				_expected = "Win";
				_received = _obj.canWin(vector <int>(nextLevel, nextLevel+sizeof(nextLevel)/sizeof(int))); break;
			}
			case 5:
			{
				int nextLevel[] = {3, 1, 1, 2, -1, 4};
				_expected = "Lose";
				_received = _obj.canWin(vector <int>(nextLevel, nextLevel+sizeof(nextLevel)/sizeof(int))); break;
			}
			/*case 6:
			{
				int nextLevel[] = ;
				_expected = ;
				_received = _obj.canWin(vector <int>(nextLevel, nextLevel+sizeof(nextLevel)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int nextLevel[] = ;
				_expected = ;
				_received = _obj.canWin(vector <int>(nextLevel, nextLevel+sizeof(nextLevel)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int nextLevel[] = ;
				_expected = ;
				_received = _obj.canWin(vector <int>(nextLevel, nextLevel+sizeof(nextLevel)/sizeof(int))); break;
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
