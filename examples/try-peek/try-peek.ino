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