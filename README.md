# Astromech

So I recently went to Disney's Star Wars: Galaxy's Edge park and built my own custom astromech unit at the Droid Depot. The park let's you build either a BB-Series or R-Series droid. Based on which you pick, you get a parts list. You then get to pick one of each of those parts from a moving conveyor belt of pieces. They have different colors of each piece. You then assemble the droid, pair it with a controller, and take it home!

I built a BB-Series one. The droid is controllable: it can move foward, backward, turn, and make noise / light up. It also reacts to things around the park by picking up Bluetooth signals. You can also buy different personality chips to insert into it - which replace the different sounds that it makes. 

I *REALLY* want to hack the controller. I would love to be able to control it via my phone or even add simple sensors to it to make it somewhat autonomous. Unfortunately, hacking the controller isn't seeming that simple... But I figured I'd compile any notes I gather about the droid here. 

------

Using the nRF Connect Android app, I was able to see that:
* My droid’s bluetooth address is: C4:CE:B2:2D:DC:99
* It is advertising multiple services:
    * Generic Access 0x1800
        * Characteristics:
            * Device Name (READ, WRITE) — 0x2A00
            * Appearance (READ) — 0x2A01
            * Peripheral Preferred Connection Parameters (READ) — 0x2A04
    * Generic Attribute 0x1801
        * empty
    * Unknown Service 09b600a0-3e42-41fc-b474-e9c0c8f0c801
        * Characteristics:
            * Unknown Characteristic
                * 09b600b0-3e42-41fc-b474-e9c0c8f0c801 (NOTIFY)
            * Client Characteristic Configuration
                * 0x2902
            * Unknown Characteristic: 
                * 09b600b1-3e42-41fc-b474-e9c0c8f0c801 (WRITE, WRITE NO RESPONSE)

* Disney’s Manufacturer Data: 0x0183
* Data for Reaction Beacons:
    * 0x0A040102A601 
    * 0x0A040202A601 
    * 0x0A040302A601 
    * 0x0A040402A601 
    * 0x0A040502A601
    * 0x0A040602A601  
    * 0x0A040702A601 
