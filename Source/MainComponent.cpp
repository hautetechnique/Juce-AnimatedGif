/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    
    AnimatedGIFImageFormat a;
    File f("/Users/sanderterbraak/Desktop/test.gif");
    
    
    AnimatedGIFImage animation;
    animation = AnimatedGIFImage::getFromFile(f);
    
    gif = new AnimatedGIFComponent();
    gif->setImage(animation);
    addAndMakeVisible(gif);
    gif->start();
    
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}



//==============================================================================
void MainComponent::paint (Graphics& g)
{
    
   
    
   
}

void MainComponent::resized()
{
    
    gif->setBounds(0, 0, gif->getGIFWidth(), gif->getGIFHeight());
}
