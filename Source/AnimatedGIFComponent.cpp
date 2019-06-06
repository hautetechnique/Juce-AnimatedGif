//
//  AnimatedGIFComponent.cpp
//  AnimatedGif
//
//  Created by Sander ter Braak on 05/06/2019.
//
//

#include "AnimatedGIFComponent.hpp"


AnimatedGIFComponent::AnimatedGIFComponent()
{
	
}

AnimatedGIFComponent::~AnimatedGIFComponent()
{

}

int AnimatedGIFComponent::getFrameRate()
{
    return framerate;
}

void AnimatedGIFComponent::useDefaultFramerate()
{
    
    framerate = 0;
    if(img.getNumFrames() > 0)
        framerate = img.getFrameDuration(0);
    
    if(framerate == 0) framerate = 100;
}

void AnimatedGIFComponent::setFrameRate(int ms)
{
    if(framerate != ms)
    {
        framerate = ms;
        if(isTimerRunning())
        {
            stopTimer();
            startTimer(framerate);
        }
    }
}

void AnimatedGIFComponent::start()
{
    if(framerate < 0) useDefaultFramerate();
    
    startTimer(framerate);
}

void AnimatedGIFComponent::stop()
{
    stopTimer();
    currentFrame = 0;
    repaint();
}

void AnimatedGIFComponent::pauze()
{
    stopTimer();
}

void AnimatedGIFComponent::timerCallback()
{
    if(img.getNumFrames() < 2)
    {
        currentFrame = 0;
        stopTimer();
        return;
    }
    currentFrame++;
    if(currentFrame > img.getNumFrames() - 1) currentFrame = 0;
    
    repaint();
}

void AnimatedGIFComponent::setImage(const AnimatedGIFImage & img)
{
    this->img = img;
    currentFrame = 0;
    framerate = -1;
    repaint();
}

int AnimatedGIFComponent::getGIFWidth()
{
    if(img.getNumFrames() > 0)
        return img.getFirst().getWidth();
    return 0;
}

int AnimatedGIFComponent::getGIFHeight()
{
    if(img.getNumFrames() > 0)
        return img.getFirst().getHeight();
    return 0;
}

void AnimatedGIFComponent::paint (Graphics& g)
{
    if(img.getNumFrames() > 0 && currentFrame < img.getNumFrames())
    {
        g.drawImage(img.getUnchecked(currentFrame),
                    0, 0, getWidth(), getHeight(),
                    0, 0, img.getFirst().getWidth(), img.getFirst().getHeight());
    }
}
   
void AnimatedGIFComponent::resized()
{
    // repaint?
    //repaint();
}
