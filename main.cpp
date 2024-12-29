#include <cstdio>
#include <iostream>

class Node {
public:
  int data;
  Node *next;

  Node(int j) { data = j; }
};

class LinkedList {
private:
  Node *head;

public:
  void append(int data) {
    Node *node = new Node(data);

    if (!head) {
      head = node;
      return;
    }

    Node *current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = node;
  }

  Node *get(int i) {
    Node *current = head;
    for (int j = 1; j <= i; j++) {
      current = current->next;
    }

    return current;
  }

  void remove(int i) {
    Node *prev = head;
    Node *current = head;

    if (i == 0) {
      Node *temp = head;
      head = head->next;
      delete temp;
      return;
    }

    for (int j = 1; j <= i; j++) {
      prev = current;
      current = current->next;
    }

    prev->next = current->next;
    delete current;
  }

  void print() {
    Node *current = head;

    while (current) {
      std::cout << current->data << ":" << current->next;
      if (current->next) {
        std::cout << " " << "<-" << " ";
      }
      current = current->next;
    }

    std::cout << std::endl;
  }
};

int main() {
  LinkedList *list = new LinkedList();
  list->append(0);
  list->append(1);
  list->append(2);
  list->append(3);
  list->append(4);

  list->remove(1);

  Node *get = list->get(2);
  std::cout << get->data << std::endl;
  std::cout << "" << std::endl;

  list->print();

  return 0;
}
