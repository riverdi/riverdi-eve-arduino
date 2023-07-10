OVERVIEW
--------
![alt text](http://circuitcellar.com/wp-content/uploads/2016/10/FTDI-Img.png "riverdi-logo")

*riverdi-eve-arduino* is an easy-to-use library and example Arduino app (good starting poiny for you own projects) for [*Riverdi Intelligent Display*](https://riverdi.com/product-category/intelligent-displays/bt817q/) driven by [*Bridgetek EVE graphics controllers*](http://brtchip.com/eve/):

- __EVE 1__ series: FT800 and FT801,
- __EVE 2__ series: FT810, FT811, FT812 and FT813,
- __EVE 3__ series: BT815 and BT816,
- __EVE 4__ series: BT817 and BT818

Library supports instructions in a similar format to the [*FT80x and FT81x Series Programmers Guides*](https://brtchip.com/wp-content/uploads/Support/Documentation/Programming_Guides/ICs/EVE/FT81X_Series_Programmer_Guide.pdf), [*BT81X Series Programming Guide*](https://brtchip.com/wp-content/uploads/2022/12/BRT_AN_033_BT81X-Series-Programming-Guide.pdf) and the [*EVE Screen Editor*](https://brtchip.com/ese-2/).

__Note:__ *a pure C version of library is available as a separate GitHub repository - [*riverdi-eve-lib*](https://github.com/riverdi/riverdi-eve-lib)*

LIBRARY ARCHITECTURE
--------------------

#### Example App

The *riverdi-eve-arduino.ino* file can be edited to produce the final application, calling the functions from the underlying layers.

#### API Layer

This layer is designed to allow the main application to use syntax close to that of the *FT80X/FT81X Programmers Guide* and make it more user friendly. The functions provided in this layer handle co-processor operation and assist with creating and executing co-processor lists as well as keeping track of the offset within the FIFO for each command and sending parameters of commands such as text strings.

#### EVE Layer / Host Layer

This layer translates the calls from the API layer above into a series of SPI byte transfers formatted for the protocol used by the FT8XX. It includes a series of functions which send the register address as well as for reading and writing 8/16/32-bit values. It also has functions for checking the read and write pointers of the RAM_CMD FIFO and for checking the free space available, which are used by the layers above. This layer provides also an interface to the hardware. It takes the SPI transfers from the EVE layer and translates them into the low-level operations (SPI and GPIO operations for chip select and power down).

COMPILING LIBRARY
-----------------

1. Clone the repository (if you haven't done so already):
```
git clone https://github.com/riverdi/riverdi-eve-arduino.git
```
2. Download and install the Arduino IDE from http://www.arduino.cc/en/Main/Software
3. Start the Arduino IDE
4. File > Open > select the *riverdi-eve-arduino.ino* file
5. Build (Ctrl+R) and upload (Ctrl+U) project to your Arduino Device.

__Note:__ *before compilation please edit Platform.h file to choose Embedded Video Engine series (-DEVE_1, -DEVE_2, -DEVE_3 or -DEVE_4 flags), choose type and size of connected TFT module (choose predefined macros for Riverdi EVE modules or edit timings manually in Riverdi_Modules.h file for custom displays) or to redefine Chip Select and Power Down pins (default configuration supports [*Arduino Riverdi TFT Shield*](https://riverdi.com/product/arduino-riverdi-tft-shield/)).*

GETTING HELP
------------

Please contact Riverdi support - [*<contact@riverdi.com>*](contact@riverdi.com)

LICENSE
-------

See *LICENSE.txt* file for details.
