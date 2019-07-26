#pragma once

#include "core.h"

#include "Camera.h"
#include "Light.h"
#include "MeshRenderer.h"




class Application
{
public:
	//Every object created must have a new id
	//unsigned int GLOBAL_ID; //replaced with extern
	SDL_Window *win;
	SDL_GLContext glContext;
	int win_width = 800;
	int win_heigth = 600;

	//static double deltaTime;
	int mouse_lastPosX;
	int mouse_lastPosY;
	int mouse_deltaX;
	int mouse_deltaY;

	unsigned long long NOW, LAST;

	bool running;
	bool captureMouse = true;

	bool KeyPressed[256];
	Vec4 bgColor{0.2f,0.2f,0.2f, 1};

	int actCam = 0;
	ShaderProgram* shaders[30]{nullptr};
	std::vector<Light*> LIGHTS;
	//std::vector < Camera*> orderedCameras;
	std::vector < Camera*> cameras;
	std::vector<MeshRenderer*> renderers;
	std::vector<Model> models;
	std::vector<GameObject *> rootNodes;
	std::map<std::string, Shader*> shadersLoaded;
	std::map<std::string, Texture*> texturesLoaded;
	CubeMap *cubeMap;
public:



	//static double DeltaTime() { return deltaTime; }
	void GLCreate(objl::Loader & model);
	void Steal(Component *);
	void HandleEvents();
	unsigned int VBO, VAO, EBO;
	void Setup(const std::vector<std::string>&, const std::vector<std::tuple<std::string, std::string>>&);
	void SetupScene();
	void SetupModels(const std::vector<std::string>& objPathsp);
	void SetupShaders(const std::vector<std::tuple<std::string, std::string>>& shaderPaths);

	//void RenderFrame() {

	//}




	ShaderProgram* shaderTri;
	void SetupDummy();

	void DummyLoop();

	void LoopMain();
	void LoopUI();
	void LoopUpdate();
	void LoopRender();
	void DrawFrame(Transform t);
	Application();
	~Application();
};