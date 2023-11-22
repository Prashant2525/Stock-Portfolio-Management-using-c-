//Implementation ofStock Portfolio Management System using concept of multiple stack

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include<stdlib.h>
using namespace std;

struct Item
{
    int itemCode;
    string itemName;
    string companyName;
    int numberOfItems;
    float price_unit;
    float total_price;
};

int main()
{
    vector<pair<string, stack<Item>>> itemStacks;
    system("color 0A");

    cout << endl;
    cout << "\t\t\t\t\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t |   Stock Portfolio Management System   |" << endl;
    cout << "\t\t\t\t\t\t--------------------------------------------" << endl;
    
    while (true)
    {
        cout << endl;
        cout << endl;
        cout << "1. Create New Stack (Area of Stock)" << endl;
        cout << "2. Add Securities" << endl;
        cout << "3. Display Securities" << endl;
        cout << "4. Check Specific Securities" << endl;
        cout << "5. Update Securities" << endl;
        cout << "6. Sell Securities" << endl;
        cout << "7. Exit" << endl;

        int choice;
        cout << "\nYour Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string stackLabel;
            cout << "Name the Area of stock (e.g Hydro Sector, Finance Sector, etc): ";
            cin >> stackLabel;
            itemStacks.push_back(make_pair(stackLabel, stack<Item>()));
            cout << "New stack created with label: " << stackLabel << endl;
            break;
        }
        case 2:
        {
            if (!itemStacks.empty())
            {
                string stackLabel;
                cout << "Enter the Area of Stock (e.g Hydro Sector, Finance Sector, etc): ";
                cin >> stackLabel;
                int code, count;
                float price;
                string name, company;
                cout << "Enter Item Code: ";
                cin >> code;
                cout << "Enter Item Name: ";
                cin >> name;
                cout << "Enter Company Name: ";
                cin >> company;
                cout << "Enter Number of Units: ";
                cin >> count;
                cout<< "Enter Current value: ";
                cin >> price;

                float total = count * price;

                for (int i = 0; i < itemStacks.size(); i++)
                {
                    if (itemStacks[i].first == stackLabel)
                    {
                        Item newItem;
                        newItem.itemCode = code;
                        newItem.itemName = name;
                        newItem.companyName = company;
                        newItem.numberOfItems = count;
                        newItem.price_unit = price;
                        newItem.total_price = total;

                        itemStacks[i].second.push(newItem);
                        cout << "Item added to stack: " << stackLabel << " successfully." << endl;
                        break;
                    }
                }
            }
            else
            {
                cout << "No stack available. Create a new stack first." << endl;
            }
            break;
        }
        case 3:
        {
            if (!itemStacks.empty())
            {
                string stackLabel;
                cout << "Enter the label of the stack to display items: ";
                cin >> stackLabel;

                for (int i = 0; i < itemStacks.size(); i++)
                {
                    if (itemStacks[i].first == stackLabel)
                    {
                        stack<Item> &currentStack = itemStacks[i].second;
                        if (currentStack.empty())
                        {
                            cout << "No items in the stack: " << stackLabel << endl;
                        }
                        else
                        {
                            cout << "Item Code\t\tItem Name\t\tCompany\t\tNo. of Items\t\tPrice per unit\t\tTotal Amount of Stock" << endl;
                            stack<Item> tempStack = currentStack;
                            while (!tempStack.empty())
                            {
                                Item item = tempStack.top();
                                tempStack.pop();
                                cout << item.itemCode << "\t\t\t\t" << item.itemName << "\t\t\t\t"<< item.companyName << "\t\t\t\t" << item.numberOfItems << "\t\t\t\t" << item.price_unit << "\t\t\t\t" << item.total_price;
                            }
                        }
                        break;
                    }
                }
            }
            else
            {
                cout << "No stack available. Create a new stack first." << endl;
            }
            break;
        }
        case 4:
        {
            if (!itemStacks.empty())
            {
                string stackLabel;
                cout << "Enter the label of the stack to check an item: ";
                cin >> stackLabel;
                int code;
                cout << "Enter Item Code to Check: ";
                cin >> code;

                for (int i = 0; i < itemStacks.size(); i++)
                {
                    if (itemStacks[i].first == stackLabel)
                    {
                        stack<Item> &currentStack = itemStacks[i].second;
                        bool found = false;

                        stack<Item> tempStack = currentStack;
                        while (!tempStack.empty())
                        {
                            Item item = tempStack.top();
                            tempStack.pop();

                            if (item.itemCode == code)
                            {
                                cout << "Item Code: " << item.itemCode << endl;
                                cout << "Item Name: " << item.itemName << endl;
                                cout << "Company: " << item.companyName << endl;
                                cout << "No. of Items: " << item.numberOfItems << endl;
                                cout << "Price per share: " << item.price_unit << endl;
                                cout << "Total Amount of share: " << item.total_price << endl;
                                found = true;
                                break;
                            }
                        }

                        if (!found)
                        {
                            cout << "Item not found in the stack: " << stackLabel << endl;
                        }
                        break;
                    }
                }
            }
            else
            {
                cout << "No stack available. Create a new stack first." << endl;
            }
            break;
        }
        case 5:
        {
            if (!itemStacks.empty())
            {
                string stackLabel;
                cout << "Enter the label of the stack to update an item: ";
                cin >> stackLabel;
                int code;
                string newName, newCompany;
                int newCount;
                float newprice, newtotal;
                cout << "Enter Item Code to Update: ";
                cin >> code;

                for (int i = 0; i < itemStacks.size(); i++)
                {
                    if (itemStacks[i].first == stackLabel)
                    {
                        stack<Item> &currentStack = itemStacks[i].second;
                        bool found = false;
                        stack<Item> tempStack;

                        while (!currentStack.empty())
                        {
                            Item &item = currentStack.top();
                            currentStack.pop();

                            if (item.itemCode == code)
                            {
                                cout << "Enter Item Name: ";
                                cin >> newName;
                                cout << "Enter Company Name: ";
                                cin >> newCompany;
                                cout << "Enter Number of Items: ";
                                cin >> newCount;
                                cout << "Enter latest Value: ";
                                cin >> newprice;

                                newtotal = newCount * newprice;
        

                                item.itemName = newName;
                                item.companyName = newCompany;
                                item.numberOfItems = newCount;
                                item.price_unit = newprice;
                                item.total_price = newtotal;
                                found = true;
                            }

                            tempStack.push(item);
                        }

                        while (!tempStack.empty())
                        {
                            currentStack.push(tempStack.top());
                            tempStack.pop();
                        }

                        if (found)
                        {
                            cout << "Item updated successfully in the stack: " << stackLabel << endl;
                        }
                        else
                        {
                            cout << "Item not found in the stack: " << stackLabel << endl;
                        }
                        break;
                    }
                }
            }
            else
            {
                cout << "No stack available. Create a new stack first." << endl;
            }
            break;
        }
        case 6:
        {
            if (!itemStacks.empty())
            {
                string stackLabel;
                cout << "Enter the label of the stack to delete an item: ";
                cin >> stackLabel;
                int code;
                cout << "Enter Item Code to Delete: ";
                cin >> code;

                for (int i = 0; i < itemStacks.size(); i++)
                {
                    if (itemStacks[i].first == stackLabel)
                    {
                        stack<Item> &currentStack = itemStacks[i].second;
                        bool found = false;
                        stack<Item> tempStack;

                        while (!currentStack.empty())
                        {
                            if (currentStack.top().itemCode == code)
                            {
                                found = true;
                            }
                            else
                            {
                                tempStack.push(currentStack.top());
                            }

                            currentStack.pop();
                        }

                        while (!tempStack.empty())
                        {
                            currentStack.push(tempStack.top());
                            tempStack.pop();
                        }

                        if (found)
                        {
                            cout << "Item deleted successfully in the stack: " << stackLabel << endl;
                        }
                        else
                        {
                            cout << "Item not found in the stack: " << stackLabel << endl;
                        }
                        break;
                    }
                }
            }
            else
            {
                cout << "No stack available. Create a new stack first." << endl;
            }
            break;
        }
        case 7:
            exit(0);
        default:
            cout << "Invalid Value. Please try again." << endl;
        }
    }

    return 0;
}
