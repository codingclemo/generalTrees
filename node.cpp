#include <iostream>
#include "node.h"

using namespace std;

Node::Node(Node *firstChild, Node *nextSibling)
    :firstChild(firstChild), nextSibling(nextSibling)
{
    cout << "Node constructed" << endl;
}

Node::~Node(){
    cout << "Node deconstructed" << endl;
}

Node* Node::getFirstChild() const {
    cout << "Node getFirstChild" << endl;
    return this->firstChild;
}

Node* Node::getNextSibling() const {
    cout << "Node getNextSibling" << endl;
    return this->nextSibling; 
} 

void Node::setFirstChild(Node *n){
    cout << "Node setFirstChild" << endl;
    firstChild = n;
}

void Node::setNextSibling(Node *n){
    cout << "Node setNextSibling" << endl;
    nextSibling = n;
}

void Node::print(std::ostream &os) const {
    os << "Node print" << flush;
}
