#include <ostream>
#include "node.h"
#include "tree.h"



Tree::Tree(){} 
Tree::~Tree(){}
Node* Tree::getRoot() const{}
void Tree::insertChild(Node *parent, Node *child){}
void Tree::deleteSubtree(Node *node){}
int Tree::getNodeCount() const{}
void Tree::Clear(){}
void Tree::DeleteElements(){}
void Tree::print(std::ostream &os) const{}