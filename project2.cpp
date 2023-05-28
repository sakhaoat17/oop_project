
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class mobile	{
private:
	char *brand,*model,*year;
	float *price;
	int *stock;
public:
	mobile()	{
	brand= new char[20];
	model=new char[20];
	year=new char[20];
	price= new float;
	stock=new int;
	}
	void enter();
	void edit();
	void show();
	int searchdata(char[],char[]);
	void buy();

};

void mobile::enter()	{
	cin.ignore();
	cout<<"\nEnter brand Name: ";
	cin.getline(brand,20);
	cout<<"Enter model Name: ";
	cin.getline(model,20);
		cout<<"Year Release: ";
	 cin.getline(year,20);
	cout<<"Enter Price: ";
	cin>>*price;
	cout<<"Enter Stock Position: ";
	 cin>>*stock;

}

void mobile::edit()	{

	cout<<"\nEnter brand Name: ";
	cin.getline(brand,20);
	cout<<"Enter model Name: ";
	cin.getline(model,20);
	cout<<"Enter Price: ";
	cin>>*price;
	cout<<"Enter Stock Position: ";
	 cin>>*stock;

}

void mobile::show()	{
	cout<<"\nbrand Name: "<<brand;
	cout<<"\nmodel Name: "<<model;
	cout<<"\nPrice: "<<*price;
	cout<<"\nStock Position: "<<*stock;

}

int mobile::searchdata(char mbuy[20],char bbuy[20] )	{
	if(strcmp(mbuy,model)==0 && strcmp(bbuy,brand)==0)
		return 1;
	else return 0;

}

void mobile::buy()	{

	int count;
	cout<<"\nEnter Number Of  mobile phone to buy: ";
	cin>>count;
	if(count<=*stock)	{
		*stock=*stock-count;
		cout<<"\n mobile phone Bought Sucessfully";
		cout<<"\nAmount: Tk. "<<(*price)*count;
	}
	else
		cout<<"\nRequired device not in Stock";
}

int main()	{
	mobile *B[20];
	int i=0,r,t,c;
	char modelbuy[20],brandbuy[20];
	while(1)	{
		cout<<"\n\n\t\tMENU"
		<<"\n1. Entry of New Mobile Phone"
		<<"\n2. Buy Mobile Phone"
		<<"\n3. Search For Mobile Phone"
		<<"\n4. Edit Details Of Mobile Phone"
		<<"\n5. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>c;

		switch(c)	{
			case 1:	B[i] = new mobile;
				B[i]->enter();
				i++;	break;

			case 2: cin.ignore();
				cout<<"\nEnter model Of mobile: "; cin.getline(modelbuy,20);
				cout<<"Enter brand Of mobile: ";  cin.getline(brandbuy,20);
				for(t=0;t<i;t++)	{
					if(B[t]->searchdata(modelbuy,brandbuy))	{
						B[t]->buy();
						break;
					}
				}
				if(t==1)
				cout<<"\nThis Mobile Phone is Not in Stock";

				break;
			case 3: cin.ignore();
				cout<<"\nEnter model Of mobile: "; cin.getline(modelbuy,20);
				cout<<"Enter brand Of mobile: ";  cin.getline(brandbuy,20);

				for(t=0;t<i;t++)	{
					if(B[t]->searchdata(modelbuy,brandbuy))	{
						cout<<"\Device Found Successfully";
						B[t]->show();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Device is Not in Stock";
				break;

			case 4: cin.ignore();
				cout<<"\nEnter model Of mobile: "; cin.getline(modelbuy,20);
				cout<<"Enter brand Of mobile: ";  cin.getline(brandbuy,20);

				for(t=0;t<i;t++)	{
					if(B[t]->searchdata(modelbuy,brandbuy))	{
						cout<<"\nDevice Found Successfully";
						B[t]->edit();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Device is Not in Stock";
				break;

			case 5: exit(0);
			default: cout<<"\nInvalid Choice Entered";

		}
	}
}





