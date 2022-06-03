#include<iostream>
#include<string>
#include<fstream>

using namespace std;

ifstream(file1);
ofstream(file2);
int main(){
    file1.open("data.txt");
    file2.open("usama.hack");
    string line;

    //cin.ignore();
    //getline(file1,line);
    //file1.seekg(0);
    while(getline(file1,line)){
        file2<<line<<endl;
    }
    return 0;

}