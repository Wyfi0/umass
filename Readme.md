# Hello!!!
### This is my repo for my 2 week program at umass amherst

## Documentation for my multimeter project

### My final code is in the "oled" folder :)

For this project I knew I needed to use the analog pins on the Arduino to detect the voltage and I also wanted to use an oled display to display the voltage. I also knew I wanted a way for the user to choose the mode, similar to other multimeters. To do this I ended up using a potentiometer.

When I did research on this project I couldnt find anything similar that used the Arduino UNO, but I did see simple projects that either just tested continuity or just measured voltage. 

To start brainstorming, I just started messing around with using an led to show when a circuit was completed to show continuity. I also set up a digital input pin to read the circuit also.

For my plan in the code I knew I wanted to use a switch statement that takes in a mode variable to draw the frames differently depending on the mode. You can see this in the code from the really nice comments I wrote.

An issue I ran into when trying to use a button to change modes (continuity / voltage). I ended up switching to using a potentiometer instead, using a digital input to make the analog output fall into eihter high or low.

The prototype I made is pretty messy wiring wise, but is functional in the way I intended. Honestly it's not what I imagined, but what I imagined was out of the scope of 2 weeks.

If I were to continue this project, I would add more functionality, like measuring amps and the resistance of resistors, I would also try using different microcontrollers like the rp2040 and esp32 to see how they function differently. Also I would design a case for it to all fit in.
