//
// Created by srj15 on 2025/12/15.
//
#include <iostream>
using namespace std;
template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(T value):data(value),next(nullptr){};
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList():head(nullptr){};
    ~LinkedList(){clear();};
    void append(T value) {
        Node<T> *newNode=new Node<T>(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T> *currentNode=head;
        while (currentNode->next) {
            currentNode=currentNode->next;
            currentNode->next=newNode;
        }
    };
    void remove(T value) {
        if (!head)return;
        if (head->data==value) {
            Node<T> *temp=head;
            head=head->next;
            delete temp;
            return;
        }
        Node<T> *currentNode=head;
        while (currentNode->next&&currentNode->next->data!=value) {
            currentNode=currentNode->next;
        }
        if (currentNode->next) {
            Node<T> *temp=currentNode->next;
            currentNode->next=temp->next;
            delete temp;
            return;
        }
    }
    void update(T oldval,T newval) {
        Node<T> *currentNode=head;
        while (currentNode) {
            if (currentNode->data==oldval) {
                currentNode->data=newval;
                return;
            }
            currentNode=currentNode->next;
        }
        return;
    }
    bool find(T value) {
        Node<T> *currentNode=head;
        while (currentNode) {
            if (currentNode->data==value) return true;
            currentNode=currentNode->next;
        }
        return false;
    }
    int size() {
        Node<T> *currentNode=head;
        int count=0;
        while (currentNode) {
            count++;
            currentNode=currentNode->next;
        }
        return count;
    }
    void show() {
        Node<T> *currentNode=head;
        if (!head){cout<<"empty list"<<endl;return;}
        while (currentNode) {
            cout<<currentNode->data<<" ";
            currentNode=currentNode->next;
        }
    }
    void clear() {
        Node<T> *currentNode=head;
        while (currentNode) {
            Node<T> *temp=currentNode;
            currentNode=currentNode->next;
            delete temp;
        }
    }
};

void menu() {
    cout << "1. append\n";
    cout << "2. remove\n";
    cout << "3. update\n";
    cout << "4. find\n";
    cout << "5. show\n";
    cout << "6. size\n";
    cout << "0. exit\n";
    cout << "make a choice ：";
}

int main() {
    LinkedList<int> list;
    int choice;
    int value, newValue;
    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "input the value to append : ";
                cin >> value;
                list.append(value);
                break;

            case 2:
                cout << "input the value to delete : ";
                cin >> value;
                list.remove(value);
                break;

            case 3:
                cout << "input old value and new value : ";
                cin >> value >> newValue;
                list.update(value, newValue);
                break;

            case 4:
                cout << "input the value to find : ";
                cin >> value;
                if (list.find(value))
                    cout << "exists\n";
                else
                    cout << "does noe exist\n";
                break;

            case 5:
                list.show();
                break;

            case 6:
                cout << "number is ：" << list.size() << endl;
                break;

            case 0:
                cout << "exit the system\n";
                break;

            default:
                cout << "invalid choice \n";
        }

    } while (choice != 0);

    return 0;
}
