#include "linked_queue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedQueue::Enqueue(Element e) {
  SinglyNode *node = new SinglyNode(e, nullptr);
    if (size_ == 0) {
        back_ = node;
        front_ = node;
    } else {
        back_->next = node;
        back_ = node;
    }
    size_ += 1;
}

void LinkedQueue::Dequeue() {
  if (size_ == 0) {
    throw std::logic_error("could not dequeue from empty queue");
  } else if (size_ == 0) {
      delete front_;
      back_ = nullptr;
      front_ = nullptr;
  } else {
      auto node = front_->next;
      delete front_;
      front_ = node;
  }
    size_ -= 1;
}


void LinkedQueue::Clear() {
    auto del_node = front_;
    for (int i = 0; i < size_; i++) {
        auto node = del_node->next;
        delete del_node;
        del_node = node;
    }
    front_ = nullptr;
    back_ = nullptr;
    size_ = 0;
}

// === РЕАЛИЗОВАНО ===

LinkedQueue::~LinkedQueue() {
  Clear();
}

std::optional<Element> LinkedQueue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedQueue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedQueue::IsEmpty() const {
  return size_ == 0;
}
int LinkedQueue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedQueue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->next) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis