#include "Node.h"

Node::Node(int newData) : data(newData), link(nullptr) {}

int Node::getData() const {
    return data;
}

Node* Node::getLink() const {
    return link;
}

void Node::setLink(Node* newLink) {
    link = newLink;
}
