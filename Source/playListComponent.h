/*
  ==============================================================================

    playListComponent.h
    Created: 20 Aug 2023 6:24:32am
    Author:  ahmed

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <vector>
#include <string>
//==============================================================================
/*
*/
class playListComponent  : public juce::Component,
                           public juce::TableListBoxModel,
                           public juce::Button::Listener
{
public:
    playListComponent(int _idStart);
    ~playListComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    int getNumRows() override;
    void paintRowBackground(Graphics&, int rowNumber,
                            int width, int height,
                            bool rowIsSelected) override;
    void paintCell(Graphics&, int rowNumber,
                    int columnId, int width, 
                    int height, bool rowIsSelected) override;
    Component* refreshComponentForCell(int rowNumber, int columnId,
        bool isRowSelected, Component* existingComponentToUpdate)override;
    void buttonClicked(Button* button)override;
private:
    TableListBox tableComponent;
    std::vector<std::string> trackTitles;
    int butCol;
    int durCol;
    int idStart;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (playListComponent)
};
