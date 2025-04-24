#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <sstream>
#include "rash.h"
#include <string>
#include <windows.h>

using namespace std;

/* ***********universal************ */
int access;
int rash;
string userData;
string user_input;
string type;
/* ******************************** */

void title() {
    // Create a wide-character string (LPCWSTR)
    const wchar_t* title = L"Rashell";  // This is a wide-character string
    
    // Change console window title
    if (SetConsoleTitleW(title)) {
        // Successfully set the title
    } else {
        // Error setting the title
        MessageBoxW(NULL, L"Failed to set title", L"Error", MB_OK | MB_ICONERROR);
    }

    // Your main loop or other logic
    

}

void licence(){
    cout<<"@Rashell corporation support ver 1.01.2 \ncommand terminal opening sucessfull !";
}

int format(){
    string input;
    int path=0;
    cout<<"sel format>>";
    getline(cin,input);
    if(input=="user" || input=="administrator"){
        if(input=="user"){
            path=1;
        }
        else{
            path=2;
        }
    }
    else{
        cout<<endl;
    }


    return path;
}

void varificationOfFormat(){
    int time=1;
    while(time!=0){
    if(time>1){
        system("cls");
        licence();
        cout<<endl;
        cout<<endl;
    }
    int path=format();
    if(path==1){
        type="user";
        time=0;
    }
    else if(path==2){
        type="administrator";
        time=0;
    }
    else{
        time++;
    }
    }    
}

void commandMaker(){
    stringstream ss(user_input);
    string temp;
    ss >> userData >> temp ;

    if(temp.empty() && userData == "-h"){
        rash = 13;
        return;
    }

    if(temp.empty() && userData == "-e"){
        rash = 7;
        return;
    }

    if (temp == "-o") {
    rash = 1;
    return;
    }
    else if (temp == "-c"){ 
        rash = 2;
        return;
    }
    else if (temp == "-s"){ 
        rash = 3;
        return;
    }
    else if (temp == "-r"){ 
        rash = 4;
        return;
    }
    else if (temp == "-lf"){ 
        rash = 5;
        return;
    }
    else if (temp == "-sf"){ 
        rash = 6;
        return;
    }
    else if (temp == "-e"){ 
        rash = 7;
        return;
    }
    else if (temp == "-cf"){ 
        rash = 8;
        return;
    }
    else if (temp == "-df"){ 
        rash = 9;
        return;
    }
    else if (temp == "-do"){ 
        rash = 10;
        return;
    }
    else if (temp == "-n"){ 
        rash = 11;
        return;
    }
    else if (temp == "-f"){ 
        rash = 12;
        return;
    }
    else if (temp == "-h"){ 
        rash = 13;
        return;
    }
    else{
        cout<<"invailed rash "<<temp<<" ?";
        access=1;
        return;
    }
}

void help(){
    cout<<"Rash                    Command	Meaning"<<endl;
    cout<<"-o                   	open"<<endl;
    cout<<"-c                  	close"<<endl;
    cout<<"-s                  	shutdown"<<endl;
    cout<<"-r                  	restart"<<endl;
    cout<<"lf                  	list files"<<endl;
    cout<<"-sf                  	select file"<<endl;
    cout<<"-e                  	exit"<<endl;
    cout<<"-cf                  	create file"<<endl;
    cout<<"-df                  	delete file"<<endl;
    cout<<"-do                  	calculate"<<endl;
    cout<<"-n                  	rename name"<<endl;
    cout<<"-f                  	format selection"<<endl;
}

int main(){
    title();
    licence();
    cout<<endl;
    cout<<endl;
    varificationOfFormat();
    cout<<endl;
    while(true){
    cout<<'@'<<type<<">>";
    getline(cin,user_input);
    commandMaker();
    if(rash==7) return 0;//exit
    if(rash==13){
        help();//help
    }
    if(access==0 && rash!=13 && rash!=7){
        int result=0;
        brain(userData,rash,result);
    }
    cout<<endl;
    cout<<endl;
    access=0;
    rash=0;
    }
}
