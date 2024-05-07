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