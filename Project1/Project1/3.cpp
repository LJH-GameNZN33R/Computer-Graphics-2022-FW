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
            // 종료
        case 'q':
            return 0;

            // 문장 뒤집기
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

            // 3문자 후 @@ 삽입, 재입력시 삭제
        case 'e':

            cout << endl;

            // 띄어쓰기 기준/e커맨드 기준 뒤집기
        case 'f':

            cout << endl;

            // 특정 문자열 치환하기
        case 'g':

            cout << endl;

            // 같은 문자가 나올때까지 출력하기
        case 'h':

            cout << endl;
        }
    }

    return 0;
}