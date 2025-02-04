#include "picoadk_hw.h"

void picoadk_init()
{
        // Overclock the CPU to 226 MHz.
        // We choose 226 MHz, because it works the best for the audio subsystem.
        vreg_set_voltage(VREG_VOLTAGE_1_30);
        sleep_ms(1);
        set_sys_clock_khz(226000, true);

        // Initialize TinyUSB
        board_init();
        tusb_init();
        stdio_init_all();

        // set gpio 25 (soft mute) to output and set to 1 (unmute)
        gpio_init(25);
        gpio_set_dir(25, GPIO_OUT);
        gpio_put(25, 1);

        // set gpio 23 (deemphasis) to output and set to 1 (enable)
        gpio_init(23);
        gpio_set_dir(23, GPIO_OUT);
        gpio_put(23, 1);

        // LED on GPIO15
        gpio_init(15);
        gpio_set_dir(15, GPIO_OUT);

        adc_init();

        // Make sure GPIO is high-impedance, no pullups etc
        adc_gpio_init(26);
        // Select ADC input 0 (GPIO26)
        adc_select_input(0);

        srand(adc_read());

        uint32_t rand_seed;
        for (int i = 0; i < 32; i++)
        {
                bool randomBit = rosc_hw->randombit;
                rand_seed = rand_seed | (randomBit << i);
        }

        srand(rand_seed);

        gpio_set_function(10, GPIO_FUNC_SPI);
        gpio_set_function(11, GPIO_FUNC_SPI);
        gpio_set_function(12, GPIO_FUNC_SPI);
        gpio_init(13);
        gpio_set_dir(13, GPIO_OUT);
        gpio_put(13, 1);

        spi_init(spi1, 16000000);
        spi_set_format(spi1, 8, SPI_CPOL_0, SPI_CPHA_0, SPI_MSB_FIRST);
        spi_set_slave(spi1, false);
}

int adc128_read(uint8_t chan)
{
        if (chan > 7)
                return 0;
        gpio_put(13, 0);
        uint8_t data[2] = {(chan << 3), 0};
        uint8_t rxData[2];
        spi_write_read_blocking(spi1, data, rxData, 2);
        gpio_put(13, 1);
        uint16_t result = (rxData[0] << 8) | rxData[1];

        return result;
}
