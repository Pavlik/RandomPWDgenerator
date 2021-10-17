#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
#include <string>
#include "conio.h"
#include "windows.h"
#include <fstream>

using namespace std;


char symbols[] = {'0','1','2','3','4','5','6','7','8','9',
                  'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                  'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                  '`','~','!','@','#','$','%','^','&','*','(',')','-','_','+','=','?','|',':','<','>',';','\\','/','[',']','{','}','"', '\''};
char excludeSybols[10] = {'0', 'O', 'o', '!', '1', 'i', 'I', 'l', 'L', '|'};

char q;
char sim_chars = 0;
int size = sizeof(symbols)/sizeof(symbols[0]);
int num,b;
    char a;
    int bo;
    int seed;
    char name[30] = "";
    string main_path;

string createPath();
char exclude();

int main()
{
    srand(time(NULL));
    while(q != 'q')
    {
        system("cls");
        main_path = createPath();
        ofstream fout(main_path, ios_base::app);
        do
        {
            cout << "If you want to exclude symbols like: 0, O, o, i, I, 1 etc. Press 1, else press 0: ";
            cin >> sim_chars;
            if(sim_chars == '0' || sim_chars == '1') break;
            else cout << "ENTER \"1\" OR \"0\"!!!!!!!!!!!!!!!" << endl;
        } while(true);
        cout << "Enter password name: ";
        cin >> name;
        fout << name;
        fout << " — ";
        cout << "Enter password lenght: ";
        cin >> num;
        cout << '\n';
        char password[num+1] = "";
        if(cin.fail()) 
        {
            cin.clear();
            cin.ignore();
            cout << "Not num" << '\n';
        }
        else for(int i = 0; i < num; i++)
        {
            if(sim_chars == '1') a = exclude(); 
            else a = rand() % size;
            password[i] = symbols[a];
        }
        password[num+1] = '\0';       // Без этого не будет работать!
        cout << '\n';

        string pas = string(password);
        cout << pas;
        fout << pas << endl;
        
        cout << '\n';
        cout << '\n';
        cout << "Press any key to continue and press 'q' to exit: \n";
        q = getch();
        fout << "-----------------------------------------------------";
        fout << endl;
        fout.close();
    }
    return 0;
}

string createPath()
{
    char path[30] = "";
    char bo = ' ';
    string expand = ".txt";
    string str = "password.txt";
        do
        {
            cout << "If you want to create new file with passwords enter \"1\" else enter \"0\": ";
            cin >> bo;
            if(bo == '1')
            {
                cout << "Enter path or file name (e.g. D:\\folder\\file_name or just file_name): " << endl;
                cin >> path;
                return string(path).append(".txt");
                break;
            }  
            else if(bo == '0') 
            {
                return str;
                break;
            } 
            else cout << "ENTER \"0\" OR \"1\" !!!!!!!" << endl;
        } while(true);
}

char exclude()
{
    char a;
    char check;
    a = rand() % size;
    for(int i = 0; i < 10; i++) if(symbols[a] == excludeSybols[i]) a = exclude();
    return a;
}
