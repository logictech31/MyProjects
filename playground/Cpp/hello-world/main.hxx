#pragma once
#include <string>
class Node{
private:
  string txt;
  Node *next;

public:
  Node();
  ~Node();

  bool traverse(Node *x);
  bool add_val(char *str);

  friend class Tokenize;
};

class Tokenize {
protected:
  string txt;
  Node *head;
public:
    Tokenize();
    ~Tokenize();

    Node* create_tokens(char *txt);
};
