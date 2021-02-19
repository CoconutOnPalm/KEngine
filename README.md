# KEngine

KEngine is a very simple library that which expands the SFML library. That's it


QUICK INSTRUCTION HOW TO LINK THIS THING   (might not work)
								
C++ version: Standard ISO C++17					
								
								
Linking works basically the same as in SFML, but there's	
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
								
	KEngine::Init()						
								
to initialize everything.					
								
if something goes wrong... you have to drink a lot of		
coffee and not sleep for two nights, because this 		
library is a freaking disaster									
														
									
									
  FROM DEV                              02.10.2020 and 18.02.2020	
  Hi, if you're using this piece of... (you know :) ) I'd like to	
  congratulate you your courage, you wisdom and your free time.	
  Why are you using this lib, I have no idea. Here I'm saying		
  sorry for my bad England, my funny functions (like isInvaded)	
  and my really bad documentation. I'm still older than your dck 	
  size and if you ever magically find where I live, please don't	
  kill me, I'mnot worth your time, just forget it...			
   Sincerely								
  CoconutOnPalm							
									
									
  1. This library was made by u/ExplosiveExplosion or			
     CoconutOnPalm (yes, it's the same person) and if 2.		
     is OK, he is the owner. If you want to let him stay		
     alive and stop his starving process you can always		
     go to my Github https://github.com/CoconutOnPalm :).		
									
  2. This library is based on SFML, so if I missed important		
     things in licence, contact me and I'll do what SFML		
     developers want (<3).						
									
  3. If everything is OK in 2. you can use this library as		
     you want, even modifying, but I'd appreciate if you		
     tell someone about me and my quarantine kebab lack		
     problem.								
									
									
  4. This library offers you these following structures:		
									
     * GuiObject:							
									
      - Rectangle		+ Physics			
									
      - Circle			+ Physics			
									
      - Triangle (60, 60, 60)	+ Physics			
									
      - Button			+ Physics			
									
      - Curved Button							
									
      - Percentage Bar						
									
      - Point Bar							
									
      - Switch							
									
      - Input Button							
									
      - Slider							
									
     * DropDown List							
									
     * Protect (simple encryption)					
									
	   * Simple debugging with console				
									
	   * Clock							
									
	   * 4D vector							
									
	   * Color							
									
     * Random number generator					
									
     * Playlist							
									
     * Sound Effects							
									
  6. Have a nice day L00oser						
									
									
									
				~Made by CoconutOnPlam using SFML	

