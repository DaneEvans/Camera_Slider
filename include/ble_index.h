/**
 * @file ble_index.h
 * @brief BLE API Documentation Index - Main Entry Point
 * @author Camera Slider Team
 * @version 1.0
 * @date 2024
 * 
 * @mainpage BLE API Documentation for Camera Slider Firmware
 * 
 * @section intro_sec Introduction
 * 
 * Welcome to the Bluetooth Low Energy (BLE) API documentation for the Camera Slider firmware.
 * This documentation provides everything you need to communicate with and control the Camera Slider
 * device from external applications, mobile apps, or web interfaces.
 * 
 * The Camera Slider is a motorized camera slider that can be controlled remotely via BLE,
 * allowing for precise positioning and movement control for photography and videography applications.
 * 
 * @section quick_start_sec Quick Start
 * 
 * ### 1. Connect to Device
 * - Scan for BLE device named "Camera Slider"
 * - Connect using the UART service UUID: `6E400001-B5A3-F393-E0A9-E50E24DCCA9E`
 * - Use TX characteristic: `6E400002-B5A3-F393-E0A9-E50E24DCCA9E`
 * - Use RX characteristic: `6E400003-B5A3-F393-E0A9-E50E24DCCA9E`
 * 
 * ### 2. Send Commands
 * ```python
 * # Move forward
 * await client.write_gatt_char(tx_char, b'a')
 * 
 * # Move backward  
 * await client.write_gatt_char(tx_char, b'b')
 * ```
 * 
 * ### 3. Monitor Responses
 * Subscribe to RX characteristic notifications to receive device feedback and status updates.
 * 
 * @section api_overview_sec API Overview
 * 
 * The BLE API provides several key areas of functionality:
 * 
 * @subsection services_sec BLE Services
 * - **UART Service**: Primary communication channel for commands and responses
 * - **Device Information**: Manufacturer and model details
 * - **Battery Service**: Power level monitoring
 * - **OTA DFU**: Over-the-air firmware updates
 * 
 * @subsection commands_sec Commands
 * - **Movement Control**: Forward/backward movement with configurable distance
 * - **Status Queries**: Device state, position, and configuration information
 * - **Configuration**: Speed, acceleration, and movement parameters
 * - **System Control**: Emergency stop, reset, and diagnostic functions
 * 
 * @subsection responses_sec Responses
 * - **Command Acknowledgments**: Confirmation of received commands
 * - **Status Updates**: Real-time device state information
 * - **Error Messages**: Detailed error reporting and troubleshooting
 * - **Data Logging**: Movement history and performance metrics
 * 
 * @section platform_support_sec Platform Support
 * 
 * The API is designed to work across multiple platforms:
 * 
 * | Platform | Library | Example File |
 * |----------|---------|--------------|
 * | Python | bleak | `python_simple.py` |
 * | Web Browser | Web Bluetooth API | `javascript_web_ble.js` |
 * | iOS | CoreBluetooth | `ios_swift_example.swift` |
 * | Android | BluetoothLeGatt | `android_kotlin_example.kt` |
 * | Node.js | noble | `javascript_node_ble.js` |
 * 
 * @section getting_started_sec Getting Started
 * 
 * ### For Python Developers
 * ```bash
 * pip install bleak
 * # See examples/python_simple.py for complete implementation
 * ```
 * 
 * ### For Web Developers
 * ```html
 * <script>
 * // Use Web Bluetooth API (Chrome/Edge)
 * // See examples/javascript_web_ble.js for complete implementation
 * </script>
 * ```
 * 
 * ### For Mobile Developers
 * - **iOS**: Use CoreBluetooth framework with Swift
 * - **Android**: Use BluetoothLeGatt with Kotlin/Java
 * - See respective example files for complete implementations
 * 
 * @section current_features_sec Current Features
 * 
 * ### ✅ Implemented
 * - Basic forward/backward movement control
 * - LED status indication
 * - BLE UART communication
 * - Device discovery and connection
 * - Real-time command processing
 * 
 * ### 🔄 In Development
 * - Position tracking and absolute positioning
 * - Speed and acceleration control
 * - Status reporting and monitoring
 * - Error handling and recovery
 * - Configuration management
 * 
 * ### 📋 Planned
 * - Programmed movement sequences
 * - Multi-device coordination
 * - Advanced motion profiles
 * - Data logging and analytics
 * - Remote firmware updates
 * 
 * @section architecture_sec Architecture
 * 
 * ```
 * ┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
 * │   Client App    │    │   BLE Stack     │    │  Camera Slider │
 * │                 │◄──►│                 │◄──►│   Firmware     │
 * │ - Commands      │    │ - UART Service  │    │ - Motor Control│
 * │ - Responses     │    │ - GATT Server   │    │ - Position     │
 * │ - Status        │    │ - Advertising   │    │ - Sensors      │
 * └─────────────────┘    └─────────────────┘    └─────────────────┘
 * ```
 * 
 * @section command_reference_sec Command Reference
 * 
 * ### Movement Commands
 * | Command | Description | Parameters | Response |
 * |---------|-------------|------------|----------|
 * | `a` | Move forward | None | "a intercept - change dir" |
 * | `b` | Move backward | None | "b intercept - change dir" |
 * | `pos:<value>` | Move to position | Integer position | "Moving to position X" |
 * | `speed:<value>` | Set speed | 1-100 | "Speed set to X" |
 * 
 * ### Control Commands
 * | Command | Description | Parameters | Response |
 * |---------|-------------|------------|----------|
 * | `s` | Get status | None | JSON status object |
 * | `x` | Emergency stop | None | "STOP" |
 * | `r` | Reset device | None | "RESET" |
 * | `h` | Go home | None | "Going home" |
 * 
 * ### Configuration Commands
 * | Command | Description | Parameters | Response |
 * |---------|-------------|------------|----------|
 * | `config:save` | Save settings | None | "Settings saved" |
 * | `config:load` | Load settings | None | "Settings loaded" |
 * | `config:reset` | Reset to defaults | None | "Defaults restored" |
 * 
 * @section response_formats_sec Response Formats
 * 
 * ### Status Response
 * ```json
 * {
 *   "status": "idle|moving|error|stopped",
 *   "position": 1234,
 *   "target": 1234,
 *   "speed": 50,
 *   "battery": 85,
 *   "temperature": 23.5,
 *   "errors": []
 * }
 * ```
 * 
 * ### Error Response
 * ```json
 * {
 *   "error": "INVALID_COMMAND",
 *   "message": "Command 'z' not recognized",
 *   "code": 1001,
 *   "timestamp": "2024-01-15T10:30:00Z"
 * }
 * ```
 * 
 * ### Command Acknowledgment
 * ```json
 * {
 *   "ack": "COMMAND_RECEIVED",
 *   "command": "a",
 *   "timestamp": "2024-01-15T10:30:00Z",
 *   "execution_time": 15
 * }
 * ```
 * 
 * @section troubleshooting_sec Troubleshooting
 * 
 * ### Common Issues
 * 
 * **Connection Problems**
 * - Ensure device is advertising (LED blinking)
 * - Check device name: "Camera Slider"
 * - Verify BLE is enabled on your device
 * - Try restarting the Camera Slider
 * 
 * **Command Not Working**
 * - Verify connection is established
 * - Check command format (single character or string)
 * - Monitor serial output for error messages
 * - Ensure device is not in error state
 * 
 * **Performance Issues**
 * - Reduce command frequency if experiencing lag
 * - Check battery level
 * - Verify firmware version
 * - Monitor memory usage
 * 
 * ### Error Codes
 * | Code | Description | Solution |
 * |------|-------------|----------|
 * | 1001 | Invalid command | Check command syntax |
 * | 1002 | Device busy | Wait for current operation |
 * | 1003 | Out of range | Check parameter values |
 * | 1004 | Hardware error | Restart device |
 * | 1005 | Low battery | Charge device |
 * 
 * @section development_sec Development
 * 
 * ### Adding New Commands
 * 1. Define command constant in `ble_api.h`
 * 2. Add command processing in `bleuart.ino`
 * 3. Update documentation in this file
 * 4. Add examples to `ble_examples.h`
 * 5. Test with various platforms
 * 
 * ### Testing
 * - Use the provided testing examples
 * - Test on multiple platforms
 * - Verify error handling
 * - Check performance under load
 * - Validate response formats
 * 
 * @section examples_sec Examples
 * 
 * ### Basic Movement Control
 * ```python
 * import asyncio
 * from bleak import BleakClient
 * 
 * async def basic_control():
 *     async with BleakClient("XX:XX:XX:XX:XX:XX") as client:
 *         # Move forward
 *         await client.write_gatt_char(tx_char, b'a')
 *         await asyncio.sleep(2)
 *         
 *         # Move backward
 *         await client.write_gatt_char(tx_char, b'b')
 *         await asyncio.sleep(2)
 *         
 *         # Get status
 *         await client.write_gatt_char(tx_char, b's')
 * 
 * asyncio.run(basic_control())
 * ```
 * 
 * ### Web Interface
 * ```html
 * <!DOCTYPE html>
 * <html>
 * <head>
 *     <title>Camera Slider Control</title>
 * </head>
 * <body>
 *     <button onclick="moveForward()">Forward</button>
 *     <button onclick="moveBackward()">Backward</button>
 *     <button onclick="getStatus()">Status</button>
 *     
 *     <script src="camera_slider.js"></script>
 * </body>
 * </html>
 * ```
 * 
 * ### Mobile App Integration
 * - iOS: Use CoreBluetooth framework
 * - Android: Use BluetoothLeGatt
 * - See platform-specific examples for complete implementations
 * 
 * @section resources_sec Additional Resources
 * 
 * ### Documentation Files
 * - **`ble_api.h`**: Complete API reference
 * - **`ble_examples.h`**: Usage examples
 * - **`bleuart.ino`**: Firmware implementation
 * - **`motors.h`**: Motor control interface
 * 
 * ### External Resources
 * - [Bluetooth SIG](https://www.bluetooth.com/specifications/)
 * - [Nordic Semiconductor](https://www.nordicsemi.com/)
 * - [Adafruit Bluefruit](https://learn.adafruit.com/adafruit-bluefruit-le-uart-friend)
 * - [Web Bluetooth API](https://web.dev/bluetooth/)
 * 
 * ### Support
 * - Check the troubleshooting section above
 * - Review error codes and messages
 * - Test with provided examples
 * - Verify firmware version compatibility
 * 
 * @section changelog_sec Changelog
 * 
 * ### Version 1.0 (Current)
 * - Initial BLE API implementation
 * - Basic movement control (forward/backward)
 * - UART service communication
 * - Device discovery and connection
 * - LED status indication
 * 
 * ### Version 1.1 (Planned)
 * - Position tracking and absolute positioning
 * - Speed and acceleration control
 * - Status reporting and monitoring
 * - Enhanced error handling
 * 
 * ### Version 1.2 (Planned)
 * - Programmed movement sequences
 * - Configuration management
 * - Data logging capabilities
 * - Multi-device support
 * 
 * @section license_sec License
 * 
 * This firmware and API documentation are provided under the MIT License.
 * See the LICENSE file for complete terms and conditions.
 * 
 * @section contact_sec Contact
 * 
 * For questions, bug reports, or feature requests:
 * - **GitHub Issues**: [Camera Slider Firmware Repository](https://github.com/your-repo)
 * - **Email**: your-email@example.com
 * - **Documentation**: This file and generated Doxygen pages
 * 
 * ---
 * 
 * *This documentation is automatically generated and maintained using Doxygen.
 * For the most up-to-date information, always refer to the generated HTML documentation.*
 */

#ifndef BLE_INDEX_H
#define BLE_INDEX_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup ble_index BLE API Documentation Index
 * @{
 * 
 * @brief Main entry point and overview for BLE API documentation
 * 
 * This file serves as the central hub for all BLE API documentation,
 * providing navigation, examples, and comprehensive information for
 * developers integrating with the Camera Slider firmware.
 */

/**
 * @brief Documentation version
 * 
 * Current version of the BLE API documentation
 */
#define BLE_API_VERSION "1.0"

/**
 * @brief Documentation date
 * 
 * Last update date for the BLE API documentation
 */
#define BLE_API_DATE "2024"

/**
 * @brief Main documentation entry point
 * 
 * This macro serves as the main entry point for Doxygen documentation
 * and should be referenced in the main page documentation.
 */
#define BLE_API_MAIN_PAGE "BLE API Documentation Index"

/** @} */ // end of ble_index

#ifdef __cplusplus
}
#endif

#endif // BLE_INDEX_H
