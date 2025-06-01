#include <Arduino.h>

// Declare a handle for the queue
QueueHandle_t xQueue;

void TaskSender();
void TaskReceiver();

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Create a queue capable of holding 10 integers
  xQueue = xQueueCreate(10, sizeof(int));

  if (xQueue != NULL) {
    // Create tasks to send and receive data
    xTaskCreate(TaskSender, "Sender Task", 1000, NULL, 1, NULL);
    xTaskCreate(TaskReceiver, "Receiver Task", 1000, NULL, 1, NULL);
  } else {
    Serial.println("Failed to create the queue");
  }
}

void loop() {
}

// Task that will send data to the queue
void TaskSender(void *pvParameters) {
  int dataToSend = 0;

  while (1) {
    // Send data to the queue
    if (xQueueSend(xQueue, &dataToSend, portMAX_DELAY)) {
      Serial.print("Sent data: ");
      Serial.println(dataToSend);
      dataToSend++;  // Increment the data
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Wait for 1 second
  }
}

// Task that will receive data from the queue
void TaskReceiver(void *pvParameters) {
  int receivedData;

  while (1) {
    // Receive data from the queue
    if (xQueueReceive(xQueue, &receivedData, portMAX_DELAY)) {
      Serial.print("Received data: ");
      Serial.println(receivedData);
    }
  }
}