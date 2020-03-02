# Blitz V2
Project repository for the line follower **Blitz V2** to compete in Robot SM 2020. Last years robot was [Blitz V1](https://github.com/caselabbet/robotsm19-linefollower).

## Goals 
- Utilize more advanced control algorithm.
    - Acceleration control
        - Speed trajectory planner
    - Speed control
        - PID + Anti windup + Active damping
    - Position control
        - PID + Anti windup + Active damping
    - State space model + LQG controller (*optional*)
    - MPC - Model Predictive Conrol (*optional)*
- Map race track + Path planner (*optional*)
- Beat last years result and take 1st place. (*not optional*) 
- Added hardware and improvements
    - Use of suction/exhuast fans
    - Single PCB
    - Bluetooth communication
    - High power motors (11W vs 1/2W)
 
## Directories 
```
robotsm20-linefollower
├── datasheets      
├── hardware        
│   ├── cad         # 3D models
│   │   └── stl     # 3D print files
│   └── pcb         # Schematic, layout and production files
├── img             
├── simulation      # Matlab + simulink simulations
└── software
    ├── Inc         # C header files
    └── Src         # C source files
  ```


## Development enviroment
The microcontroller configuration for peripherals such as ADC, GPIO, TIM, Clock etc. is set up via [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html) (GUI) and is then ported to a PlatformIO project with the [stm32pio](https://github.com/ussserrr/stm32pio) command. The software is developed in the [VS Code](https://code.visualstudio.com/) IDE with the [PlatformIO](https://platformio.org/) plugin.

This makes it possible to generate base code for initialization of peripherals with the powerful configurator <b>STM32CubeMX</b> but also use the great </b>PlatformIO + VS code</b> ecosystem to manage compiling, uploading, debugging and scripting tasks.


## Installation
In order to update configuration in <b>STM32CubeMX</b> and then update <b>PlatformIO</b> project you need to set up your development enviroment:
 - Create a `boards` directory in your platformio home folder:
    - Unix: `~/.platformio/`
    - Windows: `%HOMEPATH%\.platformio`
 - Copy the custom board `stm32f405rg.json` to the newly created `boards` directory.
 - Verify that the board has been added by running `platformio boards stm32` and find the stm32f405 board.
    <details>
    <summary><b>Common problems</b></summary>

    - If it is not in the list, make sure you put the `boards` in the correct folder and spelled it right.

    - [platformio is not recognized as an internal command](https://docs.platformio.org/en/latest/installation.html#install-shell-commands) 
    </details>
- Rename the file `stm32pio_template.ini` inside the `software` folder to `stm32pio.ini`and fill it out according to the template:
 ```` ini
[app]
java_cmd = java
platformio_cmd = platformio
cubemx_cmd = path/to/cubemx_program


[project]
cubemx_script_content = config load path/to/cubemx_file.ioc
	generate code path/to/projectFolder
	exit
platformio_ini_patch_content = [platformio]
	include_dir = Inc
	src_dir = Src
ioc_file = path/to/cubemxfile.ioc
board = stm32f405rg
````

<details><summary>Unix example</summary>

``` ini
[app]
java_cmd = java
platformio_cmd = platformio
cubemx_cmd = /Applications/STMicroelectronics/STM32CubeMX.app/Contents/Resources/STM32CubeMX


[project]
cubemx_script_content = config load /Users/isakaslund/Documents/code/robotsm20-linefollower/software/software.ioc
	generate code /Users/isakaslund/Documents/code/robotsm20-linefollower/software/
	exit
platformio_ini_patch_content = [platformio]
	include_dir = Inc
	src_dir = Src
ioc_file = /Users/isakaslund/Documents/code/robotsm20-linefollower/software/software.ioc
board = stm32f405rg


```
</details>
<details><summary>Windows example</summary>

```
[app]
java_cmd = java
platformio_cmd = platformio
cubemx_cmd = C:/Program Files/STMicroelectronics/STM32Cube/STM32CubeMX/STM32CubeMX.exe

[project]
cubemx_script_content = config load C:\Users\Isak\Documents\GitHub\robotsm20-linefollower\software\software.ioc
	generate code C:\Users\Isak\Documents\GitHub\robotsm20-linefollower
	exit
platformio_ini_patch_content = [platformio]
	include_dir = Inc
	src_dir = Src
	
ioc_file = C:\Users\Isak\Documents\GitHub\robotsm20-linefollower\software\software.ioc
board = stm32f405rg


```

</details>

Your `software` folder should look this when finished
```
software
├── Inc
│   ├── header_files.h
│   ├── ...
├── Src
│   ├── c_files.c
│   ├── ...
├── platformio.ini
├── software.ioc
├── stm32f405rg.json
└── stm32pio.ini
```

## Usage
#### Configuration change
Change configuration of peripherals in the STM32CubeMX file `software.ioc` and then save project. **DO NOT** click the `generate code` button. 

To then update the `platformio` project run the following command inside the `software` folder:
``` sh
$ stm32pio generate
```

#### Building
Use the platform build task or press the "✓" button in the bottom left in VS code

#### Uploading
A programmer called [ST-Link](https://docs.platformio.org/en/latest/plus/debug-tools/stlink.html) is needed to upload by connecting it to the SWD pins found on the robot.

Use the platform io upload task or press the "⇨" button in the bottom left in vs code. 

#### Debugging
With the STM32 processesor you can do more then `Serial.println()` debugging over serial.
You can step debug, inspect/change variables, set breakpoints and more by using the dedicated debugger/programmer `ST-Link` and the [platformio unified debugger](https://docs.platformio.org/en/latest/plus/debugging.html).

When setup you can start debugging by going to `Debug` -> `Start debugging` in the menu bar. 



## Contributors
  - Isak Åslund - aslundisak@gmail.com
  - Oskar Johansson - oskaj@student.chalmers.se

