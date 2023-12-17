#include <iostream>

struct ListNode {
    int value;
    ListNode* next;

    explicit ListNode(int val) : value(val), next(nullptr) {}
};

ListNode* HEAD = nullptr; // Global head pointer

void insertAtBeginning(int value) {
    auto newNode = new ListNode(value);
    newNode -> next = HEAD;
    HEAD = newNode;
}

void insertAtEnd(int value) {
    auto newNode = new ListNode(value);
    if (HEAD == nullptr) {
        HEAD = newNode;
    } else {
        ListNode* current = HEAD;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertAfter(int afterValue, int newValue) {
    ListNode* current = HEAD;
    while (current != nullptr && current-> value != afterValue) {
        current = current->next;
    }
    if (current != nullptr) {
        auto newNode = new ListNode(newValue);
        newNode->next = current->next;
        current->next = newNode;
    } else {
        std::cout << "Value not found.\n";
    }
}

void searchByValue(int value) {
    ListNode* current = HEAD;
    int position = 0;
    while (current != nullptr) {
        if (current->value == value) {
            std::cout << "Value" << value << " found at position " << position << std::endl;
            return;
        }
        current = current->next;
        position++;
    }
    std::cout << "Value not found.\n";
}

void accessByPosition(int position) {
    ListNode* current = HEAD;
    int count = 0;
    while (current != nullptr && count < position) {
        current = current->next;
        count++;
    }
    if (current != nullptr) {
        std::cout << "Element at position " << position << " is: " << current->value << std::endl;
    } else {
        std::cout << "Position is out of bounds.\n";
    }
}

void deleteFirst() {
    if (HEAD != nullptr) {
        ListNode* temp = HEAD;
        HEAD = HEAD->next;
        delete temp;
    } else {
        std::cout << "List is empty.\n";
    }
}

void deleteLast() {
    if (HEAD == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    if (HEAD->next == nullptr) {
        delete HEAD;
        HEAD = nullptr;
        return;
    }
    ListNode* current = HEAD;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

void deleteByPosition(int position) {
    if (HEAD == nullptr || position < 0) {
        std::cout << "Invalid position or the list is empty.\n";
        return;
    }
    if (position == 0) {
        ListNode *temp = HEAD;
        HEAD = HEAD->next;
        delete temp;
        return;
    }
    ListNode *current = HEAD;
    for (int i = 0; current != nullptr && i < position - 1; i++) {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr) {
        std::cout << "Position out of bounds.\n";
        return;
    }
    ListNode *temp = current->next;
    current->next = current->next->next;
    delete temp;
    }

void displayList() {
    ListNode *current = HEAD;
    while (current != nullptr) {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "NULL\n";
}

void displayMenu() {
    std::cout << "1. Insert at beginning\n";
    std::cout << "2. Insert at end\n";
    std::cout << "3. Insert after a given element\n";
    std::cout << "4. Access an element by searching for a given value in the list\n";
    std::cout << "5. Access an element by its position in the list\n";
    std::cout << "6. Delete the first element of the list\n";
    std::cout << "7. Delete the last element of the list\n";
    std::cout << "8. Delete a given element knowing its address\n";
    std::cout << "9. Display the list\n";
}

int main() {
    int choice, value, position;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                int afterValue;
                std::cout << "Enter the value after which to insert: ";
                std::cin >> afterValue;
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                insertAfter(afterValue, value);
                break;
            case 4:
                int searchValue;
                std::cout << "Enter the value to search for: ";
                std::cin >> searchValue;
                searchByValue(searchValue);
                break;
            case 5:
                std::cout << "Enter position to access: ";
                std::cin >> position;
                accessByPosition(position);
                break;
            case 6:
                deleteFirst();
                break;
            case 7:
                deleteLast();
                break;
            case 8:
                std::cout << "Enter position to delete: ";
                std::cin >> position;
                deleteByPosition(position);
                break;
            case 9:
                displayList();
                break;
            default:
                choice = 0;
                break;
        }
    } while (choice != 0);

    return 0;
}
