#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Input data name : ";
    string name;
    cin >> name;
	ifstream in(name);
	string s;

    int word_count = 1;

    if (in.is_open()) {
        in.seekg(0, ios::end);
        int size = in.tellg();
        s.resize(size);
        
        in.seekg(0, ios::beg);
        in.read(&s[0], size);

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ' || s[i] == '\n')
                word_count++;
        }
        if (s[0] == ' ')
            word_count--;
        if (s[s.length() - 1] == ' ')
            word_count--;
        
        cout << s << endl << endl;
    }

    else 
    {
        cout << "err" << endl;
    }


    cout << "word count : " << word_count;


	return 0;
}