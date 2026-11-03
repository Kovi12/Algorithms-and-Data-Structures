#include <iostream>
#include <fstream>
using namespace std;
#define N 20

bool IsSubset(int W, int objects, int obj[]) {
	bool mat[objects + 1][W + 1];
	for (int i = 0; i <= objects; i++)
		mat[i][0] = true;
	for (int i = 1; i <= W; i++)
		mat[0][i] = false;

	for (int i = 1; i <= objects; i++)
		for (int j = 1; j <= W; j++)
		{
			if (obj[i - 1] > j)
				mat[i][j] = mat[i - 1][j];
			if (obj[i - 1] <= j)
				mat[i][j] = mat[i - 1][j] || mat[i - 1][j - obj[i - 1]];
		}
	return mat[objects][W];
}


int main() {
	ifstream in("santa.in");
	ofstream out("santa.out");
	int houses;
	in >> houses;
	for (int i = 0; i < houses; i++)
	{
		int W,objects;
		in >> objects >> W;
		int obj[N];
		for (int j = 0; j < objects; j++)
			in >> obj[j];
		if (IsSubset(W, objects, obj))
			out << "Yes\n";
		else
			out << "No\n";
	}
	in.close();
	out.close();
    return 0;
}