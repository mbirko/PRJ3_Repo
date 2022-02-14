// Setup imports
// Following is an old version of the CDN - but the new one has weird syntax
// The code needs to run on a local server for index.html to be displayed
import * as THREE from 'https://cdn.skypack.dev/three@0.128.0/build/three.module.js';
import { OrbitControls } from 'https://cdn.skypack.dev/three@0.128.0/examples/jsm/controls/OrbitControls.js';

// Setup scene
const scene = new THREE.Scene();

// init camera
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);

// Init renderer
const renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

// // Create stuff to be rendered
// const geometry = new THREE.BoxGeometry();
// const material = new THREE.MeshBasicMaterial({ color: 0x00ff00 });
// const cube = new THREE.Mesh(geometry, material);
const vertices = [];
const numverts = 1000;
for(let i = 0; i < numverts; i++) {
    // Assosiate a random position with each vertex
    const x = THREE.MathUtils.randFloatSpread(100);
    const y = THREE.MathUtils.randFloatSpread(100);
    const z = THREE.MathUtils.randFloatSpread(100);
    vertices.push(x, y, z);
    // this will result in:
    // vertices = [x, y, z, x, y, z, x, y, z, ...]
    // and such vertices.length = numverts * 3
}
console.log(vertices.length)
const geometry = new THREE.BufferGeometry();
geometry.setAttribute('position', new THREE.Float32BufferAttribute( vertices, 3 ));
const material = new THREE.PointsMaterial({ color: 0x888888});
const points = new THREE.Points(geometry, material);

// // Add said stuff to scene
// scene.add(cube);
scene.add(points);

// Settings for camera
camera.position.z = 200;
const controls = new OrbitControls( camera, renderer.domElement );

// Render loop
function animate() {
    requestAnimationFrame(animate);
    renderer.render(scene, camera);
}
animate();

// add resize listener
window.addEventListener('resize', () => {
    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix();
    renderer.setSize(window.innerWidth, window.innerHeight);
});