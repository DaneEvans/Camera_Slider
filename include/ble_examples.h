/**
 * @file ble_examples.h
 * @brief BLE API Usage Examples for Camera Slider Firmware
 * @author Camera Slider Team
 * @version 1.0
 * @date 2024
 *
 * @details This file provides practical examples of how to use the BLE API
 * for controlling the camera slider device from various platforms.
 */

#ifndef BLE_EXAMPLES_H
#define BLE_EXAMPLES_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup ble_examples BLE API Usage Examples
 * @{
 *
 * @brief Practical examples for different platforms and use cases
 */

/**
 * @defgroup python_examples Python Examples
 * @{
 *
 * @brief Python implementations using bleak library
 */

/**
 * @example python_simple.py
 * @brief Simple Python example using bleak
 *
 * @code
 * import asyncio
 * from bleak import BleakClient
 *
 * async def control_slider():
 *     # Replace with your device's address
 *     address = "XX:XX:XX:XX:XX:XX"
 *
 *     async with BleakClient(address) as client:
 *         # Send forward command
 *         await client.write_gatt_char(
 *             "6e400002-b5a3-f393-e0a9-e50e24dcca9e",  # TX UUID
 *             b'a'
 *         )
 *         print("Sent forward command")
 *
 *         # Send backward command
 *         await client.write_gatt_char(
 *             "6e400002-b5a3-f393-e0a9-e50e24dcca9e",  # TX UUID
 *             b'b'
 *         )
 *         print("Sent backward command")
 *
 * asyncio.run(control_slider())
 * @endcode
 */

/** @} */  // end of python_examples

/**
 * @defgroup javascript_examples JavaScript Examples
 * @{
 *
 * @brief JavaScript implementations for web and Node.js
 */

/**
 * @example javascript_web_ble.js
 * @brief Web Bluetooth API example
 *
 * @code
 * class CameraSliderController {
 *     async connect() {
 *         this.device = await navigator.bluetooth.requestDevice({
 *             filters: [{ name: 'Camera Slider' }],
 *             optionalServices: ['6e400001-b5a3-f393-e0a9-e50e24dcca9e']
 *         });
 *
 *         this.server = await this.device.gatt.connect();
 *         const uartService = await this.server.getPrimaryService(
 *             '6e400001-b5a3-f393-e0a9-e50e24dcca9e'
 *         );
 *
 *         this.txCharacteristic = await uartService.getCharacteristic(
 *             '6e400002-b5a3-f393-e0a9-e50e24dcca9e'
 *         );
 *
 *         console.log('Connected to Camera Slider');
 *     }
 *
 *     async sendCommand(command) {
 *         const data = new TextEncoder().encode(command);
 *         await this.txCharacteristic.writeValue(data);
 *         console.log(`Sent command: ${command}`);
 *     }
 *
 *     async moveForward() { await this.sendCommand('a'); }
 *     async moveBackward() { await this.sendCommand('b'); }
 * }
 *
 * const controller = new CameraSliderController();
 * controller.connect().then(() => {
 *     controller.moveForward();
 *     setTimeout(() => controller.moveBackward(), 2000);
 * });
 * @endcode
 */

/** @} */  // end of javascript_examples

/**
 * @defgroup mobile_examples Mobile App Examples
 * @{
 *
 * @brief Examples for iOS and Android development
 */

/**
 * @example ios_swift_example.swift
 * @brief iOS Swift example using CoreBluetooth
 *
 * @code
 * import CoreBluetooth
 *
 * class CameraSliderController: NSObject, CBCentralManagerDelegate {
 *     var centralManager: CBCentralManager!
 *     var peripheral: CBPeripheral?
 *     var txCharacteristic: CBCharacteristic?
 *
 *     override init() {
 *         super.init()
 *         centralManager = CBCentralManager(delegate: self, queue: nil)
 *     }
 *
 *     func sendCommand(_ command: String) {
 *         guard let characteristic = txCharacteristic,
 *               let data = command.data(using: .utf8) else { return }
 *
 *         peripheral?.writeValue(data, for: characteristic, type: .withResponse)
 *         print("Sent command: \(command)")
 *     }
 *
 *     func moveForward() { sendCommand("a") }
 *     func moveBackward() { sendCommand("b") }
 * }
 * @endcode
 */

/** @} */  // end of mobile_examples

/**
 * @defgroup testing_examples Testing Examples
 * @{
 *
 * @brief Examples for testing and debugging the BLE API
 */

/**
 * @example test_commands.py
 * @brief Python script for testing all BLE commands
 *
 * @code
 * import asyncio
 * from bleak import BleakClient
 *
 * async def test_commands():
 *     address = "XX:XX:XX:XX:XX:XX"
 *
 *     async with BleakClient(address) as client:
 *         # Test basic commands
 *         await client.write_gatt_char(
 *             "6e400002-b5a3-f393-e0a9-e50e24dcca9e",
 *             b'a'
 *         )
 *         print("Sent forward command")
 *         await asyncio.sleep(2)
 *
 *         await client.write_gatt_char(
 *             "6e400002-b5a3-f393-e0a9-e50e24dcca9e",
 *             b'b'
 *         )
 *         print("Sent backward command")
 *
 * asyncio.run(test_commands())
 * @endcode
 */

/** @} */  // end of testing_examples

/** @} */  // end of ble_examples

#ifdef __cplusplus
}
#endif

#endif  // BLE_EXAMPLES_H
