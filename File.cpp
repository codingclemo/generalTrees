#include <ostream>
#include "File.h"

File::File(std::string name = "", std::string contents = "")
    :contents(contents), FSNode(name) {
}

File::~File(){
}

Node* File::clone() const {
    return new File(*this);
}

/* Files do not have children */
Node* File::getFirstChild() const {
    return nullptr;
}


void File::print(std::ostream &os) const {
    // os << name;
    os << contents;
}

std::ostream & operator << (std::ostream &os, const File &f){
    f.print(os);
    return os;
}