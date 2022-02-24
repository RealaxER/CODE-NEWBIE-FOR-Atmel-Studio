#ifndef F_CPU					// if F_CPU was not defined in Project -> Properties // ?? nó không hi?n c?nh báo
#define F_CPU 1000000UL			// define it now as 1 MHz unsigned long // khai báo t?n s? th?ch anh
#endif

#include <avr/io.h>				// this is always included in AVR programs // th? vi?n c?a ch??ng trình chsinh
#include <util/delay.h>
#include <avr/sfr_defs.h>
#define cbi(port,bit) (port) &= ~(1<<(bit))
#define sbi(port,bit) (port) |= (1<<bit)
#define tbi(port,bit) (port) ^= (1<<bit)

///////////////////////////////////////////////////////////////////////////////////////////////////
int main(void) {
	
	DDRC |= (1 << PC5);			// set Port C pin PC5 for output // ở đây ta xét chân 5 và tên chân của nó là PC5 là out tức là 1 
	
	while (1) {					// begin infinite loop
		PORTC ^= (1 << PC5);	// flip state of LED on PC5 // cái này là đảo trạng thái cho bit nếu là 1 thì về 0 nếu là 0 thì là 1
		_delay_ms(500);			// delay 1/2 second
	}
	return(0);					// should never get here, this is to prevent a compiler warning
}
