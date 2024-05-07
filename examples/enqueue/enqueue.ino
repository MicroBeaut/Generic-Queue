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