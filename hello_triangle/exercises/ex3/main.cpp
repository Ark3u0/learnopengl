// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include <iostream>

const GLchar* vertexShaderSource = "#version 330 core\n"
        "\n"
        "layout (location = 0) in vec3 position;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
        "}\0";

const GLchar* fragmentShaderSourceForTriangleOne = "#version 330 core\n"
        "\n"
        "out vec4 color;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\0";

const GLchar* fragmentShaderSourceForTriangleTwo = "#version 330 core\n"
        "\n"
        "out vec4 color;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   color = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
        "}\0";

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    int framebufferWidth, framebufferHeight;
    glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
    glViewport(0, 0, framebufferWidth, framebufferHeight);

    // Create, Compile, and Validate Vertex Shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::__1::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::__1::endl;
    }

    // Create, Compile, and Validate Fragment Shader For Triangle One
    GLuint fragmentShaderForTriangleOne = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderForTriangleOne, 1, &fragmentShaderSourceForTriangleOne, NULL);
    glCompileShader(fragmentShaderForTriangleOne);
    glGetShaderiv(fragmentShaderForTriangleOne, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShaderForTriangleOne, 512, NULL, infoLog);
        std::__1::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::__1::endl;
    }

    // Create, Compile, and Validate Fragment Shader For Triangle Two
    GLuint fragmentShaderForTriangleTwo = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderForTriangleTwo, 1, &fragmentShaderSourceForTriangleTwo, NULL);
    glCompileShader(fragmentShaderForTriangleTwo);
    glGetShaderiv(fragmentShaderForTriangleTwo, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShaderForTriangleTwo, 512, NULL, infoLog);
        std::__1::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::__1::endl;
    }

    // Create, Link Shaders, and Validate Shader Program For Triangle One
    GLuint shaderProgramForTriangleOne = glCreateProgram();
    glAttachShader(shaderProgramForTriangleOne, vertexShader);
    glAttachShader(shaderProgramForTriangleOne, fragmentShaderForTriangleOne);
    glLinkProgram(shaderProgramForTriangleOne);
    glGetProgramiv(shaderProgramForTriangleOne, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(shaderProgramForTriangleOne, 512, NULL, infoLog);
        std::__1::cout << "ERROR::SHADER::PROGRAM::LINKAGE_FAILED\n" << infoLog << std::__1::endl;
    }

    // Create, Link Shaders, and Validate Shader Program For Triangle Two
    GLuint shaderProgramForTriangleTwo = glCreateProgram();
    glAttachShader(shaderProgramForTriangleTwo, vertexShader);
    glAttachShader(shaderProgramForTriangleTwo, fragmentShaderForTriangleTwo);
    glLinkProgram(shaderProgramForTriangleTwo);
    glGetProgramiv(shaderProgramForTriangleTwo, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(shaderProgramForTriangleTwo, 512, NULL, infoLog);
        std::__1::cout << "ERROR::SHADER::PROGRAM::LINKAGE_FAILED\n" << infoLog << std::__1::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShaderForTriangleOne);
    glDeleteShader(fragmentShaderForTriangleTwo);


    GLuint vertexArrayObject[2], vertexBufferObject[2];

    GLfloat verticesForTriangleOne[] = {
            // First Triangle
            -1.0f, -0.5f, 0.0f,
            0.0f, -0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f
    };
    GLfloat verticesForTriangleTwo[] = {
            // Second Triangle
            1.0f, -0.5f, 0.0f,
            0.0f, -0.5f, 0.0f,
            0.5f, 0.5f, 0.0f
    };

    glGenVertexArrays(2, vertexArrayObject);
    glGenBuffers(2, vertexBufferObject);

    // Bind Vertex Array Object for first triangle, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(vertexArrayObject[0]);

    // Copy triangleOneVertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesForTriangleOne), verticesForTriangleOne, GL_STATIC_DRAW);

    // Set our vertex attributes pointers for vertexArrayObject of triangle 1
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // Unbind the Vertex Array Object;
    glBindVertexArray(0);

    // Redo for second triangle
    glBindVertexArray(vertexArrayObject[1]);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesForTriangleTwo), verticesForTriangleTwo, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgramForTriangleOne);
        glBindVertexArray(vertexArrayObject[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgramForTriangleTwo);
        glBindVertexArray(vertexArrayObject[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }
    glDeleteVertexArrays(2, vertexArrayObject);
    glDeleteBuffers(2, vertexBufferObject);

    glfwTerminate();
    return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}