/*
 * @author Alexander Bassov
 */

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <Windows.h>
#include <fstream>
#include <sstream>

int InitOpenGL()
{
	return 42;
}
/*
int main()
{
	// Inits glfw
	const int windowWidth = 500;
	const int windowHeight = 500;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

	GLFWwindow* windowHandle = glfwCreateWindow(windowWidth, windowHeight, "Schexy Cow", nullptr, nullptr);

	if (windowHandle == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// https://www.glfw.org/docs/latest/group__context.html#ga1c04dc242268f827290fe40aa1c91157
	glfwMakeContextCurrent(windowHandle);

	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// The render area. "Where does the coordinate system begin?"
	glViewport(0, 0, windowWidth, windowHeight);

	float clearColor[] = { .5f, 1.0f, .5f, 1.0f };

	// A "vertex" is a point which contains more information
	// about a specific point in space
	// Eg. 2d position, 2d texture coordinate

	// Create vertex array
	// A vertex array bundles vertex buffer, index buffer and vertex layout together
	unsigned int vertexArrayId;
	glGenVertexArrays(1, &vertexArrayId);

	// Next operations are meant for this array id
	glBindVertexArray(vertexArrayId);

	// Vertex buffer is needed to pass down vertices
	// to the graphics card under which memory is allocated
	unsigned int vertexBufferId;
	glGenBuffers(1, &vertexBufferId);

	// This means that all next operations are meant to be executed for this buffer id
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);

	// This is considered a "mesh"
	int textureWidth = 96;
	int textureHeight = 64;
	float deltaX = 2.0f / (float) windowWidth;
	float deltaY = 2.0f / (float) windowHeight;

	float vertices[] = {
		// Bottom left
		//-1.0f, 1.0f - deltaY * textureHeight,
		-1.0f, -1.0f,
		0.0f, 1.0f,
		// Bottom right
		//-1.0f + deltaX * textureWidth, 1.0f - deltaY * textureHeight,
		//-1.0f + deltaX * textureWidth, 1.0f - deltaY * textureHeight,
		1.0f, -1.0f,
		1.0f, 1.0f,
		// Top right
		//-1.0f + deltaX * textureWidth, 1.0f,
		//-1.0f + deltaX * textureWidth, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		// Top left
		//-1.0f, 1.0f,
		-1.0f, 1.0f,
		0.0f, 0.0f };

	// Pass down data to the graphic card
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// "Vertex layout"
	//
	// Since the full size of a single vertex is 4 this tells opengl
	// that the first two indicies of a set are position data
	// and the following two are texture data
	//
	// A "stride" is basically a vertex. We have 4 for example
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*) (2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// Create triangle associations by defining
	// which vertices belong to which triangle we want to draw
	unsigned int vertexIndicesForTriangles[] = {
		0, 1, 3,
		1, 2, 3 };

	// Allocate memory for the elements and get the id to it
	unsigned int indexBufferId;
	glGenBuffers(1, &indexBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vertexIndicesForTriangles), vertexIndicesForTriangles, GL_STATIC_DRAW);

	// glBindVertexArray(0);

	// Unbind basically reset the context for opengl so it doesn't think
	// the next operations are meant for the id previously bound
	// glBindVertexArray(0);

	// Vertex Shader
	//
	// Read vertex shader
	std::ifstream vertexShaderStream("shader.vert");

	if (!vertexShaderStream.is_open()) {
		std::cout << "Lappen weil Datei nicht offen" << std::endl;

		return 1;
	}

	std::ostringstream vertexShaderFileBuffer;
	vertexShaderFileBuffer << vertexShaderStream.rdbuf();
	std::string vertexShaderString = vertexShaderFileBuffer.str();

	const char* vertexShaderCString = vertexShaderString.c_str();
	unsigned int vertexShaderId;
	vertexShaderId = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShaderId, 1, &vertexShaderCString, nullptr);
	glCompileShader(vertexShaderId);

	int vertexShaderCompilingResult;
	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &vertexShaderCompilingResult);

	if (!vertexShaderCompilingResult) {
		char infoLog[512];
		glGetShaderInfoLog(vertexShaderId, 512, nullptr, infoLog);
		std::cout << "Failed to compile vertex shaders: " << infoLog << std::endl;

		return 2;
	}

	// Fragment shader
	//
	// Read fragment shader
	std::ifstream fragmentShaderStream("shader.frag");

	if (!fragmentShaderStream.is_open()) {
		std::cout << "Lappen weil Datei nicht offen" << std::endl;

		return 3;
	}

	std::ostringstream fragmentShaderFileBuffer;
	fragmentShaderFileBuffer << fragmentShaderStream.rdbuf();
	std::string fragmentShaderString = fragmentShaderFileBuffer.str();

	const char* fragmentShaderCString = fragmentShaderString.c_str();
	unsigned int fragmentShaderId;
	fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShaderId, 1, &fragmentShaderCString, nullptr);
	glCompileShader(fragmentShaderId);

	int fragmentShaderCompilingResult;
	glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &fragmentShaderCompilingResult);

	if (!fragmentShaderCompilingResult) {
		char infoLog[512];
		glGetShaderInfoLog(fragmentShaderId, 512, nullptr, infoLog);
		std::cout << "Failed to compile fragment shaders: " << infoLog << std::endl;

		return 4;
	}

	// Create shader program
	unsigned int shaderProgramId = glCreateProgram();

	glAttachShader(shaderProgramId, vertexShaderId);
	glAttachShader(shaderProgramId, fragmentShaderId);
	glLinkProgram(shaderProgramId);

	// Check linking result
	int linkingResult;
	glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &linkingResult);

	if (!linkingResult) {
		char infoLog[512];
		glGetProgramInfoLog(shaderProgramId, 512, nullptr, infoLog);

		std::cout << "Linking failed you moron" << std::endl;

		return 5;
	}

	// Delete vertex and fragment shader
	// Since we created the shader program we dont need the shaders anymore
	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);

	// Texures !!!
	unsigned int textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	// Texture wrapping // S = x axis // T = y axis
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Sampling
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Load image pixels from the sprite
	int width, height, nrChannels;
	unsigned char* pixelData = stbi_load("../assets/cow.png", &width, &height, &nrChannels, 0);

	if (pixelData == nullptr) {
		std::cout << "Failed to load image" << std::endl;

		return 6;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixelData);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(pixelData);

	// Define which shader we want to use
	glUseProgram(shaderProgramId);

	glUniform1i(glGetUniformLocation(shaderProgramId, "ourTexture"), 0);

	// Enable alphachannel blending. Eg. in png image files
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS); // Ensures messages are delivered immediately

	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE); // Enable all messages

	while (!glfwWindowShouldClose(windowHandle)) {
		glfwPollEvents();

		if (glfwGetKey(windowHandle, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(windowHandle, true);
		}

		glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
		glClear(GL_COLOR_BUFFER_BIT);

		// Set opengl context to be this vertex array and the texture
		glBindVertexArray(vertexArrayId);

		glUseProgram(shaderProgramId);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureId);

		// Finally draw some shit
		glDrawElements(GL_TRIANGLES, sizeof(vertexIndicesForTriangles), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(windowHandle);
	}

	glfwTerminate();

	return 0;
}
*/