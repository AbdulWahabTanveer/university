#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string p, l, p1, l1, Adress_of_branch, add;
string drug, characteristic, quantity, price, d , drug1 , characteristic1 , quantity1 ;
string u_drug, u_characteristic, u_quantity, u_price;
int  a, choice, choice1 ,choice2 ,  f = 0;

int store_quantity, record_quantity, n, sale, sq ;
void replace()
{
	cout << "Enter the New ID : ";
	getline(cin, l);
	cout << "Enter the New Password : ";
	getline(cin, p);
	fstream data;
	data.open("id.txt", ios::out);
	data << l << "\n\n" << p << endl;
	data.close();
}
void login()
{
	fstream data;
	data.open("id.txt", ios::in);
	data >> l >> p;
a:
	cout << "Enterthe Login Id : ";
	getline(cin, l1);
	cout << "Enterthe Password : ";
	getline(cin, p1);
	if (l1 == l && p1 == p)
	{
		b:
		cout << "\t  _________________________________" << endl;
		cout << "\t |                                                                                                 |" << endl;
		cout << "\t |         ***************************         |" << endl;
		cout << "\t |         ***************************         |" << endl;
		cout << "\t |         ***************************         |" << endl;
		cout << "\t |     ***********    WELCOME    ***********      |" << endl;
		cout <<"\t |         ***************************         |" << endl;
		cout << "\t |         ***************************         |" << endl;
		cout << "\t |         ***************************         |" << endl;
		cout<<"\t |         *******|    View Drug record : Press 1         | ******         | "<< endl;
		cout << "\t |         *******|    Enter the record : Press 2         |*******         |"<< endl;
		cout << "\t |         *******|    View Store record : Press 3        |*******         |" << endl;
		cout << "\t |         *******|  View Drug supplier record : Press 4  |*******         |" << endl;
		cout << "\t |         *******|    update record : Press 5            |*******         |" << endl;
		cout << "\t |         *******|    Change Password : Press 6          |*******         |" << endl;
		cout << "\t |_________________________________|" << endl;
		cout << "\n\n" << endl;
		cout << "\t\t____________   Enter the choice   ____________" << endl;
		 cin >> choice; 
		 cin.ignore();
		 cout << "__|" << endl;
		 if (choice == 1)
		 {
			 fstream record;
			 record.open("record.txt", ios::in);
			 record >> drug >> characteristic >> quantity >> price;
			 while(!record.eof())
			 { 
				 cout<< drug << "\t\t" << characteristic << "\t\t" << quantity << "\t\t" << price << endl;
				 record >> drug >> characteristic >> quantity >> price;
			 }
			 record.close();
			 goto b;



		}		 
		 else if (choice == 2)
		 {
			 c:
			 cout << "\t\t _________________" << endl;
			 cout << "\t\t|              Which record you enter               |" << endl;
			 cout << "\t\t|              * Enter Drug record Press 1          |" << endl;
			 cout << "\t\t|              * Enter Store record Press 2         |" << endl;
			 cout << "\t\t|              * Enter Drug Supplier record Press 3 |" << endl;
			 cout << "\t\t|_________________|" << endl;
			 cin >> choice1;
			 if (choice1 == 1)
			 {
				 fstream record;
				 record.open("record.txt", ios::app);
				 
				 cout << "How many Drugs you can Enter :";
				 cin >> record_quantity;

				 for (int i = 1; i <= record_quantity; i++)
				 {
					 cin.ignore(1);
					 cout << "Enter the Drug Name :";
					 getline(cin, drug);
					 cout << "Enter the Drug characteristic :";
					 getline(cin, characteristic);
					 cout << "Enter the Drug quantity :";
					 getline(cin, quantity);
					 cout << "Enter the Drug price :";
					 getline(cin, price);

					 record << drug << "\t\t" << characteristic << "\t\t" << quantity << "\t\t" << price << endl;
				 }
				 record.close();
				 goto b;
			 }
			 else if (choice1 == 2)
			 {

				 cout << "\t\t___________________" << endl;
				 cout << " \t\t|  How many Stores you Enter|" << endl;
				 cout << "\t\t|___________________|" << endl;
				 cin >> store_quantity;

				 fstream store;
				 store.open("store.txt", ios::app);

				 cout << "How many Drugs you can Enter :";
				 cin >> record_quantity;

				 for (int i = 1; i <= record_quantity; i++)
				 {
					 cin.ignore(1);
					 cout << "Enter Adress of branch : ";
					 getline(cin, Adress_of_branch);
					 cout << "Enter the sale : ";
					 cin >> sale;
					 store << "\t\t" << Adress_of_branch << "\t\t" << sale << endl;
				 }
				 store.close();
				 
	 			goto b;
			 }
			 else if(choice1==3)
			 {
			 	fstream supplier;
				 supplier.open("supplier.txt", ios::app);
				 
				 cout << "How many supplier records you can Enter :";
				 cin >> record_quantity;
                   
				 for (int i = 1; i <= record_quantity; i++)
				 {
					 cin.ignore(1);
					 cout << "Enter the Drug supplier Name :";
					 getline(cin, drug1);
					 cout << "Enter the Drug supplier companey :";
					 getline(cin, characteristic1);
					 cout << "Enter the Drug supplier cell number :";
					 getline(cin, quantity1);
					 
					 supplier << drug1 << "\t\t" << characteristic1 << "\t\t" << quantity1 << endl;
			     }
			     supplier.close();
			     goto b;
			 }
			 else
			 {
				 cout << "Invaild input " << endl;
				 goto c;
			 }
		 }
		else if (choice == 2)
		 {
			 
			
			 fstream store;
			 store.open("pharmacy multiple stores.txt", ios::app);


			 cout << "\t\t ___________________" << endl;
			 cout << "\t\t |                                                    |" << endl;
			 cout << " \t\t|          How many Store you entered                 |" << endl;
			 cout << "\t\t|___________________|" << endl;
			 cin >> store_quantity;
			 if (!store)
			 {
				 cout << "System Error" << endl;
			 }
			 for(int i=0;i<= store_quantity;i++)
			 {
				
				/// store <<"Quantity of Stores :"<< store_quantity << endl;
				 	 cin.ignore(1);
					 cout << "Enter Adress of branch : ";
					 getline(cin, Adress_of_branch);
					 cout << "Enter the sale : ";
					 cin >> sale;
					 store << "\t\t" << Adress_of_branch <<"\t\t" << sale<< endl;
				 
				 store.close();
			 }
			 goto b;
		 }
		 else if (choice == 3)
		 {
		 	fstream store;
				 store.open("store.txt", ios::in);

		        store>> Adress_of_branch >> sale ;
				 while(!store.eof())
				 {
				    cout<<Adress_of_branch <<"\t\t"<< sale<<endl;
				     store>> Adress_of_branch >> sale ;
				 }
				 store.close();
		 goto b;

			 
		

		 }
		 else if (choice == 4)
		 {
             	fstream supplier;
				 supplier.open("supplier.txt", ios::in);

		        supplier >> drug1 >> characteristic1 >> quantity1 ;

				 while(!supplier.eof())
				 {
				    cout<< drug <<"\t"<< characteristic <<"\t"<<quantity <<endl;
;
				     	supplier >> drug >> characteristic >> quantity ;

				 }
				 supplier.close();
		 goto b;

		 }
		 else if (choice == 5)
		 {
		 	
		 	cout << "\t\t  __________________" << endl;
			 cout << "\t\t|               Which record you update              |" << endl;
			 cout << "\t\t|              * update Drug record Press 1          |" << endl;
			 cout << "\t\t|              * update Store record Press 2         |" << endl;
			 cout << "\t\t|              * update Drug Supplier record Press 3 |" << endl;
			 cout << "\t\t|__________________|" << endl;
			 cin >> choice2;
			 if(choice2==1)
			 {
			 	string temp;	
			 	cin.ignore();
	            cout<< "Enter Drug Name For  Update : ";
            	getline(cin,temp);
        		ifstream record("record.txt",ios::in);
	        	if(!record)
		            {
			            cout<<"failed";
		            }
		        record >>drug >> characteristic>>quantity >> price ;
	            ofstream fout("New2.txt", ios::app);
                 while(!record.eof())
	               {
	                	if (temp == drug)
                    		{
			
	                            int update;

			                    cout<<" 1 Enter New Drug NAME "<<endl;
		                        cout<<" 2 Enter New Characteristic of Drug "<<endl;
			                    cout<<" 3 Enter New Quantity "<<endl;
			                    cout<<" 4 Enter New Price  "<<endl;
			
		                    	cin>>update;
			
			                if (update==1)
			                  {
				                cin.ignore(1);
				cout<<"Enter New NAME : ";
				getline(cin,u_drug);
				fout<< u_drug << "\t\t" << characteristic << "\t\t" << quantity << "\t\t" << price << endl;
				//break;
			}
			else if (update==2)
			{cin.ignore(1);
				cout<<"Enter New Characteristic : "<<endl;
				getline(cin, u_characteristic);
				fout<< drug << "\t\t" << u_characteristic << "\t\t" << quantity << "\t\t" << price << endl;
			}
			else if (update==3) 
			{cin.ignore(1);
				cout<<" Enter New Quantity : "<<endl;
				getline(cin,u_quantity);
				fout<< drug << "\t\t" << characteristic << "\t\t" << u_quantity << "\t\t" << price << endl;
			}
			else if (update==4)
			{cin.ignore(1);
				cout<<"Enter New Price : "<<endl;
				getline(cin,u_price);
				fout<< drug << "\t\t" << characteristic << "\t\t" << quantity << "\t\t" << u_price << endl;
			}	
				
		}
			else 
			{
				fout<< drug << "\t\t" << characteristic << "\t\t" << quantity << "\t\t" << price << endl;
		    }
			record >>drug >> characteristic>>quantity >> price ;				
	}
	cout<<"Data Update succesfull "<<endl;
	
	record.close();
	fout.close();
   remove("record.txt");
    rename("New2.txt", "record.txt");

		 goto b;	
	}	 	
		 	
else if(choice2==2)
            {
            	cin.ignore();
            			 	
		 		string temp;	
	cout<< "Enter Branch Name for update : ";
	getline(cin,temp);
		ifstream store("store.txt",ios::in);
		if(!store)
		{
			cout<<"failed";
		}
		store >>Adress_of_branch >> sale ;	
	ofstream fout("New2.txt", ios::app);
     while(!store.eof())
	  {
		if (temp == Adress_of_branch)
		{
			
	       int update;

			cout<<" 1 Enter New Adress"<<endl;
			cout<<" 2 Enter New Sales Rate "<<endl;
			
			cin>>update;
			
			if (update==1)
			{
				cin.ignore(1);
				cout<<"Enter NAME Adress : ";
				getline(cin,u_drug);
				fout<< u_drug << "\t\t" << sale << endl;
				
			}
			else if (update==2)
			{cin.ignore(1);
				cout<<" Enter New Sales Rate : "<<endl;
				getline(cin, u_characteristic);
				fout<< Adress_of_branch << "\t\t" << u_characteristic <<  endl;
			}
		}
			else 
			{
				fout<< Adress_of_branch  << "\t\t" <<sale << endl;
		    }
			store >>Adress_of_branch >> sale ;				
	}
	cout<<"Data Update succesfull "<<endl;
	
	store.close();
	fout.close();
   remove("store.txt");
    rename("New2.txt", "store.txt");

            	
           goto b; 	
   }		 	
		 	else if(choice2==3)
		 	{
		 		cin.ignore();
            			 	
		 		string temp;	
	cout<< "Enter Drug supplier Name  update : ";
	getline(cin,temp);
		ifstream supplier("supplier.txt",ios::in);
		if(!supplier)
		{
			cout<<"failed";
		}
		///store >>Adress_of_branch >> sale ;	
	ofstream fout("New2.txt", ios::app);
	 supplier >> drug1 >> characteristic1 >> quantity1 ;
     while(!supplier.eof())
	  {
		if (temp == Adress_of_branch)
		{
			
	       int update;

			cout<<" 1 Enter New Adress"<<endl;
			cout<<" 2 Enter New Sales Rate "<<endl;
			cout<<" 3 Enter New cell number "<<endl;
			cin>>update;
			
			if (update==1)
			{
				cin.ignore(1);
				cout<<"Enter New NAME of supplier : ";
				getline(cin,u_drug);
				fout<< u_drug << "\t\t" << characteristic1 << "\t\t"<< quantity1 << endl;
				
			}
			else if (update==2)
			{cin.ignore(1);
				cout<<" Enter New Sales Rate : "<<endl;
				getline(cin, u_characteristic);
				fout<<  drug1  << "\t\t" << u_characteristic << "\t\t"<< quantity1 <<endl;
			}
			else if(update==3)
			{
				fout<<  drug1  << "\t\t" << characteristic1 << "\t\t"<< u_quantity <<endl;
			}
		}
			else 
			{
				fout<< drug1  << "\t\t" << characteristic1 << "\t\t"<< quantity1 << endl;
		    }
	 supplier >> drug1 >> characteristic1 >> quantity1 ;		
	}
	cout<<"Data Update succesfull "<<endl;
	
	supplier.close();
	fout.close();
   remove("supplier.txt");
    rename("New2.txt", "supplier.txt");

            	
    goto b;
	}
     }
     else if(choice==6)
     {
     	replace();
		 	 goto a;

	 }
	}
	else
	{
		cout << "           Your Login and Password was incorrect " << endl;
		goto a;
	}
	data.close();

}
int main()
{
	login();
}