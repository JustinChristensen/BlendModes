/**
 * Blend Mode Functions
 *
 * http://stackoverflow.com/questions/5919663/how-does-photoshop-blend-two-images-together
 * http://en.wikipedia.org/wiki/Blend_modes
 *
 * Justin Christensen
 * Thu May 30 19:00:05 2013
 */

#ifndef BlendModeMacros_H_
#define BlendModeMacros_H_ 1

#include <cstdint>
#include <algorithm>
#include <cmath>

/**
 * For more information:
 *
 * http://en.wikipedia.org/wiki/HSL_and_HSV
 */
namespace ColorHelpers {
  using std::round;
  using std::max;
  using std::min;
  using std::fmod;
  using std::abs;

  /**
   * Red-Green-Blue -> Hue-Saturation-Lightness
   */
  template <typename T = uint8_t, typename R = float> 
  void RGBtoHSL(T * rgb, R * hsl) {
    R hue, saturation, lightness,

      red = rgb[0] / 255.0, 
      green = rgb[1] / 255.0, 
      blue = rgb[2] / 255.0,

      M = max(red, max(green, blue)),
      m = min(red, min(green, blue)),
      C = M - m;

    // Hue
    if     (C == 0)     { hue = 0; }
    else if(M == red)   { hue = fmod((green - blue) / C, 6) * 60; }
    else if(M == green) { hue = ((blue - red) / C + 2) * 60; }
    else if(M == blue)  { hue = ((red - green) / C + 4) * 60; }
    else                { hue = 0; }

    // Lightness
    lightness = (M + m) / 2;

    // Saturation
    if     (lightness <= 0.5) { saturation = C / (2 * lightness); }
    else if(lightness > 0.5)  { saturation = C / (2 - 2 * lightness); }
    else                      { saturation = 0; }

    // Set Values
    hsl[0] = hue;
    hsl[1] = saturation * 100;
    hsl[2] = lightness * 100;
  }

  /**
   * Red-Green-Blue -> Hue-Saturation-Brightness (Photoshop)
   */
  template <typename T = uint8_t, typename R = float> 
  void RGBtoHSB(T * rgb, R * hsb) {
    double hue, saturation, brightness,

      red = rgb[0] / 255.0, 
      green = rgb[1] / 255.0, 
      blue = rgb[2] / 255.0,

      M = max(red, max(green, blue)),
      m = min(red, min(green, blue)),
      C = M - m;

    // Hue
    if     (C == 0)     { hue = 0; }
    else if(M == red)   { hue = fmod((green - blue) / C, 6) * 60; }
    else if(M == green) { hue = ((blue - red) / C + 2) * 60; }
    else if(M == blue)  { hue = ((red - green) / C + 4) * 60; }
    else                { hue = 0; }

    // Brightness
    brightness = M;

    // Saturation
    if(C == 0) { saturation = 0; }
    else       { saturation = C / brightness; }

    hsb[0] = hue;
    hsb[1] = saturation * 100;
    hsb[2] = brightness * 100;
  }

  /**
   * Red-Green-Blue -> Hue-Chroma-Luma (Photoshop)
   */
  template <typename T = uint8_t, typename R = float> 
  void RGBtoHCL(T * rgb, R * hcl) {
    R hue, chroma, luma,

      red = rgb[0] / 255.0, 
      green = rgb[1] / 255.0, 
      blue = rgb[2] / 255.0,

      M = max(red, max(green, blue)),
      m = min(red, min(green, blue)),
      C = M - m;

    // Hue
    if     (C == 0)     { hue = 0; }
    else if(M == red)   { hue = fmod((green - blue) / C, 6) * 60; }
    else if(M == green) { hue = ((blue - red) / C + 2) * 60; }
    else if(M == blue)  { hue = ((red - green) / C + 4) * 60; }
    else                { hue = 0; }

    // Chroma
    chroma = C;

    // Luma
    luma = 0.299 * red + 0.587 * green + 0.114 * blue;

    hcl[0] = hue;
    hcl[1] = chroma * 100;
    hcl[2] = luma * 100;
  }

  // Hue-Saturation-Lightness -> Red-Green-Blue
  template <typename T = uint8_t, typename R = float> 
  void HSLtoRGB(R * hsl, T * rgb) {
    R red, green, blue,

      hue = hsl[0], 
      saturation = hsl[1] / 100, 
      lightness = hsl[2] / 100,

      H = hue / 60,
      C = (1 - abs(2 * lightness - 1)) * saturation,
      X = C * (1 - abs(fmod(H, 2) - 1)),
      m = (lightness - C / 2) * 255;

    if     (0 <= H && H < 1) { red = C; green = X; blue = 0; }
    else if(1 <= H && H < 2) { red = X; green = C; blue = 0; }
    else if(2 <= H && H < 3) { red = 0; green = C; blue = X; }
    else if(3 <= H && H < 4) { red = 0; green = X; blue = C; }
    else if(4 <= H && H < 5) { red = X; green = 0; blue = C; }
    else if(5 <= H && H < 6) { red = C; green = 0; blue = X; }
    else                     { red = 0; green = 0; blue = 0; }

    rgb[0] = (T)round(red * 255 + m);
    rgb[1] = (T)round(green * 255 + m);
    rgb[2] = (T)round(blue * 255 + m);
  }

  /**
   * Hue-Saturation-Brightness -> Red-Green-Blue (Photoshop)
   */
  template <typename T = uint8_t, typename R = float> 
  void HSBtoRGB(R * hsb, T * rgb) {
    R red, green, blue,

      hue = hsb[0], 
      saturation = hsb[1] / 100, 
      brightness = hsb[2] / 100,

      H = hue / 60,
      C = brightness * saturation,
      X = C * (1 - abs(fmod(H, 2) - 1)),
      m = (brightness - C) * 255;

    if     (0 <= H && H < 1) { red = C; green = X; blue = 0; }
    else if(1 <= H && H < 2) { red = X; green = C; blue = 0; }
    else if(2 <= H && H < 3) { red = 0; green = C; blue = X; }
    else if(3 <= H && H < 4) { red = 0; green = X; blue = C; }
    else if(4 <= H && H < 5) { red = X; green = 0; blue = C; }
    else if(5 <= H && H < 6) { red = C; green = 0; blue = X; }
    else                     { red = 0; green = 0; blue = 0; }

    rgb[0] = (T)round(red * 255 + m);
    rgb[1] = (T)round(green * 255 + m);
    rgb[2] = (T)round(blue * 255 + m);
  }

  /**
   * Hue-Chroma-Luma -> Red-Green-Blue (Photoshop)
   */
  template <typename T = uint8_t, typename R = float> 
  void HCLtoRGB(R * hcl, T * rgb) {
    R red, green, blue,

      hue = hcl[0], 
      chroma = hcl[1] / 100, 
      luma = hcl[2] / 100,

      H = hue / 60,
      C = chroma,
      X = C * (1 - abs(fmod(H, 2) - 1)), m;

    if     (0 <= H && H < 1) { red = C; green = X; blue = 0; }
    else if(1 <= H && H < 2) { red = X; green = C; blue = 0; }
    else if(2 <= H && H < 3) { red = 0; green = C; blue = X; }
    else if(3 <= H && H < 4) { red = 0; green = X; blue = C; }
    else if(4 <= H && H < 5) { red = X; green = 0; blue = C; }
    else if(5 <= H && H < 6) { red = C; green = 0; blue = X; }
    else                     { red = 0; green = 0; blue = 0; }

    m = (luma - (0.299 * red + 0.587 * green + 0.114 * blue)) * 255;

    rgb[0] = (T)round(red * 255 + m);
    rgb[1] = (T)round(green * 255 + m);
    rgb[2] = (T)round(blue * 255 + m);
  }
};

/**
 * ColorBlend Functions
 *
 * Perform arithmetic operations on individual channels
 * in the RGB color space.
 *
 * @param a Top Channel
 * @param b Bottom Channel
 */
namespace ChannelBlend {
  using std::sqrt;

  template <typename T = uint8_t> T Normal(T a, T b)       { return a; }
  template <typename T = uint8_t> T Dissolve(T a, T b)     { return 0; } // This one won't be easy
  template <typename T = uint8_t> T Darken(T a, T b)       { return a > b ? b : a; }
  template <typename T = uint8_t> T Multiply(T a, T b)     { return (a * b + (a * b / 256 + 128)) / 256; }
  template <typename T = uint8_t> T ColorBurn(T a, T b)    { return 0; }
  template <typename T = uint8_t> T LinearBurn(T a, T b)   { return 0; }
  template <typename T = uint8_t> T DarkerColor(T a, T b)  { return 0; }
  template <typename T = uint8_t> T Lighten(T a, T b)      { return a > b ? a : b; }
  template <typename T = uint8_t> T Screen(T a, T b)       { return 255 - ((255 - a) * (255 - b) + ((255 - a) * (255 - b) / 256 + 128)) / 256; }  
  template <typename T = uint8_t> T ColorDodge(T a, T b)   { return 0; }
  template <typename T = uint8_t> T LinearDodge(T a, T b)  { return 0; }
  template <typename T = uint8_t> T LighterColor(T a, T b) { return 0; }
  template <typename T = uint8_t> T Overlay(T a, T b)      { return 2 * b < 255 ? (2 * a * b + (2 * a * b / 256 + 128)) / 256 : 255 - ((2 * (255 - a) * (255 - b) + (2 * (255 - a) * (255 - b) / 256 + 128)) / 256); }
              // b 199
              // a 210
              // .832325667
              // 2 * (113/255) * (216/255) + (216/255) * (216/255) * (1 - 2 * (113/255))
              // (2 * b * a + (2 * b * a / 256 + 128)) / 256 + (a + (a / 256 + 128) / 256) / 256 * (a + (a / 256 + 128) / 256) / 256 * (255 - 2 * (b + (b / 256 + 128) / 256)) 
              // 2 * (210/255) * (1 - (199/255)) + sqrt(210/255) * (2 * (199/255) - 1)
  template <typename T = uint8_t> T SoftLight(T a, T b)    { return 2 * a < 255 ? (2 * b * a + (2 * b * a / 256 + 128)) / 256 + (a + (a / 256 + 128) / 256) / 256 * (a + (a / 256 + 128) / 256) / 256 * (255 - 2 * (b + (b / 256 + 128) / 256)) : 0; }
  template <typename T = uint8_t> T HardLight(T a, T b)    { return 0; }
  template <typename T = uint8_t> T VividLight(T a, T b)   { return 0; }
  template <typename T = uint8_t> T LinearLight(T a, T b)  { return 0; }
  template <typename T = uint8_t> T PinLight(T a, T b)     { return 0; }
  template <typename T = uint8_t> T HardMix(T a, T b)      { return 0; }
  template <typename T = uint8_t> T Difference(T a, T b)   { return 0; }
  template <typename T = uint8_t> T Exclusion(T a, T b)    { return 0; }
  template <typename T = uint8_t> T Subtract(T a, T b)     { return 0; }
  template <typename T = uint8_t> T Divide(T a, T b)       { return 0; }
  // template <typename T = uint8_t> T Hue(T a, T b)          { return 0; }
  // template <typename T = uint8_t> T Saturation(T a, T b)   { return 0; }
  // template <typename T = uint8_t> T Color(T a, T b)        { return 0; }
  // template <typename T = uint8_t> T Luminosity(T a, T b)   { return 0; }
};

namespace ColorBlend {
  enum MaintainLayers {
    LAYER_HUE    = 1 << 0,  
    LAYER_CHROMA = 1 << 1,
    LAYER_LUMA   = 1 << 2
  };

  template <typename T = uint8_t> 
  void buffer(T * result, T * a, T * b, T (*method) (T, T)) {   
    result[0] = (*method)(a[0], b[0]); 
    result[1] = (*method)(a[1], b[1]); 
    result[2] = (*method)(a[2], b[2]);
  }

  template <typename T = uint8_t, typename R = float> 
  void hcl_switch(T * result, T * a, T * b, uint32_t mask = LAYER_HUE | LAYER_CHROMA | LAYER_LUMA) {   
    R hcl_a[3], hcl_b[3], hcl[3]; 

    ColorHelpers::RGBtoHCL(a, hcl_a);
    ColorHelpers::RGBtoHCL(b, hcl_b);

    hcl[0] = (mask & LAYER_HUE)    == LAYER_HUE ? hcl_a[0]: hcl_b[0];
    hcl[1] = (mask & LAYER_CHROMA) == LAYER_CHROMA ? hcl_a[1]: hcl_b[1];
    hcl[2] = (mask & LAYER_LUMA)   == LAYER_LUMA ? hcl_a[2]: hcl_b[2];

    ColorHelpers::HCLtoRGB(hcl, result);
  }
                                                                                              
  template <typename T = uint8_t> void Normal(T * result, T * a, T * b)       { buffer(result, a, b, ChannelBlend::Normal); }
  template <typename T = uint8_t> void Dissolve(T * result, T * a, T * b)     { buffer(result, a, b, ChannelBlend::Dissolve); }
  template <typename T = uint8_t> void Darken(T * result, T * a, T * b)       { buffer(result, a, b, ChannelBlend::Darken); }
  template <typename T = uint8_t> void Multiply(T * result, T * a, T * b)     { buffer(result, a, b, ChannelBlend::Multiply); }
  template <typename T = uint8_t> void ColorBurn(T * result, T * a, T * b)    { buffer(result, a, b, ChannelBlend::ColorBurn); }
  template <typename T = uint8_t> void LinearBurn(T * result, T * a, T * b)   { buffer(result, a, b, ChannelBlend::LinearBurn); }
  template <typename T = uint8_t> void DarkerColor(T * result, T * a, T * b)  { buffer(result, a, b, ChannelBlend::DarkerColor); }
  template <typename T = uint8_t> void Lighten(T * result, T * a, T * b)      { buffer(result, a, b, ChannelBlend::Lighten); };
  template <typename T = uint8_t> void Screen(T * result, T * a, T * b)       { buffer(result, a, b, ChannelBlend::Screen); }
  template <typename T = uint8_t> void ColorDodge(T * result, T * a, T * b)   { buffer(result, a, b, ChannelBlend::ColorDodge); }
  template <typename T = uint8_t> void LinearDodge(T * result, T * a, T * b)  { buffer(result, a, b, ChannelBlend::LinearDodge); }
  template <typename T = uint8_t> void LighterColor(T * result, T * a, T * b) { buffer(result, a, b, ChannelBlend::LighterColor); }
  template <typename T = uint8_t> void Overlay(T * result, T * a, T * b)      { buffer(result, a, b, ChannelBlend::Overlay); }
  template <typename T = uint8_t> void SoftLight(T * result, T * a, T * b)    { buffer(result, a, b, ChannelBlend::SoftLight); }
  template <typename T = uint8_t> void HardLight(T * result, T * a, T * b)    { buffer(result, a, b, ChannelBlend::HardLight); }
  template <typename T = uint8_t> void VividLight(T * result, T * a, T * b)   { buffer(result, a, b, ChannelBlend::VividLight); }
  template <typename T = uint8_t> void LinearLight(T * result, T * a, T * b)  { buffer(result, a, b, ChannelBlend::LinearLight); }
  template <typename T = uint8_t> void PinLight(T * result, T * a, T * b)     { buffer(result, a, b, ChannelBlend::PinLight); }
  template <typename T = uint8_t> void HardMix(T * result, T * a, T * b)      { buffer(result, a, b, ChannelBlend::HardMix); }
  template <typename T = uint8_t> void Difference(T * result, T * a, T * b)   { buffer(result, a, b, ChannelBlend::Difference); }
  template <typename T = uint8_t> void Exclusion(T * result, T * a, T * b)    { buffer(result, a, b, ChannelBlend::Exclusion); }
  template <typename T = uint8_t> void Subtract(T * result, T * a, T * b)     { buffer(result, a, b, ChannelBlend::Subtract); }
  template <typename T = uint8_t> void Divide(T * result, T * a, T * b)       { buffer(result, a, b, ChannelBlend::Divide); }
  template <typename T = uint8_t> void Hue(T * result, T * a, T * b)          { hcl_switch(result, a, b, LAYER_HUE); }
  template <typename T = uint8_t> void Saturation(T * result, T * a, T * b)   { hcl_switch(result, a, b, LAYER_CHROMA); }
  template <typename T = uint8_t> void Color(T * result, T * a, T * b)        { hcl_switch(result, a, b, LAYER_HUE | LAYER_CHROMA); }
  template <typename T = uint8_t> void Luminosity(T * result, T * a, T * b)   { hcl_switch(result, a, b, LAYER_LUMA); }
};

#endif // BlendModeMacros_H_
