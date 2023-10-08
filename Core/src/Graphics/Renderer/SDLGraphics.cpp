#include "Graphics/Window/SDLGraphics.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

#include "glad/glad.h"
#include "Application/GameBase.h"

SDL_GLContext context;

SDLGraphics::SDLGraphics() {

}

void SDLGraphics::Init(bool createWindow) {
    this->width = 1024;
    this->height = 768;

    SDL_Init(SDL_INIT_EVERYTHING);

    if(createWindow)
        window = SDL_CreateWindow("pledGL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 680, 480, SDL_WINDOW_OPENGL);

    context = SDL_GL_CreateContext(window);
    renderer = SDL_CreateRenderer(window, -1, 0);

    gladLoadGLLoader(SDL_GL_GetProcAddress);

    SDL_Surface* surface = NULL;

    std::cout << "Window created!";
}

void SDLGraphics::Exit() {
    SDL_DestroyWindow(window);
    SDL_GL_DeleteContext(context);
    SDL_Quit();

    window = NULL; 
    renderer = NULL;
}

void SDLGraphics::Render() {
    // TODO: Move this into proper class, instead of this junk.
    const char* vertexShaderSource = R"(
    #version 330 core
    layout(location = 0) in vec3 aPos;
    void main() {
        gl_Position = vec4(aPos, 1.0);
    }
    )";

    const char* fragmentShaderSource = R"(
    #version 330 core
    out vec4 FragColor;
    void main() {
        FragColor = vec4(1.0, 1.0, 0.0, 1.0); // Red color
    }
    )";

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };
    unsigned int indices[] = {
        0,1,2
    };

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Create a Vertex Buffer Object (VBO) to store the vertex data
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

    SDL_GL_SwapWindow(window);
}

void SDLGraphics::ProcessInput(GameBase* context) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch(e.type) {
            case SDL_QUIT:
                Exit();
                context->End();
                break;
            case SDL_WINDOWEVENT:
                std::cout << "Moved window";
                break;
        }
    } 
}

void SDLGraphics::StartLoop(int fps) {
    frameDelay = 1000.0f / 60;
    frameStart = SDL_GetTicks64();
}
void SDLGraphics::EndLoop() {
    // TODO: Remove this line
    Render();
    frameTime = SDL_GetTicks64() - frameStart;
    deltaTime = frameTime/1000.0f;

    if(frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime);
    }
}