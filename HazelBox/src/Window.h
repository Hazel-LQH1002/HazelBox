#pragma once
#ifndef WINDOW_H
#define WINDOW_H

enum eRenderAPI
{
	OPENGL = 0,
	VULKAN,
	DX,

	renderAPINUM
};

struct Color
{
	float r;
	float g;
	float b;
	float a;

	Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {};
	float operator[](int i)
	{
		switch (i) 
		{
			case 0: return r;
			case 1: return g;
			case 2: return b;
			case 3: return a;
			default: return -1.0f;
		}
	}
};

class Window
{
public:
	Window();
	~Window();

	bool Init(int width, int height, Color color, eRenderAPI renderAPI = eRenderAPI::OPENGL);
	void Update();

private:

	GLFWwindow* m_Handle;
	Color m_Color;
};

#endif
