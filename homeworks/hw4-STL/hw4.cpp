#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


ostream & operator<<(ostream& out, const vector<int>& lst);
void movetoarray(vector<int>& dst, const list<int> lst);
void sortLst(list<int>& src);
void arrayListToArray(const vector<list<int>> src, vector<int>& dst);
int transformation(vector<list<int>> src);
bool sortMin(int i, int j);
bool lenoflst(list<int>& lst);
bool sortByMin(const list<int>& lst, const list<int>& lst1);




int transformation(vector<list<int>> src) {
	vector<list<int>> temp(src.size());
	vector<int> dst;
	vector<list<int>>::iterator it;
	it = copy_if(src.begin(), src.end(), temp.begin(), lenoflst);
	temp.resize(it - temp.begin());
	try {
		if (temp.empty())
			throw temp.empty();
	}
	catch (...) {
		cout << "No lists to transform!" << endl;
		return 0;
	}
	src.clear();
	sort(temp.begin(), temp.end(), sortByMin);
	for_each(temp.begin(), temp.end(), sortLst);
	arrayListToArray(temp, dst);
	cout << dst;
	cout << endl;
	return 1;
}

int main() {
	vector<list<int>> src1 = { { 1,2 },{ 30,13,31 },{ 4,2,1,2 },{ 0,1,10,0 },{ 4,5,3,6 },{ 2,5,6 } };
	vector<list<int>> src2 = { { 1 },{ 1,7,9,99,5,6,2 },{ 5,4,-3,6,0,11 },{ 2,3 },{ 4,5 },{ -10,1,1,5 },{ -100,789,456 } };
	vector<list<int>> src3 = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 3,2,1 }, { 1,5,5 } };
	vector<list<int>> src4 = { { 0,0,0,0 }, { 1,-10,-150,778 }, { 4,4,2,1,1,0,11,5,6,-1 }, { 1,1 }, { 3,3,4 }, { 4,4,2,1 } };
	transformation(src1);
	transformation(src2);
	transformation(src3);
	transformation(src4);
	return 2;
}
