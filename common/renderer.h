#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <common/sprite.h>
#include <common/actor.h>
#include <common/scene.h>

class Renderer
{
	public:
		Renderer(unsigned int w, unsigned int h);
		virtual ~Renderer();

		void renderSprite(Sprite* sprite, float px, float py, float sx, float sy, float rot);
		void renderScene(Scene* scene);
		GLuint renderToScreen(GLuint _id);

		GLFWwindow* window() { return _window; };

		unsigned int width() { return _window_width; };
		unsigned int height() { return _window_height; };

		GLuint programID;
		GLuint blurProgramID;

	private:
		int init();

		GLFWwindow* _window;
		unsigned int _window_width;
		unsigned int _window_height;

		void _renderActor(Actor* actor);

		GLuint loadShaders(
			const std::string& vertex_file_path,
			const std::string& fragment_file_path
		);

		glm::mat4 _projectionMatrix;
};

#endif /* RENDERER_H */
