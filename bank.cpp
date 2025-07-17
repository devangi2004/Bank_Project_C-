#include<iostream.h>
#include<conio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class bank
{
    private:
        float balance;
        string id, pass, name, fname, address,phone_number, pin;
    public:
        void menu();
        void bank_management();
        void atm_management();
        void new_user();
        void already_user();
        void deposit();
        void withdraw();
        void Transfer();
        void Payment();
        void search();
        void update();
        void del();
        void Show_record();
        void show_payment();
        void user_balance();
        void with_atm();
        void detail();
};
    void bank::menu()
    {
        p:
        system("cls");
        int choice;
        char ch;
        string pin,pass, email;
        cout<<"\n\n\t\tControl Panel";
        cout<<"\n\n 1. Bank Management";
        cout<<"\n 2. ATM Management";
        cout<<"\n 3. Exit";
        cout<<"\n\n Enter Your Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                system("cls");
                cout<<"\n\n\t\tLogin Account";
                cout<<"\n\n E-mail : ";
                cin>>email;
                cout<<"\n\n\t\t Pin Code : ";
                    for(int i=1;i<=5;i++)
                    {
                        ch = getch();
                        pin += ch;
                        cout<<"*";
                    }
                cout<<"\n\n Password : ";
                    for(int i=1;i<=5;i++)
                    {
                        ch = getch();
                        pass += ch;
                        cout<<"*";
                    }
                    if(email == "bank@gmail.com" && pin == "25504" && pass == "12121")
                    {
                        bank_management();
                    }
                    else
                    {
                        cout<<"\n\n Your E-mail, Pin, & Password Is Wrong...";
                    }
            break;
            case 2:
                atm_management();
            break;
            case 3:
                exit(0);
            break;
            default:
                cout<<"\n\n invalid Value...Please Try Again";
        }
        getch();
        goto p;
    }
    void bank::bank_management()
    {
        p:
        system("cls");
        int choice;
        cout<<"\n\n\t\t Bank Management System";
        cout<<"\n\n 1.  New User";
        cout<<"\n\n 2.  Already User";
        cout<<"\n\n 3.  Deposit Option";
        cout<<"\n\n 4.  Withdraw option";
        cout<<"\n\n 5.  Transfer Option";
        cout<<"\n\n 6.  Payment Option";
        cout<<"\n\n 7.  Search User Record";
        cout<<"\n\n 8.  Update User Record";
        cout<<"\n\n 9.  Delete User Record";
        cout<<"\n\n 10. Show all Records";
        cout<<"\n\n 11. Bills Records";
        cout<<"\n\n 12. Go Back";
        cout<<"\n\n Enter Your Choice :  ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                new_user();
                break;
            case 2:
                already_user();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                Transfer();
                break;
            case 6:
                Payment();
                break;
            case 7:
                search();
                break;
            case 8:
                update();
                break;
            case 9:
                del();
                break;
            case 10:
                Show_record();
                break;
            case 11:
                show_payment();
                break;
            case 12:
                menu();
        default:
            cout<<"\n\n invalid Value...Please Try Again";
        }
        getch();
        goto p;
    }
    void bank::atm_management()
    {
        p:
        system("cls");
        int choice;
        cout<<"\n\n\t\t ATM Management System";
        cout<<"\n\n 1. User Login & check Balance";
        cout<<"\n\n 2. Withdraw Amount";
        cout<<"\n\n 3. Account Details";
        cout<<"\n\n 4. Go Back";
        cout<<"\n\n Enter Your Choice :  ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            user_balance();
            break;
        case 2:
            with_atm();
            break;
        case 3:
            detail();
            break;
        case 4:
            menu();
        default:
            cout<<"\n\n invalid Value...Please Try Again";
        }
        getch();
        goto p;
    }
    void bank::new_user()
    {
        p:
        system("cls");
        fstream file;
        int p, ph;
        float b;
        string n, f, pa, a, i;
        cout<<"\n\n\t\t Add New User";
        cout<<"\n\n\t\t User ID : ";
        cin>>id;
        cout<<"\n\n\t\t Name : ";
        cin>>name;
        cout<<"\n\n\t\tFather Name : ";
        cin>>fname;
        cout<<"\n\n\t\t Address : ";
        cin>>address;
        cout<<"\n\n\t\t Pin Code (5 digit) : ";
        cin>>pin;
        cout<<"\n\n\t\t Password (5 digit) : ";
        cin>>pass;
        cout<<"\n\n\t\t Phone No. : ";
        cin>>phone_number;
        cout<<"\n\n\t\t Current Balance : ";
        cin>>balance;
        file.open("bank.txt",ios::in);
        if(!file)
        {
            file.open("bank.txt",ios::app| ios::out);
            file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone_number<<" "<<balance<<"\n";
            file.close();
        
        }
        else
        {
            file>>i>>n>>f>>a>>pa>>p>>ph>>b;
            while(!file.eof())
            {
                if(i == id)
                {
                    cout<<"\n\n User id already exist...";
                    getch();
                    goto p;
                }
                file>>i>>n>>f>>a>>pa>>p>>ph>>b;
            }
            file.close();
            file.open("bank.txt",ios::app| ios::out);
            file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone_number<<" "<<balance<<"\n";
            file.close();
        }
        cout<<"\n\n New User Account Created Successfully...";
    }
    void bank::already_user()
    {
        system("cls");
        fstream file;
        string t_id;
        int found=0;
        cout<<"\n\n\t\t\t Already User Account";
        file.open("bank.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File Opening Error...";
        }
        else
        {
            cout<<"\n\n User Id : ";
            cin>>t_id;
            file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
            while(!file.eof())
            {
                if(t_id == id)
                {
                    system("cls");
                    cout<<"\n\n\t\t\t Already User Account";
                    cout<<"\n\n User Id: "<<id<<"     Pin Code: "<<pin<<"     Password: "<<pass;
                    found++;
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
            }
            file.close();
            if (found == 0)
            cout<<"\n\n User Id Can't Found...";
        }
    }
    void bank::deposit()
    {
        fstream file,file1;
        string t_id;
        float dep;
        int found=0;
        system("cls");
        cout<<"\n\n\t\t\t Deposit Amount Option";
        file.open("bank.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File Opening Error...";
        }
        else
        {
            cout<<"\n\n User Id : ";
            cin>>t_id;
            file1.open("bank1.txt",ios::app|ios::out);
            file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
            while(!file.eof())
            {
                if(t_id == id)
                {
                    cout<<"\n\n Amount For Deposit : ";
                    cin>>dep;
                    balance += dep;
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone_number<<" "<<balance<<"\n";
                    found++;
                    cout<<"\n\n\t\t\t Your Amount "<<dep<<" Successfully Deposit...";
                }
                else
                {
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone_number<<" "<<balance<<"\n";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt","bank.txt");
            if (found == 0)
            cout<<"\n\n User Id Can't Found...";
        }
    }
     void bank::withdraw()
    {
        fstream file,file1;
        string t_id;
        float with;
        int found=0;
        system("cls");
        cout<<"\n\n\t\t\t Withdraw Amount Option";
        file.open("bank.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File Opening Error...";
        }
        else
        {
            cout<<"\n\n User Id : ";
            cin>>t_id;
            file1.open("bank1.txt",ios::app|ios::out);
            file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
            while(!file.eof())
            {
                if(t_id == id)
                {
                    cout<<"\n\n Amount For withdraw : ";
                    cin>>with;
                    if(with <= balance)
                    {
                        balance -= with;
                        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone_number<<" "<<balance<<"\n";
                        found++;
                        cout<<"\n\n\t\t\t Your Amount "<<with<<" Successfully withdraw...";
                    }
                    else
                    {
                        cout<<"\n\n\t\t\t Your Current Balance "<<balance<<" Is Less...";
                    }
                    found++;
                }
                else
                {
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone_number<<" "<<balance<<"\n";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt","bank.txt");
            if (found == 0)
            cout<<"\n\n User Id Can't Found...";
        }
    }
    void bank::Transfer()
        {
            fstream file, file1;
            system("cls");
            string s_id , r_id;
            int found=0;
            float amount;
            cout<<"\n\n\t\t\t Payment Transfer Option";
            file.open("bank.txt",ios::in);
            if(!file)
            {
                cout<<"\n\n File Opening Error...";
            }
            else
            {
                cout<<"\n\n Sender User Id For Transcation : ";
                cin>>s_id;
                cout<<"\n\n Receiver User ID For Transcation : ";
                cin>>r_id;
                cout<<"\n\n Enter Transcation Amount : ";
                cin>>amount;
                file1.open("bank1.txt",ios::app|ios::out);
                file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                while (!file.eof())
                {
                    if(s_id == id && amount <= balance)
                    found++;
                    else if(r_id == id)
                    found++;
                    file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                }
                file.close();
                if(found == 2)
                {
                    file.open("bank.txt", ios::in);
                    file1.open("bank1.txt",ios::app|ios::out); 
                    file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                    while(!file.eof())
                    {
                        if(s_id == id)
                        {
                            balance -= amount;
                            file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone_number<<" "<<balance<<"\n";
                        }
                        else if(r_id == id)
                        {
                            balance += amount;
                            file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone_number<<" "<<balance<<"\n";
                        }
                        else
                        {
                            file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone_number<<" "<<balance<<"\n";
                        }
                        file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                    }
                    file.close();
                    file1.close();
                    remove("bank.txt");
                    rename("bank1.txt","bank.txt");
                    cout<<"\n\n\t\t\t Transcation Successfully...";
                }
                else
                {
                    cout<<"\n\n\t\t\t Both Transcation User ID's & Balance Invalid...";
                }
            }
        }
        void bank::Payment()
        {
            fstream file,file1;
            system("cls");
            int found=0;
            string t_id , b_name;
            float amount;
            SYSTEMTIME x;
            cout<<"\n\n\t\t\t Bills Payment Option";
            file.open("bank.txt",ios::in);
            if(!file)
            {
                cout<<"\n\n File Opening Error...";
            }
            else
            {
                cout<<"\n\n Enter User ID : ";
                cin>>t_id;
                cout<<"\n\n Bill Name : ";
                cin>>b_name;
                cout<<"\n\n Bill Amount : ";
                cin>>amount;
                file1.open("bank1.txt",ios::app|ios::out);
                file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                while(!file.eof())
                {
                    if(t_id == id && amount <= balance)
                    {
                        balance -= amount;
                        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone_number<<" "<<balance<<"\n";
                        found++;
                    }
                    else
                    {
                        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone_number<<" "<<balance<<"\n";
                    }
                    file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                }
                file.close();
                file1.close();
                remove("bank.txt");
                rename("bank1.txt","bank.txt");
                if(found == 1)
                {
                    GetSystemTime(&x);
                    file.open("bill.txt",ios::app|ios::out);
                    file<<t_id<<" "<<b_name<<" "<<amount<<" "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<"\n";
                    file.close();
                    cout<<"\n\n\t\t\t"<<b_name<<"Bill Pay Successfully...";
                }
                else
                {
                    cout<<"\n\n User ID OR Amount Invalid...";
                }
            }
        }
        void bank::search()
        {
            system("cls");
            fstream file;
            string t_id;
            int found=0;
            cout<<"\n\n\t\t\t Search User Record";
            file.open("bank.txt",ios::in);
            if(!file)
            {
                cout<<"\n\n File Opening Error...";
            }
            else
            {
                cout<<"\n\n User Id : ";
                cin>>t_id;
                file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                while (!file.eof())
                {
                    if(t_id == id)
                    {
                        system("cls");
                        cout<<"\n\n\t\t\t Search User Record";
                        cout<<"\n\n\n User ID : "<<id;
                        cout<<"\n\n\n Name : "<<name;
                        cout<<"\n\n\n Father Name : "<<fname;
                        cout<<"\n Address : "<<address;
                        cout<<"\n Pin : "<<pin;
                        cout<<"\n Password : "<<pass;
                        cout<<"\n Phone no. : "<<phone_number;
                        cout<<"\n Balance : "<<balance;
                        found++;
                    }
                    file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                }
                file.close();
                if(found == 0)
                cout<<"\n\n User ID Can't Found...";
            }
        }
        void bank::update()
        {
            system("cls");
            fstream file, file1;
            string t_id, pa, n, f, a;
            int found=0, p, ph;
            cout<<"\n\n\t\t\t Edit User Record";
            file.open("bank.txt",ios::in);
            if(!file)
            {
                cout<<"\n\n File Opening Error...";
            }
            else
            {
                cout<<"\n\n User ID : ";
                cin>>t_id;
                file1.open("bank1.txt",ios::app|ios::out);
                file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                while (!file.eof())
                {
                    if(t_id == id)
                    {
                        cout<<"\n\n\t\t Name : ";
                        cin>>n;
                        cout<<"\n\n\t\tFather Name : ";
                        cin>>f;
                        cout<<"\n\n\t\t Address : ";
                        cin>>a;
                        cout<<"\n\n\t\t Pin Code : ";
                        cin>>p;
                        cout<<"\n\n\t\t Password : ";
                        cin>>pa;
                        cout<<"\n\n\t\t Phone No. : ";
                        cin>>ph;
                        file1<<" "<<id<<" "<<n<<" "<<f<<" "<<a<<" "<<p<<" "<<pa<<" "<<ph<<" "<<balance<<"\n";
                        cout<<"\n\n\t\t\t Record Update Successfully...";
                        found++;
                    }
                    else
                    {
                        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone_number<<" "<<balance<<"\n";
                    }
                    file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                }
                file.close();
                file1.close();
                remove("bank.txt");
                rename("bank1.txt","bank.txt");
                if(found == 0)
                cout<<"\n\n User ID Can't Found...";
            }
        }
        void bank::del()
        {
           system("cls");
            fstream file, file1;
            string t_id;
            int found=0;
            cout<<"\n\n\t\t\t Edit User Record";
            file.open("bank.txt",ios::in);
            if(!file)
            {
                cout<<"\n\n File Opening Error...";
            }
            else
            {
                cout<<"\n\n User ID : ";
                cin>>t_id;
                file1.open("bank1.txt",ios::app|ios::out);
                file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                while (!file.eof())
                {
                    if(t_id == id)
                    {
                        cout<<"\n\n\t\t\t Record Deleted Successfully...";
                        found++;
                    }
                    else
                    {
                        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone_number<<" "<<balance<<"\n";
                    }
                    file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                }
                file.close();
                file1.close();
                remove("bank.txt");
                rename("bank1.txt","bank.txt");
                if(found == 0)
                cout<<"\n\n User ID Can't Found...";
            } 
        }
        void bank::Show_record()
        {
            system("cls");
            fstream file;
            int found=0;
            cout<<"\n\n\t\t\t Show All User's Records";
            file.open("bank.txt",ios::in);
            if(!file)
            {
                cout<<"\n\n File Opening Error...";
            }
            else
            {
                file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                while (!file.eof())
                {
                    cout<<"\n\n\n User ID: "<<id;
                    cout<<"\n Name: "<<name;
                    cout<<"\n Father Name: "<<fname;
                    cout<<"\n Address: "<<address;
                    cout<<"\n Pin: "<<pin;
                    cout<<"\n Password: "<<pass;
                    cout<<"\n Phone Number: "<<phone_number;
                    cout<<"\n Current Balance: "<<balance;
                    cout<<"\n\n=========================================================";
                    file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                    found++;
                }
                file.close();
                if(found == 0)
                cout<<"\n\n Data Base is Empty...";
            }
        }
        void bank::show_payment()
        {
            system("cls");
            fstream file;
            int found=0,c_date,c_month,c_year;
            float amount;
            cout<<"\n\n\t\t\t Show All Bill's Records";
            file.open("bill.txt",ios::in);
            if(!file)
            {
                cout<<"\n\n File Opening Error...";
            }
            else
            {
                file>>id>>name>>amount>>c_date>>c_month>>c_year;
                while (!file.eof())
                {
                    cout<<"\n\n\n User ID: "<<id;
                    cout<<"\n Bill Name: "<<name;
                    cout<<"\n Amount: "<<amount;
                    cout<<"\n Date: "<<c_date;
                    cout<<"\n Month: "<<c_month;
                    cout<<"\n Year: "<<c_year;
                    cout<<"\n\n=========================================================";
                    file>>id>>name>>amount>>c_date>>c_month>>c_year;
                    found++;
                }
                file.close();
                if(found == 0)
                cout<<"\n\n Data Base is Empty...";
            }
        }
        void bank::user_balance()
        {
            system("cls");
            fstream file;
            int found=0;
            string t_id,t_pin,t_pass;
            char ch;
            cout<<"\n\n\t\t\t User Login & Check Balance";
            file.open("bank.txt",ios::in);
            if(!file)
            {
                cout<<"\n\n File Opening Error...";
            }
            else
            {
                cout<<"\n\n User ID: ";
                cin>>t_id;
                cout<<"\n\n Pin Code: ";
                for (int i = 1; i <= 5; i++)
                {
                    ch = getch();
                    t_pin += ch;
                    cout<<"*";
                }
                cout<<"\n\n Password: ";
                for (int i = 1; i <= 5; i++)
                {
                    ch = getch();
                    t_pass += ch;
                    cout<<"*";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                while(!file.eof())
                {
                    if(t_id == id && t_pin == pin && t_pass == pass)
                    {
                        cout<<"\n\n\t\t\t Your Current Balance Is : "<<balance;
                        found++;
                    }
                    file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                }
                file.close();
                if(found == 0)
                cout<<"\n\n\t\t\t User ID, Pin & Password Invalid...";
            }
        }
        void bank::with_atm()
        {
            fstream file,file1;
            string t_id,t_pin,t_pass;
            float with;
            int found=0;
            char ch;
            system("cls");
            cout<<"\n\n\t\t\t Withdraw Amount Option";
            file.open("bank.txt",ios::in);
            if(!file)
            {
                cout<<"\n\n File Opening Error...";
            }
            else
            {
                cout<<"\n\n User Id : ";
                cin>>t_id;
                cout<<"\n\n Pin : ";
                for (int i = 1; i <= 5; i++)
                    {
                        ch = getch();
                        t_pin += ch;
                        cout<<"*";
                    }
                cout<<"\n\n Password : ";
                for (int i = 1; i <= 5; i++)
                    {
                        ch = getch();
                        t_pass += ch;
                        cout<<"*";
                    }
                file1.open("bank1.txt",ios::app|ios::out);
                file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                while(!file.eof())
                {
                    if(t_id == id && t_pin == pin && t_pass == pass)
                    {
                        cout<<"\n\n Amount For withdraw : ";
                        cin>>with;
                        if(with <= balance)
                        {
                            balance -= with;
                            file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone_number<<" "<<balance<<"\n";
                            found++;
                            cout<<"\n\n\t\t\t Your Amount "<<with<<" Successfully withdraw...";
                            cout<<"\n\n\t\t\t Your Current Balance Is : "<<balance;
                        }
                        else
                        {
                            cout<<"\n\n\t\t\t Your Current Balance "<<balance<<" Is Less...";
                        }
                        found++;
                    }
                    else
                    {
                        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone_number<<" "<<balance<<"\n";
                    }
                    file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                }
                file.close();
                file1.close();
                remove("bank.txt");
                rename("bank1.txt","bank.txt");
                if (found == 0)
                cout<<"\n\n User Id Can't Found...";
            }
        }
        void bank::detail()
        {
            fstream file;
            string t_id,t_pin,t_pass;
            int found=0;
            char ch;
            system("cls");
            cout<<"\n\n\t\t\t Check details Option";
            file.open("bank.txt",ios::in);
            if(!file)
            {
                cout<<"\n\n File Opening Error...";
            }
            else
            {
                cout<<"\n\n User Id : ";
                cin>>t_id;
                cout<<"\n\n Pin : ";
                for (int i = 1; i <= 5; i++)
                    {
                        ch = getch();
                        t_pin += ch;
                        cout<<"*";
                    }
                cout<<"\n\n Password : ";
                for (int i = 1; i <= 5; i++)
                    {
                        ch = getch();
                        t_pass += ch;
                        cout<<"*";
                    }
                file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                while(!file.eof())
                {
                    if(t_id == id && t_pin == pin && t_pass == pass)
                    {
                        system("cls");
                        cout<<"\n\n\t\t\t Check details";
                        cout<<"\n\n\n User ID: "<<id;
                        cout<<"\n Name: "<<name;
                        cout<<"\n Father Name: "<<fname;
                        cout<<"\n Address: "<<address;
                        cout<<"\n Pin: "<<pin;
                        cout<<"\n Password: "<<pass;
                        cout<<"\n Phone Number: "<<phone_number;
                        cout<<"\n Current Balance: "<<balance;
                        found++;
                    }
                    file>>id>>name>>fname>>address>>pin>>pass>>phone_number>>balance;
                }
                file.close();
                if (found == 0)
                cout<<"\n\n User Id Can't Found...";
            }
        }
main()
{
    bank obj;
    obj.menu();
}
