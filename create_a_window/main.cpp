// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include <iostream>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    // When a user presses the escape key, we set the WindowShouldClose property to true,
    // closing the application
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main() {

    /*
     * glfwInit - initialize GLFW context
     * glfwWindowHint - configure GLFW; first option tells what to configure, second option selects options value
     */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Necessary for OSX compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create window with dimensions and title
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Set window as current context
    glfwMakeContextCurrent(window);

    // Setting to true ensures GLEW uses more modern techniques for managing OpenGL functionality
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    int framebufferWidth, framebufferHeight;
    glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);

    // First two parameters set location of lower left corner of window.
    // Third and fourth parameters set width and height of rendering window in pixels, which we retrieve from GLFW itself.
    // Taking viewport dimensions from GLFW instead of 800 x 600 allows it to also work on high DPI screens (i.e. retina displays)
    glViewport(0, 0, framebufferWidth, framebufferHeight);

    glfwSetKeyCallback(window, key_callback);

    /*
     * glfwWindowShouldClose - checks if GLFW has been instructed to close.
     * glfwPollEvents - checks if any events are triggered (i.e. keyboard input or mouse movement) and calls corresponding
     *      functions (which can be set via callback methods). Usually call eventprocessing functions at start of loop
     * glfwSwapBuffers - swap color buffer (large buffer containing color values for each pixel in GLFW window)
     */
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    /*
     * Double vs. Single buffer drawing - front buffer contains final output image shown on screen, while
     * all rendering commands draw back buffer. As soon as commands are finished, swap front and back to remove
     * old artifacts.
     */

    /*
     * glfwTerminate - clean/delete all resources that were allocated for glfw
     */
    glfwTerminate();
    return 0;
}