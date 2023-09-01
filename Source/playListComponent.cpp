/*
  ==============================================================================

    playListComponent.cpp
    Created: 20 Aug 2023 6:24:32am
    Author:  ahmed

  ==============================================================================
*/

#include <JuceHeader.h>
#include "playListComponent.h"

//==============================================================================
playListComponent::playListComponent( int _idStart)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    trackTitles.push_back("track 1");
    trackTitles.push_back("track 2");
    idStart = _idStart;
    durCol = idStart + 2;
    butCol = idStart + 1;
    tableComponent.getHeader().addColumn("tracks", idStart, 200);
    tableComponent.getHeader().addColumn("", butCol, 100);
    tableComponent.getHeader().addColumn("duration", durCol, 100);

   
    tableComponent.setModel(this);
    addAndMakeVisible(tableComponent);
}

playListComponent::~playListComponent()
{
}

void playListComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("playListComponent", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void playListComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    tableComponent.setBounds(0, 0, getWidth(), getHeight());

}
int playListComponent::getNumRows()
{
    return trackTitles.size();
};
void playListComponent::paintRowBackground(Graphics&g, int rowNumber,
    int width, int height,
    bool rowIsSelected)
{
    if (rowIsSelected)
    {
        g.fillAll(Colours::orange);
    }
    else
    {
        g.fillAll(Colours::darkgrey);
    }

};
void playListComponent::paintCell(Graphics&g, int rowNumber,
    int columnId, int width,
    int height, bool rowIsSelected)
{
    g.drawText(trackTitles[rowNumber], 2, 0, width - 4, height, Justification::centredLeft, true);
};
Component* playListComponent::refreshComponentForCell(int rowNumber, int columnId,
    bool isRowSelected, Component* existingComponentToUpdate)
{
    if (columnId == butCol)
    {
        if (existingComponentToUpdate == nullptr)
        {
            TextButton* btn = new TextButton{ "play" };
            String id{ std::to_string (rowNumber) };

            btn->setComponentID(id);
            btn->addListener(this);
            existingComponentToUpdate = btn;
        }
    }
    return existingComponentToUpdate;
}
void playListComponent::buttonClicked(Button* button)
{
    std::cout << "playListComponent::buttonClicked" << std::endl;
    int id = std::stoi(button->getComponentID().toStdString());
};