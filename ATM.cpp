#include<iostream>
#include<string>                             
using namespace std;                            
class atm
{
	private:
	long int Account_no; //acc_no = account number
    string Name;
	int pin;
	double Balance;
	string Mobile_no;

	public:
		// using i at the end of variable for clear understanding as input .

    void setdata(long int acc_no_s,string name_s,int pin_s,double balance_s,string mob_no_s)
	{
      Account_no=acc_no_s;
	  Name=name_s;
	  pin=pin_s;
	  Balance=balance_s;
	  Mobile_no=mob_no_s;
	}

//now using get_functions to receive user details.
long int get_account_no()
{
	return Account_no;
}
string get_name()
{
	return Name;
}
int get_pin()
{
	return pin;
}
double get_balance()
{
	return Balance;
}
string get_mobile_no()
{
	return Mobile_no;
}
   



void set_mobile(string mob_prev,string mob_new)
{
	if(mob_prev==Mobile_no) 
	{
		Mobile_no=mob_new;  // mobile no will update after execution of case 5;
		
		cout<<mob_new<<" mobile number updated succesfully.";
	}
	else
	{
		cout<<" Entered mobile number is incorrect.";
	}
}
void cash_withdraw(int amount)
{
	if(amount>0 && amount<Balance)
	{
        Balance=Balance-amount;
		cout<<" Please collect your cash ."<<endl;
		cout<<" Available Balance :"<<Balance<<endl;
	}
	else
	{
		cout<<" Invalid input or insufficient balance.";
	}
}
void cash_credite(int amount)
{
    	Balance=Balance+amount;

		cout<<" Please collect your cash ."<<endl;
		cout<<" Available Balance :"<<Balance<<endl;
}
};

int main()
{
	int choice=0;
	int enterpin;
	long int account_no;

	system("cls");
	atm user1;      //object creation
	user1.setdata(123456789,"sourabh dhangar",1111,5000,"6263863343"); //data insertion
	atm user2;
	user2.setdata(987654321,"aadrsh thakur",2222,1000,"7489553373");

	do
	{
		system("cls");
		cout<<"******* Welcom to ATM *******"<<endl;
		cout<<" Enter your bank account no : "<<endl;
		cin>>account_no;
		cout<<" Enter pin : "<<endl;
		cin>>enterpin;


	if((account_no==user1.get_account_no()) && (enterpin==user1.get_pin()))
	{
		do{
			int amount=0;
			string oldmobileno;
			string newmboileno;

			system("cls");
			 // user Interface
                cout << endl << "**** Welcome to ATM *****" << endl;
                cout << endl << "Select Options ";
                cout << endl << "1. Check Balance";
                cout << endl << "2. Cash withdraw";
                cout << endl << "3. Show User Details";
                cout << endl << "4. Update Mobile no.";
				cout << endl << "5. void cash_credite";
                cout << endl << "6. Exit" << endl;
				cin>>choice;

				switch(choice)
				{
					case 1:
					cout<<" your bank balance is :"<<user1.get_balance()<<endl;
					break;

					case 2:
					cout<<" Enter amount :"<<endl;
					cin>>amount;
					user1.cash_withdraw(amount);

					case 3:
					cout<<" User details are :"<<endl;
					cout<<" Account no : "<<user1.get_account_no();
					cout<<" Available Balance : "<<user1.get_balance();
					cout<<" Mobile no : "<<user1.get_mobile_no();
					break;

					case 4:
					cout<<" Update Mobile no"<<endl;
					cout<<" Enter old mobile no :"<<endl;
					cin>>oldmobileno;
					cout<<" Enter new mobile no :"<<endl;
					cin>>newmboileno;
					user1.set_mobile(oldmobileno,newmboileno);
					break;
					
					case 5:
					cout<<" Enter amount :"<<endl;
					cin>>amount;
					user1.cash_credite(amount);
					cout<<endl<<"your money is credited succesfully "<<endl;
					break;

					case 6:
					exit(0);
					default:
					cout<<" Enter valid data .";
				}
	    }while(1);
	}
    else
	{
		cout<<"User details are invalid !!!";
	}
	}while(1);
return 0;
}
