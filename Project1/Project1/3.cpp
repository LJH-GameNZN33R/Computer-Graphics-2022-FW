#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Input data name : ";
    string name;
    //cin >> name;

    ifstream in("cg2.txt");
    string s;
    char input{};

    in.seekg(0, ios::end);
    int size = in.tellg();
    s.resize(size);

    in.seekg(0, ios::beg);
    in.read(&s[0], size);

    cout << s << endl << endl;

    int line_num = 0;

    while (true)
    {
        cout << "command :";
        cin >> input;

        switch (input)
        {
            // ����
        case 'q':
            return 0;

            // ���� ������
        case 'd':
            for (int i = 0; i < size; i++)
            {
                if (s[i] == '\n') {
                    int start = i;
                    {
                        for (int j = start; j >= line_num; j--)
                            cout << s[j];
                    }
                    line_num = i;
                }

            }
            cout << endl;
            break;

            // 3���� �� @@ ����, ���Է½� ����
        case 'e':

            cout << endl;

            // ���� ����/eĿ�ǵ� ���� ������
        case 'f':

            cout << endl;

            // Ư�� ���ڿ� ġȯ�ϱ�
        case 'g':

            cout << endl;

            // ���� ���ڰ� ���ö����� ����ϱ�
        case 'h':

            cout << endl;
        }
    }

    return 0;
}