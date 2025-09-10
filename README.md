## stm32-humidity-controller (STM32F4)
Closed-loop humidifier controller: lets a user set a target RH and automatically toggles the humidifier to keep RH within a ±3% hysteresis band around that target.

### What it does
- Shows target and live humidity on a 128×64 SSD1306 OLED (I²C).
- Lets the user adjust target RH via pull-up GPIO buttons (debounced).
- Reads humidity from an SHT31-D sensor over I²C.
- Controls the humidifier by simulating a front-panel button press through a 4N25 optocoupler (GPIO-driven), ensuring electrical isolation.

### Demo
https://github.com/user-attachments/assets/c23da429-ac59-43c4-85e8-08c5b49aa72a

### Design decisions
- Optocoupler (4N25): Provides galvanic isolation between the STM32 (3.3 V logic) and the humidifier’s circuit, protecting the MCU from voltage spikes or unknown transients.
- ±3% hysteresis band: Prevents rapid toggling near the setpoint, reducing actuator stress and ensuring stable humidity control.
- Pull-up buttons with time-delayed debouncing: Pull-ups prevent floating inputs, while a time-based debounce filter avoids multiple counts from a single press. 

### Next steps:
- FreeRTOS refactor (tasks, queues, watchdog). 
