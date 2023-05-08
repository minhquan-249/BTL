#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Product
{
private:
    string name;
    string code;
    int quantity;
    double price;
    string date;
    string status;

public:
    Product(string name, string code, int quantity, double price, string date, string status)
    {
        this->name = name;
        this->code = code;
        this->quantity = quantity;
        this->price = price;
        this->date = date;
        this->status = status;
    }
    void setName(string name);
    string getName();
    void setCode(string code);
    string getCode();
    void setStatus(string status);
    string getStatus();
};

class Node
{
public:
    Product *data;
    Node *prev;
    Node *next;

    Node(Product *data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void addProduct(Product *product)
    {
        Node *node = new Node(product);

        if (head == NULL)
        {
            head = node;
            return;
        }

        node->next = head;
        head->prev = node;
        head = node;
    }

    void deleteProduct(string code)
    {
        if (head == NULL)
            return;

        if (head->data->code == code)
        {
            head = head->next;

            if (head != NULL)
                head->prev = NULL;

            return;
        }

        Node *temp = head;

        while (temp != NULL && temp->data->code != code)
            temp = temp->next;

        if (temp == NULL)
            return;

        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
    }
    void editProduct(string code, string newName, int newQuantity, double newPrice, string newDate, string newStatus)
    {
        if (head == NULL)
            return;

        Node *temp = head;

        while (temp != NULL && temp->data->code != code)
            temp = temp->next;

        if (temp == NULL)
            return;

        temp->data->name = newName;
        temp->data->quantity = newQuantity;
        temp->data->price = newPrice;
        temp->data->date = newDate;
        temp->data->status = newStatus;
    }

    void searchProduct(string code)
    {
        if (head == NULL)
            return;

        Node *temp = head;

        while (temp != NULL && temp->data->code != code)
            temp = temp->next;

        if (temp == NULL)
        {
            cout << "Product not found" << endl;
            return;
        }

        temp->data->display();
    }

    void sortByName()
    {
        if (head == NULL || head->next == NULL)
            return;

        bool swapped;

        do
        {
            swapped = false;
            Node *temp = head;

            while (temp != NULL && temp->next != NULL)
            {
                if (temp->data->name > temp->next->data->name)
                {
                    swap(temp, temp->next);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }

    void sortByCode()
    {
        if (head == NULL || head->next == NULL)
            return;

        bool swapped;

        do
        {
            swapped = false;
            Node *temp = head;

            while (temp != NULL && temp->next != NULL)
            {
                if (temp->data->code > temp->next->data->code)
                {
                    swap(temp, temp->next);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            temp->data->display();
            cout << endl;
            temp = temp->next;
        }
    }

private:
    void swap(Node *a, Node *b)
    {
        Product *temp = a->data;
        a->data = b->data;
        b->data = temp;
    }
};

class Inventory
{
private:
    DoublyLinkedList list;

public:
    void addProduct(Product *product)
    {
        list.addProduct(product);
    }

    void deleteProduct(string code)
    {
        list.deleteProduct(code);
    }

    void editProduct(string code, string newName, int newQuantity, double newPrice, string newDate, string newStatus)
    {
        list.editProduct(code, newName, newQuantity, newPrice, newDate, newStatus);
    }

    void searchProduct(string code)
    {
        list.searchProduct(code);
    }

    void sortByName()
    {
        list.sortByName();
    }

    void sortByCode()
    {
        list.sortByCode();
    }

    void display()
    {
        list.display();
    }
};

void menu()
{
    cout << "1. Add product" << endl;
    cout << "2. Delete product" << endl;
    cout << "3. Edit product" << endl;
    cout << "4. Search product" << endl;
    cout << "5. Sort products by name" << endl;
    cout << "6. Sort products by code" << endl;
    cout << "7. Display all products" << endl;
    cout << "0. Exit" << endl;
}

int main()
{
    Inventory inventory;

    int choice;
    string name, code, date, status;
    int quantity;
    double price;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter product code: ";
            cin >> code;
            cout << "Enter product quantity: ";
            cin >> quantity;
            cout << "Enter product price: ";
            cin >> price;
            cout << "Enter product date: ";
            cin >> date;
            cout << "Enter product status: ";
            cin >> status;

            inventory.addProduct(new Product(name, code, quantity, price, date, status));
            break;
        case 2:
            cout << "Enter product code: ";
            cin >> code;

            inventory.deleteProduct(code);
            break;
        case 3:
            cout << "Enter product code: ";
            cin >> code;
            cout << "Enter new product name: ";
            cin >> name;
            cout << "Enter new product quantity: ";
            cin >> quantity;
            cout << "Enter new product price: ";
            cin >> price;
            cout << "Enter new product date: ";
            cin >> date;
            cout << "Enter new product status: ";
            cin >> status;

            inventory.editProduct(code, name, quantity, price, date, status);
            break;
        case 4:
            cout << "Enter product code: ";
            cin >> code;

            inventory.searchProduct(code);
            break;
        case 5:
            inventory.sortByName();
            break;
        case 6:
            inventory.sortByCode();
        case 7:
            inventory.display();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}