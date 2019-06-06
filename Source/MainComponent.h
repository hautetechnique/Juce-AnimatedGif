//
//  MainComponent.cpp
//  AnimatedGif
//
//  Created by Sander ter Braak on 04/06/2019.
//
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AnimatedGIFImage.hpp"
#include "AnimatedGIFComponent.hpp"

class MainComponent   : public Component
{
public:

    MainComponent();
    ~MainComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    
    ScopedPointer<AnimatedGIFComponent> gif;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
