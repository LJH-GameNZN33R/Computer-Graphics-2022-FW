#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream in("cg2.txt");
	string s;

    if (in.is_open()) {
        in.seekg(0, ios::end);
        int size = in.tellg();
        s.resize(size);
        
        in.seekg(0, ios::beg);
        in.read(&s[0], size);

        cout << s << endl;
    }
    else 
    {
        cout << "err" << endl;
    }

	return 0;
}