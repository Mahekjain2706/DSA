#include<bits/stdc++.h>
using namespace std;

class Books{
    private:
    int stock;
    double cost;
    string title;
    string author;

    public: 

    Books(string title,string author, int stock, int cost){
        this->title = title;
        this->author = author;
        this->stock = stock;
        this->cost = cost;
    };


    void displayInfo(){
        cout << "Book - \n";
        cout << "Title :" << title << "Author :" << author << "Cost :" << cost << "Stock :" << stock << "\n";
    }

    void sellCopy(){
        if(stock > 0){
            cout<< "Sold a copy of : "<< title << " Author : " << author << '\n';
            cout << " Thankyou for buying !!\n" ;
            stock--;
        }else{
            cout<< "Sorry , the book is out of stock !!";
        }
    }

    void addCopy(int addCopy){
        stock += addCopy;
        cout << stock << " copies of "<< title << "add to the inventory.";
    }
};

class Magazines{
    private:
    int stock;
    double cost;
    string title;
    string author;

    public:  
    Magazines(string title,string author, int stock, int cost){
        this->title = title;
        this->author = author;
        this->stock = stock;
        this->cost = cost;
    };

    
    void displayInfo(){
        cout<< "Magazines - \n";
        cout << "Title :" << title << "Author :" << author << "Cost :" << cost << "Stock :" << stock << "\n";
    }

    void sellCopy(){
        if(stock > 0){
            cout<< "Sold a copy of : "<< title << " Author : " << author << '\n';
            cout << " Thankyou for buying !!\n" ;
            stock--;
        }else{
            cout<< "Sorry , the book is out of stock !!";
        }
    }

    void addCopy(int addCopy){
        stock += addCopy;
        cout << stock << " copies of "<< title << "add to the inventory.";
    }
};

class StoreManager{
    private:
    string name;

    public:
    StoreManager(string name){
        this->name = name;
    }

    void StoreManagerInfo(){
        cout << "Store Manager: "<< name << "\n";
    }

    void manageBooks(Books &book,int addBook){
        book.addCopy(addBook);
    }

    void manageMagazines(Magazines &mag,int addMag){
        mag.addCopy(addMag);
    }
};

class Cashier{
    private:
    string name;

    public:
    Cashier(string name){
        this->name = name;
    }

    void CashierInfo(){
        cout<< "Cashier Name: "<< name << "\n";
    }

    void sellBook(Books &book){
        book.sellCopy();
    }

    void sellMagazines(Magazines &mag){
        mag.sellCopy();
    }
};

class Customer{
    private:
    string name;

    public:
    Customer(string name){
        this->name = name;
    }

    void buyBookCopy(Cashier &cashier,Books &book){
        cashier.sellBook(book);
    }

    void buyMagazineCopy(Cashier &cashier,Magazines &mag){
        cashier.sellMagazines(mag);
    }
};

int main(){

    Books book("The Great Indian Book", "Dr.Manoj Joshi",10,15.99);
    Magazines magazines("National Geographic","National Geographic Society",20,6.99);

    StoreManager manager("Dr. Farnadise");
    Cashier cashier("Alice");
    Customer customer("Bob");

    cout<< "Library Storage :\n";
    book.displayInfo();
    magazines.displayInfo();

    // Store Manager add more copies
    manager.manageBooks(book,10);
    manager.manageMagazines(magazines,15);

    // Customer buys copies
    customer.buyBookCopy(cashier,book);
    customer.buyMagazineCopy(cashier,magazines);

    // Display Information
    book.displayInfo();
    magazines.displayInfo();

    return 0;
}