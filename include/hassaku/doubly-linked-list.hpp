#ifndef HASSAKU_DOUBLY_LINKED_LIST_HPP
#define HASSAKU_DOUBLY_LINKED_LIST_HPP

#include <iostream>
#include <map>
#include <ostream>

namespace hassaku {
struct LinkedListNode {
    int key;
    LinkedListNode *prev, *next;

    LinkedListNode(int key) {
        this->key = key;
        this->prev = this->next = nullptr;
    }
};

class DoublyLinkedList {
   private:
    std::map<int, LinkedListNode *> keyToNode;
    LinkedListNode *head, *tail;

   public:
    inline DoublyLinkedList() {
        head = new LinkedListNode(-1);
        tail = new LinkedListNode(-1);
        head->next = tail;
        tail->prev = head;
    }

    inline ~DoublyLinkedList() {
        LinkedListNode *cur = head;
        while (cur != nullptr) {
            LinkedListNode *tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }

    inline void push_back(int key) {
        if (keyToNode.find(key) != keyToNode.end()) {
            throw std::runtime_error("key already exists");
        }
        LinkedListNode *node = new LinkedListNode(key);
        keyToNode[key] = node;

        LinkedListNode *prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;
    }

    inline void erase(int key) {
        if (keyToNode.find(key) == keyToNode.end()) {
            return;
        }

        LinkedListNode *node = keyToNode[key];
        LinkedListNode *prev = node->prev;
        LinkedListNode *next = node->next;
        prev->next = next;
        next->prev = prev;

        keyToNode.erase(key);
        delete node;
    }

    // `key`の後ろに`newKey`を挿入
    inline void insert(int key, int newKey) {
        if (keyToNode.find(key) == keyToNode.end()) {
            throw std::runtime_error("key not found");
        }
        if (keyToNode.find(newKey) != keyToNode.end()) {
            throw std::runtime_error("new key already exists");
        }

        LinkedListNode *node = keyToNode[key];
        LinkedListNode *newNode = new LinkedListNode(newKey);
        keyToNode[newKey] = newNode;

        LinkedListNode *next = node->next;
        node->next = newNode;
        newNode->prev = node;
        newNode->next = next;
        next->prev = newNode;
    }

    inline void print(std::ostream &os = std::cout) const {
        LinkedListNode *cur = head->next;
        while (cur != tail) {
            os << cur->key;
            cur = cur->next;
            if (cur != tail) {
                os << " ";
            }
        }
        os << std::endl;
    }

    inline LinkedListNode *find(int key) {
        if (keyToNode.find(key) == keyToNode.end()) {
            return nullptr;
        }
        return keyToNode[key];
    }

    inline LinkedListNode *operator[](int key) {
        if (keyToNode.find(key) == keyToNode.end()) {
            throw std::runtime_error("key not found");
        }
        return keyToNode[key];
    }

    inline bool empty() const { return head->next == tail; }
    inline size_t size() const { return keyToNode.size(); }

    inline LinkedListNode *begin() const { return head->next; }
    inline LinkedListNode *end() const { return tail; }
    inline LinkedListNode *rbegin() const { return tail->prev; }
    inline LinkedListNode *rend() const { return head; }
};
}  // namespace hassaku

#endif