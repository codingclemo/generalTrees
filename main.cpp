#include <iostream>
#include "tree.h"
#include "node.h"
#include "StringNode.h"

using namespace std;


void stringNodeTest(){
  Tree *baumi = new Tree();
  StringNode *node_01 = new StringNode("01");
  StringNode *node_02 = new StringNode("02");
  StringNode *node_03 = new StringNode("03");
  StringNode *node_04 = new StringNode("04");
  StringNode *node_05 = new StringNode("05");
  StringNode *node_06 = new StringNode("06");
  StringNode *node_07 = new StringNode("07");
  StringNode *node_08 = new StringNode("08");
  StringNode *node_09 = new StringNode("09");
  StringNode *node_10 = new StringNode("10");

  baumi->insertChild(nullptr, node_01);
  baumi->insertChild(node_01, node_02);
  baumi->insertChild(node_01, node_03);
  baumi->insertChild(node_01, node_04);
  baumi->insertChild(node_02, node_05);
  baumi->insertChild(node_02, node_06);
  baumi->insertChild(node_03, node_07);
  baumi->insertChild(node_03, node_08);
  baumi->insertChild(node_03, node_09);
  baumi->insertChild(node_03, node_10);

  int nodeCounter = baumi->getNodeCount();
  cout << "This tree contains " << nodeCounter << " nodes." << endl;
  cout << "*** Print baumi:        ****" << endl;
  cout << *baumi << endl;

  // cout << "*** Copy tree           ****" << endl;
  // Tree *zweig = new Tree();
  // *zweig = *baumi;
  // cout << "*** Print zweig:        ****" << endl;
  // cout << zweig << endl;

  baumi->DeleteElements();
  delete baumi;
}

int main(void) {

  stringNodeTest();
  
  return 0;
}

