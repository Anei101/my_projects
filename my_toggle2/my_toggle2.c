#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"

#define 	RED_MASK 		  0x02
#define 	BLUE_MASK 		0x04
#define 	GREEN_MASK 		0x08
//*****************************************************************************
//
//!
//! A very simple example that toggles the 3 on-board LEDs using direct register
//! access.
//
//*****************************************************************************


void
PortFunctionInit(void)
{
//
		volatile uint32_t ui32Loop;   
	// Enable the GPIO port that is used for the on-board LED.
    //
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    //
    // Do a dummy read to insert a few cycles after enabling the peripheral.
    //
    ui32Loop = SYSCTL_RCGC2_R;

    //
    // Enable the GPIO pin for the red LED (PF1).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIO_PORTF_DIR_R |= 0x02;
    GPIO_PORTF_DEN_R |= 0x02;

    //
    // Enable the GPIO pin for the blue LED (PF2).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIO_PORTF_DIR_R |= 0x04;
    GPIO_PORTF_DEN_R |= 0x04;	

    //
    // Enable the GPIO pin for the green LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIO_PORTF_DIR_R |= 0x08;
    GPIO_PORTF_DEN_R |= 0x08;
}


int main(void)
{
	
		//initialize the GPIO ports	
		PortFunctionInit();
		
    //
    // Loop forever.
    //
    while(1)
    {
        // Delay for a bit.
				SysCtlDelay(2000000);	
			
				// Turn on the Blue and Green LEDs.
				GPIO_PORTF_DATA_R |= 0x0C;
			
        // Delay for a bit.
				SysCtlDelay(2000000);	

        // Toggle the LED.
        GPIO_PORTF_DATA_R ^=0x0C;
			
        // Delay for a bit.
				SysCtlDelay(2000000);	

        // Turn on the Green and Red LED.
        GPIO_PORTF_DATA_R |=0x0A;
			
        // Delay for a bit.
				SysCtlDelay(2000000);	

        // Toggle the LED.
        GPIO_PORTF_DATA_R ^=0x0A;
        // Delay for a bit.
				SysCtlDelay(2000000);	

        // Turn on the Blue and Red LED.
        GPIO_PORTF_DATA_R |=0x06;
			
        // Delay for a bit.
				SysCtlDelay(2000000);	

        // Toggle the LED.
        GPIO_PORTF_DATA_R ^=0x06;
				
    }
}
