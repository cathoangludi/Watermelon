#include "Scene0.h"


using namespace GAME;

Scene0::Scene0(class Window& windowRef, class KeyboardManager& keymanRef):  Scene(windowRef) {
	keyboardManager = &keymanRef;
}
Scene0::~Scene0(){}

bool Scene0::OnCreate() {

	/// Load Assets:
	/// Background
	bg = new Texture(windowPtr->GetRenderer());

	bg->Load("res/textures/limb800x600.bmp");

	/// Title
	/// SoundEffects
	/// Models needed for this scene
	/// Music
	bgm = new Music();
	bgm->Load("res/bgm/Martin Stig Andersen - Limbo (Original Videogame Soundtrack) - 01 Menu.wav");
	bgm->Play();

	
	Debug::Log(EMessageType::INFO, "Created Scene 0", __FILENAME__, __LINE__);
	return true;
}
void Scene0::OnDestroy(){
	/// Cleanup Assets

}

void Scene0::Update(const float deltaTime){
	if (keyboardManager->IsPressed(Keyboard::Key::A)) {
		std::cout << "Pressed A" << std::endl;
	}

	if (keyboardManager->IsPressed(Keyboard::Key::W)) {
		std::cout << "Pressed W" << std::endl;
	}

	if (keyboardManager->IsPressed(Keyboard::Key::S)) {
		std::cout << "Pressed S" << std::endl;
	}

	if (keyboardManager->IsPressed(Keyboard::Key::D)) {
		std::cout << "Pressed D" << std::endl;
	}

	if (keyboardManager->IsPressed(Keyboard::Key::SPACE)) {
		std::cout << "Pressed SPACE-DESU" << std::endl;
	}
}

void Scene0::Render() const{
	windowPtr->ClearRenderer();
	/// Draw you scene
	bg->Draw();
	

	SDL_RenderPresent(windowPtr->GetRenderer());
};
