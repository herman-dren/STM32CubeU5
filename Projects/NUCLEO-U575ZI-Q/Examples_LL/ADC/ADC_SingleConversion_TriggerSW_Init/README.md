## <b>ADC_SingleConversion_TriggerSW_Init Example Description</b>

How to use ADC to convert a single channel at each SW start, conversion performed using programming model: polling.
This example is based on the STM32U5xx ADC LL API.
The peripheral initialization is done using LL unitary service functions
for optimization purposes (performance and size).

Example configuration:

ADC is configured to convert a single channel, in single conversion mode, from SW trigger.

Example execution:

From the main program execution, a ADC software start is performed
every second, ADC group regular converts the selected channel.
Software polls for conversion completion.
When conversion is completed, program reads conversion data from ADC data register and stores it into a variable.

LED1 is used to monitor program execution status:

- Normal operation: ADC group regular activity can be observed with LED toggle:

- At each ADC conversion: LED toggle once (every 1sec)
- Error: LED remaining turned on

Debug: variables to monitor with debugger:

- "uhADCxConvertedData": ADC group regular buffer conversion data (resolution 12 bits)
- "uhADCxConvertedData_Voltage_mVolt": ADC group regular buffer conversion data computed to voltage value (unit: mV)

Connection needed:

Use an external power supply to generate a voltage in range [0V; 3.3V]
and connect it to analog input pin (cf pin below).
Note: If no power supply available, this pin can be let floating (in this case
      ADC conversion data will be undetermined).

Other peripherals used:

  1 GPIO for LED1
  1 GPIO for analog input: ADC channel 9 on pin PA.04 (Arduino connector CN7 pin 9 D20, Morpho connector CN11 pin 32)

### <b>Keywords</b>

ADC, analog digital converter, analog, conversion, voltage, channel, analog input

### <b>Directory contents</b>

  - ADC/ADC_SingleConversion_TriggerSW_Init/Inc/stm32u5xx_it.h          Interrupt handlers header file
  - ADC/ADC_SingleConversion_TriggerSW_Init/Inc/main.h                  Header for main.c module
  - ADC/ADC_SingleConversion_TriggerSW_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - ADC/ADC_SingleConversion_TriggerSW_Init/Src/stm32u5xx_it.c          Interrupt handlers
  - ADC/ADC_SingleConversion_TriggerSW_Init/Src/main.c                  Main program
  - ADC/ADC_SingleConversion_TriggerSW_Init/Src/system_stm32u5xx.c      STM32U5xx system source file

### <b>Hardware and Software environment</b>

  - This example runs on STM32U575xx devices.

  - This example has been tested with NUCLEO-U575ZI-Q board and can be
    easily tailored to any other supported device and development board.

### <b>How to use it ?</b>

In order to make the program work, you must do the following :

 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example
