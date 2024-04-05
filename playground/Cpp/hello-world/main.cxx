#include <iostream>
#include "main.hxx"

bool Node::traverse(Node *x) {
  if(x == NULL) {
    std::cout << "Empty node";
    return false;
  }
  while(x != NULL) {
    std::cout << x->txt;
    x = x->next;
  }

  return true;
}

bool Node::add_val(char *str) {
  int len = 0;

  len = strlen(str);
}

Tokenize::Tokenize() {
  head = new Node;
  head->add_val("Hello_World!");
}

int main(int argc, char *argv[]) {
  if(argc < 2) {
    std::cout << "Invalid number of arguments";
    return 1;
  }
  


  return 0;
}
