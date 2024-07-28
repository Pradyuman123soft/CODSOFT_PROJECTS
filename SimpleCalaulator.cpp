#include <iostream>
using namespace std;

int main()
{
    int choice;
    double FirstTerm, SecondTerm;
    cout << "1.Perform Sum" << endl
         << "2.Perform Subtract" << endl
         << "3.Perform Multiplication" << endl
         << "4.Perform Division" << endl
         <<"Enter Your Choice: "<<endl;
    cin >> choice;
    cout << "Enter the First number: " << endl;
    cin >> FirstTerm;
    cout << "Enter The Second number: " << endl;
    cin >> SecondTerm;
    switch (choice)
    {
    case 1:
        cout<<"Result: "<<(FirstTerm + SecondTerm)<<endl;
        break;
    case 2:
        cout<<"Result: "<<(FirstTerm - SecondTerm)<<endl;
        break;
    case 3:
        cout<<"Result: "<<(FirstTerm * SecondTerm)<<endl;
        break;
    case 4:
    if (SecondTerm!=0)
    {
        cout<<"Result: "<<(FirstTerm / SecondTerm)<<endl;
    }else{
        cout<<"Error Division BY Zero is not allowed."<<endl;
    }
        break;
    default:
        cout << "You Have Entered a Wrong Option";
        break;
    }
    return 0;
}
