#include <iostream>
#include "CP.h"
using namespace std;

int main()
{
	vector<vector<int> > Sets(2, vector<int>(3));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			Sets[i][j] = (i + 1) * (j + 1);
			cout << Sets[i][j] << " ";
		}
		cout << endl;
	}

	CartesianProduct CP(Sets);

	cout << CP << endl;

	CartesianProduct::iterator iter = CP.begin();
	cout << "------------------" << endl;


	for (iter = CP.begin(); iter != CP.end(); ++iter) {
//		cout << (*iter) << endl;
		vector<int> &vec = *iter;
		for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << " ";
		cout << endl;

	}

	return 1;
}

