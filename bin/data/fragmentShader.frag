//Hand Pointer のフラグメントシェーダー

#version 150

uniform vec4 globalColor;

out vec4 outColor;

void main(){
	outColor = globalColor;
}