Spot welder controller

I used a basic arduino nano and a relay to turn on and off a MOT (Microwave Oven Transformer) Whoms secondary winding has been modified with 3 turns of the thickest cable I could find so that it outputs around 3V AC and around 900A.

While powering the arduino nano, make sure to power it externally with a 5V input. Do not power it through the USB C port otherwise it will for some reason output only 4,5V on the 5V output which is not enough to trigger the relay.

WIRING:
5V source to VIN and GND
NO button to D8 and GND
Relay IN(trigger) to D2
Relay 5V to 5V source (NOT 5V OUTPUT ON ARDUINO)
Relay GND to any GND
AC power one N to MOT
AC power L to COM on relay
AC power G to body of MOT
Relay NO to MOT

![PXL_20240620_205230258](https://github.com/MatessakCZE/Spot-welder-controller/assets/77834293/a21a3744-7ba9-4d90-b2d5-6eb61cba3ae1)
