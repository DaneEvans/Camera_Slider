/**
 * @file ble_api.h
 * @brief BLE API Documentation for Camera Slider Firmware
 * @author Dane Evans
 * @version 1.0
 * @date 2024
 *
 * @details This file documents the Bluetooth Low Energy (BLE) API interface
 * that allows communication between the camera slider device and a phone/computer.
 * The API is implemented using the Adafruit Bluefruit LE UART service.
 *
 * @note This is a documentation-only header file. The actual implementation
 * is in src/bleuart.ino
 */

#ifndef BLE_API_H
#define BLE_API_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup ble_api BLE API Documentation
 * @{
 *
 * @brief Complete API reference for BLE communication with the Camera Slider
 *
 * The Camera Slider firmware provides a BLE UART interface that allows
 * remote control and monitoring of the device. This API supports both
 * command-based control and real-time status updates.
 */

/**
 * @defgroup ble_services BLE Services
 * @{
 *
 * @brief Available BLE services on the Camera Slider device
 */

/**
 * @brief Device Information Service
 *
 * Provides basic device information including manufacturer and model details.
 *
 * @details
 * - Manufacturer: "Adafruit Industries"
 * - Model: "Bluefruit Feather52"
 * - Device Name: "Camera Slider"
 *
 * @note This service is automatically included in all BLE connections
 */
#define BLE_SERVICE_DEVICE_INFO "Device Information Service"

/**
 * @brief BLE UART Service
 *
 * Primary communication service for sending commands and receiving status updates.
 *
 * @details
 * - Service UUID: Standard BLE UART service
 * - Characteristics: TX (write) and RX (read)
 * - MTU: Optimized for small command packets
 *
 * @note This is the main service used for device control
 */
#define BLE_SERVICE_UART "BLE UART Service"

/**
 * @brief Battery Service
 *
 * Provides battery level information to connected devices.
 *
 * @details
 * - Initial battery level: 100%
 * - Updates: Real-time battery level monitoring
 *
 * @note Battery level is automatically updated during operation
 */
#define BLE_SERVICE_BATTERY "Battery Service"

/**
 * @brief OTA DFU Service
 *
 * Over-the-Air Device Firmware Update service for remote firmware updates.
 *
 * @details
 * - Enables firmware updates without physical connection
 * - Compatible with Nordic DFU tools
 *
 * @warning Use with caution - improper updates can brick the device
 */
#define BLE_SERVICE_DFU "OTA DFU Service"

/** @} */  // end of ble_services

/**
 * @defgroup ble_commands BLE Commands
 * @{
 *
 * @brief Available commands that can be sent via BLE UART
 *
 * Commands are sent as single characters or strings over the BLE UART service.
 * All commands are processed in the main loop and provide immediate feedback.
 */

/**
 * @brief Move slider forward
 *
 * @details
 * - Command: 'a'
 * - Action: Moves the camera slider forward by 50 steps
 * - LED: Toggles green LED state
 * - Response: "a intercept - change dir" sent to serial
 *
 * @note This command changes the current direction and moves the slider
 * @see slide_dist()
 */
#define BLE_CMD_FORWARD 'a'

/**
 * @brief Move slider backward
 *
 * @details
 * - Command: 'b'
 * - Action: Moves the camera slider backward by 50 steps
 * - LED: Toggles green LED state
 * - Response: "b intercept - change dir" sent to serial
 *
 * @note This command changes the current direction and moves the slider
 * @see slide_dist()
 */
#define BLE_CMD_BACKWARD 'b'

/**
 * @brief Get device status
 *
 * @details
 * - Command: 's'
 * - Action: Returns current device status and position
 * - Response: JSON formatted status string
 *
 * @note This command is planned for future implementation
 */
#define BLE_CMD_STATUS 's'

/**
 * @brief Emergency stop
 *
 * @details
 * - Command: 'x'
 * - Action: Immediately stops all motor movement
 * - Response: "STOP" confirmation
 *
 * @note This command is planned for future implementation
 */
#define BLE_CMD_STOP 'x'

/**
 * @brief Set movement speed
 *
 * @details
 * - Command: "speed:<value>"
 * - Action: Sets the movement speed (1-100)
 * - Response: "Speed set to <value>"
 *
 * @note This command is planned for future implementation
 */
#define BLE_CMD_SPEED "speed:"

/**
 * @brief Set target position
 *
 * @details
 * - Command: "pos:<value>"
 * - Action: Moves slider to absolute position
 * - Response: "Moving to position <value>"
 *
 * @note This command is planned for future implementation
 */
#define BLE_CMD_POSITION "pos:"

/** @} */  // end of ble_commands

/**
 * @defgroup ble_responses BLE Responses
 * @{
 *
 * @brief Response messages sent by the device
 *
 * The device provides feedback for all commands and status updates
 * through the BLE UART service.
 */

/**
 * @brief Command acknowledgment responses
 */
#define BLE_RESP_CMD_ACK "Command received and executed"

/**
 * @brief Error responses
 */
#define BLE_RESP_ERROR "Error: Invalid command"
#define BLE_RESP_PARAM_ERROR "Error: Invalid parameter"
#define BLE_RESP_BUSY "Error: Device busy"

/**
 * @brief Status response format
 *
 * @details JSON formatted status response:
 * @code
 * {
 *   "status": "idle|moving|error",
 *   "position": 1234,
 *   "target": 1234,
 *   "speed": 50,
 *   "battery": 85
 * }
 * @endcode
 */
#define BLE_RESP_STATUS_FORMAT "JSON status object"

/** @} */  // end of ble_responses

/**
 * @defgroup ble_connection BLE Connection
 * @{
 *
 * @brief Connection management and configuration
 */

/**
 * @brief Advertising configuration
 *
 * @details
 * - Advertising interval: 32-244 units (20-152.5 ms)
 * - Fast timeout: 30 seconds
 * - Auto-restart: Enabled on disconnect
 * - Flags: LE Only, General Discovery Mode
 * - Power: 4 dBm (configurable)
 */
#define BLE_ADV_INTERVAL_MIN 32
#define BLE_ADV_INTERVAL_MAX 244
#define BLE_ADV_FAST_TIMEOUT 30

/**
 * @brief Connection parameters
 *
 * @details
 * - Bandwidth: Maximum (SRAM intensive)
 * - Auto LED: Enabled on connection
 * - Connection callbacks: Connect/Disconnect handlers
 * - Peer name retrieval: 32 character limit
 */
#define BLE_CONN_BANDWIDTH_MAX true
#define BLE_CONN_AUTO_LED true
#define BLE_PEER_NAME_MAX 32

/** @} */  // end of ble_connection

/**
 * @defgroup ble_usage Usage Examples
 * @{
 *
 * @brief Common usage patterns and examples
 */

/**
 * @example basic_control.ino
 * @brief Basic BLE control example
 *
 * This example shows how to connect to the Camera Slider and send
 * basic movement commands:
 *
 * @code
 * // Connect to "Camera Slider" device
 * // Send 'a' to move forward
 * // Send 'b' to move backward
 * // Monitor responses for feedback
 * @endcode
 */

/**
 * @example status_monitoring.ino
 * @brief Status monitoring example
 *
 * This example shows how to continuously monitor device status:
 *
 * @code
 * // Connect to device
 * // Send 's' command periodically
 * // Parse JSON status responses
 * // Update UI with current position/speed
 * @endcode
 */

/** @} */  // end of ble_usage

/**
 * @defgroup ble_implementation Implementation Details
 * @{
 *
 * @brief Technical implementation information
 */

/**
 * @brief Main BLE processing loop
 *
 * @details The main loop processes incoming BLE commands and forwards
 * serial data to connected devices. Command processing includes:
 * - Character-based commands (a, b)
 * - LED state management
 * - Motor control via slide_dist()
 * - Bidirectional data forwarding
 *
 * @see loop() in bleuart.ino
 */
#define BLE_MAIN_LOOP "Main BLE processing loop"

/**
 * @brief Buffer management
 *
 * @details
 * - Input buffer: 64 bytes
 * - Processing delay: 2ms for buffer filling
 * - Character-by-character command processing
 * - Real-time response generation
 */
#define BLE_BUFFER_SIZE 64
#define BLE_PROCESSING_DELAY 2

/**
 * @brief Motor control integration
 *
 * @details BLE commands directly interface with the motor control system:
 * - slide_dist() function calls
 * - Direction changes
 * - Position tracking
 * - Speed control
 *
 * @see motors.h for motor control functions
 */
#define BLE_MOTOR_INTEGRATION "Direct motor control integration"

/** @} */  // end of ble_implementation

/**
 * @defgroup ble_troubleshooting Troubleshooting
 * @{
 *
 * @brief Common issues and solutions
 */

/**
 * @brief Connection issues
 *
 * @details
 * - Ensure device is advertising (LED should be blinking)
 * - Check device name: "Camera Slider"
 * - Verify BLE is enabled on your phone/computer
 * - Try restarting the device if connection fails
 */
#define BLE_TROUBLESHOOT_CONNECTION "Connection troubleshooting guide"

/**
 * @brief Command not working
 *
 * @details
 * - Verify connection is established
 * - Check that commands are sent as single characters
 * - Monitor serial output for error messages
 * - Ensure device is not in error state
 */
#define BLE_TROUBLESHOOT_COMMANDS "Command troubleshooting guide"

/**
 * @brief Performance issues
 *
 * @details
 * - Reduce command frequency if experiencing lag
 * - Check battery level (low battery may affect performance)
 * - Verify firmware version is up to date
 * - Monitor memory usage during operation
 */
#define BLE_TROUBLESHOOT_PERFORMANCE "Performance troubleshooting guide"

/** @} */  // end of ble_troubleshooting

/**
 * @defgroup ble_future Future Enhancements
 * @{
 *
 * @brief Planned API improvements
 */

/**
 * @brief Enhanced command set
 *
 * @details Planned commands include:
 * - Absolute positioning
 * - Speed control
 * - Programmed sequences
 * - Status queries
 * - Configuration management
 */
#define BLE_FUTURE_COMMANDS "Enhanced command set"

/**
 * @brief Data logging
 *
 * @details Planned features include:
 * - Movement history
 * - Performance metrics
 * - Error logging
 * - Usage statistics
 */
#define BLE_FUTURE_LOGGING "Data logging capabilities"

/**
 * @brief Multi-device support
 *
 * @details Planned features include:
 * - Multiple slider control
 * - Synchronized movements
 * - Master-slave configurations
 * - Network coordination
 */
#define BLE_FUTURE_MULTI_DEVICE "Multi-device support"

/** @} */  // end of ble_future

/** @} */  // end of ble_api

#ifdef __cplusplus
}
#endif

#endif  // BLE_API_H
