	#Lab 3 for Comp Arch

	##Introduction to he project

	This was a lab project for my CS 3432 class. The goal is to create a toy that
	contains moving objects, buzzer, switches, timer, custom shapes, and states.

	 #Requirements:
	 -VM to run code
	 -MSP430

	#Compiling and Running
	In order to compile and execute my lab you must insert these
	instructions into
	your VM and have the MSP430 plugged into your VM. There are 2 load options you
	may choose either one.

1. cd p3-lcd-lab-EAguil22
2. make
3. cd project
4. make load_c
4. make load_s

   #NOTES
   1. The assembly function of stateSelection_s.s does not work as intended as it
      doesn't compile when calling switch_interrupt_handler and doesn't make the
      buzzer play and after count is >= 25 goes to the lose state instead of the
      win state
   2. The switches don't work as intended and will breifly do the switch case
      and then resetting the game
	 
