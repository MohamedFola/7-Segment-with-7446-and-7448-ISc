/*
--> 7seg with 7446/7448 ICs.c
--> Author : Mohamed Hassan Fola


      --------------------------
     |             A            |
     |	        -------         |
0 <--|A	      ||       ||       |
1 <--|B     F ||       || B     |
2 <--|C       ||   G   ||       |
3 <--|D		-------         |
4 <--|E       ||       ||       |
5 <--|F	    E ||       || C     |
6 <--|G       ||       ||       |
7 <--|DP        -------	        |
     |             D            |
      --------------------------
	  

--> using 7446 IC on proteus for common anode seven segment display which is BCD to 7 segment decoder
--> using 7448 IC on proteus for common cathode seven segment display which is BCD to 7 segment decoder

--> 7446 IC pin out 
    ------------------
1--| B            VCC |--16
2--| C             ~f |--15
3--|~LT            ~g |--14
4--|~(BI/RBO)      ~a |--13
5--|~RBI           ~b |--12
6--| D             ~c |--11
7--| A             ~d |--10
8--| GND           ~e |--9
    ------------------
	
--> 7448 IC pin out
    ------------------
1--| B            VCC |--16
2--| C              f |--15
3--|~LT             g |--14
4--|~(BI/RBO)       a |--13
5--|~RBI            b |--12
6--| D              c |--11
7--| A              d |--10
8--| GND            e |--9
    ------------------
	
Binary    ---> Equivelant Decimal
D C B A
0 0 0 0   ---> 0
0 0 0 1   ---> 1
0 0 1 0   ---> 2
0 0 1 1   ---> 3
0 1 0 0   ---> 4
0 1 0 1   ---> 5
0 1 1 0   ---> 6
0 1 1 1   ---> 7
1 0 0 0   ---> 8 
1 0 0 1   ---> 9

*/

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define SSD_CC_Direction DDRD
#define SSD_CC_Port      PORTD

#define SSD_CA_Direction DDRC
#define SSD_CA_Port      PORTC

int main(void)
{
	int counter = 0;
    uint8_t SSD_CC_CA[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		
	// set the first 4 pins of port C & D as output
	SSD_CC_Direction = 0x0F;
	SSD_CA_Direction = 0x0F;
	
    while (1) 
    {
		SSD_CC_Port = SSD_CC_CA[counter];
		SSD_CA_Port = SSD_CC_CA[counter];
		if (++counter > 9) counter = 0;
		_delay_ms(1000);
    }
}

