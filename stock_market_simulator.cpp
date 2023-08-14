/*                        
                        ***** CPP PROJECT STOCK MARKET SIMULATION *****
*/
#include <iostream>
#include <fstream>
using namespace std;

class demat_account
{
public:
	float main_balance;
	float balance = 0;
	float dep;
	int ac_num;
	char name[20];

	void create_demat();
	float deposite(float);
};

void demat_account::create_demat()
{
	fstream file;
	file.open("file.txt", ios::app);
	cout << "\nEnter your name: ";
	cin >> name;
	file << name << " ";
	cout << "\nEnter your account number : ";
	cin >> ac_num;
	file << ac_num << " ";
	balance = 0;
	cout << "\nYour demat account has been successfully created!";
	file.close();
}

float demat_account::deposite(float n)
{
	balance = balance + n;
	cout << "\nYour amount has been successfully added in your demat account.";
	return balance;
}

class display : public demat_account
{
public:
	void display_balance(float balance)
	{
		cout << "\nCurrent balance: " << balance;
	}

	void display_details()
	{
		cout << "\nAccount holder : " << name;
		cout << "\nAccount number : " << ac_num;
		cout << "\nCurrent balance: " << balance;
	}

	void summary()
	{
		cout << "********SUMMARY OF THE DAY********" << endl
			 << endl;
		cout << "\nAccount holder : " << name << endl;
		cout << "\nAccount number : " << ac_num << endl;
		cout << "Balance at the starting of the day : " << main_balance << endl;
		cout << "Balance at the end of the day : " << balance << endl;
		cout << endl;
		if (main_balance - balance >= 0)
		{
			cout << "You have loss of : " << main_balance - balance << " $" << endl;
		}
		else if (main_balance - balance < 0)
		{

			cout << "Your profit gain is : " << balance - main_balance << " $" << endl;
		}
	}
};

int main()
{
	int mX = 0;
	int mY = 0;
	int mZ = 0;
	int mQ = 0; // new
	int fX = 25;
	int fY = 50;
	int fZ = 75;
	int fQ = 150; // new
	bool bValid(true);
	display a;
	int choice = 1;
	cout << "------------------------------Stock Market Simulator---------------------------------\n\n";
	cout << "--> demat account creation <--\n\n";

	do
	{
		cout << "\n\n1.enter 1 to create demat account.\n2.enter 2 to show details of your demat account.\n3.enter 3 to deposit amount.";
		cout << "\n4.enter 4 to show current balance.\n5.enter 0 to exit from account creation.";
		cout << "\nenter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			a.create_demat();
			break;
		case 2:
			a.display_details();
			break;
		case 3:
			float d;
			cout << "\nenter amount for deposit: ";
			cin >> d;
			a.deposite(d);
			a.display_balance(a.balance);
			break;
		case 4:
			a.display_balance(a.balance);
			break;
		}

	} while (choice != 0);
	cout << " \n\n--> stocks management <-- ";

	do
	{

		cout << "\n\nTotal amount in demat account: " << a.balance << "$" << endl;
		cout << "\n   Stock name"
			 << "            Price "
			 << "         amount" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "   Apple         (a)  |   " << fX << "         |    " << mX << "" << endl;
		cout << "   Reliance      (r)  |   " << fY << "         |    " << mY << "" << endl;
		cout << "   TATA          (t)  |   " << fZ << "         |    " << mZ << "" << endl;
		cout << "   Microsoft     (m)  |   " << fQ << "        |    " << mQ << "" << endl; // new
		cout << "---------------------------------------------------" << endl;
		cout << "\nBuy (b)\nSell (s)\nEnd Day (e) \nExit (E)\n\nSelect: " << endl;

		char bse_select;
		cin >> bse_select;

		if (bse_select == 'b')
		{

			do
			{

				bValid = true;

				char buy_select;
				int buy_amount;

				cout << "\nBuy (a/r/t/m): ";
				cin >> buy_select;

				if (buy_select == 'a')
				{

					cout << "\nBuy Shares: ";
					cin >> buy_amount;

					if (buy_amount * fX > a.balance)
						cout << "Insufficiant Funds.";

					else
					{
						a.main_balance = a.balance;
						mX = buy_amount + mX;
						a.balance = a.balance - (fX * buy_amount);
					}
				}

				else if (buy_select == 'r')
				{
					cout << "\nBuy Shares: ";
					cin >> buy_amount;

					if (buy_amount * fY > a.balance)
						cout << "Insufficiant Funds.";

					else
					{
						a.main_balance = a.balance;
						mY = buy_amount + mY;
						a.balance = a.balance - (fY * buy_amount);
					}
				}

				else if (buy_select == 't')
				{
					cout << "\nBuy Shares: ";
					cin >> buy_amount;

					if (buy_amount * fZ > a.balance)
						cout << "Insufficiant Funds.";

					else
					{
						a.main_balance = a.balance;
						mZ = buy_amount + mZ;
						a.balance = a.balance - (fZ * buy_amount);
					}
				}

				else if (buy_select == 'm')
				{ // copy pasted this section from others
					cout << "\nBuy Shares: ";
					cin >> buy_amount;

					if (buy_amount * fQ > a.balance)
						cout << "Insufficiant Funds.";

					else
					{
						a.main_balance = a.balance;
						mQ = buy_amount + mQ;

						a.balance = a.balance - (fQ * buy_amount);
					}
				}

				else
				{
					cout << "Invalid Selection.";
					bValid = false;
				}
			} while (!bValid);
		}

		else if (bse_select == 's')
		{

			do
			{

				bValid = true;

				int sell_amount;
				char sell_select;

				cout << "\nsell (a/r/t/m): ";
				cin >> sell_select;

				if (sell_select == 'a')
				{
					cout << "\nSell Shares: ";
					cin >> sell_amount;

					if (mX - sell_amount < 0)
						cout << "\nYou can't sell what you don't own.\n";
					else
					{
						a.main_balance = a.balance;
						mX = mX - sell_amount;
						a.balance = a.balance + (fX * sell_amount);
					}
				}

				else if (sell_select == 'r')
				{
					cout << "\nSell Shares: ";
					cin >> sell_amount;

					if (mY - sell_amount < 0)
						cout << "\nYou can't sell what you don't own.\n";
					else
					{
						a.main_balance = a.balance;
						mY = mY - sell_amount;
						a.balance = a.balance + (fY * sell_amount);
					}
				}

				else if (sell_select = 't')
				{
					cout << "\nSell Shares: ";
					cin >> sell_amount;

					if (mZ - sell_amount < 0)
						cout << "\nYou can't sell what you don't own.\n";
					else
					{
						a.main_balance = a.balance;
						mZ = mZ - sell_amount;
						a.balance = a.balance + (fZ * sell_amount);
					}
				}

				else if (sell_select == 'm')
				{
					cout << "\nSell Shares: ";
					cin >> sell_amount;

					if (mQ - sell_amount < 0)
						cout << "\nYou can't sell what you don't own.\n";
					else
					{
						a.main_balance = a.balance;
						mQ = mQ - sell_amount;
						a.balance = a.balance + (fQ * sell_amount);
					}
				}

				else
				{
					cout << "Invalid Selection.";
					bValid = false;
				}
			} while (!bValid);
		}

		else if (bse_select == 'e')
		{
			a.summary();
			cout << "\n\n\n\n   A New Day has begun!";

			if (fX >= 25)
			{

				int random;
				random = rand() % 20;

				fX = fX - random;
			}

			if (fX <= 25)
			{

				int random;
				random = rand() % 20;

				fX = fX + random;
			}

			if (fY >= 50)
			{

				int random;
				random = rand() % 50;

				fY = fY - random;
			}

			if (fY <= 50)
			{

				int random;
				random = rand() % 30;

				fY = fY + random;
			}

			if (fZ >= 75)
			{

				int random;
				random = rand() % 50;

				fZ = fZ - random;
			}

			if (fZ <= 75)
			{

				int random;
				random = rand() % 110;

				fZ = fZ + random;
			}

			if (fQ >= 150)
			{ // again, copy pasted from others

				int random;
				random = rand() % 224;

				fQ = fQ - random;
			}

			if (fQ <= 150)
			{

				int random;
				random = rand() % 350;

				fQ = fQ + random;
			}
		}
		else if (bse_select == 'E')
		{
			cout << "******** THANK YOU ********";
			break;
		}

		else
			cout << "Invalid Selection.";

	} while (a.balance < 25000);
	return 0;
}
