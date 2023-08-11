#include <iostream>
#include <memory>
#include <stdexcept>
#include <sstream>
#include <GLFW/glfw3.h>

namespace glfw {
  namespace {
    struct window_deleter {
      void operator()(GLFWwindow *p) {
        glfwDestroyWindow(p);
      }
    };
  }

  class window {
    std::unique_ptr<GLFWwindow, window_deleter> p;

  public:
    template<typename... Args>
    window(Args&& ...args) : p(glfwCreateWindow(std::forward<Args>(args)...)) {}

    bool should_close() {
      return glfwWindowShouldClose(p.get());
    }
  };
}

void error_callback(int error_code, const char* description) {
  std::stringstream ss;
  ss << "GLFW error: " << description;
  throw std::runtime_error(ss.str());
}

int main() try {
  glfwSetErrorCallback(error_callback);
  glfwInit();
  {
    glfw::window window(400, 300, "Ingrate", nullptr, nullptr);
    while (!window.should_close())
      glfwWaitEvents();
  }
  glfwTerminate();
} catch (std::runtime_error const& e) {
  std::cerr << e.what() << std::endl;
}
