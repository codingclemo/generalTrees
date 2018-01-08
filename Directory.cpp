#include <ostream>
#include "Directory.h"

Directory::Directory(std::string name = "")
    :FSNode(name) {
}

Directory::~Directory(){
}

Node* Directory::clone() const {
    return new Directory(*this);
}

void Directory::print(std::ostream &os) const {
    os << name;
}

std::ostream & operator << (std::ostream &os, const Directory &d){
    d.print(os);
    return os;
}