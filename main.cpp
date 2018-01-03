#include <iostream>
// #include "tree.h"
#include "node.h"

using namespace std;

int main(void) {
  cout << "Hello World" << std::endl;

  Node* a;
  Node* b; 
  Node* c;
  a->setFirstChild(b);
  b->setNextSibling(c);
  if (a->getFirstChild() == b) {cout << "   b is the first child of a" << endl;}
  if (b->getNextSibling() == c) {cout << "   c is the next sibling of b" << endl;}
  // a.print();


  return 0;
}

