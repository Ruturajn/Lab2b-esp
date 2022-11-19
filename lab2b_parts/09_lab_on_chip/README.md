# LAB ON CHIP

The following demonstration video shows color data acquired from the `APDS9960` sensor, which is sent to the `neopixel` LED, based on highest component of
red, green and blue.


https://user-images.githubusercontent.com/56625259/202836148-9da617ec-794e-4934-8334-598d093804b5.mp4


- The process for implementing this part was very similar to part [`08_apds_protocol`](https://github.com/Ruturajn/Lab2b-esp/tree/main/lab2b_parts/08_apds_protocol).
- Once the raw data was acquired from the `APDS9960` it was processed, and converted into a `24` bit color packet.
- This packet was created based on the highest component among the `red`, `green` and the `blue` channel.
- In this implementation `2` state machines were used, one of them was to interface the `APDS9960` sensor and the other one was used to drive the `neopixel` LED.
