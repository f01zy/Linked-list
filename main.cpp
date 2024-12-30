#include <cstdio>
#include <iostream>

class Node {
public:
  int data;
  Node *next = nullptr;

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
      if (current == nullptr)
        break;

      current = current->next;
    }

    return current;
  }

  void remove(int i) {
    Node *prev = nullptr;
    Node *current = head;

    for (int j = 0; j < i; j++) {
      if (current == nullptr)
        break;

      prev = current;
      current = current->next;
    }

    if (current == nullptr) {
      return;
    }

    if (prev == nullptr) {
      head = current->next;
    }

    else {
      prev->next = current->next;
    }

    delete current;
  }

  void print() {
    if (!head) {
      std::cout << "list is empty" << std::endl;
      return;
    }

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

  list->print();

  return 0;
}
