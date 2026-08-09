#include<bits/stdc++.h>
using namespace std;
 

class BankAccount{
private:
    static long long count;
    long long Balance;
    long long Accno;//unique accno so using accno as first in map
    int joining_date;//format is DDMMYYYY
    string Name;
    long long Phone_num;
public:
    BankAccount(){

    }

    BankAccount(string name,long long phone_no,int date){
        Name = name;
        Phone_num = phone_no;
        joining_date = date;
        Balance = 0;
        Accno = count++;
    }

    BankAccount(long long acc ,string name,long long phone_no,int date,long long balance){
        Name = name;
        Phone_num = phone_no;
        joining_date = date;
        Balance = balance;
        Accno = acc;
    }

    static void setNextAccNo(long long val) {
        if (val > count) {
            count = val;
        }
    }

    long long getAccno(){
        return Accno;
    }

    void setName(){
        string temp;
        cout<<"Enter the new name "<<endl;
        cin.ignore(1000, '\n'); // Clears the leftover enter key
        getline(cin,temp,'\n'); 
        Name = temp;
    }

    void setPhone(){
        long long temp;
        cout<<"Enter The New Phone Number "<<endl;
        cin>>temp;
        Phone_num = temp;
    }
    
    string getName(){
        return Name;
    }

    long long getJoiningDate(){
        return joining_date; 
    }

    long long getBalance(){
        return Balance;
    }

    long long getPhone(){
        return Phone_num;
    }

    void addMoney(long long temp){
        Balance+=temp;
    }

    void deduct(long long temp){
        Balance-=temp;
    }

};

long long BankAccount::count = 1;

void createAccount(map<long long,BankAccount>&mp);
void printDetails(map<long long,BankAccount>&mp);
void depositeMoney(map<long long,BankAccount>&mp);
void withdraw(map<long long,BankAccount>&mp,long long acc,long long money);
void withdrawMoney(map<long long,BankAccount>&mp);
void getBalance(map<long long,BankAccount>&mp);
void updateDetails(map<long long,BankAccount>&mp);
void saveToFile(map<long long, BankAccount>& mp);
void loadFromFile(map<long long, BankAccount>& mp);

int main(){
    map<long long,BankAccount>mp;

    loadFromFile(mp);
    
    int choice;

    do{
        cout<<"----- Choose the service You Want -----"<<endl;
        cout<<"1 ->  Create a new Account "<<endl;
        cout<<"2 ->  Print Account Details "<<endl;
        cout<<"3 ->  Deposite Money "<<endl;
        cout<<"4 ->  Withdraw money"<<endl;
        cout<<"5 ->  Get Balance"<<endl;
        cout<<"6 ->  Update details of Account Holder"<<endl;
        cout<<"7 ->  Exit"<<endl;
        
        cout<<"enter your choice of service below"<<endl;

        if (!(cin >> choice)) {
            cout << "Please enter a valid numeric choice." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cout<<endl;
        
        cin.ignore(1000, '\n');

        switch(choice){
        case 1:
            createAccount(mp);
            saveToFile(mp);
            break;
        case 2:
            printDetails(mp);
            break;
        case 3:
            depositeMoney(mp);
            saveToFile(mp);
            break;
        case 4:
            withdrawMoney(mp);
            saveToFile(mp);
            break;
        case 5:
            getBalance(mp);
            break;
        case 6:
            updateDetails(mp);
            saveToFile(mp);
            break;
        case 7:
            saveToFile(mp);
            cout<<"Sucsessfully Saved to file"<<endl;
            break;
        default:
            cout<<"please enter valid choice"<<endl;
            break;
        }
        cout<<endl<<endl;

    }while(choice != 7);

    return 0;
}

void createAccount(map<long long,BankAccount>&mp){
    string name;
    long long phone_no;
    int date;
    cout<<"please enter your Name"<<endl;
    getline(cin,name,'\n');
    cout<<"Enter your Phone Number"<<endl;
    cin>>phone_no;
    cout<<"Enter today's date in format DDMMYYYY "<<endl;
    cin>>date;
    BankAccount temp = BankAccount(name,phone_no,date);
    mp[temp.getAccno()] = temp;

    cout<<"------------ DO NOT SHARE YOUR ACCOUNT NUMBER ! ------------"<<endl;
    cout<<"Your Account Number is "<<temp.getAccno()<<" .Please Remmember your Account number for any further needs."<<endl;
}

void printDetails(map<long long,BankAccount>&mp){
    long long acc;
    cout<<"Please enter your Account Number and to continue"<<endl;
    cin>>acc;

    if(mp.find(acc) != mp.end()){
        cout<<" Account Holder : "<<mp[acc].getName()<<endl;
        cout<<" Account Number : "<<mp[acc].getAccno()<<endl;
        cout<<"   Phone Number : "<<mp[acc].getPhone()<<endl;
        cout<<"Account Balance : "<<mp[acc].getBalance()<<endl;
        return;
    }
    else{
        cout<<"Account Not found try creating a new one"<<endl;
        return;
    }
}

void depositeMoney(map<long long,BankAccount>&mp){
    long long acc;
    cout<<"Please enter your Account Number and to continue"<<endl;
    cin>>acc;

    if(mp.find(acc) != mp.end()){
        long long temp;
        cout<<"enter the amount you will deposite "<<endl;
        cin>>temp;
        mp[acc].addMoney(temp);
        cout<<"--- Deposite Succesful ---"<<endl;
        cout<<"Current Balance in your Account is :"<<mp[acc].getBalance()<<endl;
    }
    else{
        cout<<"Account Not found,try creating a new one"<<endl;
        return;
    }
}

void withdrawMoney(map<long long,BankAccount>&mp){
    long long acc;
    cout<<"Please enter your Account Number and to continue"<<endl;
    cin>>acc;

    if(mp.find(acc) != mp.end()){
        long long temp;
        cout<<"enter the amount you wnat to withdraw "<<endl;
        cin>>temp;
        withdraw(mp,acc,temp);
    }
    else{
        cout<<"Account Not found,try creating a new one"<<endl;
        return;
    }
}

void withdraw(map<long long,BankAccount>&mp,long long acc,long long money){
    long long balance = mp[acc].getBalance();
    if(balance < money || money < 0){
        cout<<" Insufficient Balance or Invalid Amount ! "<<endl;
    }
    else{
        mp[acc].deduct(money);
        cout<<"--- Withdrawl Succesful ---"<<endl;
        cout<<"Current Balance in your Account is :"<<mp[acc].getBalance()<<endl;
    }
}

void getBalance(map<long long,BankAccount>&mp){
    long long acc;
    cout<<"Please enter your Account Number and to continue"<<endl;
    cin>>acc;

    if(mp.find(acc) != mp.end()){
        cout<<"Balance in your Account is"<<mp[acc].getBalance()<<endl;
    }
    else{
        cout<<"Account Not found,try creating a new one"<<endl;
        return;
    }   
}

void updateDetails(map<long long,BankAccount>&mp){
    long long acc;
    cout<<"Please enter your Account Number to continue"<<endl;
    cin>>acc;

    if(mp.find(acc) != mp.end()){
        int choice;
        cout<<"----- CHOOSE FROM OPTIONS BELOW -----"<<endl;
        cout<<" 1-> Change Account Holder Name "<<endl;
        cout<<" 2-> Change Phone Number"<<endl;
        cout<<"Enter Your choce"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                mp[acc].setName();
                cout<<"The Updated Name is "<<mp[acc].getName()<<endl;
                break;
            case 2:
                mp[acc].setPhone();
                cout<<"The Updated Phone Number is "<<mp[acc].getPhone()<<endl;
                break;
            default:
                cout<<"Enter Valid Choice"<<endl;
                break;
        }
    }
    else{
        cout<<"Account Not found,try creating a new one"<<endl;
        return;
    }
}

// BY GEMINI
void saveToFile(map<long long, BankAccount>& mp) {
    ofstream outfile("bank_data.txt");
    if (!outfile.is_open()) {
        cout << "[FILE ERROR] Could not save data to file!" << endl;
        return;
    }

    // Save each account as CSV: AccNo,Name,Phone,JoiningDate,Balance
    for (auto& pair : mp) {
        BankAccount& acc = pair.second;
        outfile << acc.getAccno() << ","
                << acc.getName() << ","
                << acc.getPhone() << ","
                << acc.getJoiningDate() << ","
                << acc.getBalance() << "\n";
    }
    outfile.close();
}

void loadFromFile(map<long long, BankAccount>& mp) {
    ifstream infile("bank_data.txt");
    if (!infile.is_open()) {
        return; // File doesn't exist yet on first startup
    }

    string line;
    long long maxAccNo = 0;

    while (getline(infile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string accStr, name, phoneStr, dateStr, balStr;

        if (getline(ss, accStr, ',') &&
            getline(ss, name, ',') &&
            getline(ss, phoneStr, ',') &&
            getline(ss, dateStr, ',') &&
            getline(ss, balStr, ',')) {

            long long acc = stoll(accStr);
            long long phone = stoll(phoneStr);
            int date = stoi(dateStr);
            long long balance = stoll(balStr);

            BankAccount loadedAcc(acc, name, phone, date, balance);
            mp[acc] = loadedAcc;

            if (acc > maxAccNo) {
                maxAccNo = acc;
            }
        }
    }
    infile.close();

    // Set nextAccNo to max loaded account ID + 1 to prevent collisions
    BankAccount::setNextAccNo(maxAccNo + 1);
}