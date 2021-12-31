// Pharmacy Management System in C++//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#define max 10
using namespace std;
//the header file

class medicineType	//base class
{
public:
    void take_order();//to  take_order
    void delete_order(); //to delete the order
    void modify(); //to modify the order
	void order_list(); //to display the order_list
	void daily_summary(); //to display daily_summary
	void exit();  //function to exit system
	medicineType();//constuctor
};

 medicineType::medicineType ()
{

}		//constructor for class CarType


struct node //construct node
{
	int reciept_number;
	string customerName;
	string date;
	int quantity[10];
	string type = {"OTC"};
	int x, menu2[10];
    double amount[10];
    string medicineName[10]={"Probiotics","Vitamin C(500mg)","Acid Free C(500mg)","Women'S Multivate","Marino Tablet","Maxi Cal Tablet",
	"Amino Zinc Tablet","Burnex","Fabuloss 5","Royal Propollen"};
	double Medicine[10] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};
	double total;

	node *prev;
	node *next;
	node *link; 

}*q, *temp;				//pointer declaration 


node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

int main()	// Main function
{

	system("COLOR 7D");		//Color to change background
	medicineType medicine;
	int menu;
	do
	{
		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tWelcome to Pharmacy Management System \n";
		cout<<"\t\t\t\t==================================================\n\n";
		cout<<"\t\t\t\t--------------------------------------------------\n";
		cout<<"\t\t\t\t||\t1. Take new Medicine order \t\t ||\n";
		cout<<"\t\t\t\t||\t2. Delete latest Medicine order\t\t ||\n";
		cout<<"\t\t\t\t||\t3. Modify Order List \t\t\t ||\n";
		cout<<"\t\t\t\t||\t4. Print the Reciept and Make Payment \t ||\n";
		cout<<"\t\t\t\t||\t5. Daily Summary of total Sale \t\t ||\n";
		cout<<"\t\t\t\t||\t6. Exit\t\t\t\t\t ||\n";
		cout<<"\t\t\t\t--------------------------------------------------\n";
		cout<<"\n\n\t\t\t\t\tEnter choice: ";

		cin>>menu;

		switch (menu)
		{
		case 1:
			{
				medicine.take_order();	//function add
				break;
			}	//end case 1
		
		
		case 2:
			{
				medicine.delete_order();	//function delete
				system("PAUSE");
				break;
			}	//end case 2
			
		case 3:
			{
				medicine.modify();	//function modify
				system("PAUSE");
				break;
			}	//end case 3

		case 4:
			{
				medicine.order_list();	//function order
				system("PAUSE");
				break;
			}	//end case 4
		case 5:
			{
				medicine.daily_summary();	//function daily_summary
				system("PAUSE");
				break;
			}	//end case 5
        case 6:
			{
				medicine.exit();	//function exit
				goto a;
				break;
			}	//end case 6

		
		default:
			{
				cout<<"\n\n\n\n\n\t\t\t\tYou enter invalid input\nre-enter the input\n"<<endl;
				break;
			}//end defeault
		}//end Switch
	}while(menu!=6);//end do
	a://goto
	cout<<"\t\t\t*************"<<endl;
	cout<<"\t\t\t||thank you||"<<endl;
	cout<<"\t\t\t*************"<<endl;
	system ("PAUSE");
	return 0;
}//end  main function


void medicineType::take_order()		//function to take_order
{
	system("cls");
	int i;
    int choice, quantity, price,None;

	cout <<"\n\n\n\n\n\t\t\t\t\t\tAdd Order Details\n";
	cout <<" \t\t\t\t\t_____________________________________ \n";
	cout <<" \t\t\t\t\t_____________________________________ \n\n";

	node *temp;
	temp=new node;

				cout <<"\n\n\t\t\t**************************************************************************\n";
				cout<<"\t\t\tDRUGS ID"<<"\tDRUGS TYPE"<<"   \t\tDRUGS NAME"<<"           DRUGS PRICE(RM)"<<endl;
				cout <<"\t\t\t**************************************************************************\n";
                cout<<"\t\t\t0001"<<"\t"<<"\tOTC"<<"\t\t"<<"    Probiotics"<<"			RM 2.00"<<endl;
                cout<<"\t\t\t0002"<<"\t"<<"\tOTC"<<"\t\t"<<"    Vitamin C(500mg)"<<"		RM 3.00"<<endl;
                cout<<"\t\t\t0003"<<"\t"<<"\tOTC"<<"\t\t"<<"    Acid Free C(500mg)"<<"		RM 1.00"<<endl;
                cout<<"\t\t\t0004"<<"\t"<<"\tOTC"<<"\t\t"<<"    Women'S Multivate"<<"		RM 4.00"<<endl;
                cout<<"\t\t\t0005"<<"\t"<<"\tOTC"<<"\t\t"<<"    Marino Tablet"<<"	 	RM 1.00"<<endl;
                cout<<"\t\t\t0006"<<"\t"<<"\tOTC"<<"\t\t"<<"    Maxi Cal Tablet"<<" 		RM 5.00"<<endl;
                cout<<"\t\t\t0007"<<"\t"<<"\tOTC"<<"\t\t"<<"    Amino Zinc Tablet"<<"		RM 7.00"<<endl;
                cout<<"\t\t\t0008"<<"\t"<<"\tOTC"<<"\t\t"<<"    Burnex"<<"			RM 4.00"<<endl;//1353fn
                cout<<"\t\t\t0009"<<"\t"<<"\tOTC"<<"\t\t"<<"    Fabuloss 5"<<"			RM 3.00"<<endl;
                cout<<"\t\t\t0010"<<"\t"<<"\tOTC"<<"\t\t"<<"    Royal Propollen"<<"		RM 5.00"<<endl;
                cout<<"\t\t\t "<<endl;
    
	temp = new node;
	cout << "\n\n\n\t\t\tType Order no: ";
    cin >> temp->reciept_number;
	cout<< "\t\t\tEnter Customer Name: ";
	cin>> temp->customerName;
	cout<<"\t\t\tEnter Date : ";
	cin>>temp->date;
	cout << "\t\t\tHow many Medicine would you like to order:"<< endl;
	cout<<"\t\t\t( Maximum is 10 order for each transaction ) \n";
	cout <<" \t\t\t  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "\t\t\tThe Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "\n\n\n\n\n\t\t\tPlease enter your selection : "<<endl;
		cin>> temp->menu2[i];
        cout<< "\t\t\tMedicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "\t\t\tHow many medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        system("cls");
        cout << "\n\n\n\n\n\n\n\t\t\t\t***************************************"<<endl;
        cout << "\t\t\t\t||The amount You need to pay is:"<< temp->amount[i]<<" RM||"<<endl;
        cout << "\t\t\t\t***************************************"<<endl;
        cout << "\n\n\t\t\t\t***************************************"<<endl;
        cout << "\t\t\t\t************||thank you||**************"<<endl;
        cout << "\t\t\t\t***************************************"<<endl;
        system("PAUSE");
                      
	}
	cout<<"\n\n\n\n\n\t\t\t==========================================================================="<<endl;
    cout << "\t\t\tOrder Taken Successfully"<<endl;
    cout<<"\t\t\t==========================================================================="<<endl;
    cout << "\t\t\tGo to Reciept Menu to Pay The Bill"<<endl;
    cout<<"\t\t\t==========================================================================="<<endl;
	system ("PAUSE");

    temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
	system("cls");
}
}//End function take_order


void medicineType::order_list()		//Function to display receipt
{
	int i, num, num2;	
	bool found;			//variable to search 
	system("cls");
	node *temp;

	temp=start_ptr;
	found = false;
	
	cout<<"\n\n\n\n\n\t\t\t\t Enter the Reciept Number To Print The Reciept\n";
	cin>>num2;
	cout<<"\n";
	cout<<"\t\t\t\t==========================================================================="<<endl;
	cout <<"\t\t\t\t\t\t\t\tHere is the Order list\n"; 
	cout<<"\t\t\t\t==========================================================================="<<endl;


	if(temp == NULL) //Invalid receipt code
	{
		cout << "\n\n\n\n\t\t\t\t\t\t\tThere is no Order to show\n\t\t\t\t\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)	//print the receipt
        {
		cout <<"\t\t\t\t\t\tReciept Number : "<<temp->reciept_number;
		cout <<"\n";
		cout<<"\t\t\t\t\t\tCustomer Name: "<<temp->customerName<<endl;
				
		cout<<"\t\t\t\t\t\tOrder Date : "<<temp->date<<endl;
				
		cout<<"\t\t\t_______________________________________________________________________________"<<endl;
			
		cout << "\t\t\t===============================================================================" << endl;
		cout << "\t\t\t|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
		cout << "\t\t\t=======++==================++================++===============++===============" << endl;
		for (i=0;i<temp->x;i++)
		{
			cout << "\t\t\t\t"<<temp->type;
			cout<<"\t        "<<temp->medicineName[temp->menu2[i]-1];
			cout<<" \t            "<<temp->quantity[i];
			cout<<"  \t        "<< temp->amount[i]<<"RM"<<endl;
			cout<<"\t\t\t_______________________________________________________________________________"<<endl;
		}
		
		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9];
		cout<<"\n\n\t\t\t\t\t\tTotal Bill is : "<<temp->total;
		cout<<"\n";
		cout << "\n\t\t\t\t\t\tType the exact amount You need to pay: ";
        cin >> num;

		cout <<"\n";
		cout <<"\n";
		cout<<"\t\t\t\t\t\tPayment Done\n\t\t\t\t\t\tThank You\n";
		cout <<"\n_______________________________________________________________________________\n";
		}


}
}	//End function order_list


void medicineType::delete_order()	//function to delete_order
{
	system("cls");
	int i, num, count;
    cout<<"\n\n\n\n\t\t\t\tEnter the data you want to delete \n";
    cin>>num;
    node *q;
	node *temp;
	bool found;

	if(start_ptr == NULL)
		cerr<<"\t\t\t\t\t\tCan not delete from an empty list.\n";
	else
	{
		if(start_ptr->reciept_number == num)
		{
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if(start_ptr == NULL)
			last = NULL;
			delete q;
			cout<<"\t\t\t\t\t\tThe Reciept is Deleted Successfully"<<endl;
		}
		else
		{
			found = false;
			temp = start_ptr;
			q = start_ptr->next;
	
		while((!found) && (q != NULL))
		{
  			if(q->reciept_number != num) 
			{
				temp = q;
				q = q-> next;
			}
			else
				found = true;
		}

			if(found)
			{
				temp->next = q->next;
				count--;

				if(last == q) 
				last = temp;
				delete q;
				cout<<"\t\t\t\t\t\tThe Reciept is Deleted Successfully"<<endl;
			}
			else
				cout<<"\t\t\t\t\t\tItem to be deleted is not in the list."<<endl;
			}
		} 
}	//End function delete_order



void medicineType::modify()		//function to modify order
{
 system("cls");
 int i, ch, sid;
 bool found;
 found = false;
 temp = start_ptr;
 cout<<"\n\n\n\n\t\t\t\t\t\tEnter Receipt Number To Modify: ";
 cin>>sid;
 if (temp==NULL && sid==0)
 {
    cout<<"\n\n\t\t\t\t\t\tNO RECORD TO MODIFY..!"<<endl;
 }

 else
 {
 	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==sid)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
    if (found)
    {
	cout << "\t\t\t\t\t\tChange  Order Number: ";
    cin >> temp->reciept_number;
	cout<< "\t\t\t\t\t\tChange Customer Name: ";
	cin>> temp->customerName;
	cout<<"\t\t\t\t\t\tChange Date : ";
	cin>>temp->date;
	cout << "\t\t\t\t\t\tHow many New Medicine would you like to Change:"<< endl;
	cout<<"\t\t\t\t\t\t( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "\t\t\t\t\t\tThe Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "\t\t\t\t\t\tPlease enter your selection to Change: "<<endl;
		cin>> temp->menu2[i];
        cout<< "\t\t\t\t\t\tChange Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "\t\t\t\t\t\tHow many New medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "\t\t\t\t\t\tThe amount You need to pay After Modify  is: " << temp->amount[i]<<" RM"<<endl;
        system("PAUSE");
	}
	temp = temp->next;
	system("cls");
	
	}

 cout<<"\t\t\t\t\t\tRECORD MODIFIED....!"<<endl;
 }
 else 
 {
 	if(temp != NULL && temp->reciept_number != sid)
 	{
 	cout<<"\t\t\t\t\t\tInvalid Reciept Number...!"<<endl;
    }
 }
}
}
}		//End modify function



void medicineType::daily_summary()		//Function to display Daily Summary
{
	int i,num;
	system("cls");
	node *temp ;

	temp=start_ptr;


	if(temp == NULL) //Invalid receipt code
	{
		cout << "\n\n\n\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout<<"\n\n";
		cout<<"\t\t==========================================================================="<<endl;
		cout <<"\t\t\               Here is the Daily Summary of All Orders \n"; //print all receipt
		cout<<"\t\t==========================================================================="<<endl;

		while(temp!=NULL)
		{
		
				cout <<"\t\t\t\t\t\tReciept Number : "<<temp->reciept_number;
				cout <<"\n";
				cout<<"\t\t\t\t\t\tCustomer Name: "<<temp->customerName<<endl;
				
				cout<<"\t\t\t\t\t\tOrder Date : "<<temp->date<<endl;
				
				cout<<"\t\t_________________________________________________________________"<<endl;
			
				cout << "\t\t===========================================================" << endl;
				cout << "\t\t|Medicine Type |Medicine Name  |Quantity     |Total Price |" << endl;
				cout << "\t\t=====++==============++=============++===========++========" << endl;
			for (i=0;i<temp->x;i++)
			{
				cout  <<"\t\t"<<temp->type;
				cout<<"\t\t"<<temp->medicineName[temp->menu2[i]-1];
				cout<<"\t"<<temp->quantity[i];
				cout<<"\t\t"<<temp->amount[i]<<" RM"<<endl;
				cout<<"\t\t_________________________________________________________________"<<endl;
			}
			
			temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
			+temp->amount[8]+temp->amount[9];
			cout<<"\n\t\tTotal Bill is : "<<temp->total<<"Rs";
		
			cout <<"\n";
			cout <<"\n";
			cout <<"\n______________________________________________________________________________________________________________________\n";
				
			temp=temp->next;
		}
	}
}		//End daily summary
void medicineType::exit() //Function to exit
{
	cout<<"\n\t\t\t\t\t\tYou choose to exit.\n"<<endl;
}	//end function exit


////////////////////////////THE END OF PROGRAM//////////////////////////////////////////


