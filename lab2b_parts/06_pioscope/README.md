# PIOSCOPE

The demonstration video below shows the I2C trace captured on PuTTY.

https://user-images.githubusercontent.com/56625259/202349881-a7d310e9-fcde-42be-bf1e-794808edc22e.mp4

- The `logic_analyser` example from `pico-examples` was adapted to capture an I2C trace whenever the `BOOT` button was pressed.
- The capture included both the `SCL` and `SDA` pins.
- Two separate boards were utilized to display the capture on PuTTY. The first board was running the adapted code from `logic_analyser` and the other board (RP2040)
  runs the code that interfaces APDS9960 with the QtPy using micropython.
