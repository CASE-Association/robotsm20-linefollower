# CASE line follower Robot SM 2020
Project repository for the line follower to compete with in Robot SM 2020. 

## Goal 
- Beat last years result and end up at 1st place. 
- Utilize more advanced motor control algorithm.
- Utilize some kind of path planning to optimize speed. 


## Contributors
  - Isak Åslund
  - Oskar Johansson
## Structure 
  - software (Code for STM32 MCU)
  - hardware
    - cad (3D models and stls)
    - pcb (schematics, board layout and production files)
  - img


## Development
Hardware configuration as ADC, GPIO, TIM, Clock etc. is set up via STM32CubeMX (GUI) and ported to platformIO via <b>stm32pio</b> command. To change config and update files you need to set up enviroment correctly and run <b>stm32pio generate</b>. To set up correctly follow these steps:
 - Create a ```boards``` directory in your platformIO home folder (~/.platformio/)
 - Add the custom board by copying ```stm32f405rg.json``` to the ```boards``` directory
 - Verify that the board has been added by running ```platformio boards stm32``` and find the stm32f405 board.
 - Create a file ```stm32pio.ini``` in the ```software``` folder according to the following template:

 ````
[app]
java_cmd = java
platformio_cmd = platformio
cubemx_cmd = path/to/cubemx


[project]
cubemx_script_content = config load path/to/cubemxFile.ioc
	generate code path/to/projectFolder
	exit
platformio_ini_patch_content = [platformio]
	include_dir = Inc
	src_dir = Src
ioc_file = path/to/cubemxfile.ioc
board = stm32f405rg
````
Your ```software``` folder should look like this
```
software
├── Inc
│   ├── gpio.h
│   ├── main.h
│   ├── stm32f4xx_hal_conf.h
│   ├── stm32f4xx_it.h
│   └── sys.h
├── MXTmpFiles
│   ├── license.tmp
│   └── system.tmp
├── Src
│   ├── gpio.c
│   ├── main.c
│   ├── stm32f4xx_hal_msp.c
│   ├── stm32f4xx_it.c
│   └── sys.c
├── platformio.ini
├── software.ioc
├── stm32f405rg.json
└── stm32pio.ini
```

