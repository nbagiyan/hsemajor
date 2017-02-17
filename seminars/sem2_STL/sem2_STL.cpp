#include <iostream> 
#include <algorithm> 
#include <string> 
#include <vector> 
#include <list> 

using namespace std;

bool is_even(int n)
{
	return !(n % 2);
}

void square(int n)
{
	cout << n*n << ' ' << endl;
}

int make_square(int n)
{
	return n*n;
}

void view(int n)
{
	cout << ' ' << n << endl;
}


void main()
{
	string s = "a long string";
	vector<int> v(3);
	vector<int> v2(10, 100);
	vector<int> v3 = { 1, 2, 3, 4, 5, 6, 1, 2 };
	vector<int> v5(5, 7);
	vector<int> v10(10);
	list<int> l(10);
	reverse(s.begin(), s.end());
	cout << s << endl;
	for (vector<int> ::reverse_iterator it = v3.rbegin(); it != v3.rend(); ++it) {
		cout << ' ' << *it << endl;
	}
	reverse(v3.begin() + 2, v3.end() - 1);
	for (vector<int> ::iterator it = v3.begin(); it != v3.end(); ++it) {
		cout << ' ' << *it;
	}
	vector<int> :: iterator it = find(v3.begin(), v3.end(), 4);
	if (it == v3.end()) {
		cout << "not found" << endl;
	}
	else {
		cout << "found!" << endl;
		cout << "found \"4\" - " << count(v3.begin(), v3.end(), 4) << " time(s)" << endl;
		cout << "found \"2\" - " << count(v3.begin(), v3.end(), 2) << " time(s)" << endl;
	}
	cout << count_if(v3.begin(), v3.end(), is_even) << endl;
	for_each(v3.begin(), v3.end(), square);
	transform(v3.begin(), v3.end(), v3.begin(), make_square);
	for_each(v3.begin(), v3.end(), view);
	for_each(v5.begin(), v5.end(), view);
	replace(v5.begin(), v5.end(), 7, 3);
	for_each(v5.begin(), v5.end(), view);
	fill(v5.begin() + 1, v5.end() - 2, 8);
	for_each(v5.begin(), v5.end(), view);
	for (int i = 0; i < v10.size(); i++) {
		v10.at(i) = i;
	}
	copy(v10.begin(), v10.end(), l.begin());
	for_each(l.begin(), l.end(), view);
	vector<int>::iterator it1 = min_element(v10.begin(), v10.end());
	vector<int>::iterator it2 = max_element(v10.begin(), v10.end());
	cout << "min " << *it1 << endl;
	cout << "max "<< *it2 << endl;
}

