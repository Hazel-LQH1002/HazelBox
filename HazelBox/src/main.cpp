#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Window.h"

/*
*  debugtool window -> imgui tools(gizmo) ->camera -> scene -> loader model texture 
* 
*   graphics -> opengl dx vk API / render -> shader
*   vulkan gl 
*   spirv  -> bitcode -> hlsl  glsl 
*   
*   GBuffer -> shadow -> ........ -> raytracing
* 
*/


int main() {
    Window window;
    Color windowColor = Color(0.2f, 0.3f, 0.3f, 1.0f);
    eRenderAPI renderAPI = eRenderAPI::OPENGL;
    window.Init(800, 600, windowColor, renderAPI);
    window.Update();
    return 0;
}