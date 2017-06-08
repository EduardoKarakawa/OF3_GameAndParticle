#pragma once
#include "ofBaseApp.h"
#include "ofImage.h"
#include "ofVec2f.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

class GameObject
{
protected:
	ofVec2f m_position;
	int m_width;
	int m_height;
	uint64_t frameIndex;
	int m_iFrame;
	int m_sequenceFPS;
	ofImage m_image;
	vector <ofImage> m_images;
	ofDirectory m_dir;

public:
	GameObject();
	
	void LoadNewImage(string folder, string image);
	void LoadNewAnimation(string folder);
	
	void DrawImage();
	void DrawImage(int x, int y);
	void DrawAnimation();
	void DrawAnimation(int x, int y);
	void DrawAnimationFrame(int frame);

	ofVec2f GetPosition() const;
	void SetPosition(ofVec2f &position);

	bool OnScreen();

};