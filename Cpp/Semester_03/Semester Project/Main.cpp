#include<iostream>
#include<string.h>
//#include"Store.cpp"
#include"FileHandling.cpp"
#include"ExtraFunctions.cpp"

using namespace std;

int main(){
    char name[30],company[45],sec[25]; 
    int date,month,year,stock,price,selector,choice;
    char rerun='1';

    char input[30];Medicine m;
    bool flag,doc;
    Store S=FileRead();
    login();

    while(rerun=='1'||rerun=='\n'){
		cout << "\n\n" << "*******|Enter Operation Number: ";
        cin>>choice;

    switch(choice){
        
        case 1:
        cout<<"Enter the Name of Medicine to Search: "; 
            //cin.ignore();
            m=S.search(flag);
            if(flag)    cout<<"\n"<<m;
            else cout<<"No match found\n";
            break;
        case 2:
        cout<<"Adding Medicine at the End of Current Record\n ";
            m.create_Medicine();
            S.add_medicine(m);
            cout<<"\nRecord Added Successfully"<<"\n\n"<<m;
            break;
        case 3:
        cout<<"Enter The Record Number to Modify:\n";
            cin>>selector;
            m.create_Medicine();
            S.Medicine_set(--selector,m);
            m=S.get_medicine(selector,flag);
            if(flag)    cout<<"\nRecord Updated Successfully"<<"\n\n"<<m;
            else cout<<"Wrong Id Record doesnt Exist.\n\n";
            break;
        case 4:
        cout<<"Enter the Number of Medicine to Show: "; 
            cin>>selector;
            m=S.get_medicine(--selector,flag);
            if(flag)    cout<<m;
            else cout<<"Wrong Id\n";
            break;
        case 5:
            S.Bill();
            break;
        case 6:
            cout<<S;
            break;

    }
    cout<<"\nEnter 1 to repeat or 0 to Terminate the Program.";
    cin>>rerun;
    }



    return 0;
}