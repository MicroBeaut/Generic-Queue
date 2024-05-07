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