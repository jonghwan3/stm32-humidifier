## stm32-humidifier
Embedded humidity controller: set target humidity, measure current value, and switch humidifier on/off to maintain the target.

### Current progress: 
- Communicate with SSD1306 OLED (128×64, I²C) display.
- Control target humidity using GPIO switches (pull-up).

https://github.com/user-attachments/assets/6c7bf53c-c079-41cc-9ded-4e9018d1ed94

### Future plans:
- Communicate with humidity sensor (SHT31-D, I²C)
- Add relay switch (SRD-05VDC-SL-C) to control humidifier (on/off)
