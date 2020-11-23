# KEngine
KEngine is a simple (and bad) library based on SFML which provides you some classes and functions that can make it easier for you to create bigger projects

QUICK INSTRUCTION HOW TO LINK THIS THING

C++ version: Standard ISO C++17 (but C++14 will be OK too)

Everything king works basically the same as in SFML, but there's
less things to worry about. First, link KEngine include
folder in the same place as SFML include. Then, do exacly
the same with lib file. Now you have to add .lib files
exactly where you were adding sfml-graphics-d.lib,
sfml-audio-d.lib et  -  KEngine-d.lib (debug) and
KEngine.lib (relase). after this, the only thing you have to
do is to include
 * #include <KEngine/Graphics.hpp> for Gui
 * #include <KEngine/Algorithms.hpp> for algorhitms
 * #include <KEngine/Graphics.hpp> for audio

If you're using Graphics, remember to call

ke::GuiObject::Init();

to initialize fonts.

if something goes wrong... you have to drink a lot of
coffee and not sleep for two nights, because this
library is a freaking disaster (I'm warning you)


FROM DEV                                            02.10.2020	

  Hi, if you're using thislibrary, I'd like to	
  congratulate you your courage, you wisdom and your free time recourcess.	
  Why are you using this lib? I have no idea. Here I'm saying
  sorry for my bad England, my funny functions (like isInvaded)	
  and my really bad documentation. I'm too young to die, do please 
  don't kill me, I'm not worth your time, just forget it.
   Sincerely
  CoconutOnPalm


  1. This library was made by CoconutOnPalm or
     u/ExplosiveExplosion (yes, it's the same person) and if 2.
     is OK, he is the owner.

  2. This library is made on SFML, so if I missed important
     something in licence, contact me and I'll do what SFML
     developers want (<3).

  3. If everything is OK in 2. you can use this library as
     you want, even modifying, but I'd appreciate if you
     tell someone about me and my quarantine food shortage
     problem.


  4. This library offers you the following structures:

     * GuiObject:

      - Rectangle

      - Circle

      - Triangle (60, 60, 60)

      - Button

      - Curved Button

      - Percentage Bar

      - Point Bar

      - Switch

      - Input Button

      - Slider

     * DropDown List

     * Protect (simple encryption)

     * Random number generator

     * Playlist

     * Sound Effects


  5. Have a nice day looser


				~Made by CoconutOnPlam using SFML	
