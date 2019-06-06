//
//  AnimatedGIFComponent.hpp
//  AnimatedGif
//
//  Created by Sander ter Braak on 05/06/2019.
//
//

#ifndef AnimatedGIFComponent_hpp
#define AnimatedGIFComponent_hpp

#include "../JuceLibraryCode/JuceHeader.h"
#include "AnimatedGIFImage.hpp"

class AnimatedGIFComponent : public Component, public Timer
{

public:
	
	AnimatedGIFComponent();
	~AnimatedGIFComponent();
    
    void setImage(const AnimatedGIFImage & img);
    void setMouseOverPlaysAnimation(bool plays);
    
    void start();
    void stop();
    void pauze();
    
    void setSpeed(float speed);
    
    int getGIFWidth();
    int getGIFHeight();
    
private:
    
    
    
    int currentFrame{0};
    AnimatedGIFImage img;
	
    void timerCallback() override;
    void paint (Graphics& g) override;
    void resized() override ;
	
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AnimatedGIFComponent)

};

#endif /* AnimatedGIFComponent_hpp */
