/**
 * Blend Mode Macros
 *
 * http://stackoverflow.com/questions/5919663/how-does-photoshop-blend-two-images-together
 *
 * Justin Christensen
 * Thu May 30 19:00:05 2013
 */

#ifndef BlendModeMacros_H_
#define BlendModeMacros_H_ 1

#include <cstdint>
#include <cmath>
#include <algorithm>

using std::max;
using std::min;
using std::round;
using std::floor;
using std::ceil;

typedef int32_t int32;
typedef uint8_t uint8;
typedef double  float64;

#ifndef TRUE
#define TRUE true
#endif

/**
 * ChannelBlend Macros
 *
 * Image A: Top
 * Image B: Bottom
 */
#define ChannelBlend_Normal(A, B)        ((uint8)(A))
// #define ChannelBlend_Lighten(A, B)       ((uint8)((B > A) ? B : A))
// #define ChannelBlend_Darken(A, B)        ((uint8)((B > A) ? A : B))
// #define ChannelBlend_Multiply(A, B)      ((uint8)(round((float)(A * B) / 255)))
// #define ChannelBlend_Average(A, B)       ((uint8)((B > A) ? ceil((float)(A + B) / 2) : floor((float)(A + B) / 2)))
// #define ChannelBlend_Add(A, B)           ((uint8)(min(255, (A + B))))
// #define ChannelBlend_Subtract(A, B)      ((uint8)((A + B < 255) ? 0 : (A + B - 255)))
// #define ChannelBlend_Difference(A, B)    ((uint8)(abs(A - B)))
// #define ChannelBlend_Negation(A, B)      ((uint8)(255 - abs(255 - A - B)))
// #define ChannelBlend_Screen(A, B)        ((uint8)(255 - (((255 - A) * (255 - B)) >> 8)))
// #define ChannelBlend_Exclusion(A, B)     ((uint8)(A + B - 2 * A * B / 255))
// #define ChannelBlend_Overlay(A, B)       ((uint8)((B < 128) ? (2 * A * B / 255) : (255 - 2 * (255 - A) * (255 - B) / 255)))
// #define ChannelBlend_SoftLight(A, B)     ((uint8)((B < 128) ? (2 * ((A >> 1) + 64)) * ((float)B / 255) : (255 - (2 * (255 - ((A >> 1) + 64)) * (float)(255 - B) / 255))))
// #define ChannelBlend_HardLight(A, B)     (ChannelBlend_Overlay(B, A))
// #define ChannelBlend_ColorDodge(A, B)    ((uint8)((A == 255) ? B : min(255, ((A << 8 ) / (255 - B)))))
// #define ChannelBlend_ColorBurn(A, B)     ((uint8)((B == 0) ? B : max(0, (255 - ((255 - A) << 8 ) / B))))
// #define ChannelBlend_LinearDodge(A, B)   (ChannelBlend_Add(A , B))
// #define ChannelBlend_LinearBurn(A, B)    (ChannelBlend_Subtract(A, B))
// #define ChannelBlend_LinearLight(A, B)   ((uint8)(B < 128) ? ChannelBlend_LinearBurn(A, (2 * B)) : ChannelBlend_LinearDodge(A, (2 * (B - 128))))
// #define ChannelBlend_VividLight(A, B)    ((uint8)(B < 128) ? ChannelBlend_ColorBurn(A, (2 * B)) : ChannelBlend_ColorDodge(A, (2 * (B - 128))))
// #define ChannelBlend_PinLight(A, B)      ((uint8)(B < 128) ? ChannelBlend_Darken(A, (2 * B)) : ChannelBlend_Lighten(A, (2 * (B - 128))))
// #define ChannelBlend_HardMix(A, B)       ((uint8)((ChannelBlend_VividLight(A, B) < 128) ? 0 : 255))
// #define ChannelBlend_Reflect(A, B)       ((uint8)((B == 255) ? B : min(255, (A * A / (255 - B)))))
// #define ChannelBlend_Glow(A, B)          (ChannelBlend_Reflect(B, A))
// #define ChannelBlend_Phoenix(A, B)       ((uint8)(min(A, B) - max(A, B) + 255))
// #define ChannelBlend_Alpha(A, B, O)      ((uint8)(O * A + (1 - O) * B))
// #define ChannelBlend_AlphaF(A, B, F, O)  (ChannelBlend_Alpha(F(A, B), A, O))

/**
 * ColorBlend Buffer Macro
 *
 * Executes the given blend operation {M} given two pointers to channel
 * data for image {A} and {B} and stores the result in a pointer {T}
 */
#define ColorBlend_Buffer(T, A, B, M)    (T)[0] = ChannelBlend_##M((A)[0], (B)[0]), \
                                         (T)[1] = ChannelBlend_##M((A)[1], (B)[1]), \
                                         (T)[2] = ChannelBlend_##M((A)[2], (B)[2])

/**
 * ColorBlend Macros
 * 
 * Given a pixel from {A} and a pixel from {B} worth of data, executes the given blend operation
 * and store the result in {T}
 */
#define ColorBlend_Normal(T, A, B)       (ColorBlend_Buffer(T, A, B, Normal))
// #define ColorBlend_Lighten(T, A, B)      (ColorBlend_Buffer(T, A, B, Lighten))
// #define ColorBlend_Darken(T, A, B)       (ColorBlend_Buffer(T, A, B, Darken))
// #define ColorBlend_Multiply(T, A, B)     (ColorBlend_Buffer(T, A, B, Multiply))
// #define ColorBlend_Average(T, A, B)      (ColorBlend_Buffer(T, A, B, Average))
// #define ColorBlend_Add(T, A, B)          (ColorBlend_Buffer(T, A, B, Add))
// #define ColorBlend_Subtract(T, A, B)     (ColorBlend_Buffer(T, A, B, Subtract))
// #define ColorBlend_Difference(T, A, B)   (ColorBlend_Buffer(T, A, B, Difference))
// #define ColorBlend_Negation(T, A, B)     (ColorBlend_Buffer(T, A, B, Negation))
// #define ColorBlend_Screen(T, A, B)       (ColorBlend_Buffer(T, A, B, Screen))
// #define ColorBlend_Exclusion(T, A, B)    (ColorBlend_Buffer(T, A, B, Exclusion))
// #define ColorBlend_Overlay(T, A, B)      (ColorBlend_Buffer(T, A, B, Overlay))
// #define ColorBlend_SoftLight(T, A, B)    (ColorBlend_Buffer(T, A, B, SoftLight))
// #define ColorBlend_HardLight(T, A, B)    (ColorBlend_Buffer(T, A, B, HardLight))
// #define ColorBlend_ColorDodge(T, A, B)   (ColorBlend_Buffer(T, A, B, ColorDodge))
// #define ColorBlend_ColorBurn(T, A, B)    (ColorBlend_Buffer(T, A, B, ColorBurn))
// #define ColorBlend_LinearDodge(T, A, B)  (ColorBlend_Buffer(T, A, B, LinearDodge))
// #define ColorBlend_LinearBurn(T, A, B)   (ColorBlend_Buffer(T, A, B, LinearBurn))
// #define ColorBlend_LinearLight(T, A, B)  (ColorBlend_Buffer(T, A, B, LinearLight))
// #define ColorBlend_VividLight(T, A, B)   (ColorBlend_Buffer(T, A, B, VividLight))
// #define ColorBlend_PinLight(T, A, B)     (ColorBlend_Buffer(T, A, B, PinLight))
// #define ColorBlend_HardMix(T, A, B)      (ColorBlend_Buffer(T, A, B, HardMix))
// #define ColorBlend_Reflect(T, A, B)      (ColorBlend_Buffer(T, A, B, Reflect))
// #define ColorBlend_Glow(T, A, B)         (ColorBlend_Buffer(T, A, B, Glow))
// #define ColorBlend_Phoenix(T, A, B)      (ColorBlend_Buffer(T, A, B, Phoenix))

/**
 * ColorBlend Additional Macros
 */
#define ColorBlend_Hue(T, A, B)          ColorBlend_Hls(T, A, B, HueB, LuminationA, SaturationA)
#define ColorBlend_Saturation(T, A, B)   ColorBlend_Hls(T, A, B, HueA, LuminationA, SaturationB)
#define ColorBlend_Color(T, A, B)        ColorBlend_Hls(T, A, B, HueB, LuminationA, SaturationB)
#define ColorBlend_Luminosity(T, A, B)   ColorBlend_Hls(T, A, B, HueA, LuminationB, SaturationA)

#define ColorBlend_Hls(T, A, B, O1, O2, O3) { \
  float64 HueA, LuminationA, SaturationA; \
  float64 HueB, LuminationB, SaturationL; \
  Color::RGBtoHLS((A)[2], (A)[1], (A)[0], &HueA, &LuminationA, &SaturationA); \
  Color::RGBtoHLS((B)[2], (B)[1], (B)[0], &HueB, &LuminationB, &SaturationB); \
  Color::HLStoRGB(O1, O2, O3, &(T)[2], &(T)[1], &(T)[0]); \
}

/**
 * Helper Functions
 *
 */
namespace Color {

  /**
   * Hue to RGB Conversion
   */
  int32 HUEtoRGB(float64 M1, float64 M2, float64 Hue, float64 *Channel) {
    if (Hue < 0.0)
      Hue += 1.0;
    else if (Hue > 1.0)
      Hue -= 1.0;

    if ((6.0 * Hue) < 1.0)
      *Channel = (M1 + (M2 - M1) * Hue * 6.0);
    else if ((2.0 * Hue) < 1.0)
      *Channel = (M2);
    else if ((3.0 * Hue) < 2.0)
      *Channel = (M1 + (M2 - M1) * ((2.0F / 3.0F) - Hue) * 6.0);
    else
      *Channel = (M1);

    return TRUE;
  }

  /**
   * RGB to HLS Conversion
   */
  int32 RGBtoHLS(uint8 Red, uint8 Green, uint8 Blue, float64 *Hue, float64 *Lumination, float64 *Saturation) {
    float64 Delta;
    float64 Max, Min;
    float64 Redf, Greenf, Bluef;

    Redf    = ((float64)Red   / 255.0F);
    Greenf  = ((float64)Green / 255.0F);
    Bluef   = ((float64)Blue  / 255.0F); 

    Max     = max(max(Redf, Greenf), Bluef);
    Min     = min(min(Redf, Greenf), Bluef);

    *Hue        = 0;
    *Lumination = (Max + Min) / 2.0F;
    *Saturation = 0;

    if (Max == Min)
      return TRUE;

    Delta = (Max - Min);

    if (*Lumination < 0.5)
      *Saturation = Delta / (Max + Min);
    else
      *Saturation = Delta / (2.0 - Max - Min);

    if (Redf == Max)
      *Hue = (Greenf - Bluef) / Delta;
    else if (Greenf == Max)
      *Hue = 2.0 + (Bluef - Redf) / Delta;
    else
      *Hue = 4.0 + (Redf - Greenf) / Delta;

    *Hue /= 6.0; 

    if (*Hue < 0.0)
      *Hue += 1.0;       

    return TRUE;
  }

  /**
   * HLS to RGB Conversion
   */
  int32 HLStoRGB(float64 Hue, float64 Lumination, float64 Saturation, uint8 *Red, uint8 *Green, uint8 *Blue) {
    float64 M1, M2;
    float64 Redf, Greenf, Bluef;

    if (Saturation == 0) {
      Redf    = Lumination;
      Greenf  = Lumination;
      Bluef   = Lumination;
    }
    else {
      if (Lumination <= 0.5)
        M2 = Lumination * (1.0 + Saturation);
      else
        M2 = Lumination + Saturation - Lumination * Saturation;

      M1 = (2.0 * Lumination - M2);

      HUEtoRGB(M1, M2, Hue + (1.0F / 3.0F), &Redf);
      HUEtoRGB(M1, M2, Hue, &Greenf);
      HUEtoRGB(M1, M2, Hue - (1.0F / 3.0F), &Bluef);
    }

    *Red    = (uint8)(Redf * 255);
    *Blue   = (uint8)(Bluef * 255);
    *Green  = (uint8)(Greenf * 255);

    return TRUE;
  }

};

#endif // BlendModeMacros_H_
