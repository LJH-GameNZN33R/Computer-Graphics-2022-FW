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

    int word_count = 0;
    int num_count = 0;
    bool Bnum = 0;
    int cap_count = 0;
    bool Bcap = 0;

    if (in.is_open()) {
        in.seekg(0, ios::end);
        int size = in.tellg();
        s.resize(size);
        
        in.seekg(0, ios::beg);
        in.read(&s[0], size);

        cout << s << endl << endl;

        for (int i = 0; i < size; i++)
        {
            if (s[i] > 47 && s[i] < 58)
                Bnum = 1;
            if (s[i] > 64 && s[i] < 91)
                Bcap = 1;

            cout << s[i] << Bnum << Bcap << " ";

            if (s[i] == ' ' || s[i] == '\n') {
                if (Bnum)
                {
                    Bnum = 0;
                    num_count++;
                }
                if (Bcap)
                {
                    Bcap = 0;
                    cap_count++;
                }
                word_count++;
            }
        }
    }

    else 
    {
        cout << "err" << endl;
    }


    cout << "Whole word count : " << word_count << endl;
    cout << "alphabet word count : " << word_count - num_count << endl << "number count : " << num_count << endl << "Capital count : " << cap_count << endl;

	return 0;
}