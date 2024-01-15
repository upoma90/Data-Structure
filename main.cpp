#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

void adminLogin();
void staffLogin();
void doctorLogin();
string inputPassword();
void startMenu();

int main()
{
    FILE *ptr;
    if((ptr = fopen("start.txt","r")))
    {
        fclose(ptr);
        startMenu();
        return 0;
    }
    else
    {
        string pass;
        string passRep;
        cout<<"Enter Admin Password (Max 30 Letters and only printable character): ";
        pass = inputPassword();
        cout<<endl<<"Retype Password: ";
        passRep = inputPassword();
        if(pass == passRep)
        {
            FILE *f;
            f = fopen("start.txt","w");
            fprintf(f,"%s",pass.c_str());
            fclose(f);
        }
        startMenu();
    }
    return 0;
}

string inputPassword()
{
    char pass[31];
    string passSt="";
    int i = 0;
    while(1)
    {
        char in = getch();
        if(in == 8)
        {
            if(i != 0)
            {
                pass[i] = '\0';
                i--;
            }
        }
        else if(i==29 || in == '\r')
        {
            pass[i] = '\0';
            break;
        }
        else if(in>=32&&in<=126)
        {
            pass[i] = in;
            i++;
        }
    }
    for(int c = 0; pass[c]!='\0';c++)
    {
        passSt.push_back(pass[c]);
    }
    return passSt;
}

void adminLogin()
{
}

void staffLogin()
{
}

void doctorLogin()
{
}

void startMenu()
{
    while(1)
        {
            int choice;
            cout<<"\nChoose Your Role:\n1. Admin\n2.Staff\n3.Doctor\n4.Exit The System\n";
            cout<<"Choice: ";
            cin>>choice;
            if(choice==4)
                break;
            switch(choice)
            {
            case 1:
                adminLogin();
                break;
            case 2:
                staffLogin();
                break;
            case 3:
                doctorLogin();
                break;
            default:
                cout<<"Wrong Choice!!!";
            }
        }
}
