#include <algorithm>
#include <vector>

using namespace std;

class AstronomicalRecords {
public:
  int minimalPlanets(const vector<int>& A, const vector<int>& B) {
    uint8_t m = numeric_limits<uint8_t>::max();
    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < B.size(); ++j) {
        m = min(m, f(A, B, i, j));
      }
    }
    return m;
  }
private:
  uint8_t f(const vector<int>& A, const vector<int>& B, int i, int j) {
    auto aSize = A.size();
    auto bSize = B.size();
    vector<vector<uint8_t>> N(aSize + 1, vector<uint8_t>(bSize + 1));
    vector<vector<uint8_t>> M(aSize + 1, vector<uint8_t>(bSize + 1));
    for (int a = 0; a <= aSize; ++a) {
      M[a][0] = a;
    }
    for (int b = 0; b <= bSize; ++b) {
      M[0][b] = b;
    }
    for (int a = 1; a <= aSize; ++a) {
      for (int b = 1; b <= bSize; ++b) {
        if (static_cast<long>(A[a - 1]) * B[j] == static_cast<long>(B[b - 1]) * A[i]) {
          N[a][b] = N[a - 1][b - 1] + 1;
          M[a][b] = M[a - 1][b - 1];
        } else if (M[a - 1][b] < M[a][b - 1]) {
          N[a][b] = N[a - 1][b];
          M[a][b] = M[a - 1][b] + 1;
        } else {
          N[a][b] = N[a][b - 1];
          M[a][b] = M[a][b - 1] + 1;
        }
      }
    }
    return N[aSize][bSize] + M[aSize][bSize];
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
		cout << "Testing AstronomicalRecords (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1516919917;
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
		AstronomicalRecords _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1,2,1,2,1};
				int B[] = {2,1,2,1,2};
				_expected = 6;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {1,2,3,4};
				int B[] = {2,4,6,8};
				_expected = 4;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {2,3,2,3,2,3,2};
				int B[] = {600,700,600,700,600,700,600};
				_expected = 10;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {1,2,3,4,5,6,7,8,9};
				int B[] = {6,7,8,9,10,11,12};
				_expected = 12;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {100000000,200000000};
				int B[] = {200000000,100000000};
				_expected = 3;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 5:
			{
				int A[] = {85, 473, 340, 450, 331, 398, 66, 485, 130, 240, 283, 464, 193, 157, 218, 468, 202, 181, 192, 111, 128, 254, 303, 559, 296, 521, 377};
                                int B[] = {473, 340, 161, 450, 331, 398, 168, 66, 224, 130, 240, 283, 464, 333, 157, 218, 468, 113, 202, 192, 111, 254, 156, 559, 561, 546, 296, 521, 377, 299, 467};
				_expected = 37;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 6:
			{
				int A[] = {705032704, 1000000000};
				int B[] = {10, 2};
				_expected = 3;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			/*case 7:
			{
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
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
