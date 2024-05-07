/*
  MIT License
  Copyright (c) 2024 MicroBeaut
*/

#ifndef GENERICQUEUE_H
#define GENERICQUEUE_H

#include <Arduino.h>

enum QueueState {
  DEQUEUE,
  ENQUEUE
};

typedef struct {
  size_t index;
  size_t size;
  QueueState state;
} QueueEventArgs;

template <typename T>
class GenericQueue {
    //Event Handler
  private:
    typedef void (*Action)(size_t index, T item);
    typedef void (*QueueEventCallback)(QueueEventArgs e, T item);

    //variable
  private:
    T* _queue;
    size_t _head;           // First valid element in the queue
    size_t _tail;           // Last valid element in the queue
    T* _emptyT;

    size_t _capacity;
    size_t _size;
    const size_t _defaultCapacity = 0;
    QueueEventCallback _function;

    size_t internalSize(size_t size);
    bool internalDequeue(T *result);
    void internalClear(size_t size);
    void internalOnStateChanged(QueueState state, T item);
  public:
    size_t const& count;

    GenericQueue(size_t capacity);
    void onStateChanged(QueueEventCallback function);
    void enqueue(T item);
    T dequeue();
    bool tryDequeue(T* result);
    T peek();
    bool tryPeek(T* result);
    void clear();
    void forEach(Action action);
    bool isFull();
    bool isEmpty();

    // Public Operator
    T& operator[](int index);
};

template <typename T>
inline GenericQueue<T>::GenericQueue(size_t capacity) : count(_size) {
  _capacity = internalSize(capacity);
  _queue = new T[capacity];
  _emptyT = new T[0];
  this->internalClear(capacity);
}

template <typename T>
inline void GenericQueue<T>::onStateChanged(QueueEventCallback function) {
  _function = function;
}

template <typename T>
inline T& GenericQueue<T>::operator[](int index) {
  if (index < _size & _size > 0) return _queue[(_head + index) % _capacity];
  else return _emptyT[0];
}

template <typename T>
inline void GenericQueue<T>::enqueue(T item) {
  if (_size < _capacity) {
    _queue[_tail] = item;
    _tail = (_tail + 1) % _capacity;
    _size++;
    this->internalOnStateChanged(ENQUEUE, item);
  }
}

template <typename T>
inline T GenericQueue<T>::dequeue() {
  T removed;
  this->internalDequeue(&removed);
  return removed;
}

template <typename T>
inline bool GenericQueue<T>::tryDequeue(T* result) {
  return this->internalDequeue(result);
}

template <typename T>
inline bool GenericQueue<T>::internalDequeue(T *result) {
  if (this->isEmpty()) {
    result[0] = _emptyT[0];
    return false;
  } else {
    result[0] = _queue[_head];
    _queue[_head] = _emptyT[0];
    _head = (_head + 1) % _capacity;
    _size--;
    this->internalOnStateChanged(DEQUEUE, result[0]);
    return true;
  }
}

template <typename T>
inline T GenericQueue<T>::peek() {
  return _queue[_head];
}

template <typename T>
inline bool GenericQueue<T>::tryPeek(T* result) {
  if (this->isEmpty()) {
    result[0] = _emptyT[0];
    return false;
  } else {
    result[0] = _queue[_head];
    return true;
  }
}

template <typename T>
inline void GenericQueue<T>::clear() {
  this->internalClear(_size);
}

template <typename T>
inline void GenericQueue<T>::internalClear(size_t size) {
  for (size_t index = 0 ; index < size ; index++) {
    _queue[(_head + index) % _capacity] = _emptyT[0];
  }
  _head = 0;
  _tail = 0;
  _size = 0;
}

template <typename T>
inline void GenericQueue<T>::forEach(Action action) {
  if (action) {
    for (size_t index = 0 ; index < _size ; index++) {
      action(index, _queue[(_head + index) % _capacity]);
    }
  }
}

template <typename T>
inline bool GenericQueue<T>::isEmpty() {
  return _size == 0;
}

template <typename T>
inline bool GenericQueue<T>::isFull() {
  return _size == _capacity;
}

template <typename T>
inline size_t GenericQueue<T>::internalSize(size_t size) {
  if (size > 1) return size;
  else return _defaultCapacity;
}

template <typename T>
inline void GenericQueue<T>::internalOnStateChanged(QueueState state, T item) {
  if (_function) {
    QueueEventArgs e = {_size - 1, _size, state};
    if (e.state == DEQUEUE) e.index = 0;
    _function(e, item);
  }
}

#endif // GENERICQUEUE_H
