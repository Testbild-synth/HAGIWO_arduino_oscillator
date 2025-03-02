# HAGIWO 019/022/023 Triple Oscillator (FM/CHORD/ADDITIVE)
<img src="images/in_rack.jpg" width="40%" height="40%">
4HP through hole version of the HAGIWO FM/additive/chord oscillator with mode switch and gain input.

This module is basically my PCB version of the HAGIWO osc, heavily inspired by [luis lutz version](https://github.com/luislutz/Arduino-VDCO).
The main difference is since I could not get his code to work without major audio problems, I rewrote the entire thing myself.

The module combines three different oscillators from HAGIWO,  with a mode switch (and mode cv input) to switch between them.
Additionally, it has a gain input that normals so that it is only used when you plug in a jack.

### STATUS: Revision 1.1 PCB with slight modifications to make the build easier.

## Hardware and PCB
<img src="images/panel.JPG" width="10%" height="10%"><img src="images/front_pcb.JPG" width="12%" height="12%"><img src="images/main_pcb.JPG" width="13%" height="13%">

You can find the schematic and BOM in the root folder.
For the potentiometers, any value between 10k and 100k should be fine.

The module has three PCBs: a panel PCB, a main PCB and a controls pcb.
You can order them on any common PCB manufacturing service, I used JLCPCB. For the circuit PCBs, standard settings should be fine.
For the panel, since it has copper exposed, make sure to choose a lead free surface finish (LeadFree HASL, ENIG) and/or spraypaint your panels so that you don't get lead on your hands.

Assembly is pretty straight forward. Since it is so crowded, make sure to do the resistors first before the headers so you have more space to work.

Also make sure to put the headers connecting both PCBs in the correct direction so that the arduino faces to the back.

The only thing there is to tune is a trimpot that sets output gain (as arduino is 0-5V output and I wanted to be able to make mine louder). Tune it to your liking.

<img src="images/both_parts.jpg" width="40%" height="40%">
<img src="images/side.jpg" width="40%" height="40%">

## Build

Most of the build is relatively straight forward. be sure to actually have fitting values for the resistors that need to be precise. These are indicated with % on the board and in the bom.      
One thing to watch out for is that due to size constraints I oriented one row of thonkiconn jacks to face another one and have the grounds go into the same hole.
So top two rows face each other, ground legs go into the same hole.


