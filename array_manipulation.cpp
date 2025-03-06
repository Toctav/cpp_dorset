#include <iostream>
using namespace std;

const int max_size = 10;
int arr[max_size];
int currentSize = 0;     // to track the current number of elements in the array

void displayArray()
{
    if (currentSize == 0)
    {
        cout << "The array is empty" << endl;
    } 
    else 
    {
        cout << "Array elements: ";
        for (int i = 0; i < currentSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void insertElement()
{
    int value, pos;
    cout << "Enter the element to insert: ";
    cin >> value;
    cout << "Enter the position to insert (0 to " << currentSize << "): ";
    cin >> pos;
    
    if (pos < 0 || pos > currentSize || currentSize == max_size)
    {
        cout << "Invalid position or array is full!" << endl;
    }
    else
    {
        for (int i = currentSize; i > pos; i--)
        {
            arr[i] = arr[i - 1]; // Shift elements to the right
        }
        arr[pos] = value; // Insert the new element
        currentSize++;
        cout << "Element inserted successfully" << endl;
    }
}

void deleteElement()
{
    int pos;
    cout << "Enter the position to delete (0 to " << currentSize - 1 << "): ";
    cin >> pos;
    
    if (pos < 0 || pos >= currentSize)
    {
        cout << "Invalid position!" << endl;
    }
    else
    {
        for (int i = pos; i < currentSize - 1; i++)
        {
            arr[i] = arr[i + 1]; // Shift elements to the left
        }
        currentSize--;
        cout << "Element deleted successfully" << endl;
    }
}

void searchElement()
{
    int value;
    cout << "Enter the element to search: ";
    cin >> value;
    
    for (int i = 0; i < currentSize; i++)
    {
        if (arr[i] == value)
        {
            cout << "Element found at index: " << i << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}

void updateElement()
{
    int pos, newValue;
    cout << "Enter the position to update (0 to " << currentSize - 1 << "): ";
    cin >> pos;
    
    if (pos < 0 || pos >= currentSize)
    {
        cout << "Invalid position!" << endl;
    }
    else
    {
        cout << "Enter the new value: ";
        cin >> newValue;
        arr[pos] = newValue;
        cout << "Element updated successfully " << endl;
    }
}

int main()
{
    int choice;
    
    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Display Array\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Search Element\n";
        cout << "5. Update Element\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                displayArray();
                break;
            case 2:
                insertElement();
                break;
            case 3:
                deleteElement();
                break;
            case 4:
                searchElement();
                break;
            case 5:
                updateElement();
                break;
            case 6:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
