#include <iostream>
#include <string>
using namespace std;
class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;
    int quantity;

public:
    void setTitle(string t)
    {
        title = t;
    }
    void setAuthor(string a)
    {
        author = a;
    }
    void setDueDate(string d)
    {
        dueDate = d;
    }
    void setquantity(int q)
    {
        quantity = q;
    }
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    string getDueDate()
    {
        return dueDate;
    }
    int getquantity()
    {
        return quantity;
    }
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;
    virtual ~LibraryItem()
    {
    }
};
class Book : public LibraryItem
{
public:
    void checkOut() override
    {
        cout << "Book Checked Out." << endl;
    }
    void returnItem() override
    {
        cout << "Book Returned." << endl;
    }
    void displayDetails() override
    {
        cout << "Enter The Item Type : Book" << endl;
        cout << "Enter The Title : " << getTitle() << endl;
        cout << "Enter The Author : " << getAuthor() << endl;
        cout << "Enter The Due Date : " << getDueDate() << endl;
        cout << "Enter The Quantity : " << getquantity() << endl;
    }
};
class DVD : public LibraryItem
{
public:
    void checkOut() override
    {
        cout << "DVD Checked Out." << endl;
    }
    void returnItem() override
    {
        cout << "DVD Returned." << endl;
    }
    void displayDetails() override
    {
        cout << "Item Type : DVD" << endl;
        cout << "Title : " << getTitle() << endl;
        cout << "Author : " << getAuthor() << endl;
        cout << "Due Date : " << getDueDate() << endl;
        cout << "Quantity : " << getquantity() << endl;
    }
};
class Magazine : public LibraryItem
{
public:
    void checkOut() override
    {
        cout << "Magazine Checked Out." << endl;
    }
    void returnItem() override
    {
        cout << "Magazine Returned." << endl;
    }
    void displayDetails() override
    {
        cout << "Item Type : Magazine" << endl;
        cout << "Title : " << getTitle() << endl;
        cout << "Author : " << getAuthor() << endl;
        cout << "Due Date : " << getDueDate() << endl;
        cout << "Quantity : " << getquantity() << endl;
    }
};
int main()
{
    const int MAX_ITEMS = 10;
    LibraryItem *libraryItems[MAX_ITEMS];
    int count = 0;
    int choice;
    do
    {
        cout << endl
             << "-------Library Menu-------" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Add DVD" << endl;
        cout << "3. Add Magazine" << endl;
        cout << "4. Display Items" << endl;
        cout << "5. Check Out Item" << endl;
        cout << "6. Return Item" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        try
        {
            if (choice == 1 || choice == 2 || choice == 3)
            {
                if (count >= MAX_ITEMS)
                {
                    throw "Library Full.";
                }
                string t, a, d;
                int q;
                cout << "Enter The Title : " << endl;
                cin.ignore();
                getline(cin, t);
                cout << "Enter The Author : " << endl;
                getline(cin, a);
                cout << "Enter The Due Date : " << endl;
                getline(cin, d);
                cout << "Enter The Quanty : " << endl;
                cin >> q;
                if (t == "" || a == "" || d == "")
                {
                    throw "Invalid Input.";
                }
                if (q <= 0)
                {
                    throw "Invalid Input Quantity Should Be Positive.";
                }
                if (choice == 1)
                {
                    libraryItems[count] = new Book();
                }
                else if (choice == 2)
                {
                    libraryItems[count] = new DVD();
                }
                else
                {
                    libraryItems[count] = new Magazine();
                    libraryItems[count]->setTitle(t);
                    libraryItems[count]->setAuthor(a);
                    libraryItems[count]->setDueDate(d);
                    libraryItems[count]->setquantity(q);
                    count++;
                    cout << "Item Added Successfully." << endl;
                }
            }
            else if (choice == 4)
            {
                for (int i = 0; i < count; i++)
                {
                    cout << "------------------" << endl;
                    libraryItems[i]->displayDetails();
                    cout << "------------------" << endl;
                }
            }
            else if (choice == 5)
            {
                int idx;
                cout << "Enter The Item Number To Check Out (0-" << count - 1 << ") : ";
                cin >> idx;
                if (idx < 0 || idx >= count)
                {
                    throw "Invalid Index.";
                    libraryItems[idx]->checkOut();
                }
            }
            else if (choice == 6)
            {
                int idx;
                cout << "Enter Item Number To Return (0-" << count - 1 << ") : ";
                cin >> idx;
                if (idx < 0 || idx >= count)
                {
                    throw "Invalid Index.";
                    libraryItems[idx]->returnItem();
                }
            }
            else if (choice == 7)
            {
                cout << "Exiting program." << endl;
            }
            else
            {
                throw "Wrong Choice.";
            }
        }
        catch (const char *msg)
        {
            cout << "Error : " << msg << endl;
        }
    } while (choice != 7);
    for (int i = 0; i < count; i++)
    {
        delete libraryItems[i];
    }
    return 0;
}
