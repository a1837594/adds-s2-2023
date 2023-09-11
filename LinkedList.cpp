#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <limits>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    if (array != nullptr) {
        for (int i = len - 1; i >= 0; i--) {
            insertPosition(1, array[i]);
        }
    }
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->getLink();
        delete temp;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    if (pos <= 0) {
        pos = 1;
    }

    Node* newNode = new Node(newNum);

    if (pos == 1 || head == nullptr) {
        newNode->setLink(head);
        head = newNode;
    } else {
        Node* current = head;
        int i = 1;

        while (i < pos - 1 && current->getLink() != nullptr) {
            current = current->getLink();
            i++;
        }

        newNode->setLink(current->getLink());
        current->setLink(newNode);
    }
}

bool LinkedList::deletePosition(int pos) {
    if (pos <= 0 || head == nullptr) {
        return false;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->getLink();
        delete temp;
        return true;
    } else {
        Node* current = head;
        int i = 1;

        while (i < pos - 1 && current->getLink() != nullptr) {
            current = current->getLink();
            i++;
        }

        if (current->getLink() != nullptr) {
            Node* temp = current->getLink();
            current->setLink(temp->getLink());
            delete temp;
            return true;
        } else {
            return false;
        }
    }
}

int LinkedList::get(int pos) {
    if (pos <= 0 || head == nullptr) {
        return std::numeric_limits<int>::max();
    }

    Node* current = head;
    int i = 1;

    while (i < pos && current->getLink() != nullptr) {
        current = current->getLink();
        i++;
    }

    if (i == pos) {
        return current->getData();
    } else {
        return std::numeric_limits<int>::max();
    }
}

int LinkedList::search(int target) {
    Node* current = head;
    int pos = 1;

    while (current != nullptr) {
        if (current->getData() == target) {
            return pos;
        }

        current = current->getLink();
        pos++;
    }

    return -1;
}

void LinkedList::printList() {
    std::cout << '[';

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->getData();
        current = current->getLink();
        if (current != nullptr) {
            std::cout << ' ';
        }
    }

    std::cout << ']' << std::endl;
}
