#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "pio_i2c.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

#include "registers.h"
#include "adps_registers.h"
#include "/home/ruturajn/Git-Repos/pico/pico-sdk/src/boards/include/boards/adafruit_qtpy_rp2040.h"

#define PIN_SDA 22
#define PIN_SCL 23

bool reserved_addr(uint8_t addr) {
    return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}

void config_adps(PIO pio, uint sm){
    // Power ON the ADPS
    // The register address for the slave needs to be
    // prepended to the data.
    uint8_t txbuf[2] = {0};
    txbuf[0] = ADPS_ENABLE_REGISTER;
    txbuf[1] = ADPS_ENABLE_PON;
    pio_i2c_write_blocking(pio, sm, ADPS_ADDRESS, txbuf, 2);

    // Config the Cotrol Register.
    txbuf[0] = ADPS_CONTROL_ONE_REGISTER;
    txbuf[1] = ADPS_CONTROL_ONE_LDRIVE | ADPS_CONTROL_ONE_PGAIN | ADPS_CONTROL_ONE_AGAIN;
    pio_i2c_write_blocking(pio, sm, ADPS_ADDRESS, txbuf, 2);

    // Enable Ambient Light and Proximity Sensor
    txbuf[0] = ADPS_ENABLE_REGISTER;
    txbuf[1] = ADPS_ENABLE_AEN | ADPS_ENABLE_PEN;
    pio_i2c_write_blocking(pio, sm, ADPS_ADDRESS, txbuf, 2);
}

void adps_read(PIO pio, uint sm, uint8_t reg_addr, uint8_t *rxbuf, uint num_bytes) {
    // Read from `reg_addr`.
    pio_i2c_write_blocking(pio, sm, ADPS_ADDRESS, &reg_addr, 1);  
    pio_i2c_read_blocking(pio, sm, ADPS_ADDRESS, rxbuf, num_bytes);
}

int main() {
    stdio_init_all();

    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &i2c_program);
    i2c_program_init(pio, sm, offset, PIN_SDA, PIN_SCL);
    
    // Wait until USB is connected.
    while(!stdio_usb_connected());

    printf("Starting PIO I2C ADPS9960 Interface\n");
    
    // Start I2C commuinication.
    pio_i2c_start(pio, sm);

    // Configure the ADPS Sensor.
    config_adps(pio, sm);

    while(1) {
        
        // Check the status register, to know if we can read the values
        // from the ALS and Proximity engine.
        uint8_t rxbuf[1] = {0};
        adps_read(pio, sm, STATUS_REGISTER, rxbuf, 1);
        printf("The value in RX Buffer is : 0x%08x\n", rxbuf[0]);

        // Use the mask to check if our Proximity and color data is ready to be read.
        uint8_t data_arr[8] = {0};
        if ((rxbuf[0] & STATUS_REGISTER_PVALID) == STATUS_REGISTER_PVALID) {
            adps_read(pio, sm, PROXIMITY_DATA_REGISTER, data_arr, 1);
            printf("The Proximity Data : %d\n", data_arr[0]);
        } if ((rxbuf[0] & STATUS_REGISTER_AVALID) == STATUS_REGISTER_AVALID) {
            adps_read(pio, sm, RGBC_DATA_REGISTER_CDATAL, data_arr, 8);
            /* adps_read(pio, sm, RGBC_DATA_REGISTER_CDATAH, &data_arr[1], 1); */
            /* adps_read(pio, sm, RGBC_DATA_REGISTER_RDATAL, &data_arr[2], 1); */
            /* adps_read(pio, sm, RGBC_DATA_REGISTER_RDATAH, &data_arr[3], 1); */
            /* adps_read(pio, sm, RGBC_DATA_REGISTER_GDATAL, &data_arr[4], 1); */
            /* adps_read(pio, sm, RGBC_DATA_REGISTER_GDATAH, &data_arr[5], 1); */
            /* adps_read(pio, sm, RGBC_DATA_REGISTER_BDATAL, &data_arr[6], 1); */
            /* adps_read(pio, sm, RGBC_DATA_REGISTER_BDATAH, &data_arr[7], 1); */
            printf("The Color Data : %d\n", data_arr[1]);
        }

        sleep_ms(500); 
    }
 
    /* printf("\nPIO I2C Bus Scan\n"); */
    /* printf("   0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n"); */

    /* for (int addr = 0; addr < (1 << 7); ++addr) { */
    /*     if (addr % 16 == 0) { */
    /*         printf("%02x ", addr); */
    /*     } */
    /*     // Perform a 0-byte read from the probe address. The read function */
    /*     // returns a negative result NAK'd any time other than the last data */
    /*     // byte. Skip over reserved addresses. */
    /*     int result; */
    /*     if (reserved_addr(addr)) */
    /*         result = -1; */
    /*     else */
    /*         result = pio_i2c_read_blocking(pio, sm, addr, NULL, 0); */

    /*     printf(result < 0 ? "." : "@"); */
    /*     printf(addr % 16 == 15 ? "\n" : "  "); */
    /* } */
    /* printf("Done.\n"); */

    return 0;
}
