#include <iostream>
#include "StringNode.h"

using namespace std; 

/* Constructor */
StringNode::StringNode(std::string value)
    :Node(), value(value) {
}

/* Copy Constructor */
StringNode::StringNode(const StringNode &sn) 
    :Node(), value(sn.value) {
}

/* Destructor */
StringNode::~StringNode() {
}

void StringNode::print(std::ostream &os) const {
    os << value;
}

std::ostream & operator << (std::ostream &os, const StringNode &sn) {
    sn.print(os);
    return os; 
}

Node* StringNode::clone() const {
    return new StringNode(*this);
} 