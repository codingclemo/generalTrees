#include <iostream>
#include "node.h"
#include "tree.h"

using namespace std;

Tree::Tree()
    :root(nullptr), nodeCount(0)
{
    cout << "Tree constructed" << endl;
} 
Tree::~Tree(){
    cout << "Tree destructed" << endl;
}

Node* Tree::getRoot() const{
    cout << "Tree getRoot" << endl;
    return root;
}
void Tree::insertChild(Node *parent, Node *child){
    cout << "Tree insertChild" << endl;
    nodeCount++;
    if (parent == nullptr) {
        root = child;
    } else if (parent->getFirstChild() == nullptr) {
        parent->setFirstChild(child);
    } else {
        Node *sibling = parent->getFirstChild();
        while (sibling->getNextSibling() != nullptr) {
            sibling = sibling->getNextSibling();
        }
        sibling->setNextSibling(child);
    }
}
void Tree::deleteSubtree(Node *node){
    cout << "Tree delete Subtree" << endl;
    Node *child;
    Node *sibling;
    Node *deletePointer;

    child = node->getFirstChild();
    node->setFirstChild(nullptr);

    while (child != nullptr) {
        sibling = child;
        deletePointer = child;

        child = child->getFirstChild();
        sibling = sibling->getNextSibling();
        delete deletePointer;
        deletePointer = nullptr;
        nodeCount--;

        while (sibling != nullptr){
            if (sibling->getFirstChild() != nullptr) {
                deleteSubtree(sibling);
            }
            deletePointer = sibling;
            sibling = sibling->getNextSibling();
            delete deletePointer;
            deletePointer = nullptr;
            nodeCount--;            
        }
    }
}


int Tree::getNodeCount() const{
    cout << "Tree getNodeCount" << endl;
    return nodeCount;
}
void Tree::Clear(){
    cout << "Tree Clear" << endl;
    root = nullptr;
}
void Tree::DeleteElements(){
    cout << "Tree DeleteElements" << endl;
    if (root != nullptr) {
        deleteSubtree(root);
        delete root;
        root = nullptr;
    }
}

// void Tree::print(std::ostream &os) const{}

void Tree::copySubtree(Node &dest, Node &source) {
    Node *sChild;
    Node *sSibling;
    Node *dChild;
    Node *dSibling;
    Node *copyPointer;

    sChild = source.getFirstChild();
    dest.setFirstChild(dChild);

    while (sChild != nullptr) {
        
        /* Clone the first Child of the current Node */
        dChild = sChild->clone();

        /* Set the first Child and next sibling */
        copyPointer = sChild->getFirstChild();
        dChild->setFirstChild(copyPointer);
        dChild->setNextSibling(dSibling);

        /* Get the next sibling */
        sSibling = sChild->getNextSibling();

        /** Copy all the siblings **/
        while (sSibling != nullptr) {

            /* Set the next sibling */
            copyPointer = sSibling->clone();
            dSibling = copyPointer;

            /* Copy the subtree */
            if (sSibling->getFirstChild() != nullptr) {
                this->copySubtree(*dSibling, *sSibling);
            }

            nodeCount++;

            /* Get the next siblings */
            sSibling = sSibling->getNextSibling();
            dSibling = dSibling->getNextSibling();
        }

        nodeCount++;

        sChild = sChild->getFirstChild();
        dChild = dChild->getFirstChild();
    }
}

Tree& Tree::operator = (const Tree &t) {
    cout << "Tree assignment opearator" << endl;
    if (this == &t) {
        return *this;
    }
    this->DeleteElements();
    this->copySubtree(*this->getRoot(), *t.getRoot());
    
    return *this;
}

std::ostream & operator << (std::ostream &os, const Tree &t) {
    t.print(os);
    return os; 
}