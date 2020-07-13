#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int kmp(string s,string sub) {
		if (s.empty() || sub.empty() || s.size() < sub.size()) {
			return -1;
		}
		vector<int> next = creatNext(sub);
		int i = 0;
		int j = 0;
		while (i < s.size()&&j<sub.size()) {
			if (s[i] == sub[j]) {
				i++;
				j++;
			}
			else if(next[j]==-1){
				i++;
			}
			else {
				j = next[j];
			}
		}
		if (j == sub.size()) {
			return i-j;
		}
		else {
			return -1;
		}
	}
	vector<int> creatNext(string sub) {
		vector<int> next(sub.size());
		next[0] = -1;
		next[1] = 0;
		int cn = 0;
		int i = 2;
		while (i < sub.size()) {
			if (sub[i-1] == sub[cn]) {
				next[i++] = (++cn);
			}
			else if (cn > 0) {
				cn = next[cn];
			}
			else {
				next[i++] = 0;
			}
		}
		return next;
	}
};
int main() {
	Solution s;
	int index = s.kmp("abdabzdabc", "abc");
	cout << index << endl;
	return 0;
}