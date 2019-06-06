//
//  MainComponent.hpp
//  AnimatedGif
//
//  Created by Sander ter Braak on 04/06/2019.
//
//

#include "MainComponent.h"


MainComponent::MainComponent()
{
    
    File f("~/Desktop/test2.gif");
    
    
    AnimatedGIFImage animation;
    animation = AnimatedGIFImage::getFromFile(f);
    
    gif = new AnimatedGIFComponent();
    gif->setImage(animation);
    gif->start();
    addAndMakeVisible(gif);
    
    
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint (Graphics& g)
{
}

void MainComponent::resized()
{
    gif->setBounds(0, 0, gif->getGIFWidth(), gif->getGIFHeight());
}
