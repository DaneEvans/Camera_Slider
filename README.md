# Camera Slider

## Stack 

- Platform IO
- Arduino 

## Hardware

Microcontroller - Seeed Xiao BLE / nrf52840 
Motors - NEMA 17, 12-24v 4A 
Motor drivers - not settled 

## Communication 

BLE UART - Plan is to use Gcode or similar commands, so it's easier to understand. 

## CI/CD Pipeline

This project includes automated CI/CD workflows that:

- **Build Firmware**: Automatically compiles the firmware using PlatformIO
- **Generate Documentation**: Creates comprehensive Doxygen documentation
- **Deploy to GitHub Pages**: Publishes documentation automatically
- **Quality Checks**: Runs on every push and pull request

### Documentation

- **Live Documentation**: [View on GitHub Pages](https://daneevans.github.io/Camera_Slider_firmware/)
- **Local Generation**: Run `make docs` to generate locally
- **Auto-updating**: Documentation updates automatically with code changes

### Workflows

- `ci.yml` - Complete CI pipeline (build + docs + deploy)
- `pages.yml` - Documentation deployment only
- `build.yml` - Firmware building and testing

See [GitHub Pages Setup Guide](docs/GITHUB_PAGES_SETUP.md) for detailed configuration instructions.

## Dev Setup 
- Download PlatformIO
- Open project 
- Upload and Monitor 
- Connect to the uC using a BLE-UART app (nRF connect, or another)


## Hardware design 

![Xiao BLE pinout](https://files.seeedstudio.com/wiki/XIAO-BLE/pinout2.png)

Xiao has just enough pins 

| Pin | Purpose          |     Pin | Purpose    |
| --- | --- | --- | --- |
| 0   | limit switch high |   5V    | N/C        |
| 1   | limit switch low |   GND   | To drivers |
| 2   | Motor - slider 1 |   3v3   |   N/C      |
| 3   | Motor - slider 2 |   10    | Motor - rotator 1 |
| 4   | Motor - slider 3 |   9     | Motor - rotator 2 |
| 5   | Motor - slider 4 |   8     | Motor - rotator 3 |
| 6   | Camera trigger   |   7     | Motor - rotator 4 |

### Motor Drivers
The motor drivers / motors will run on 12 - 24v .
The arduino will either have it's own 5V supply, or maybe feed from one of the drivers. 

### Limit swithches 
Interrupt driven, active Low
Pullups on. 

### Camera trigger 
May need an optocoupler, need to look at my old notes. 

Looks like it's just a matter of shorting a TRS in different configs for focus and shutter
See if we can another pin from NFC ... looks like yes. 
[reddit reference for ZMK, not Arduino](https://www.reddit.com/r/olkb/comments/11hl7is/extra_gpio_on_seeed_xiao_controllers_via_zmk/)

