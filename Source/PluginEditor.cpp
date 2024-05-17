/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortionAudioProcessorEditor::DistortionAudioProcessorEditor (DistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 200);
    
    driveSlider.setSliderStyle (juce::Slider::Rotary);
    driveSlider.setRange (0.1f, 5.0, 0.0001);
    driveSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 100, 10);
    driveSlider.setValue(0.1);
    driveSlider.addListener(this);
    
    rangeSlider.setSliderStyle(juce::Slider::Rotary);
    rangeSlider.setRange(1.f, 10, 0.0001);
    rangeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 10);
    rangeSlider.setValue(1);
    rangeSlider.addListener(this);
    
    blendSlider.setSliderStyle(juce::Slider::Rotary);
    blendSlider.setRange(0.f, 1.0, 0.0001);
    blendSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 10);
    blendSlider.setValue(0.5);
    blendSlider.addListener(this);
    
    volumeSlider.setSliderStyle(juce::Slider::Rotary);
    volumeSlider.setRange(0.f, 1.0, 0.0001);
    volumeSlider.setSkewFactorFromMidPoint(0.1);
    volumeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 10);
    volumeSlider.setValue(0.5);
    volumeSlider.addListener(this);
    
    
    addAndMakeVisible(&driveSlider);
    addAndMakeVisible(&rangeSlider);
    addAndMakeVisible(&blendSlider);
    addAndMakeVisible(&volumeSlider);
    
    // Create and configure the label
    driveLabel.setText("Drive", juce::dontSendNotification);
    driveLabel.attachToComponent(&driveSlider, false);
    driveLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&driveLabel);
    
    rangeLabel.setText("Range", juce::dontSendNotification);
    rangeLabel.attachToComponent(&rangeSlider, false);
    rangeLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&rangeLabel);
    
    
    blendLabel.setText("Blend", juce::dontSendNotification);
    blendLabel.attachToComponent(&blendSlider, false);
    blendLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&blendLabel);
    
    volumeLabel.setText("Volume", juce::dontSendNotification);
    volumeLabel.attachToComponent(&volumeSlider, false);
    volumeLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&volumeLabel);
    
    
    
}

DistortionAudioProcessorEditor::~DistortionAudioProcessorEditor()
{
}

//==============================================================================
void DistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    //juce::Image background = juce::ImageCache::getFromMemory (BinaryData::tictacteo_png, BinaryData::tictacteo_pngSize);
      //  g.drawImageAt (background, 0, 0);
        // ...
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void DistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    driveSlider.setBounds((getWidth() / 5 * 1) - (100 / 2), (getHeight() / 5 * 2) - (100 / 2), 100, 100);
    rangeSlider.setBounds((getWidth() / 5 * 2) - (100 / 2), (getHeight() / 5 * 2) - (100 / 2), 100, 100);
    blendSlider.setBounds((getWidth() / 5 * 3) - (100 / 2), (getHeight() / 5 * 2) - (100 / 2), 100, 100);
    volumeSlider.setBounds((getWidth() / 5 * 4) - (100 / 2), (getHeight() / 5 * 2) - (100 / 2), 100, 100);
}


void DistortionAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &driveSlider)
    {
        audioProcessor.drive = driveSlider.getValue();
    }
    if (slider == &rangeSlider)
    {
        audioProcessor.range = rangeSlider.getValue();
    }
    if (slider == &blendSlider)
    {
        audioProcessor.blend = blendSlider.getValue();
    }
    if (slider == &volumeSlider)
    {
        audioProcessor.volume = volumeSlider.getValue();
    }
}
