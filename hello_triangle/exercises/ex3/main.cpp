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

const GLchar* fragmentShaderSourceOne = "#version 330 core\n"
        "\n"
        "out vec4 color;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\0";

const GLchar* fragmentShaderSourceTwo = "#version 330 core\n"
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

    // Create, Compile, and Validate Fragment Shader
    GLuint fragmentShaderOne = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderOne, 1, &fragmentShaderSourceOne, NULL);
    glCompileShader(fragmentShaderOne);
    glGetShaderiv(fragmentShaderOne, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShaderOne, 512, NULL, infoLog);
        std::__1::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::__1::endl;
    }


    // Create, Compile, and Validate Fragment Shader
    GLuint fragmentShaderTwo = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderTwo, 1, &fragmentShaderSourceTwo, NULL);
    glCompileShader(fragmentShaderTwo);
    glGetShaderiv(fragmentShaderTwo, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShaderTwo, 512, NULL, infoLog);
        std::__1::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::__1::endl;
    }

    // Create, Link Shaders, and Validate Shader Program
    GLuint shaderProgramOne = glCreateProgram();
    glAttachShader(shaderProgramOne, vertexShader);
    glAttachShader(shaderProgramOne, fragmentShaderOne);
    glLinkProgram(shaderProgramOne);
    glGetProgramiv(shaderProgramOne, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(shaderProgramOne, 512, NULL, infoLog);
        std::__1::cout << "ERROR::SHADER::PROGRAM::LINKAGE_FAILED\n" << infoLog << std::__1::endl;

    }

    // Create, Link Shaders, and Validate Shader Program
    GLuint shaderProgramTwo = glCreateProgram();
    glAttachShader(shaderProgramTwo, vertexShader);
    glAttachShader(shaderProgramTwo, fragmentShaderTwo);
    glLinkProgram(shaderProgramTwo);
    glGetProgramiv(shaderProgramTwo, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(shaderProgramTwo, 512, NULL, infoLog);
        std::__1::cout << "ERROR::SHADER::PROGRAM::LINKAGE_FAILED\n" << infoLog << std::__1::endl;

    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShaderOne);
    glDeleteShader(fragmentShaderTwo);





    GLuint vertexArrayObject[2], vertexBufferObject[2];

    GLfloat vertices1[] = {
            // Triangle 1
            -1.0f, -0.5f, 0.0f, // Left-Point
            0.0f, -0.5f, 0.0f, // Center
            -0.5f, 0.5f, 0.0f // Left-Top
    };

    GLfloat vertices2[] = {
            // Triangle 2
            1.0f, -0.5f, 0.0f, // Right-Point
            0.0f, -0.5f, 0.0f, // Center
            0.5f, 0.5f, 0.0f // Right-Top

    };

    glGenVertexArrays(2, vertexArrayObject);
    glGenBuffers(2, vertexBufferObject);

    // ROUND 1
    // Bind Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(vertexArrayObject[0]);

    // Copy triangleVertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);

    // Set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Unbind the Vertex Array Object;
    glBindVertexArray(0);


    // ROUND 2
    glBindVertexArray(vertexArrayObject[1]);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgramOne);

        glBindVertexArray(vertexArrayObject[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);


        glUseProgram(shaderProgramTwo);

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