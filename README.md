# ReadValuesModified 
Is a sketch baised on ReadValues from the DFPlayer library examples.  
It has been modified to try to understand how the class methods return values.  

## Function Detials
It workes poorly with DFPlayer.   

* Serial Monitor output with SD card in place  
```
17:40:13.110 -> DFRobot DFPlayer Mini Demo  
17:40:13.110 -> Compiled at: Dec 28 2025 17:27:08  
17:40:13.110 -> Initializing DFPlayer ... (May take 3~5 seconds)  
17:40:14.367 -> DFPlayer Mini online.  
17:40:14.367 -> Files found: 9  
17:40:14.406 -> Current file number: -1  
17:40:17.915 -> Player State: 0  
17:40:20.930 ->   
17:40:20.930 -> Loop test.  
17:40:21.068 -> myDFPlayer.available() is available  
17:40:21.068 -> myDFPlayer.readType() is: 11  
17:40:21.068 -> myDFPlayer.read() is: 512  
17:40:21.068 -> myDFPlayer.readType() is: 11  
17:40:21.068 -> myDFPlayer.read() is: 512  
17:40:21.068 -> State: 512  
17:40:21.118 -> Again, State: -1  
17:40:24.602 -> Third time, State: 512  
17:40:24.680 -> Forth time, State: 512  
17:40:24.681 -> readFileCounts(): 512  
17:40:24.706 -> Again, readFileCounts(): 9  
17:40:24.761 -> Third time, readFileCounts(): 9  
17:40:24.799 -> Forth time, readFileCounts(): 9  
17:40:24.831 -> readCurrentFileNumber(): 9  
17:40:24.877 -> Again, readCurrentFileNumber(): 0  
```
  
* Serial Monitor output with SD card removed
```
17:44:48.626 -> ets Jul 29 2019 12:21:46  
17:44:48.626 ->   
17:44:48.626 -> rst:0x1 (POWERON_RESET),boot:0x17 (SPI_FAST_FLASH_BOOT)  
17:44:48.626 -> configsip: 0, SPIWP:0xee  
17:44:48.626 -> clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00 
17:44:48.626 -> mode:DIO, clock div:1  
17:44:48.626 -> load:0x3fff0030,len:4832 
17:44:48.626 -> load:0x40078000,len:16460  
17:44:48.626 -> load:0x40080400,len:4  
17:44:48.626 -> load:0x40080404,len:3504  
17:44:48.626 -> entry 0x400805cc  
17:44:48.745 ->   
17:44:48.745 -> DFRobot DFPlayer Mini Demo  
17:44:48.745 -> Compiled at: Dec 28 2025 17:27:08  
17:44:48.789 -> Initializing DFPlayer ... (May take 3~5 seconds)  
17:44:49.002 -> !!!!!!!!!!!!  
17:44:49.002 -> Unable to begin:  
17:44:49.002 -> 1.Please recheck the connection!  
17:44:49.002 -> 2.Please insert the SD card or USB drive!  
17:44:49.002 -> !!!!!!!!!!!!  
17:44:49.176 -> DFPlayer Mini online.  
17:44:49.176 -> Files found: -1  
17:44:52.711 -> Current file number:  
```
  
* Removing the SD card during loop causes the loop test to lock up on the State
```
17:47:50.252 -> Loop test.  
17:47:50.346 -> myDFPlayer.available() is available  
17:47:50.346 -> myDFPlayer.readType() is: 11  
17:47:50.346 -> myDFPlayer.read() is: 0  
17:47:50.346 -> myDFPlayer.readType() is: 11  
17:47:50.346 -> myDFPlayer.read() is: 0  
17:47:50.346 -> State: 512  
17:47:50.393 -> Again, State: -1  
17:47:53.489 -> Third time, State:  
```

It works poorly but different with TD5580A mini MP3 players. In particular with the TD5580A mini MP3 player the sketch can detect SD card in the connector or not. So for the SD card detection it works better than with the DFPlayer.  

* Serial Monitor output with SD card in place  
```
7:36:27.591 -> Loop test.  
17:36:27.674 -> myDFPlayer.available() not available  
17:36:27.707 -> myDFPlayer.readType() is: 11  
17:36:27.707 -> myDFPlayer.read() is: 0  
17:36:27.707 -> State: 512  
17:36:27.707 -> Again, State: 512  
17:36:27.742 -> Third time, State: 512  
17:36:27.775 -> Forth time, State: 512  
17:36:27.808 -> readFileCounts(): 9  
17:36:27.842 -> Again, readFileCounts(): 9  
17:36:27.874 -> Third time, readFileCounts(): 9  
17:36:27.907 -> Forth time, readFileCounts(): 9  
17:36:27.942 -> readCurrentFileNumber(): 0  
17:36:27.974 -> Again, readCurrentFileNumber(): 0  
17:36:28.007 -> Third time, readCurrentFileNumber(): 0  
17:36:28.041 -> Forth time, readCurrentFileNumber(): 0  
```

* Serial Monitor output with SD card removed at boot
``` 
17:52:30.726 -> ets Jul 29 2019 12:21:46  
17:52:30.726 ->   
17:52:30.726 -> rst:0x1 (POWERON_RESET),boot:0x17 (SPI_FAST_FLASH_BOOT)  
17:52:30.726 -> configsip: 0, SPIWP:0xee  
17:52:30.726 -> clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00  
17:52:30.726 -> mode:DIO, clock div:1  
17:52:30.726 -> load:0x3fff0030,len:4832  
17:52:30.726 -> load:0x40078000,len:16460  
17:52:30.726 -> load:0x40080400,len:4  
17:52:30.726 -> load:0x40080404,len:3504  
17:52:30.726 -> entry 0x400805cc  
17:52:30.860 ->   
17:52:30.860 -> DFRobot DFPlayer Mini Demo  
17:52:30.860 -> Compiled at: Dec 28 2025 17:27:08  
17:52:30.860 -> Initializing DFPlayer ... (May take 3~5 seconds)  
17:52:31.066 -> !!!!!!!!!!!!  
17:52:31.066 -> Unable to begin:  
17:52:31.066 -> 1.Please recheck the connection!  
17:52:31.066 -> 2.Please insert the SD card or USB drive!  
17:52:31.066 -> !!!!!!!!!!!!  
17:52:31.292 -> DFPlayer Mini online.  
17:52:31.292 -> Files found: -1  
17:52:34.804 -> Current file number:
```
  
* Serial Monitor output with SD card removed during loop
```
17:38:30.641 -> Loop test.  
17:38:30.717 -> myDFPlayer.available() is available  
17:38:30.752 -> myDFPlayer.readType() is: 3  
17:38:30.752 -> myDFPlayer.read() is: 2  
17:38:30.752 -> myDFPlayer.readType() is: 3  
17:38:30.752 -> myDFPlayer.read() is: 2  
17:38:30.752 -> Card Removed!  
17:38:30.752 -> Card Removed!  
17:38:30.752 -> Card Removed!  
17:38:30.752 -> Card Removed!  
17:38:30.752 -> State: -1  
17:38:30.785 -> Again, State: -1  
17:38:34.280 -> Third time, State:   
```



## References  
"...practice things are different: depending on the manufacturers and versions, the features they offer are not always there...."
https://bigsoundbank.com/articles/df-player-mini-f104.html



