#include <vector>

using namespace std;

class CollectingTokens {
public:
  int maxTokens(const vector<int>& A, const vector<int>& B, const vector<int>& tokens, int L) {
    tokens_ = tokens;
    LoadTree(A, B);
    FilterTree(-1, 0);
    vector<int> not_returned;
    vector<int> returned;
    GetTokens(L + 1, 0, not_returned, returned);
    return not_returned.back();
  }

private:
  vector<int> tokens_;
  vector<vector<int>> tree_;

  void LoadTree(const vector<int>& A, const vector<int>& B) {
    tree_.resize(A.size() + 1);
    for (int i = 0; i < A.size(); ++i) {
      tree_[A[i] - 1].push_back(B[i] - 1);
    }
    for (int i = 0; i < B.size(); ++i) {
      tree_[B[i] - 1].push_back(A[i] - 1);
    }
  }

  void FilterTree(int r, int n) {
    auto& subtree = tree_[n];
    auto it = subtree.begin();
    while (it != subtree.end()) {
      if (*it == r) {
        it = subtree.erase(it);
        continue;
      }
      if (!tree_[*it].empty()) {
        FilterTree(n, *it);
      }
      ++it;
    }
  }

  void GetTokens(int l, int n, vector<int>& not_returned, vector<int>& returned) {
    if (l < 2) {
      // Only one step left. Regardless of the node kind, the result is the same.
      not_returned.push_back(0);
      not_returned.push_back(tokens_[n]);
      returned.push_back(0);
      returned.push_back(0);
      return;
    }

    if (tree_[n].empty()) {
      // The node is a leaf.
      for (int i = 0; i <= l; ++i) {
        switch (i) {
          case 0:
            not_returned.push_back(0);
            returned.push_back(0);
            break;
          case 1:
            not_returned.push_back(tokens_[n]);
            returned.push_back(0);
            break;
          default:
            not_returned.push_back(tokens_[n]);
            returned.push_back(tokens_[n]);
        }
      }
      return;
    }
    // The node contains a subtree.
    // Load tokens of every subnode.
    const auto n_subnodes = tree_[n].size();
    vector<vector<int>> not_returned_sub(n_subnodes);
    vector<vector<int>> returned_sub(n_subnodes);
    for (int i = 0; i < n_subnodes; ++i) {
      GetTokens(l - 1, tree_[n][i], not_returned_sub[i], returned_sub[i]);
    }
    vector<vector<int>> memo(n_subnodes);
    // Process not returning paths.
    vector<int> max_not_returned_sub(l);
    for (int nri = 0; nri < n_subnodes; ++nri) {
      // Try every subnode for not returning paths.
      for (int i = nri > 0 ? nri - 1 : 0; i < n_subnodes; ++i) {
        const auto& tokens_sub = i == nri ? not_returned_sub[i] : returned_sub[i];
        if (i == 0) {
          memo[i] = tokens_sub;
          continue;
        }
        memo[i] = vector<int>(l);
        for (int j = 0; j < l; ++j) {
          for (int k = 0; k <= j; ++k) {
            memo[i][j] = max(memo[i][j], memo[i - 1][j - k] + tokens_sub[k]);
          }
        }
      }
      // Find max among all subtrees.
      for (int j = 0; j < l; ++j) {
        max_not_returned_sub[j] = max(max_not_returned_sub[j], memo.back()[j]);
      }
    }
    not_returned.resize(l + 1);
    for (int i = 1; i < l + 1; ++i) {
      not_returned[i] = tokens_[n] + max_not_returned_sub[i - 1];
    }
    // Process returning paths.
    vector<int> max_returned_sub(l);
    // Memo is already containing correct data except for the last vector, which is for not returning.
    int i = n_subnodes - 1;
    if (i == 0) {
      max_returned_sub = returned_sub[i];
    } else {
      for (int j = 0; j < l; ++j) {
        for (int k = 0; k <= j; ++k) {
          max_returned_sub[j] = max(max_returned_sub[j], memo[i - 1][j - k] + returned_sub[i][k]);
        }
      }
    }
    returned.resize(l + 1);
    for (int i = 2; i < l + 1; ++i) {
      returned[i] = tokens_[n] + max_returned_sub[i - 2];
    }
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
		cout << "Testing CollectingTokens (999.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1515202031;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 999.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CollectingTokens _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1};
				int B[] = {2};
				int tokens[] = {7,1};
				int L = 6;
				_expected = 8;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
			}
			case 1:
			{
				int A[] = {3,1};
				int B[] = {2,2};
				int tokens[] = {2,3,9};
				int L = 5;
				_expected = 14;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
			}
			case 2:
			{
				int A[] = {1,2,5,3};
				int B[] = {4,4,1,4};
				int tokens[] = {6,1,6,4,4};
				int L = 3;
				_expected = 16;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
			}
			case 3:
			{
				int A[] = {9,1,7,10,5,8,3,4,2};
				int B[] = {6,6,9,6,6,1,1,6,6};
				int tokens[] = {4,2,1,6,3,7,8,5,2,9};
				int L = 4;
				_expected = 26;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
			}
			case 4:
			{
				int A[] = {25,22,35,42,40,9,32,12,37,44,23,1,24,28,20,4,26,33,11,48,34,6,16,50,46,17,8,43,18,30,31,36,39,13,
				          10,45,3,47,15,2,29,19,7,14,41,49,38,27,21};
				int B[] = {5,5,25,25,25,42,25,40,5,35,25,32,42,9,32,23,40,25,20,33,26,37,12,1,48,24,22,25,11,24,48,34,18,9,50,42,16,40,1,
				          10,47,22,48,44,48,1,4,46,47};
				int tokens[] = {6,9,4,9,5,8,6,4,4,1,4,8,3,4,5,8,5,6,4,9,7,9,7,9,5,2,7,2,7,7,5,9,5,8,5,7,1,9,3,9,3,6,4,5,5,4,7,9,2,2};
				int L = 48;
				_expected = 194;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
			}
			case 5:
			{
				int A[] = {1,1,1,4,5,6,7};
				int B[] = {2,3,4,5,6,7,8};
				int tokens[] = {1,2,2,3,4,5,6,7};
				int L = 5;
				_expected = 26;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
			}
			case 6:
			{
				int A[] = {1,1,1,3,5,5,4,4};
				int B[] = {2,3,4,5,8,9,6,7};
				int tokens[] = {1,3,1,2,100,5,100,5,30};
				int L = 7;
				_expected = 234;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
			}
			/*case 7:
			{
				int A[] = ;
				int B[] = ;
				int tokens[] = ;
				int L = ;
				_expected = ;
				_received = _obj.maxTokens(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(tokens, tokens+sizeof(tokens)/sizeof(int)), L); break;
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
