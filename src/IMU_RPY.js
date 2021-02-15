let scene, camera, rendered, cube, controls, helper;

function parentWidth(elem) {
  return elem.parentElement.clientWidth;
}

function parentHeight(elem) {
  return elem.parentElement.clientHeight;
}

function init3D(){
  THREE.Object3D.DefaultUp.set(0, 0, 1);
  scene = new THREE.Scene();
  scene.background = new THREE.Color(0xffffff);

  camera = new THREE.PerspectiveCamera(75, parentWidth(document.getElementById("3Dcube")) / parentHeight(document.getElementById("3Dcube")), 0.1, 1000);
  camera.position.x = 10;
  camera.position.y = 10;
  camera.position.z = 20;

  renderer = new THREE.WebGLRenderer({ antialias: true });
  renderer.setSize(parentWidth(document.getElementById("3Dcube")), parentHeight(document.getElementById("3Dcube")));

  document.getElementById('3Dcube').appendChild(renderer.domElement);

  // Create a geometry
  const geometry = new THREE.BoxGeometry(10, 5, 3);

  // Materials of each face
  var cubeMaterials = [
    new THREE.MeshBasicMaterial({color:0x03045e}),
    new THREE.MeshBasicMaterial({color:0x023e8a}),
    new THREE.MeshBasicMaterial({color:0x0077b6}),
    new THREE.MeshBasicMaterial({color:0x03045e}),
    new THREE.MeshBasicMaterial({color:0x023e8a}),
    new THREE.MeshBasicMaterial({color:0x0077b6}),
  ];

  const material = new THREE.MeshFaceMaterial(cubeMaterials);

  cube = new THREE.Mesh(geometry, material);
  scene.add(cube);
  camera.position.z = 5;
  renderer.render(scene, camera);

  var helper = new THREE.AxesHelper( 200 );
  scene.add(helper);
  controls = new THREE.OrbitControls(camera, renderer.domElement);

}

// Resize the 3D object when the browser window changes size
function onWindowResize(){
  camera.aspect = parentWidth(document.getElementById("3Dcube")) / parentHeight(document.getElementById("3Dcube"));
  //camera.aspect = window.innerWidth /  window.innerHeight;
  camera.updateProjectionMatrix();
  //renderer.setSize(window.innerWidth, window.innerHeight);
  renderer.setSize(parentWidth(document.getElementById("3Dcube")), parentHeight(document.getElementById("3Dcube")));

}

window.addEventListener('resize', onWindowResize, false);

// Create the 3D representation
init3D();

// Create events for the sensor readings
if (!!window.EventSource) {
  var source = new EventSource('/events');

  source.addEventListener('open', function(e) {
    console.log("Events Connected");
  }, false);

  source.addEventListener('error', function(e) {
    if (e.target.readyState != EventSource.OPEN) {
      console.log("Events Disconnected");
    }
  }, false);

  source.addEventListener('gyro_readings', function(e) {

    var obj = JSON.parse(e.data);
    document.getElementById("roll").innerHTML = Math.round( obj.roll* Math.PI / 180*100)/100;
    document.getElementById("pitch").innerHTML = Math.round( obj.yaw* Math.PI / 180*100)/100;
    document.getElementById("yaw").innerHTML = Math.round( obj.pitch* Math.PI / 180*100)/100;


    document.getElementById("rolldeg").innerHTML = obj.roll;
    document.getElementById("pitchdeg").innerHTML = obj.yaw;
    document.getElementById("yawdeg").innerHTML = obj.pitch;
    
    //Quaternion Readings
    document.getElementById("Qw").innerHTML = Math.round( obj.qw*100)/100;
    document.getElementById("Qx").innerHTML = Math.round( obj.qx*100)/100;
    document.getElementById("Qy").innerHTML = Math.round( obj.qy*100)/100;
    document.getElementById("Qz").innerHTML = Math.round( obj.qz*100)/100; 


    roll = -obj.roll*Math.PI/180;
    pitch = obj.pitch*Math.PI/180;
    yaw = -obj.yaw*Math.PI/180;

    // Change cube rotation after receiving the readinds
    cube.rotation.x = pitch;
    cube.rotation.y = roll;
    cube.rotation.z = yaw;


    renderer.render(scene, camera);
  }, false);

}

function resetPosition(element){
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/"+element.id, true);
  console.log(element.id);
  xhr.send();
}