#define STYLECSS ""
#define RPYJS ""
char index_html[] PROGMEM = "<!DOCTYPE HTML><html><head><title>ESP Web Server</title><link rel=\"icon\" href=\"data:,\"><link rel=\"stylesheet\" href=\"https://use.fontawesome.com/releases/v5.7.2/css/all.css\" integrity=\"sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr\" crossorigin=\"anonymous\"><link rel=\"stylesheet\" href=\"https://imuwebserver.s3.eu-west-3.amazonaws.com/IMU_TestServer.css\"><script src=\"https://cdn.jsdelivr.net/npm/three@0.119.1/build/three.js\"></script><script src=\"https://imuwebserver.s3.eu-west-3.amazonaws.com/OrbitControls.js\"></script></head><body> <div class=\"topnav\"><h1><i class=\"far fa-compass\"></i> MPU6050 <i class=\"far fa-compass\"></i></h1></div><div class=\"content\"><div class=\"cards\"><div class=\"card\"><p class=\"card-title\">Orientation Radians</p><p><span class=\"reading\">X: <span id=\"yaw\"></span> rad</span></p><p><span class=\"reading\">Y: <span id=\"roll\"></span> rad</span></p><p><span class=\"reading\">Z: <span id=\"pitch\"></span> rad</span></p></div><div class=\"card\"><p class=\"card-title\">Orientation Degree</p><p><span class=\"reading\">X: <span id=\"yawdeg\"></span> degrees</span></p><p><span class=\"reading\">Y: <span id=\"rolldeg\"></span> degrees</span></p><p><span class=\"reading\">Z: <span id=\"pitchdeg\"></span> degrees</span></p></div><div class=\"card\"><p class=\"card-title\">IMU</p><p class=\"card-title\">Inertial Test</p><p><span class=\"reading\"> Q.w: <span id=\"Qw\"></span> </span> </p><p><span class=\"reading\"> Q.x: <span id=\"Qx\"></span> </span> </p><p><span class=\"reading\"> Q.y: <span id=\"Qy\"></span> </span> </p><p><span class=\"reading\"> Q.z: <span id=\"Qz\"></span> </span> </p>  </div></div><div class=\"cube-content\"><div id=\"3Dcube\"></div></div></div><script src=\"https://imuwebserver.s3.eu-west-3.amazonaws.com/IMU_QuaternionBot.js\"></script>   </body></html>";
