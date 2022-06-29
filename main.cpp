#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <windows.h>
#include <cstdlib>
using namespace std;

class User{
    private:
    string name, password;

    public:
    User(string _name= "", string _password= "") 
    : name(_name), password(_password) {}
    void setNP(string n, string p){
        name = n;
        password = p;
    }

    string getName()const{
        return name;
    }

    string getPassword()const{
        return password;
    }

    virtual int userPage() const {
        return 0;
    }

};


class Item{
    protected :
    string  category[50]={},item[50]={};
    double price[50]={};
    int i;

    public:
    Item(){
    }
    void ReadItem(){
        i=0;
        ifstream in("Item.txt");
        if (in.is_open()){
            while(!in.eof()){
                getline(in, category[i]);
                getline(in,item[i]);
                in >> price[i];
                in.ignore();
                i++;
            }
        
            in.close();
    }else{
        cout << "No such file !\n";
    }
    }        
void PrintAll(){
        ReadItem();
        cout << "\tListing available products ... \n\n";
        Sleep(1500);
        cout << "\tList of available products :  \n";
        cout << "\t-------------------------------------------------------------\n";
        cout << "\tCategory\t\t"<< "Name\t\t\t"<< "Price(RM)"<<endl;
        cout << "\t-------------------------------------------------------------\n";
        for (int j=0;j<i;j++){
            if (category[j]=="Accessories")
            {cout << "\t" << category[j] << "\t\t";
            cout << item[j]<< "\t\t";
            cout << price[j]<< endl ;}
            }

        for (int j=0;j<i;j++){
            if (category[j]=="Bags/Purse")
            {cout << "\t" << category[j] << "\t\t";
            cout << item[j]<< "\t\t";
            cout << price[j]<< endl ;}
            }

        for (int j=0;j<i;j++){
            if (category[j]=="Beauty Care")
            {cout << "\t" << category[j] << "\t\t";
            cout << item[j]<< "\t\t";
            cout << price[j]<< endl ;}
            }

        for (int j=0;j<i;j++){
            if (category[j]=="Clothings")
            {cout << "\t" << category[j] << "\t\t";
            cout << item[j]<< "\t\t";
            cout << price[j]<< endl ;}
            }

        for (int j=0;j<i;j++){
            if (category[j]=="Shoes/Heels")
            {cout << "\t" << category[j] << "\t\t";
            cout << item[j]<< "\t\t";
            cout << price[j]<< endl ;}
            }
        cout << "\t-------------------------------------------------------------\n";
    }

    void byCategory(char a){
        ReadItem();
        cout << "\t-----------------------------------------\n";
        cout << "\t" << "No.\t" << "Name\t\t\t" << "Price(RM) \n";
        cout << "\t-----------------------------------------\n";
        if (a == 'a'){
            for (int j=0; j<i; j++){
                if ( category[j] == "Accessories"){
                cout << "\t" << j+1 << ". \t" << item[j] << "\t\t" << price[j] << endl;
            }
        }
        }
        else if (a == 'b'){
            for (int j=0; j<i; j++){
                if ( category[j] == "Bags/Purse"){
                cout << "\t" << j+1 << ". \t" << item[j] << "\t\t" << price[j] << endl;
            }
       }
       }

       else if (a == 'c'){
            for (int j=0; j<i; j++){
                if ( category[j] == "Beauty Care"){
                cout << "\t" << j+1 << ". \t" << item[j] << "\t\t" << price[j] << endl;
            }
       }
       }

       else if (a == 'd'){
            for (int j=0; j<i; j++){
                if ( category[j] == "Clothings"){
                cout << "\t" << j+1 << ". \t" << item[j] << "\t\t" << price[j] << endl;
            }
       }
       }

       else if (a == 'e'){
            for (int j=0; j<i; j++){
                if ( category[j] == "Shoes/Heels"){
                cout << "\t" << j+1 << ". \t" << item[j] << "\t\t" << price[j] << endl;
            }
       }
       }

       cout << "\t-----------------------------------------\n";
    }


};

class Cart:public Item{
    protected:
    int index[50], totalProd;
    double totalAmt;

    public:
    Cart(){
    }

    void addToCart(){
        system ("cls");
        int k=0, prodInd;
        char lp;
        ReadItem();
        totalAmt=0;
        cout << "\tListing available products ... \n";
        Sleep(500);
        cout << endl;
        do{
        cout << "\t-----------------------------------------------------------------\n";
        cout << "\tProduct" << "\t\tCategory\t\t"<< "Name\t\t" << "Price(RM)\n";
        cout << "\t-----------------------------------------------------------------\n";
        for (int j=0;j<i-1;j++){
            cout << "\t# " << j+1 ;
            cout << "\t\t" <<category[j] ;
            cout << "\t\t" << item[j];
            cout << "\t" << price[j]<< endl ;
            }
        cout << "\t-----------------------------------------------------------------\n";

        cout << "\tEnter the product number (1,2,3...) >> ";
        cin  >> prodInd;
        totalAmt += price [prodInd-1];
        index[k] = prodInd-1;
        k++;
        totalProd = k;
        Sleep(500);
        cout << "\tSuccesfully added [" << item[prodInd-1] <<"] into the cart. \n";
        cout << "\tContinue adding ? (Y/n) >> ";
        cin  >> lp;
        system ("cls");
        }while ((lp == 'y')||(lp =='Y'));
        cout << "\tYou have added " << totalProd << " items into your cart\n";
        cout << "\tAmount to pay : RM " << totalAmt <<endl;
    }

    double getTotalAmt(){
        return totalAmt;
    }

    double getTotalProd(){
        return totalProd;
    }

    void clearCart(){
        index[50]={NULL};
        totalAmt=0;
    }

    void CartList(){
        ofstream out("Receipt.txt");
        out << "\n\tHere is your receipt for reference : \n";
        cout << "\tYour Cart : \n";
        out  << "\tItem Bought : \n";
        cout << "\t-------------------------------------------------------------\n";
        out << "\t-------------------------------------------------------------\n";
        cout << "\t" << "Category \t\t" << " Item\t\t\t" << " Price" << endl;
        out << "\t" << "Category \t\t" << " Item\t\t\t" << " Price" << endl;
        cout << "\t-------------------------------------------------------------\n";
        out << "\t-------------------------------------------------------------\n";
        //Index of item added to cart are stored in Index[i]
        //Exp Index[2]={2,4}
        for (int j=0;j< getTotalProd();j++){
            cout << "\t" << category[index[j]] << "\t\t" << item[index[j]] << " x 1 \t\t" <<  fixed << setprecision(2) << price[index[j]] << endl;
            out << "\t" << category[index[j]] << "\t\t" << item[index[j]] << " x 1 \t\t" << fixed << setprecision(2) << price[index[j]] << endl;
        }
        cout << "\t-------------------------------------------------------------\n";
        out << "\t-------------------------------------------------------------\n";
        cout << endl  <<  "\tTotal Price : RM "  << getTotalAmt() << endl;
        out << endl  <<  "\tTotal Price : RM " << fixed << setprecision(2) << getTotalAmt() << endl;
        out.close();
    }

};

class Promotion{
    private :
    string promocode =  "SeeU2023";;

    public: 
    Promotion(){
    }

    string getpromo()const{
        return promocode;
    }

    double promoamt() const{
        return 0.7;
    }
};


class Buyer:public User{
    protected:
    double ewallet;
    Cart cart;
    Promotion *promo;

    public:
    Buyer(string _name= "", string _password= ""): User(_name, _password){
        ewallet = 50;
    }
    void identify(){
        char loop;
        do{
            string n,p;
            cout << "\n\tEnter Username   >> ";
            cin >> n;
            cout << "\tEnter Password   >> ";
            cin >> p;
            setNP(n,p);
            if ((getName() == "buyer") && (getPassword() == "abc")){
            cout << "\tWelcome, " <<getName() << endl << endl;
            loop = 'n';
            Sleep(1000);
            }
            else{
                cout << "\tWrong Credentials !\n";
                loop = 'y';
            }
    }while (loop == 'y');
    }

    int userPage () const
    {
        char action;
        cout<<endl;
        cout << "\t   HOME PAGE   \n";
        cout << "\tA. Account Details \n";
        cout << "\tB. Store Notice \n";
        cout << "\tC. View All Item \n";
        cout << "\tD. Search by Category \n";
        cout << "\tE. Add to Cart \n";
        cout << "\tF. View Cart \n";
        cout << "\n\tSelect Action >> ";
        cin  >> action;
        
        return action;
    }
        
    void TopUp(double a){
        ewallet+=a;
    }

    double getEwallet(){
        return ewallet;
    }

    void AccDetails(){
        cout << "\n\t---------------- Personal Details ----------------\n" ;
        cout << "\tName                       : " << getName() << endl ;
        cout << "\tBalance Amount in E-Wallet : RM " << getEwallet() << endl ;
        cout << "\t---------------------------------------------------\n\n";
    }   

    void addCart(){
        cart.addToCart();
    }

    void viewCart(){
        system ("cls");
        cart.CartList();
    }

    void checkOut(){
        ofstream out("Receipt.txt",ios::app);
        char pmcode [50];
        double totalAmt = cart.getTotalAmt();
        cout << "\tEnter Promo Code, press anything if no >> ";
        cin >> pmcode;
        cin.ignore(30,'\n');

        if (strcmp(pmcode, "SeeU2023") == 0 ){  
            totalAmt = totalAmt * promo->promoamt() ;
            double saved = cart.getTotalAmt() - totalAmt;
            cout << "\n\tCongratulations ! You saved RM "<< saved << endl;
            out  << "\n\tYou are usung the promo code #" << pmcode << " for discount.\n";
            out << "\n\tCongratulations ! You saved RM "<< fixed << setprecision(2) << saved << endl;
            cout << "\tYou need to pay only RM " <<  totalAmt <<  " now, Enjoy ! \n";
            out << "\tYou need to pay only RM " <<  fixed << setprecision(2) << totalAmt <<  " now, Enjoy ! \n";
        }
        else {
            "\tWrong Promocode! \n";
        }
        
        while ( totalAmt > getEwallet()) {
            double tp;
            cout << "\n\tInsufficient Balance !\n";
            cout << "\tYou have only RM " << getEwallet() << " left. \n";
            Sleep(1000);
            cout << "\tProceeding to Top Up... \n";
            Sleep(1000);
            cout << "\tEnter Amount to Top Up : RM ";
            cin  >> tp;
            TopUp(tp);
        }

        cout << "\n\tYour E-wallet balance is : RM " << getEwallet() << endl;
        cout << "\tPaying RM " << totalAmt << endl;
        out  << "\tPaid Amount : RM " << totalAmt << endl;
        Sleep(1000);
        cout << "\n\tYour E-wallet balance is now : RM " << getEwallet()-totalAmt << endl;
        out << "\n\tYour E-wallet balance is now : RM " << getEwallet()-totalAmt << endl;
        cout << "\tThank you ! Your receipt has been generated and is ready to view !.\n\n";  
        out << "\tThank you ! Please visit again <3 ✐.ɴɪᴄᴇ ᴅᴀʏ 〰\n\n";
        cart.clearCart();
    }

};

class Seller:public User,public Item    // multiple inheritance
{
    private:
    string newItem;
    double newPrice;

    public:
    Seller(string _name= "", string _password= "") : User(_name, _password), Item()   // pass arguments to base class
    {
    }

    void identify(){
        char loop;
        do{
            string n,p;
            cout << "\n\tEnter Username   >> ";
            cin >> n;
            cout << "\tEnter Password   >> ";
            cin >> p;
            setNP(n,p);
            if ((getName() == "seller") && (getPassword() == "abc")){
            cout << "\tWelcome, " << getName() << endl << endl ;
            Sleep(1000);
            loop = 'n';
            }
             else{
            cout << "\tWrong Credentials !\n";
            loop = 'y';
            }

        }while(loop == 'y');
    }

    int userPage() const
    {
        char action;

        cout<<endl;
        cout << "\t   HOME PAGE   \n";
        cout<<"\tG. View current stock"<<endl;
        cout<<"\tH. Add stock"<<endl;
        cout<<"\tI. Write notice"<<endl;
        cout<<"\tSelect Action >> ";
        cin>>action;
        
        return action;
    }

    // wirte current stock from text file to console
    void writeStock()
    {
        ReadItem();     // inherit from class Item
        PrintAll();
    }

    // for seller to add new stock item
    void addNewItem()
    {
        char choice;
        int numNewItem = 0;

        do
        {       
            system("cls");
            ReadItem();     // inherit from class Item
            PrintAll();

            // prompt user to add new stock according to his desired catagories

            cout << "\tChoose a category to update your stock item \n";
            cout << "\t[1]Accessories"<<"\t[2]Bags/Purse\t"<< "[3]Beauty Care\n";
            cout << "\t[4]Clothings"<<"\t[5]Shoes/Heels\n\n";

            int newCategory;
            cout << "\tCategory [1/2/3/4/5]=> ";
            cin>>newCategory;
            cin.ignore();
            
            ofstream stockFile;
            stockFile.open("Item.txt",ios::app);    // in append mode
            switch(newCategory)
            {
                case 1: stockFile<<"Accessories"<<endl; break;
                case 2: stockFile<<"Bags/Purse"<<endl; break;
                case 3: stockFile<<"Beauty Care"<<endl; break;
                case 4: stockFile<<"Clothings"<<endl; break;
                case 5: stockFile<<"Shoes/Heels"<<endl; break;   
            }

            cout<<"\tName => ";
            getline(cin, newItem);

            for(int idx= 0; idx< newItem.length(); idx++)
            {
                newItem[0]= toupper(newItem[0]);
                int space= newItem.find(" ", 0);
                newItem[space+1]= toupper(newItem[space+1]);
            } 

            cout << "\tPrice => ";
            cin >> newPrice;

            stockFile << newItem << endl;
            stockFile << newPrice<<endl;
            stockFile.close();

            cout<<"\tAdding "<<newItem<<" into stock list ..."<<endl;
            Sleep(600);
            system ("cls");

            PrintAll();
            cout<<endl;
            cout << "\tSuccesfully added [" << newItem <<"] into the stock. \n";
            cout << "\tContinue adding ? (Y/n) >> ";
            cin>>choice;
        } while ((choice == 'y')||(choice =='Y'));
        
    }

    // set notice or promotion code for buyer
    void setNotice()
    {
        int numNotice;
        string notice;

        ofstream noticeFile("notice.txt", ios::out);    // write / override new notice
        if(noticeFile.is_open())
        {
            cout<<"\tSet notice for buyer"<<endl;
        }

        cout << "\tHow many notice you want to set => ";
        cin >> numNotice;
        cin.ignore();

        cout << endl;
        for(int i= 0; i< numNotice; i++)
        {
            cout<<"\tNotice #"<<(i+1)<<" => ";
            getline(cin, notice); 
            noticeFile << notice << endl ;
        }

        noticeFile.close();
 
    }
    
};


int main(){
    cout << fixed << setprecision(2);
    User *u;
    Buyer b;
    Item items;
    Seller s;
    int role;
    char choice,buyerchoice,buyermenu,cate,sellerchoice,sellermenu,topup;
    string n,p;
    double amt;

    do{
    //-------------Ask Role-------------
    system ("cls");
    cout << "\n\t============================================";
    cout << "\n\t|                LOGIN PAGE                |";
    cout << "\n\t============================================";
    cout << "\n\t1. Buyer ";
    cout << "\n\t2. Admin ";
    cout << "\n\tLogin as >> ";
    cin >> role;
    cout << endl;
    switch(role){
        //-------------Buyer-------------
        case 1:{
            b.identify();
            //-------------Buyer's Menu-------------
            do{
            cout << endl;
            system ("cls");
            u = &b;
            buyerchoice = u->userPage();
            switch(buyerchoice){
                case 'A': {
                    //---------------Buyer's Menu---------------
                    b.AccDetails();
                    cout << "\n\tPress Y/y to top up E-Wallet, else if no >> ";
                    cin  >> topup;
                    if ((topup == 'Y') || (topup == 'y')){
                        cout << "\n\tEnter amount to top up : RM ";
                        cin  >> amt;
                        b.TopUp(amt);
                    }
                    cout << "\tBack to Menu ? (Y/n) >> ";
                    cin  >> buyermenu;
                    break;
                    }

                case 'B':{
                    //---------------Read Store Notice from file---------------
                    string line[50];
                    int m;
                    ifstream in("notice.txt");
                    if (in.is_open()){
                        m=0;
                    while(!in.eof()){
                        getline(in, line[m]);
                        m++;
                    }}
                    else {
                        cout << "\tNo such file ! \n";
                    }
                    
                    cout << "\n\t*********************************************************\n";
                    cout << "\t               Welcome to Fashion Jojo               \n";
                    cout << "\t**********************************************************\n";
                    for (int n=0; n<m-1 ;n++ ){
                        cout << "\t" << n+1 << ". " << line[n] << endl;
                    }
                    cout << "\t*********************************************************\n\n";
                    in.close();
                    cout << "\tBack to Menu ? (Y/n) >> ";
                    cin  >> buyermenu;
                    break;
                }

                case 'C': {
                    //---------------Print All Items---------------
                    items.PrintAll();
                    cout << "\tBack to Menu ? (Y/n) >> ";
                    cin  >> buyermenu;
                    break;
                    }

                case 'D': {
                    //---------------Print Item by Categories---------------
                    cout << endl;
                    cout << "\ta. Accessories \n";
                    cout << "\tb. Bags/Purse \n";
                    cout << "\tc. Beauty Care \n";
                    cout << "\td. Clothings \n";
                    cout << "\te. Shoes/Heels \n";

                    cout << "\tSelect category ----> ";
                    cin  >> cate;
                    items.byCategory(cate);
                    cout << "\tBack to Menu ? (Y/n) >> ";
                    cin  >> buyermenu;
                    break;
                }

                case 'E': {
                    //---------------Add to Cart by listing out all Item---------------
                    char checkout;
                    b.addCart();
                    cout << endl;
                    cout << "\tBack to Menu ? (Y/n) >> ";
                    cin  >> buyermenu;
                    break;
                }

                case 'F': {
                    //---------------View & Edit Cart and Check Out---------------
                    char checkout,editCart;
                    b.viewCart();
                    cout << "\tEdit your cart ? (Y/n) ";
                    cin  >> editCart;
                    if ((editCart == 'Y')||(editCart == 'y')){
                        b.addCart();
                        system("cls");
                        b.viewCart();
                    }
                    cout << "\tProceed to check out ? (Y/n) ";
                    cin  >> checkout;
                    if ((checkout == 'y')||(checkout == 'Y')){
                             b.checkOut();
                    }
                    cout << "\tBack to Menu ? (Y/n) >> ";
                    cin  >> buyermenu;
                    break;
                }
                
            }

        }while ((buyermenu == 'y')||(buyermenu == 'Y'));
        break;
        }

        //-------------Seller-------------
        case 2:{
        s.identify();
        do{
            cout << endl;
            system ("cls");
            //---------------Buyer's Menu---------------
            u = &s;
            sellerchoice= u->userPage();

            switch(sellerchoice){
                case 'G' : {
                    //---------------To view Stock List---------------
                    s.writeStock();
                    cout << "\tBack to Menu ? (Y/n) >> ";
                    cin  >> sellermenu;
                    break;
                }

                case 'H': {
                    //---------------To append Stock List---------------
                    s.addNewItem();
                    cout << "\tBack to Menu ? (Y/n) >> ";
                    cin  >> sellermenu;
                    break;
                }

                case 'I': {
                    //---------------To write notice---------------
                    s.setNotice();
                    cout << "\tBack to Menu ? (Y/n) >> ";
                    cin  >> sellermenu;
                    break;
                }
            }


        }while ((sellermenu == 'y')||(sellermenu == 'Y'));
 
        break;
        }
        
    }   
    cout << "\n\tDo you want to continue ? (Y/n) >> ";
    cin  >> choice;

    } while ((choice == 'y')||(choice == 'Y'));

    system ("pause");
    return 0;
}
