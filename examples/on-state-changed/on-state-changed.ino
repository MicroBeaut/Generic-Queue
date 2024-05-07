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