#include <iostream>
#include <queue>
#include<cstdlib>
using namespace std;

int main(){
    queue <int> shop;
    srand(time(0));

    int count=1;bool Flag=true;

    while(Flag){
            switch (rand()%5){
            
                case 0:
                    if(shop.size()<4){
                        cout<<"Customer "<<count<<" entered, Accepted"<<endl;
                        shop.push(count++);
                    }
                    else    
                        cout<<"Customer "<<count<<" entered, Refused"<<endl;
                    
                    if(shop.size()==1)
                        cout<<"Customer "<<shop.front()<<" assigned Cutting Chair"<<endl;  
                    break;
                
                case 1:
                    if(shop.size()<4){
                        cout<<"Customer "<<count<<" entered, Accepted"<<endl;
                        shop.push(count++);
                    }
                    else    
                        cout<<"Customer "<<count<<" entered, Refused"<<endl;
                    
                    if(shop.size()==1)
                        cout<<"Customer "<<shop.front()<<" assigned Cutting Chair"<<endl; 
                    break;
                
                case 2:
                    if(shop.size()<4){
                        cout<<"Customer "<<count<<" entered, Accepted"<<endl;
                        shop.push(count++);
                    }
                    else    cout<<"Customer "<<count<<" entered, Refused"<<endl;
                    
                    if(shop.size()==1)
                        cout<<"Customer "<<shop.front()<<" assigned Cutting Chair"<<endl; 
                    break;
                
                case 3:
                    if(shop.size()!= 0){
                        
                        cout<<"Customer "<<shop.front()<<" served"<<endl;
                        shop.pop();
                        
                        if(shop.size()!= 0)
                            cout<<"Customer "<<shop.front()<<" assigned Cutting Chair"<<endl;
                    }
                    break;
                
                case 4:
                    cout<<"Shop time closed"<<endl;
                    while(shop.size()!= 0){
                        cout<<"Customer "<<shop.front()<<" served"<<endl;
                        shop.pop();
                        if(shop.size()!= 0)
                            cout<<"Customer "<<shop.front()<<" assigned Cutting Chair"<<endl;
                    }
                    Flag=false;
                    break;
            }
        }

    return 0;
}