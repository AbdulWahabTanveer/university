#include<iostream>
#include<string.h>
#include"Medicine.cpp"

using namespace std;

class Store{


    Medicine *m;
    char store_name[50];
    int count;
    
    void copy(int count,const char name[]){

        m=new Medicine[count];
        strcpy(this->store_name,name);
        this->count=count;
    }

friend void FileWrite(const Store &S);
friend Store FileRead();

public:
    Store(int count=0,char name[]=" "){
        copy(count,name);
    }
    void set(int count,char name[]){
        copy(count,name);
    }
   // void Medicine_set(int i,char name[],char company[],int price,int date,int month,int year,int stock,char sec[],bool doc){
   //     m[i].set(name,company,price,date,month,year,stock,sec,doc);
   // }
    void Medicine_set(int i,Medicine &M){
        m[i]=M;
    }
    void operator =(const Store &S){
        copy(S.count,S.store_name);
        m=S.m;
    }
    Medicine search(bool &flag){
        char mname[25];
        //cout<<"check check";
        cin.ignore();
        cin.getline(mname,25);
        //cout<<"\ncheck check"<<mname;
        flag=true;
        int arr[count],local_count=0;char company[45];
        for(int i=0;i<count;i++){
            if(strcmp(mname,m[i].get_name())==0){
                arr[local_count++]=i;}
        }
        
        if(local_count>1){
            cout<<"There are 2 or medicines of the same name.\nEnter Company: ";
            cin.ignore();
            cin.getline(&company[0],sizeof(char)*45);
            //cout<<"You entered :"<<company<<'\n'; used in debugging
            for(int i=0;i<local_count;i++){
                if(strcmp(company,m[arr[i]].get_company())==0){
                    cout<<"company matched: "<<m[arr[i]].get_company();
                    return m[arr[i]];
                }
            }
        }
        else if(local_count==1){
            cout<<"Name Matched : "<<m[arr[0]].get_name()<<'\n';
            return m[arr[0]];
        }
    flag=false;
    Medicine m1;
    return m1;
    //In case no condition full filled an empty medcine will be returned
    }
    Medicine get_medicine(int i,bool &flag){
        flag=true;
        Medicine m1;
        if(i>count||i<0){
            flag=false;
            return m1;
        } 
        
        else{
            return m[i];
        }
        return m1;
    }
    void add_medicine(const Medicine &M){
        Medicine *newmed;
        newmed=new Medicine[count+1];
        for(int i=0;i<count;i++)
            newmed[i]=m[i];
        newmed[count]=M;
        count++;
        free(m);
        m=newmed;
    }
    int findindex(Medicine med){
        for(int i=1;i<=count;i++)
            if(strcmp(med.get_name(),m[i].get_name())==0)
                return i;
        return -99999;
    }
    void Bill(){
        bool flag=true,check;
        int tablets,bill=0;
        char medname[25];
        Medicine med;int index;

        while(flag){
            cout<<"\nEnter the Name of Medicine: ";
            med=search(check);
            if(check){
                index=findindex(med);
                cout<<'\n'<<med;
                cout<<"How many Tablets?";
                cin>>tablets;
                if(tablets>med.get_stock())
                    cout<<"Sorry Not enough quantity available.";
                else{
                bill+=(med.get_price()*tablets);
                m[index].set_stock(m[index].get_stock()-tablets);}
            }
            else cout<<"Sorry Medicine not Found.\n";
            cout<<"\nEnter 1 to add another Medicine or 0 to Total.";
            cin>>flag;
        }
        cout<<"\nTotal Bill: "<<bill<<"\nHappy Shopping :) \n";
    }
    friend ostream& operator <<(ostream &out,const Store &s);
    friend void Filehandle(const Store &S);
};
ostream& operator <<(ostream &out,const Store &s){
    
    out<<s.store_name<<"\n\n";

    cout<<"No. of Records: "<<s.count<<"\n\n";

    for(int j=0;j<s.count;j++){
        cout<<s.m[j];
    }
    return out;
}
/*
int main(){


    Store M(50,"Islamia Pharmacy");
    for(int i=0;i<50;i++){
        cin>>a>>b>>c>>d>>e>>f;
        M.Medicine_set();
    }
    //ofstream out("Output.bin",ios::out|ios::binary);
}*/
