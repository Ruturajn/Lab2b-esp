# Lab2B Expansion Board Proposal

Following is the overview of the proposal for the expansion board,

### GIF / VIDEO of the LED Breadboard Circuit

https://user-images.githubusercontent.com/56625259/197113303-1fc282c5-d4c5-42aa-a6ec-4f7fd6d85651.mp4

<br>

<div align="center">

![LAB2B-ESP](https://user-images.githubusercontent.com/56625259/197111698-343c84d4-fd93-4c4e-ae10-cb961dcff87c.gif)

</div>

### Outline

The application is to light two different LEDs based on which character is sent to the **RP2040** (user input) using the *serial communication*. The **Qt Py RP2040** 
has `SCL1` and `SDA1` pins connected to `GPIO23` and `GPIO22` respectively, as seen from the Adafruit's documentation on the QTPy below (link to [documentation](https://learn.adafruit.com/adafruit-qt-py-2040/pinouts)),

<div align="center">

![image](https://user-images.githubusercontent.com/56625259/197115556-33657e7e-3034-4e4f-be93-bc57ae4e4304.png)

</div>

So, we will be using those `GPIO` pins to control our LEDs based on user input. 
- We initialize the both `GPIO22` and `GPIO23` as output pins using the `gpio_init()`, and the `gpio_set_dir()` functions. 
- Once the `GPIO` pins have been intialized, we can move on to the logic that decides which LED will glow. For that, the user's input is read using the 
`getchar_timeout_us(5000)` function, which returns a character from `stdin` if avaialable, within the timeout. 
- If the user presses `c`, the green LED lights up, and `GREEN SHOULD BE ON` is printed to serial out. Similarly if the user presses `d`, the blue LED lights up and 
`BLUE SHOULD BE ON` is printed to serial out. This can be seen from the demo above. 
- For driving the LEDs, the `GPIO` pins need to driven to a high or low state, this is achieved using the `gpio_put()` function.

This can be extended to be used as a password authenticator in lockers, where you are granted access whenever the right password is entered.

### Components Used

- Red LED
- Green LED
- STEMMA QT Cable
- Adafruit QTPy : RP2040
- 1k ohm and 100 ohm resistors
- Breadboard
