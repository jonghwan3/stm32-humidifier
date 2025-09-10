## stm32-humidity-controller (STM32F4)
Closed-loop humidifier controller: lets a user set a target RH and automatically toggles the humidifier to keep RH within a ±3% hysteresis band around that target.

### What is does
- Shows target and live RH on a 128×64 SSD1306 OLED (I²C).
- Lets the user adjust target RH via pull-up GPIO buttons (debounced).
- Reads humidity from an SHT31-D sensor over I²C.
- “Presses” the humidifier’s front-panel button using a 4N25 optocoupler (GPIO-driven), preserving electrical isolation.

### Demo
https://github.com/user-attachments/assets/c23da429-ac59-43c4-85e8-08c5b49aa72a

### Next steps:
- Refactor to FreeRTOS: split into tasks (SensorRead, ControlLoop, UI/OLED, Input) with queues/semaphores; add watchdog. 
