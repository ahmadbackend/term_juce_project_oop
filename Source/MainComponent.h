/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DJAudioPlayer.h"
#include "DeckGUI.h"
#include "playListComponent.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent : public AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint(Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...

    AudioFormatManager formatManager;
    AudioThumbnailCache thumbCache{ 100 };
    playListComponent playList1{1};
    playListComponent playList2{4};
    

    DJAudioPlayer player1{formatManager};
    DeckGUI deckGUI1{&player1, formatManager, &playList1, thumbCache}; 

    DJAudioPlayer player2{formatManager};
    DeckGUI deckGUI2{&player2, formatManager, &playList2, thumbCache}; 

    MixerAudioSource mixerSource; 
    

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
