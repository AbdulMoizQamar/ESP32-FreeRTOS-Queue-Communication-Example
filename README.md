# ESP32-FreeRTOS-Queue-Communication-Example
This project demonstrates inter-task communication using FreeRTOS queues on an ESP32 with the Arduino framework.
📝 Description:
This project demonstrates inter-task communication using FreeRTOS queues on an ESP32 with the Arduino framework. It includes two tasks:
TaskSender: Periodically sends integer values to a FreeRTOS queue.
TaskReceiver: Receives those values and prints them to the Serial Monitor.
This example helps you understand how FreeRTOS queues can be used to pass data safely between concurrent tasks in real-time embedded systems.

✅ Features:
FreeRTOS queue communication between tasks
Periodic data production and consumption
Use of xQueueSend() and xQueueReceive()
Compatible with ESP32 and Arduino IDE

📦 Requirements:
ESP32 development board
Arduino IDE or PlatformIO
FreeRTOS (bundled with ESP32 Arduino core)
