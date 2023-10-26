/*
	Khushminder Kaur
	100437630

	i used comments while writing but i removed them after writing whole code
*/


#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main() {
	double fixed_mcost = 11.50, fixed_pcost = 13.75, fixed_hcost = 10.99;
	int quantity_m = 0, quantity_p = 0, quantity_h = 0;
	char requirement;
	int quantity;
	int avai_m = 20, avai_p = 20, avai_h = 20;


	double total_before_tax = 0, total_after_tax = 0;

	cout << endl << "Welcome to Tom's Nursery Shop" << endl;
invalid:

	cout << "M or m for Monstera" << endl;;
	cout << "P or p for Philodendron" << endl;
	cout << "H or h for Hoya" << endl;
	cout << "A or a for payment" << endl;
	cout << endl << "Enter your requirement : ";
	cin >> requirement;

	if (requirement == 'M' || requirement == 'm' || requirement == 'P' || requirement == 'p' || requirement == 'H' || requirement == 'h')
	{

		cout << endl << "Enter how quantity pots would you like : ";
		cin >> quantity;

		if (quantity < 0 || quantity>20)
		{
			cout << "Sorry, we do not have this amount" << endl;
			goto invalid;
		}
		else
		{
			switch (requirement)
			{
			case 'M':
			case 'm':
				if (quantity <= avai_m)
				{
					quantity_m = quantity_m + quantity;
					quantity = 0;
					avai_m = avai_m - quantity_m;
				}
				else
				{
					cout << "Sorry Less pots available" << endl;
					goto invalid;
				}
				quantity = 0;
				break;

			case 'P':
			case 'p':
				if (quantity <= avai_p)
				{
					quantity_p = quantity_p + quantity;
					quantity = 0;
					avai_p = avai_p - quantity_p;
				}
				else
				{
					cout << "Sorry Less pots available" << endl;
					goto invalid;
				}
				quantity = 0;
				break;

			case 'H':
			case 'h':
				if (quantity <= avai_h)
				{
					quantity_h = quantity_h + quantity;
					quantity = 0;
					avai_h = avai_h - quantity_h;
				}
				else
				{
					cout << "Sorry Less pots available" << endl;
					goto invalid;
				}
				quantity = 0;
				break;

			}
			goto invalid;
		}
	}
	else if (requirement == 'A' || requirement == 'a')
	{
		char loyal;
		char buyer[50];
		int points;
		cout << "Are you a loyal buyer Y/N? ";
		cin >> loyal;
		if (loyal == 'Y' || loyal == 'y')
		{
			cout << "Please enter your name : " << endl;
			cin >> buyer;
		}
		cout << "Units/Description/cost" << endl;
		cout << fixed << showpoint;
		if (quantity_m > 0)
		{
			cout << quantity_m << " Monstera pots cost $" << setprecision(3) << fixed_mcost * quantity_m << endl;
		}
		if (quantity_p > 0)
		{
			cout << quantity_p << " Philodendron pots cost $" << setprecision(3) << fixed_pcost * quantity_p << endl;
		}
		if (quantity_h > 0)
		{
			cout << quantity_h << " Hoya pots cost $" << setprecision(3) << fixed_hcost * quantity_h << endl;
		}

		total_before_tax = (fixed_mcost * quantity_m + fixed_pcost * quantity_p + fixed_hcost * quantity_h);
		total_after_tax = total_before_tax + (total_before_tax * 0.12);

		cout << "Total amount before tax is $" << total_before_tax << endl;
		cout << "Total amount after tax is $" << total_after_tax << endl;

		points = total_before_tax / 0.75;
		if (loyal == 'Y' || loyal == 'y')
		{
			cout << buyer << ", you earned " << points << " points on the current purchase" << endl;
			cout << "Thank you " << buyer << " ! Please come again!" << endl;
		}
		else
		{
			cout << "Thank you!, Please come again!" << endl;
		}

		cout << endl << "\t\tRECIEPT" << endl;
		if (loyal == 'Y' || loyal == 'y')
		{
			cout << left << setw(50) << "Buyer Name : " << setw(50) << buyer << endl;
		}
		cout << left << setw(50) << "Monstera : " << setw(50) << fixed_mcost * quantity_m << endl;
		cout << left << setw(50) << "Philondendron : " << setw(50) << fixed_pcost * quantity_p << endl;
		cout << left << setw(50) << "Hoya Name : " << setw(50) << fixed_hcost * quantity_h << endl;
		cout << left << setw(50) << "Cost Before Tax : " << setw(50) << total_before_tax << endl;
		cout << left << setw(50) << "Cost After 12% Tax : " << setw(50) << total_after_tax << endl;

		if (loyal == 'Y' || loyal == 'y')
		{
			cout << left << setw(50) << "Points : " << setw(50) << points << endl;
		}




	}
	else
	{
		cout << "Enter valid input" << endl;
		goto invalid;
	}

	return 0;
}