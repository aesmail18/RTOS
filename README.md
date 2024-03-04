# RTOS : Simple OS for LED Toggling
Welcome to the Simple OS project! This is a basic operating system designed for microcontrollers that allows you to toggle LEDs using different tasks. This README will guide you through setting up the project, understanding its structure, and running the example tasks.

#Table of Contents
1- Introduction
2- Usage
3- Tasks
4- Contributing

#Introduction
Simple OS is a lightweight operating system framework for microcontrollers, specifically designed to manage tasks efficiently. The primary purpose of this OS is to demonstrate multitasking capabilities on resource-constrained devices.

This project comes with 8 example tasks, each responsible for toggling a LED connected to the microcontroller. These tasks are designed to run concurrently, demonstrating how multitasking works in an embedded environment.

#Usage
After setting up the project, you can upload the compiled binary to your microcontroller. Upon booting, the Simple OS scheduler will start executing the example tasks.

Make sure to connect LEDs to the GPIO pins of your microcontroller as per the task configurations.

#Tasks
The Simple OS project comes with 8 example tasks, each toggling a LED:

Task 1: Toggle LED 1
Task 2: Toggle LED 2
Task 3: Toggle LED 3
Task 4: Toggle LED 4
Task 5: Toggle LED 5
Task 6: Toggle LED 6
Task 7: Toggle LED 7
Task 8: Toggle LED 8
Each task is implemented as a separate thread and demonstrates concurrent execution.

#Contributing
Contributions to the Simple OS project are welcome! If you have any ideas for improvements or new features, feel free to fork the repository, make your changes, and submit a pull request.

When contributing, please follow the existing code style and ensure that your changes are well-documented.
