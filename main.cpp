//
// Created by maxim on 22.05.2019.
//

#include "filedata.h"
#include "createGameLoop.h"
#include <memory>

using namespace std;

bool state[2]={false};

void key_callback(GLFWwindow * window,int key,int scancode,int action,int mode)
{
    if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window,GL_TRUE);
    }


    if((key==GLFW_KEY_LEFT || key==GLFW_KEY_A)&& action ==GLFW_PRESS)
    {
        if(state[1])
        {
            state[1]=false;
        }

        state[0]=true;
    }

    else if((key==GLFW_KEY_RIGHT || key==GLFW_KEY_D) && action == GLFW_PRESS)
    {
        if(state[0])
        {
            state[0]=false;
        }

        state[1]=true;
    }

}

void resize (GLFWwindow * window, int w, int h)
{
    glViewport(0,0,w,h);
}

//Check setting. If "full" make full screen window, null not full screen
GLFWwindow * createDisplay(vector<string> fileData)
{
    GLFWwindow * window;
    string name="test";

    //if(fileData.at(0)=="full")
    //{
    //    window=createMonitor(name.c_str());
    //}

    //else
    //{
    window=createWindow(name.c_str());
    //}

    return window;
}


/*
 Задания:
     * поправить размерность массива
     * вернуть текстуры
     * сделать плавное движение платформы
     * сделать плавное движение шарика
     * отбивания шарика от платформа и стенок
 */

int main()
{
    BaseGameObject * ball=nullptr,* platform=nullptr;
    vector<string> fileData=getClearDataFromFile();
    GLFWwindow * window=createDisplay(fileData);
    glfwSetFramebufferSizeCallback (window, resize);
    ball = createBall(window);
    platform = createPlatform(window, state);
    glfwSetKeyCallback(window, key_callback);
    mainloop(ball,platform,window);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
