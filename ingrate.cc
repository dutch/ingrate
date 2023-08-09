#include <glad/gl.h>
#include <GLFW/glfw3.h>

int main() {
  glfwInit();
  GLFWwindow *window = glfwCreateWindow(400, 300, "Ingrate", nullptr, nullptr);
  gladLoadGL(glfwGetProcAddress);
  glfwTerminate();
}
