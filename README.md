# IMU_WebServer_Quaternion
Test for Inertial Measurement Units MPU6050 for robotic applications with Webserver. Testing Accuracy in reading and Filtering applying Roll Pitch Yaw Or Quaternion visualization in order to visualize best method and results.


# IMU_WebServer_Quaternion

Test for Inertial Measurement Units MPU6050 for robotic applications with Webserver. Testing Accuracy in reading and Filtering applying Roll Pitch Yaw Or Quaternion visualization in order to visualize best method and results.

## Quaternion Solution

[Gimbal Lock](https://en.wikipedia.org/wiki/Gimbal_lock)  

![https://zaragozamakerspace.com/wp-content/uploads/2021/02/QuaternionVisualization.gif](https://zaragozamakerspace.com/wp-content/uploads/2021/02/QuaternionVisualization.gif)

Quaternion Solution

## Gimbal Lock

![https://zaragozamakerspace.com/wp-content/uploads/2021/02/RPYVisualization.gif](https://zaragozamakerspace.com/wp-content/uploads/2021/02/RPYVisualization.gif)

Roll Pitch Yaw – No Quaternion Applied

## MPU6050

This giroscope and accelerometer module is needed in order to obtain ( accX, accY, accZ ) ( gyroX, gyroY, gyroZ ) and 

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/fdfc8fa6-c35f-4465-bea2-89d8353284d8/GY-521.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/fdfc8fa6-c35f-4465-bea2-89d8353284d8/GY-521.png)

## Library For MPU6050

## IMU Connection ESP32 with Interruption

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a8d718a3-704a-45e3-b8f4-d6ba3264378c/IMUESP32_bb.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a8d718a3-704a-45e3-b8f4-d6ba3264378c/IMUESP32_bb.png)

## IMU Connection ESP8266 without Interruption

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/0f24ad21-29d1-4a36-9929-c2cdcae03781/IMUESP8266_bb.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/0f24ad21-29d1-4a36-9929-c2cdcae03781/IMUESP8266_bb.png)

## Links

- [ZGZMakerSpace - Post](https://zaragozamakerspace.com/index.php/projects/quaternions-solving-gimbal-lock/)
- [RandomnerTutorials](https://randomnerdtutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/)
- [jrowberg MPU6050 Library](https://github.com/jrowberg/i2cdevlib/blob/master/Arduino/MPU6050/MPU6050_6Axis_MotionApps20.h)
- [3Blue1Brown - Quaternions](https://www.youtube.com/watch?v=d4EgbgTm0Bg)