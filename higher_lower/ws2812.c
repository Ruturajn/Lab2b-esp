#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"

#include "/home/ruturajn/Git-Repos/pico/pico-sdk/src/boards/include/boards/adafruit_qtpy_rp2040.h"

#define LED_PIN_NUM_1 5 // BLUE
#define LED_PIN_NUM_2 6 // YELlOW

#define CONST_MULT 4
#define CONST_ADD 3
#define CONST_MOD 10
#define NUM_ITERATIONS 5

// function to define a random number
int linear_congruential(int seed, int count){
    for (int i=0;i<count;i++){
        seed = (CONST_MULT * seed + CONST_ADD) % CONST_MOD;
    }
    return seed;
}

int main() {
    gpio_init(LED_PIN_NUM_1);
    gpio_init(LED_PIN_NUM_2);
    gpio_set_dir(LED_PIN_NUM_1, GPIO_OUT);
    gpio_set_dir(LED_PIN_NUM_2, GPIO_OUT);
    stdio_init_all();

    char user_seed, user_inp;
    int flag = 0, rand_num = 0;

    while(!stdio_usb_connected());
    
    
    while(1){
        if (flag == 0){
            sleep_ms(10000);
            printf("Enter a seed between 1-10 for generating a random number:");
            sleep_ms(5000);
            while((user_seed = getchar_timeout_us(0)) < 0);
            user_seed = user_seed - 48;
            printf("This is your seed: %d\n", (int)user_seed);
            rand_num = linear_congruential((int)user_seed, NUM_ITERATIONS);
            printf("Your random number is generated which lies between 1 to 10!!\n\n");
            flag = 1;
        }
        printf("Enter your guess:\n");
        while ((user_inp = getchar_timeout_us(0)) < 0);
        sleep_ms(100);
        user_inp = user_inp - 48;
        /* printf("%d", rand_num); */
        if (user_inp != 207){
            printf("This is your number:%d\n", (int)user_inp);
            if ((int)user_inp < rand_num){
                gpio_put(LED_PIN_NUM_1, 1);
                printf("Think Higher!!\n");
                sleep_ms(500);
                gpio_put(LED_PIN_NUM_1, 0);
            }if ((int)user_inp > rand_num){
                gpio_put(LED_PIN_NUM_1, 1);
                printf("Think Lower!!\n");
                sleep_ms(500);
                gpio_put(LED_PIN_NUM_1, 0);
            }if ((int)user_inp == rand_num){
                gpio_put(LED_PIN_NUM_2, 1);
                printf("Woohoo!!!! That's great you won!!\n");
                sleep_ms(500);
                gpio_put(LED_PIN_NUM_2, 0);
                break;
            }
        }

        sleep_ms(500);
    }
    return 0;
}
