#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
class bank {
public :

    string fname ;
    string lname ;
    string name  ;
    int acc_no ;
    int balance ;
    bank()
    {
        name = "no name" ;
        int acc_no = 0 ;
        int balance = 0 ;
    }
    void read_data()
        {
            cout << "Enter your First Name : " ;
            cin >> fname ;
            cout<< endl ;
            cout << "Enter your Last Name : " ;
            cin >> lname ;
            name = fname + lname ;
            cout<< endl ;
            cout << "Enter your Account Number : " ;
            cin >> acc_no ;
            cout<<endl ;
            cout<<"Enter the balance : " ;
            cin>> balance ;
            cout<< endl ;
            if(acc_no == 0)
               {
                   return ;
               }
            ofstream myfile("datasheet.dat" , ios :: app | ios :: binary) ;
            myfile.write((char*)this , sizeof(*this)) ;
            myfile.close();



        }
        void show_data()
        {
           ifstream myfile ;
           myfile.open("datasheet.dat" , ios::in | ios ::binary) ;
           if(!myfile)
           {
               cout<< "file not found " ;
           }
           else
           {
                myfile.read((char*)this , sizeof(*this)) ;
                while(!myfile.eof())
                {
                    cout << name << "\t" << acc_no << "\t" << balance  << endl ;
                    myfile.read((char*)this , sizeof(*this)) ;
                }
                myfile.close() ;
           }
        }
        void add_balance()
        {

        }
        void view_balance(int* t)
        {
            ifstream myfile ;
            myfile.open("datasheet.dat" , ios::in|ios::binary) ;
            if(!myfile)
            {
                cout<<"file not found " ;
                return ;
            }
            else
            {
                myfile.read((char*)this ,  sizeof(*this)) ;
                while(!myfile.eof())
                {
                    if((*t==acc_no))
                    {
                        cout << name << "\t" << acc_no << "\t" << balance  << endl ;
                    }
                    myfile.read((char*)this ,  sizeof(*this)) ;
                }
            }
        }
        void delete_acc(int *t)
        {
            ifstream fin ;
            ofstream fout ;
            fin.open("datasheet.dat" , ios:: in | ios ::binary) ;
            if(!fin)
            {
                cout<<"file not found " ;
            }
            else
            {
                fout.open("tempfile.dat" , ios::out | ios::app |ios::binary) ;
                fin.read((char*)this , sizeof(*this));
                while(!fin.eof())
                {
                    if(*t != acc_no)
                    {
                        fout.write((char*)this , sizeof(*this)) ;
                    }
                    fin.read((char*)this , sizeof(*this));
                }
                fin.close();
                fout.close();
                remove("datasheet.dat");
                rename("tempfile.dat" , "datasheet.dat") ;
            }
        }
};


int main()
{
    bank b1 ;
    char num ;
    cout<< " Enter a no.  according to the service you want " ;


        system("cls") ;
        cout<<"\n\n\t\t\t\t======================\n";
	cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t\t======================\n";

		cout<<"\t\t\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t\t\t1. NEW ACCOUNT";
		cout<<"\n\t\t\t\t2. ALL ACCOUNT HOLDER LIST";
		//cout<<"\n\t\t\t\t3. UPDATE AMOUNT";
		cout<<"\n\t\t\t\t3. BALANCE ENQUIRY";
		cout<<"\n\t\t\t\t4. DELETE ACCOUNT";
		cout<<"\n\t\t\t\t5. EXIT";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-8): ";
		cin>>num ;
		switch(num)
		{
        case '1' :
            {
                system("cls") ;
                b1.read_data() ;
                break ;
            }
        case '2' :
            {
                system("cls") ;
                b1.show_data() ;
                break ;
            }
         /*case '3' :
            {
                break ;
            }*/
         case '3' :
            {
                system("cls") ;
                cout<<"Enter acc. no. " ;
                int n ;
                cin>>n ;
                b1.view_balance(&n) ;
                break ;
            }
         case '4' :
            {
                system("cls") ;
                cout<<"Enter acc. no. " ;
                int n ;
                cin>>n ;
                b1.delete_acc(&n) ;
                break ;
            }
         case '5' :
            {
                return 0 ;
                break ;
            }
         default :
            {
                cout<< " \a" ;
                cout<< "Enter valid input" ;
            }

		}
		return 0 ;

}
