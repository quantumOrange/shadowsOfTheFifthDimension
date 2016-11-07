#version 150

uniform mat4 modelViewProjectionMatrix;
in vec2 texcoord;

in vec4 position;
out vec2 texCoordVarying;


void main(){
    texCoordVarying = texcoord;
	gl_Position = modelViewProjectionMatrix * position;
}
