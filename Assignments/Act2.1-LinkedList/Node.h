#pragma once
//#include <memory>

template <typename T>
struct Node {
    T data;
    //std::unique_ptr<Node<T>> next;
    Node<T>* next;

    Node(const T& value) : data(value), next(nullptr) {}
    //Node(const T& value, std::unique_ptr<Node<T>> nextNode) : data(value), next(std::move(nextNode)) {}
    Node(const T& value, Node<T>* nextNode) : data(value), next(nextNode) {}
};