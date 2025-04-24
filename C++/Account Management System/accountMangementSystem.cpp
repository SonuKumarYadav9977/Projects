#include <iostream>
using namespace std;












class Account{
    // Public members accessible outside the class
    public:
        string   user_name;  // Stores the user's name
        string   emailID;    // Stores the user's email ID
        long long      number;     // Stores the user's phone number
        string   account_no; // Stores the account number
        string   password;   // Stores the account password
    
        // Default constructor
        Account(){
        }
    
        // Deposit function (To be implemented by the user)
        int deposite(){
            long long depo;
            cout<<endl;
            cout<<"enter deposite amount: ";
            cin>>depo;
            amount=amount+depo;
            cout<<endl;
            cout<<"deposited sucessesfull!"<<endl;
            return 0;
        }
    
        // Withdraw function (To be implemented by the user)
        void withdrawl(){
            cout<<endl;
            if(amount==0){
                cout<<"try depositing amount is blank!"<<endl;
                return;
            }
            long long with;
            cout<<"enter withdrawl amount: ";
            cin>>with;
            if(with<amount){
                amount=amount-with;
                cout<<"withdrawl sucessfully!"<<endl;
            }
            else{
                cout<<"please enter small amount!you dont have that much money.";
            }
        }
    
        // Balance check function (To be implemented by the user)
        void balance(){
            cout<<endl;
            cout<<"amount : "<<amount<<endl;
        }
    
        // Display function (To be implemented by the user)
        void display(){
            cout<<endl;
            cout<<"user name : "<<user_name<<endl;
            cout<<"email :"<<emailID<<endl;
            cout<<"account Id : "<<account_no<<endl;
            cout<<"phone no. : "<<number<<endl;
        }
    
        // Update account function (To be implemented by the user)
        void update(){
            string temp;
            char user_input='n';
            do{
            cout<<endl;
            cout<<"enter your password: ";
            cin>>temp;
            if(temp==password){
                cout<<"updating...."<<endl<<endl;
                cout<<"enter your name: ";
                cin>>user_name;
                cout<<"enter your email: ";
                cin>>emailID;
                cout<<"enter phone number: ";
                cin>>number;
                cout<<"enter your new password: ";
                cin>>password;
            }
            else{
                cout<<"wrong password!try again(y/n): ";
                cin>>user_input;
            }
            }while(user_input=='y' || user_input=='Y');
        }

    // Private members (not accessible outside the class)
    private:
        int amount=0;  // Stores the account balance
};














// Global pointer to store the currently logged-in account
Account *currentAccount = nullptr; 

// Function to create a new account
void createAccount() {
    if (currentAccount != nullptr) { // Check if an account already exists
        cout << "\nAn account already exists!" << endl;
        return;
    }
    cout << "\nCreating new account..." << endl;
    currentAccount = new Account(); // Allocate memory for a new account
    cout<<"enter your name: ";
    cin>>currentAccount->user_name;
    cout<<"enter your email: ";
    cin>>currentAccount->emailID;
    cout<<"enter phone number: ";
    cin>>currentAccount->number;
    currentAccount->account_no="a00fx653748dush";
    cout<<"your account ID is: a00fx653748dush"<<endl;
    cout<<"enter your password: ";
    cin>>currentAccount->password;
    system("cls");
}






bool loggpass=false;








// Function to log in to an existing account
void login() {
    if (currentAccount == nullptr) { // Ensure an account exists before login
        cout << "\nNo account exists. Please create an account first!" << endl;
        return;
    }
    char user_input;
    do{
    cout << "\nLogging in..." << endl;
    cout<<endl;
    string inname,inpassword;
    cout<<"enter user name : ";
    cin>>inname;
    cout<<"enter password: ";
    cin>>inpassword;
    if(inname==currentAccount->user_name && inpassword==currentAccount->password){
         loggpass=true;
         system("cls");
         return;
    }
    else {
        cout<<"something is not valid !"<<endl;
    }
    cout<<"do you want to continue(y/n): ";
    cin>>user_input;
    system("cls");
   }while(user_input=='y' || user_input=='Y');

}













// Function to display the account menu after login
void accountMenu() {
    int choice;
    while (true) {
        cout << "\n********* ACCOUNT MANAGEMENT *********" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. View Account Info" << endl;
        cout << "5. Update Account" << endl;
        cout << "6. Delete Account" << endl;
        cout << "7. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");
        switch (choice) {
            case 1:
                currentAccount->deposite(); // Call deposit function
                system("cls");
                break;
            case 2:
                currentAccount->withdrawl(); // Call withdraw function
    system("cls");
                break;
            case 3:
                currentAccount->balance(); // Call balance function
    system("cls");
                break;
            case 4:
                currentAccount->display(); // Call display function
    system("cls");
                break;
            case 5:
                currentAccount->update(); // Call update function
    system("cls");
                break;
            case 6:
                cout << "\nDeleting account..." << endl;
                delete currentAccount; // Free memory
                currentAccount = nullptr;
                return;
            case 7:
                cout << "\nLogging out..." << endl;
                loggpass==false;
                return;
            default:
                cout << "\nInvalid choice! Try again." << endl;
        }
    }
}














// Function to display the main welcome menu
void welcome() {
    int choice;
    while (true) {
        cout << "\n********* WELCOME TO RAKUDA MANAGEMENT *********" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");
        switch (choice) {
            case 1:
                createAccount(); // Call function to create account
                break;
            case 2:
                login(); // Call function to log in
                if (loggpass != false) accountMenu(); // If login successful, show menu
                break;
            case 3:
                cout << "\nExiting..." << endl;
                return;
            default:
                cout << "\nInvalid choice! Try again." << endl;
        }
    }
}














// Main function to start the program
int main() {
    welcome(); // Call welcome function to start UI
    return 0;
}
