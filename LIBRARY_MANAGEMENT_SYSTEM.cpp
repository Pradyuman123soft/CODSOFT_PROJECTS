#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

struct Book
{
    string tittle;
    string author;
    string ISBN;
    bool is_checked_out;
    Book(string &t, string &a, string &i) : tittle(t), author(a), ISBN(i), is_checked_out(false) {};
};
vector<Book> bookdatabase;

void AddBook(string title, string author, string ISBN)
{
    bookdatabase.push_back(Book(title, author, ISBN));
}

void DisplayBooks()
{
    for (const auto &book : bookdatabase)
    {
        cout << "Tittle: " << book.tittle << ", Author: " << book.author << ", ISBN: " << book.ISBN << ", Check Out: " << (book.is_checked_out ? "YEs" : "No") << endl;
    }
}

void SearchBook(const string Querry)
{
    for (const auto &book : bookdatabase)
    {
        if (book.tittle.find(Querry) != string::npos || book.author.find(Querry) != string::npos || book.ISBN.find(Querry) != string::npos)
        {
            cout << "Tittle: " << book.tittle << ", Author: " << book.author << ", ISBN: " << book.ISBN << ", Check out: " << (book.is_checked_out ? "Yes" : "No") << endl;
        }
    }
}

void CheckoutBook(string isbn){
    for (auto &book : bookdatabase)
    {
        if(book.ISBN.find(isbn) !=string::npos && !book.is_checked_out){
            book.is_checked_out = true;
            cout<<"Successfully Checked Out!!!"<<endl;
            return;
        }
    }
    cout<<"...Book Already CheckOut or Not found..."<<endl;
    
}

void ReturnBook(string isbn){
    for (auto &book : bookdatabase)
    {
        if (book.ISBN == isbn && book.is_checked_out)
        {
            book.is_checked_out = false;
            cout<<"!!!Succesfully Return, Have a Great day!!!"<<endl;
            return;
        }
        
    }
    cout<<"XXXX Book Not found or Not Check out XXXX"<<endl;
    
}

double CalculateFine(int overdue_day){
    double Per_day_fine = 0.50;
    return (Per_day_fine * overdue_day);
}

void DisplayMenu()
{
    cout << "...LIBRARY MANAGEMENT SYSTEM..." << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Display Books" << endl;
    cout << "3. Search Book" << endl;
    cout << "4. Checkout Book" << endl;
    cout << "5. Return Book" << endl;
    cout << "6. Calculate Fine" << endl;
    cout << "7. Exit" << endl;
}
int main()
{
    int choice;
    do
    {
        DisplayMenu();
        cout << "Enter Your Choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string tittle;
            string author;
            string ISBN;
            cout << "...Enter Book Details..." << endl;
            cout << "Enter BOOK Tittle:" << endl;
            cin.ignore();
            getline(cin, tittle);
            cout << "Enter BOOK Author:" << endl;
            cin.ignore();
            getline(cin, author);
            cout << "Enter BOOK ISBN:" << endl;
            cin.ignore();
            getline(cin, ISBN);
            AddBook(tittle, author, ISBN);
            break;
        }
        case 2:
            DisplayBooks();
            break;
        case 3:
        {
            string querry ;
            cout << "Enter Book Querry (Tittle, Author, ISBN): " << endl;
            cin.ignore();
            getline(cin, querry);
            SearchBook(querry);
            break;
        }
        case 4:{
            string isbn;
            cout<<"Enter Book ISBN: "<<endl;
            cin.ignore();
            getline(cin,isbn);
            CheckoutBook(isbn);
            break;
        }
        case 5:{
            string isbn;
            cout<<"Enter ISBN: "<<endl;
            cin.ignore();
            getline(cin, isbn);
            ReturnBook(isbn);
            break;
        }
        case 6:{
            int overdue_day;
            cout<<"Enter The Over days: "<<endl;
            cin>>overdue_day;

            cout<<"Your Total Due is:$ "<<CalculateFine(overdue_day)<<endl;;
            break;
        }
        case 7:
        cout<<"....Exiting...."<<endl;
            break;
        default:
        cout<<"...Invlid input! ,you Entered a Wrong Input..."<<endl;
            break;
        }
    } while (choice != 7);
    
    return 0;
}