#include <iostream>
#include "tree.h"
#include "node.h"

using namespace std;

int main(void) {
  cout << "Hello World" << std::endl;

  // Node ist eine abstrakte Klasse, davon kann man keine Objekte anlegen :-(
  // aber man kann zumindest den nullptr zuweisen
  Node* a = nullptr;
  Node* b = nullptr; 
  Node* c = nullptr;
  // a->setFirstChild(b);
  // b->setNextSibling(c);
  // if (a->getFirstChild() == b) {cout << "   b is the first child of a" << endl;}
  // if (b->getNextSibling() == c) {cout << "   c is the next sibling of b" << endl;}
  // a.print();

  return 0;
}

