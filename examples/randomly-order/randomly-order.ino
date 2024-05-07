#include "GenericQueue.h"

typedef struct {
  String name;          // Order name
  uint32_t cookingTime; // Cooking time in milliseconds
} Order;

const uint8_t numberOfLists = 4;  // The number of order in list
const Order orderLists[numberOfLists] = {
  {"Potato  ", 5000}, // 5 seconds
  {"Sandwich", 4000}, // 4 seconds
  {"Burger  ", 3000}, // 3 seconds
  {"Chicken ", 2000}  // 2 seconds
};

// Define the order led pin
const uint8_t orderLedPins[numberOfLists] = {5, 4, 3, 2};

// Define the maximum of queues
const size_t numberOfQueues = 5;
// Initializes a new queue of the numbers
// that are empty and have the specified 5-capacity.
GenericQueue<uint8_t> queues(numberOfQueues);   //

// Declare the start time (in milliseconds).
uint32_t startTime;

void setup() {
  Serial.begin(115200);

  // Set the LED pinmode.
  for (uint8_t index = 0; index < numberOfLists; index ++ ) {
    pinMode(orderLedPins[index], OUTPUT);
  }
  // Initializes the pseudo-random number generator
  randomSeed(analogRead(A0));

  // Add the callback function on state changed.
  queues.onStateChanged(OnStateChanged);
  // Randomly add the order.
  RandomOrder();
}

void loop () {
  if (!queues.isEmpty()) {
    uint32_t elapsedTime = millis() - startTime;        // Calculate the elapsed time.
    uint8_t order = queues.peek();                      // Get a current order number.
    if (elapsedTime >= orderLists[order].cookingTime) { // If the cooking time is done,
      queues.dequeue();                                 // dequeue.
    }
  }
}

void RandomOrder() {
  // Randomly add the order.
  queues.enqueue(random(numberOfLists));
}

void OnStateChanged(QueueEventArgs e, uint8_t order) {
  switch (e.state) {
    case DEQUEUE:
      digitalWrite(orderLedPins[order], LOW);
      Serial.println(" Done...");
      RandomOrder();
      break;
    case ENQUEUE:
      startTime = millis();
      digitalWrite(orderLedPins[order], HIGH);
      Serial.print("Cooking:");
      Serial.print(orderLists[order].name);
      break;
  }
}