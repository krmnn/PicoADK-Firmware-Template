# PicoADK - Audio Development Kit Firmware

![PicoADK_Top](https://user-images.githubusercontent.com/6614616/204331473-485c4a37-0c32-4387-92df-22c15a2e22aa.jpg)

Photos courtesy of Paul D. Pape - derwellenreiter for schneidersladen, Berlin, Germany. 

This boilerplate template allows you to create standalone synthesizers, noise boxes, sample players, ..

## Repository structure
* C code is located in the src folder and contains all the low-level funtionality for the firmware incl. USB MIDI handling and dealing with the Audio DAC.
* Includes for the C code are located in the include folder.
* The Vult DSP code is located in the vultsrc folder.
* The includes for Vult are located in lib/vult/examples. These provide some oscillator, filter and envelope implementation along others.

## Prerequisites

1. Install the [Vult](https://github.com/vult-dsp/vult/) compiler: `sudo npm install vult -g`
2. Install the compiler toolchain:
    - *MacOS:* `brew install armmbed/formulae/arm-none-eabi-gcc cmake`

## Compiling the firmware 
```bash
git clone --recursive https://github.com/DatanoiseTV/PicoADK-FreeRTOS-Template picoadk-template
cd picoadk-template
export PICO_SDK_FETCH_FROM_GIT=1
mkdir build && cd build
cmake ..
make
```
Now you can find a `main.uf2` in the build folder, which is your firmware.

## Copying the Firmware to the PicoADK

Plug in the PicoADK USB Type-C while holding the **BOOT** button **or** hold **BOOT** and press the reset button quickly.
After that, a **RPI-RP2** disk volume will appear. Simply drag and drop the UF2 file to this drive and the PicoADK will
reboot after a moment, the drive will disappear and your firmware will be running.

## More information

Please check the [Pico Getting Started Guide](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf) on how to install the toolchain and required libraries for your OS.

# Hardware

The way-to-go hardware option is the [PicoADK](https://github.com/DatanoiseTV/PicoADK-Hardware)

# Getting RAM and flash usage statistics

![image](https://user-images.githubusercontent.com/6614616/203217505-7b235539-9cc0-42c1-a4ca-f910ef306fb1.png)

Your statically allocated memory and flash usage will be reported upon linking.

## Community

You can find the PicoADK at Discord right [here](https://discord.gg/BsHUEdStMt) and a community discussion board on [GitHub Discussions](https://github.com/DatanoiseTV/PicoADK-Hardware/discussions)
