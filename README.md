# Generic Queue Library for Arduino
[![Arduino-Lint-Action](https://github.com/MicroBeaut/Generic-Queue/actions/workflows/Arduino-Lint-Action.yml/badge.svg)](https://github.com/MicroBeaut/Generic-Queue/actions/workflows/Arduino-Lint-Action.yml)
[![Spell-Check](https://github.com/MicroBeaut/Generic-Queue/actions/workflows/Spell-Check.yml/badge.svg)](https://github.com/MicroBeaut/Generic-Queue/actions/workflows/Spell-Check.yml)
[![Compile-Examples](https://github.com/MicroBeaut/Generic-Queue/actions/workflows/Compile-Examples.yml/badge.svg)](https://github.com/MicroBeaut/Generic-Queue/actions/workflows/Compile-Examples.yml)
![Github](https://img.shields.io/github/v/release/MicroBeaut/Generic-Queue)

A circular-array implementation of a generic queue library for Arduino.

# GenericQueue\<T>
- [Class](#genericqueuet-class)
- [Constructors](#constructors)
  - [GenericQueue\<T>(size_t)](#genericqueuetsize_t)
- [Property](#property)
  - [Count](#count)
  - [IsEmpty](#isempty)
  - [IsFull](#isfull)
- [Method](#method)
  - [Clear](#clear)
  - [Dequeue](#dequeue)
  - [Enqueue](#enqueue)
  - [ForEach](#foreach)
  - [OnStateChanged](#onstatechanged)
  - [Peek](#peek)
  - [TryDequeue](#trydequeue)
  - [TryPeek](#trypeek)


# GenericQueue\<T> Class
The [GenericQueue\<T>](#genericqueuet) class is a data structure that effectively manages a collection of objects by adhering to the first-in, first-out (FIFO) principle.

```c
template <typename T>
class GenericQueue
```

## Type Parameters
`T`

Specifies the type of elements in the queue.

# Constructors
## GenericQueue\<T>(size_t)
Initializes a new instance of the [GenericQueue\<T>](#genericqueuet) class that is empty and has the specified initial capacity.

```C
GenericQueue(size_t capacity);
```
### Parameters
`capacity` size_t

The initial number of elements that the [GenericQueue\<T>](#genericqueuet) can contain.

## Exceptions
`capacity` is less than `zero`.

## Examples
Initialize an integer queue containing 12 queues.
```C
#include "GenericQueue.h"

// Initialize an integer queue containing 12 queues.
GenericQueue<int> numbers(12);
```

# Property
## Count
Gets the number of elements contained in the [GenericQueue\<T>](#genericqueuet).

```C
size_t const& count;
```
### Property Value
`Int32`

The number of elements contained in the [GenericQueue\<T>](#genericqueuet).

## IsEmpty
Gets a value that indicates whether the [GenericQueue\<T>](#genericqueuet) is `empty`.

```C
bool isEmpty();
```

### Property Value
`bool`

true if the [GenericQueue\<T>](#genericqueuet) is `empty`; otherwise, false.

## IsFull
Gets a value that indicates whether the [GenericQueue\<T>](#genericqueuet) is `full`.

```C
bool isFull();
```

### Property Value
`bool`

true if the [GenericQueue\<T>](#genericqueuet) is `full`; otherwise, false.

# Method
## Clear
Removes all objects from the [GenericQueue\<T>](#genericqueuet).

```C
void clear();
```

### Examples
The following code example demonstrates several methods of the [GenericQueue\<T>](#genericqueuet) class, including the `Clear` property.

```C
#include "GenericQueue.h"

// Define the maximum of queues
const size_t numberOfQueues = 5;
// Initializes a new queue of the numbers
// that are empty and have the specified 5-capacity.
GenericQueue<String> numbers(numberOfQueues);

void setup() {
  Serial.begin(115200);
  numbers.enqueue("one");
  numbers.enqueue("two");
  numbers.enqueue("three");
  Serial.print("\nThe number of order contained in the queue = ");
  Serial.println(numbers.count);
  Serial.println("\nRemoves all objects from the Queue.");
  numbers.clear();  // Removes all objects from the Queue.
  Serial.print("The number of order contained in the queue = ");
  Serial.println(numbers.count);
}

void loop () {

}
```

### Results

```
The number of order contained in the queue = 3

Removes all objects from the Queue.
The number of order contained in the queue = 0
```

## Dequeue
Removes and returns the object at the beginning of the [GenericQueue\<T>](#genericqueuet).

```C
T dequeue();
```

### Returns
`T`

The object that is removed from the beginning of the [GenericQueue\<T>](#genericqueuet).

### Exceptions
The [GenericQueue\<T>](#genericqueuet) is empty.

### Examples
The following code example demonstrates several methods of the [GenericQueue\<T>](#genericqueuet) class, including the `Dequeue` method.

```C
#include "GenericQueue.h"

// Define the maximum of queues
const size_t numberOfQueues = 5;
// Initializes a new queue of the numbers
// that are empty and have the specified 5-capacity.
GenericQueue<String> numbers(numberOfQueues);

void setup() {
  Serial.begin(115200);
  numbers.enqueue("one");
  numbers.enqueue("two");
  numbers.enqueue("three");

  Serial.print("Dequeuing '");
  Serial.print(numbers.dequeue());  // Removes and returns the object at the beginning of the numbers.
  Serial.println("'");
}

void loop () {

}
```

### Results

```
Dequeuing 'one'
```

## Enqueue
Adds an object to the end of the [GenericQueue\<T>](#genericqueuet).

```C
void Enqueue(T item);
```

### Parameters
`item` T

The object to add to the [GenericQueue\<T>](#genericqueuet). The value can be null for reference types.

### Examples
The following code example demonstrates several methods of the [GenericQueue\<T>](#genericqueuet) class, including the `Enqueue` method.

```C
#include "GenericQueue.h"

// Define the maximum of queues
const size_t numberOfQueues = 5;
// Initializes a new queue of the numbers
// that are empty and have the specified 5-capacity.
GenericQueue<String> numbers(numberOfQueues);

void setup() {
  Serial.begin(115200);
  numbers.enqueue("one");
  numbers.enqueue("two");
  numbers.enqueue("three");
  numbers.enqueue("four");
  numbers.enqueue("five");

  Serial.println("The list of the numbers:");
  for (size_t index = 0; index < numbers.count; index++) {
    Serial.println(numbers[index]);
  }
}

void loop () {

}
```

### Results

```
The list of the numbers:
one
two
three
four
five
```

## ForEach
Performs the specified action on each element of the [GenericQueue\<T>](#genericqueuet).

```C
void forEach(Action<size_t, T> action)
```

### Type Parameters
`size_t`

The index number of the elements of the [GenericQueue\<T>](#genericqueuet).

`T`

The type of the elements of the [GenericQueue\<T>](#genericqueuet).


`action` Action\<size_t, T>

The Action\<size_t, T> to perform on each element of the [GenericQueue\<T>](#genericqueuet).

### Exceptions
action is `null`.


### Examples
The following code example demonstrates several methods of the [GenericQueue\<T>](#genericqueuet) class, including the `ForEach` method to display each element in [GenericQueue\<T>](#genericqueuet).

```C
#include "GenericQueue.h"

// Define the maximum of queues
const size_t numberOfQueues = 5;
// Initializes a new queue of the numbers
// that are empty and have the specified 5-capacity.
GenericQueue<String> numbers(numberOfQueues);

void setup() {
  Serial.begin(115200);
  numbers.enqueue("one");
  numbers.enqueue("two");
  numbers.enqueue("three");
  numbers.enqueue("four");
  numbers.enqueue("five");

  Serial.println("The list of each number:");
  numbers.forEach(Action);
}

void loop () {

}

void Action(size_t index, String number) {
  Serial.print("Index ");
  Serial.print(index);
  Serial.print(": ");
  Serial.println(number);
}
```

### Results

```
The list of each number:
one
two
three
four
five
```

## OnStateChanged
Raises the StateChanged event.

```C
void onStateChanged(QueueEventCallback function)
```

### Parameters
`function` QueueEventCallback

A callback function when state changed.


```C
void function(QueueEventArgs e, T item)
```

`e` QueueEventArgs

An QueueEventArgs that contains the event data.

```C
enum QueueState {
  DEQUEUE,
  ENQUEUE
};

typedef struct {
  size_t index;
  size_t size;
  QueueState state;
} QueueEventArgs;
```

`item` T

The object at the state changed.

### Examples
The following code example demonstrates several methods of the [GenericQueue\<T>](#genericqueuet) class, including the `onStateChanged` method.

```C
#include "GenericQueue.h"

// Define the maximum of queues
const size_t numberOfQueues = 5;
// Initializes a new queue of the numbers
// that are empty and have the specified 5-capacity.
GenericQueue<String> numbers(numberOfQueues);

void setup() {
  Serial.begin(115200);
  numbers.onStateChanged(OnStateChanged); // Add a callback function when the state changes.
  numbers.enqueue("one");
  numbers.enqueue("two");

  uint8_t count = numbers.count;
  for (uint8_t index = 0; index < count; index++) {
    Serial.print("\nPeek at next item to dequeue: ");
    Serial.println(numbers.peek());   // Returns the object at the beginning without removing it.
    numbers.dequeue();                // Removes and returns the object at the beginning of the numbers.
  }
}

void loop () {

}

void OnStateChanged(QueueEventArgs e, String number) {
  switch (e.state) {
    case DEQUEUE:
      Serial.print("Dequeuing '");
      Serial.print(number);
      Serial.println("'");
      break;
    case ENQUEUE:
      Serial.print("Enqueuing '");
      Serial.print(number);
      Serial.println("'");
      break;
  }
}
```

### Results

```
Enqueuing 'one'
Enqueuing 'two'

Peek at next item to dequeue: one
Dequeuing 'one'

Peek at next item to dequeue: two
Dequeuing 'two'
```

## Peek
Returns the object at the beginning of the [GenericQueue\<T>](#genericqueuet) without removing it.

```C
T peek();
```

### Returns
`T`

The object at the beginning of the [GenericQueue\<T>](#genericqueuet).

### Exceptions
The [GenericQueue\<T>](#genericqueuet) is empty.

### Examples
The following code example demonstrates several methods of the [GenericQueue\<T>](#genericqueuet) class, including the `Peek` method.

```C
#include "GenericQueue.h"

// Define the maximum of queues
const size_t numberOfQueues = 5;
// Initializes a new queue of the numbers
// that are empty and have the specified 5-capacity.
GenericQueue<String> numbers(numberOfQueues);

void setup() {
  Serial.begin(115200);
  numbers.enqueue("one");
  numbers.enqueue("two");
  numbers.enqueue("three");

  Serial.print("Dequeuing '");
  Serial.print(numbers.dequeue());  // Removes and returns the object at the beginning of the numbers.
  Serial.println("'");

  Serial.print("Peek at next item to dequeue: ");
  Serial.println(numbers.peek());  // Returns the object at the beginning without removing it.

  Serial.print("Dequeuing '");
  Serial.print(numbers.dequeue());  // Removes and returns the object at the beginning of the numbers.
  Serial.println("'");
}

void loop () {

}
```

### Results

```
Dequeuing 'one'
Peek at next item to dequeue: two
Dequeuing 'two'
```

## TryDequeue
Removes the object at the beginning of the [GenericQueue\<T>](#genericqueuet), and copies it to the result parameter.

```C
bool tryDequeue(T *result);
```

### Parameters
`result` T

If present, the object at the beginning of the [GenericQueue\<T>](#genericqueuet); otherwise, the default value of `T`.

### Returns
`boo`

`true` if an element was removed and returned from the beginning of the [GenericQueue\<T>](#genericqueuet) successfully; otherwise, `false`.


### Examples
The following code example demonstrates several methods of the [GenericQueue\<T>](#genericqueuet) class, including the `TryDequeue` method.

```C
#include "GenericQueue.h"

// Define the maximum of queues
const size_t numberOfQueues = 5;
// Initializes a new queue of the numbers
// that are empty and have the specified 5-capacity.
GenericQueue<String> numbers(numberOfQueues);

void setup() {
  Serial.begin(115200);
  numbers.enqueue("one");
  numbers.enqueue("two");

  Serial.println("The list of each number:");
  numbers.forEach(Action);

  uint8_t count = numbers.count;
  Serial.print("\nCount: ");
  Serial.println(count);
  count++;

  for (uint8_t index = 0; index < count; index++ ) {
    // Removes the numbers at the beginning and copies it to the result.
    // Return true if an element was removed. Otherwise, false.
    String result;
    bool successful = numbers.tryDequeue(&result);
    Serial.print(successful ? "\nSuccessfully" : "\nUnsuccessfully");
    Serial.print(" \tTry Dequeuing");
    if (successful) {
      Serial.print(" '");
      Serial.print(result);
      Serial.print ("'");
    }
  }
}

void loop () {

}

void Action(size_t index, String number) {
  Serial.print("Index ");
  Serial.print(index);
  Serial.print(": ");
  Serial.println(number);
}
```

### Results

```
The list of each number:
Index 0: one
Index 1: two

Count: 2

Successfully 	Try Dequeuing 'one'
Successfully 	Try Dequeuing 'two'
Unsuccessfully 	Try Dequeuing
```

## TryPeek
Returns a value that indicates whether there is an object at the beginning of the [GenericQueue\<T>](#genericqueuet), and if one is present, copies it to the result parameter. The object is not removed from the [GenericQueue\<T>](#genericqueuet).

```C
bool tryPeek(T *result);
```

### Parameters
`result` T

If present, the object at the beginning of the [GenericQueue\<T>](#genericqueuet); otherwise, the default value of `T`.

### Returns
`boolean`

`true` if there is an object at the beginning of the [GenericQueue\<T>](#genericqueuet); `false` if the [GenericQueue\<T>](#genericqueuet) is empty.

### Examples
The following code example demonstrates several methods of the [GenericQueue\<T>](#genericqueuet) class, including the `TryDequeue` method.

```C
#include "GenericQueue.h"

// Define the maximum of queues
const size_t numberOfQueues = 5;
// Initializes a new queue of the numbers
// that are empty and have the specified 5-capacity.
GenericQueue<String> numbers(numberOfQueues);

void setup() {
  Serial.begin(115200);
  numbers.enqueue("one");
  numbers.enqueue("two");

  Serial.println("The list of each number:");
  numbers.forEach(Action);

  uint8_t count = numbers.count;
  Serial.print("\nCount: ");
  Serial.println(count);
  count++;

  for (uint8_t index = 0; index < count; index++ ) {
    // Removes the numbers at the beginning and copies it to the result.
    // Return true if an element was removed. Otherwise, false.
    String result;
    bool successful = numbers.tryPeek(&result);
    Serial.print(successful ? "\nSuccessfully" : "\nUnsuccessfully");
    Serial.print(" \tTry Peek at next item to dequeue");
    if (successful) {
      Serial.print(": '");
      Serial.print(result);
      Serial.print ("'");
      Serial.print("\nDequeuing '");
      Serial.print(numbers.dequeue());  // Removes and returns the object at the beginning of the numbers.
      Serial.print ("'");
    }
  }
}

void loop () {

}

void Action(size_t index, String number) {
  Serial.print("Index ");
  Serial.print(index);
  Serial.print(": ");
  Serial.println(number);
}
```

### Results

```
The list of each number:
Index 0: one
Index 1: two

Count: 2

Successfully 	Try Peek at next item to dequeue: 'one'
Dequeuing 'one'
Successfully 	Try Peek at next item to dequeue: 'two'
Dequeuing 'two'
Unsuccessfully 	Try Peek at next item to dequeue
```

# Reference
[Learn Microsoft](https://learn.microsoft.com/en-us/dotnet/api/system.collections.generic.queue-1?view=net-8.0)
