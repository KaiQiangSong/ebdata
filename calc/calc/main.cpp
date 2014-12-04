#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> Label_data;
vector<int> Label_predict;
int cnt1, cnt2, cnt3, cnt4;

int main()
{
	ifstream idata("feat1_test.data");
	ifstream ipredict("test.predict");
	int cnt = 0;
	while (!idata.eof())
	{
		int x;
		idata >> x;
		Label_data.push_back(x);
		string s;
		getline(idata, s);
		//++cnt;
		//cout << cnt << endl;
	}
	cnt = 0;
	while (!ipredict.eof())
	{
		int x;
		ipredict >> x;
		Label_predict.push_back(x);
		//++cnt;
		//cout << cnt << endl;
	}
	size_t n = Label_data.size();
	cnt1 = cnt2 = cnt3 = cnt4 = 0;
	for (size_t i = 0; i < n; ++i)
	{
		if (Label_data[i] == 1 && Label_predict[i] == 1) ++cnt1;
		if (Label_data[i] == 1 && Label_predict[i] == -1) ++cnt2;
		if (Label_data[i] == -1 && Label_predict[i] == 1) ++cnt3;
		if (Label_data[i] == -1 && Label_predict[i] == -1) ++cnt4;
	}
	double A = (double)(cnt1 + cnt4) / (double)(n);
	double P = (double)(cnt1) / (double)(cnt1 + cnt3);
	double R = (double)(cnt1) / (double)(cnt1 + cnt2);
	double F = 2*P*R / (P + R);
	cout << "A = " << A << endl;
	cout << "P = " << P << endl;
	cout << "R = " << R << endl;
	cout << "F = " << F << endl;
	system("pause");
	return 0;
}