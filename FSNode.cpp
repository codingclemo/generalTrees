#include <ostream>
#include <string>
#include "FSNode.h"

/* constructor */
FSNode::FSNode(std::string name = "")
    :name(name), Node() {
}

/* copy constructor */
FSNode::FSNode(const FSNode &fsn)
    :name(fsn.name), Node() {
}

/* destructor */
FSNode::~FSNode() {
}

std::string FSNode::getName() const {
    return name;
}

void FSNode::print(std::ostream &os) const {
    os << name;
}

friend std::ostream & operator << (std::ostream &os, const FSNode &fsn){
    fsn.print(os);
    return os;
}