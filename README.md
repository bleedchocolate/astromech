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
* You can also change the 02 to FF to make it only respond once. 
    
* My own droid broadcasts this: 0x030444819208 and it seems I can have it meet another droid by copying that and optionally changing the last 4. 

## Useful Resources

* [Vince Parker](https://www.youtube.com/watch?v=liKQ0LrN9q0&t=480s) sniffed all of the signal’s around the park and talked about how to recreate them using the nFR Connect app on an android device. 
* [Ruthsarian](https://www.youtube.com/channel/UCoaydZePyAJOQlCbkfDwHIQ) has many good videos about the droid and other Star Wars things in general. Notable Ones:
   * He added an LED to the Droid’s Head and explained how to head works. [Link](https://www.youtube.com/watch?v=A0AJl5ipgx0&t=600s) 
   * He added a power indicator LED to the droid’s remote control. [Link](https://www.youtube.com/watch?v=gonG7LuBkk0&t=369s) 
   * He created a custom personality chip for the droid:
      * [Part 0](https://www.youtube.com/watch?v=t2lm5inhGkM&t=745s)
      * [Part 1](https://www.youtube.com/watch?v=qy98ys3AuwQ)
      * [Part 1A - an edit](https://www.youtube.com/watch?v=9T1lsqVU0W4 )
      * [Part 2](https://www.youtube.com/watch?v=xRQRMBJe9Gg&t=1213s)
      * [Part 3 - R2 accessory noises/lights with custom chip](https://www.youtube.com/watch?v=SUpH8con-GQ)
* [Dead Bothans Society](https://www.deadbothans.com/category/droids/) has a section on the droids
   * [R2 Unit Teardown](https://www.deadbothans.com/2020/02/09/r2-unit-droid-teardown-video-photos/) 
   * [R2 Accessory Teardown](https://www.deadbothans.com/2019/09/16/droid-accessory-teardown/) 
