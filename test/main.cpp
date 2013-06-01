/**
 * Photoshop Blend Modes Tests
 *
 * Justin Christensen
 * Fri May 31 09:31:25 2013
 */

#include "UnitTest++.h"
#include "macros.h"
#include <iostream>

#define NUM_CHANNELS 3
#define CHECK_COLORS_EQUAL(A, B)  CHECK_ARRAY_EQUAL(A, B, NUM_CHANNELS)

/**
 * The following namespaces are an attempt to spot check the methods of blending
 * layers together in Photoshop
 */
namespace WhiteTests {
  uint8_t black[]        = { 0, 0, 0 },
          white[]        = { 255, 255, 255 };

  TEST(ColorBlend_Normal) {
    uint8_t result[3];
    ColorBlend_Normal(result, white, black);
    CHECK_COLORS_EQUAL(result, white);
  }

  // TEST(ColorBlend_Dissolve) {
  //   uint8_t result[3];
  //   ColorBlend_Dissolve(result, white, black);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_Darken) {
  //   uint8_t result[3];
  //   ColorBlend_Normal(result, white, black);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_Multiply) {
  //   uint8_t result[3];
  //   ColorBlend_Multiply(result, white, black);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_ColorBurn) {
  //   uint8_t result[3];
  //   ColorBlend_ColorBurn(result, white, black);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_LinearBurn) {
  //   uint8_t result[3];
  //   ColorBlend_LinearBurn(result, white, black);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_DarkerColor) {
  //   uint8_t result[3];
  //   ColorBlend_DarkerColor(result, white, black);
  //   CHECK_COLORS_EQUAL(result, black);
  // }
  // 
  // TEST(ColorBlend_Lighten) {
  //   uint8_t result[3];
  //   ColorBlend_Lighten(result, white, black);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_Screen) {
  //   uint8_t result[3];
  //   ColorBlend_Screen(result, white, black);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_ColorDodge) {
  //   uint8_t result[3];
  //   ColorBlend_ColorDodge(result, white, black);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_LinearDodge) {
  //   uint8_t result[3];
  //   ColorBlend_LinearDodge(result, white, black);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_LighterColor) {
  //   uint8_t result[3];
  //   ColorBlend_LighterColor(result, white, black);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_Overlay) {
  //   uint8_t result[3];
  //   ColorBlend_Overlay(result, white, black);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_SoftLight) {
  //   uint8_t result[3];
  //   ColorBlend_SoftLight(result, white, black);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_HardLight) {
  //   uint8_t result[3];
  //   ColorBlend_HardLight(result, white, black);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_VividLight) {
  //   uint8_t result[3];
  //   ColorBlend_VividLight(result, white, black);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_LinearLight) {
  //   uint8_t result[3];
  //   ColorBlend_LinearLight(result, white, black);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_PinLight) {
  //   uint8_t result[3];
  //   ColorBlend_PinLight(result, white, black);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_HardMix) {
  //   uint8_t result[3];
  //   ColorBlend_HardMix(result, white, black);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_Difference) {
  //   uint8_t result[3];
  //   ColorBlend_Difference(result, white, black);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_Exclusion) {
  //   uint8_t result[3];
  //   ColorBlend_Exclusion(result, white, black);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_Subtract) {
  //   uint8_t result[3];
  //   ColorBlend_Subtract(result, white, black);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_Divide) {
  //   uint8_t result[3];
  //   ColorBlend_Divide(result, white, black);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_Hue) {
  //   uint8_t result[3];
  //   ColorBlend_Hue(result, white, black);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_Saturation) {
  //   uint8_t result[3];
  //   ColorBlend_Saturation(result, white, black);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_Color) {
  //   uint8_t result[3];
  //   ColorBlend_Color(result, white, black);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_Luminosity) {
  //   uint8_t result[3];
  //   ColorBlend_Luminosity(result, white, black);
  //   CHECK_COLORS_EQUAL(result, white);
  // }
};

namespace CyanTests {
  uint8_t black[]              = { 0, 0, 0 },
          white[]              = { 255, 255, 255 },
          cyan[]               = { 113, 199, 216 },
          yellow_green[]       = { 216, 210, 113 };
          
  // expected results (from photoshop)
  uint8_t * const normal        = cyan,
          * const dissolve      = cyan,
          * const darker_color  = cyan,
          * const color_dodge   = white,
          * const linear_dodge  = white,
          * const lighter_color = yellow_green,
          * const hard_mix      = white,
          * const saturation    = yellow_green;
  
  uint8_t darken[]       = { 113, 199, 113 },
          multiply[]     = { 96, 164, 96 },
          color_burn[]   = { 167, 197, 87 },
          linear_burn[]  = { 74, 154, 74 },
          lighten[]      = { 216, 210, 216 },
          screen[]       = { 233, 245, 233 },
          overlay[]      = { 212, 235, 191 },
          soft_light[]   = { 212, 222, 152 },
          hard_light[]   = { 191, 235, 211 },
          vivid_light[]  = { 211, 255, 255 },
          linear_light[] = { 186, 255, 255 },
          pin_light[]    = { 216, 210, 177 },
          difference[]   = { 103, 11, 103 },
          exclusion[]    = { 137, 81, 137 },
          subtract[]     = { 103, 11, 0 },
          divide[]       = { 255, 255, 133 },
          hue[]          = { 139, 225, 242 },
          color[]        = { 139, 225, 242 },
          luminosity[]   = { 190, 184, 87 };
          
  TEST(ColorBlend_Normal) {
    uint8_t result[3];
    ColorBlend_Normal(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(result, normal);
  }

  // TEST(ColorBlend_Dissolve) {
  //   uint8_t result[3];
  //   ColorBlend_Dissolve(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, dissolve);
  // }

  // TEST(ColorBlend_Darken) {
  //   uint8_t result[3];
  //   ColorBlend_Darken(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, darken);
  // }

  // TEST(ColorBlend_Multiply) {
  //   uint8_t result[3];
  //   ColorBlend_Multiply(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, multiply);
  // }

  // TEST(ColorBlend_ColorBurn) {
  //   uint8_t result[3];
  //   ColorBlend_ColorBurn(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, color_burn);
  // }

  // TEST(ColorBlend_LinearBurn) {
  //   uint8_t result[3];
  //   ColorBlend_LinearBurn(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, linear_burn);
  // }

  // TEST(ColorBlend_DarkerColor) {
  //   uint8_t result[3];
  //   ColorBlend_DarkerColor(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, darker_color);
  // }

  // TEST(ColorBlend_Lighten) {
  //   uint8_t result[3];
  //   ColorBlend_Lighten(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, lighten);
  // }

  // TEST(ColorBlend_Screen) {
  //   uint8_t result[3];
  //   ColorBlend_Screen(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, screen);
  // }

  // TEST(ColorBlend_ColorDodge) {
  //   uint8_t result[3];
  //   ColorBlend_ColorDodge(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, color_dodge);
  // }

  // TEST(ColorBlend_LinearDodge) {
  //   uint8_t result[3];
  //   ColorBlend_LinearDodge(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, linear_dodge);
  // }

  // TEST(ColorBlend_LighterColor) {
  //   uint8_t result[3];
  //   ColorBlend_LighterColor(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, lighter_color);
  // }

  // TEST(ColorBlend_Overlay) {
  //   uint8_t result[3];
  //   ColorBlend_Overlay(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, overlay);
  // }

  // TEST(ColorBlend_SoftLight) {
  //   uint8_t result[3];
  //   ColorBlend_SoftLight(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, soft_light);
  // }

  // TEST(ColorBlend_HardLight) {
  //   uint8_t result[3];
  //   ColorBlend_HardLight(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, hard_light);
  // }

  // TEST(ColorBlend_VividLight) {
  //   uint8_t result[3];
  //   ColorBlend_VividLight(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, vivid_light);
  // }

  // TEST(ColorBlend_LinearLight) {
  //   uint8_t result[3];
  //   ColorBlend_LinearLight(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, linear_light);
  // }

  // TEST(ColorBlend_PinLight) {
  //   uint8_t result[3];
  //   ColorBlend_PinLight(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, pin_light);
  // }

  // TEST(ColorBlend_HardMix) {
  //   uint8_t result[3];
  //   ColorBlend_HardMix(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, hard_mix);
  // }

  // TEST(ColorBlend_Difference) {
  //   uint8_t result[3];
  //   ColorBlend_Difference(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, difference);
  // }

  // TEST(ColorBlend_Exclusion) {
  //   uint8_t result[3];
  //   ColorBlend_Exclusion(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, exclusion);
  // }

  // TEST(ColorBlend_Subtract) {
  //   uint8_t result[3];
  //   ColorBlend_Subtract(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, subtract);
  // }

  // TEST(ColorBlend_Divide) {
  //   uint8_t result[3];
  //   ColorBlend_Divide(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, divide);
  // }

  // TEST(ColorBlend_Hue) {
  //   uint8_t result[3];
  //   ColorBlend_Hue(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, hue);
  // }

  // TEST(ColorBlend_Saturation) {
  //   uint8_t result[3];
  //   ColorBlend_Saturation(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, saturation);
  // }

  // TEST(ColorBlend_Color) {
  //   uint8_t result[3];
  //   ColorBlend_Color(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, color);
  // }

  // TEST(ColorBlend_Luminosity) {
  //   uint8_t result[3];
  //   ColorBlend_Luminosity(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(result, luminosity);
  // }
};

namespace YellowGreenTests {
  uint8_t black[]        = { 0, 0, 0 },
          white[]        = { 255, 255, 255 },
          cyan[]         = { 113, 199, 216 },
          yellow_green[] = { 216, 210, 113 };
  
  // expected results (from photoshop)
  uint8_t * const normal        = yellow_green,
          * const dissolve      = yellow_green,
          * const darker_color  = cyan,
          * const color_dodge   = white,
          * const linear_dodge  = white,
          * const lighter_color = yellow_green,
          * const hard_mix      = white,
          * const saturation    = cyan;
  
  uint8_t darken[]       = { 113, 199, 113 },
          multiply[]     = { 96, 164, 96 },
          color_burn[]   = { 87, 187, 167 },
          linear_burn[]  = { 74, 154, 74 },
          lighten[]      = { 216, 210, 216 },
          screen[]       = { 233, 245, 233 },
          overlay[]      = { 191, 235, 212 },
          soft_light[]   = { 152, 216, 212 },
          hard_light[]   = { 211, 235, 191 },
          vivid_light[]  = { 255, 255, 211 },
          linear_light[] = { 255, 255, 186 },
          pin_light[]    = { 177, 199, 216 },
          difference[]   = { 103, 11, 103 },
          exclusion[]    = { 137, 81, 137 },
          subtract[]     = { 0, 0, 103 },
          divide[]       = { 133, 242, 255 },
          hue[]          = { 190, 184, 87 },
          color[]        = { 190, 184, 87 },
          luminosity[]   = { 139, 225, 242 };

  TEST(ColorBlend_Normal) {
    uint8_t result[3];
    ColorBlend_Normal(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(result, normal);
  }

  // TEST(ColorBlend_Dissolve) {
  //   uint8_t result[3];
  //   ColorBlend_Dissolve(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, dissolve);
  // }

  // TEST(ColorBlend_Darken) {
  //   uint8_t result[3];
  //   ColorBlend_Darken(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, darken);
  // }

  // TEST(ColorBlend_Multiply) {
  //   uint8_t result[3];
  //   ColorBlend_Multiply(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, multiply);
  // }

  // TEST(ColorBlend_ColorBurn) {
  //   uint8_t result[3];
  //   ColorBlend_ColorBurn(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, color_burn);
  // }

  // TEST(ColorBlend_LinearBurn) {
  //   uint8_t result[3];
  //   ColorBlend_LinearBurn(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, linear_burn);
  // }

  // TEST(ColorBlend_DarkerColor) {
  //   uint8_t result[3];
  //   ColorBlend_DarkerColor(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, darker_color);
  // }

  // TEST(ColorBlend_Lighten) {
  //   uint8_t result[3];
  //   ColorBlend_Lighten(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, lighten);
  // }

  // TEST(ColorBlend_Screen) {
  //   uint8_t result[3];
  //   ColorBlend_Screen(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, screen);
  // }

  // TEST(ColorBlend_ColorDodge) {
  //   uint8_t result[3];
  //   ColorBlend_ColorDodge(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, color_dodge);
  // }

  // TEST(ColorBlend_LinearDodge) {
  //   uint8_t result[3];
  //   ColorBlend_LinearDodge(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, linear_dodge);
  // }

  // TEST(ColorBlend_LighterColor) {
  //   uint8_t result[3];
  //   ColorBlend_LighterColor(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, lighter_color);
  // }

  // TEST(ColorBlend_Overlay) {
  //   uint8_t result[3];
  //   ColorBlend_Overlay(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, overlay);
  // }

  // TEST(ColorBlend_SoftLight) {
  //   uint8_t result[3];
  //   ColorBlend_SoftLight(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, soft_light);
  // }

  // TEST(ColorBlend_HardLight) {
  //   uint8_t result[3];
  //   ColorBlend_HardLight(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, hard_light);
  // }

  // TEST(ColorBlend_VividLight) {
  //   uint8_t result[3];
  //   ColorBlend_VividLight(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, vivid_light);
  // }

  // TEST(ColorBlend_LinearLight) {
  //   uint8_t result[3];
  //   ColorBlend_LinearLight(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, linear_light);
  // }

  // TEST(ColorBlend_PinLight) {
  //   uint8_t result[3];
  //   ColorBlend_PinLight(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, pin_light);
  // }

  // TEST(ColorBlend_HardMix) {
  //   uint8_t result[3];
  //   ColorBlend_HardMix(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, hard_mix);
  // }

  // TEST(ColorBlend_Difference) {
  //   uint8_t result[3];
  //   ColorBlend_Difference(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, difference);
  // }

  // TEST(ColorBlend_Exclusion) {
  //   uint8_t result[3];
  //   ColorBlend_Exclusion(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, exclusion);
  // }

  // TEST(ColorBlend_Subtract) {
  //   uint8_t result[3];
  //   ColorBlend_Subtract(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, subtract);
  // }

  // TEST(ColorBlend_Divide) {
  //   uint8_t result[3];
  //   ColorBlend_Divide(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, divide);
  // }

  // TEST(ColorBlend_Hue) {
  //   uint8_t result[3];
  //   ColorBlend_Hue(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, hue);
  // }

  // TEST(ColorBlend_Saturation) {
  //   uint8_t result[3];
  //   ColorBlend_Saturation(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, saturation);
  // }

  // TEST(ColorBlend_Color) {
  //   uint8_t result[3];
  //   ColorBlend_Color(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, color);
  // }

  // TEST(ColorBlend_Luminosity) {
  //   uint8_t result[3];
  //   ColorBlend_Luminosity(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(result, luminosity);
  // }
};

namespace BlackTests {
  uint8_t black[]        = { 0, 0, 0 },
          white[]        = { 255, 255, 255 };
  
  TEST(ColorBlend_Normal) {
    uint8_t result[3];
    ColorBlend_Normal(result, black, white);
    CHECK_COLORS_EQUAL(result, black);
  }

  // TEST(ColorBlend_Dissolve) {
  //   uint8_t result[3];
  //   ColorBlend_Dissolve(result, black, white);
  //   CHECK_COLORS_EQUAL(result, black);
  // }
  //  
  // TEST(ColorBlend_Darken) {
  //   uint8_t result[3];
  //   ColorBlend_Darken(result, black, white);
  //   CHECK_COLORS_EQUAL(result, black);
  // }
  //    
  // TEST(ColorBlend_Multiply) {
  //   uint8_t result[3];
  //   ColorBlend_Multiply(result, black, white);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_ColorBurn) {
  //   uint8_t result[3];
  //   ColorBlend_ColorBurn(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_LinearBurn) {
  //   uint8_t result[3];
  //   ColorBlend_LinearBurn(result, black, white);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_DarkerColor) {
  //   uint8_t result[3];
  //   ColorBlend_DarkerColor(result, black, white);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_Lighten) {
  //   uint8_t result[3];
  //   ColorBlend_Lighten(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_Screen) {
  //   uint8_t result[3];
  //   ColorBlend_Screen(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_ColorDodge) {
  //   uint8_t result[3];
  //   ColorBlend_ColorDodge(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_LinearDodge) {
  //   uint8_t result[3];
  //   ColorBlend_LinearDodge(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_LighterColor) {
  //   uint8_t result[3];
  //   ColorBlend_LighterColor(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_Overlay) {
  //   uint8_t result[3];
  //   ColorBlend_Overlay(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_SoftLight) {
  //   uint8_t result[3];
  //   ColorBlend_SoftLight(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_HardLight) {
  //   uint8_t result[3];
  //   ColorBlend_HardLight(result, black, white);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_VividLight) {
  //   uint8_t result[3];
  //   ColorBlend_VividLight(result, black, white);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_LinearLight) {
  //   uint8_t result[3];
  //   ColorBlend_LinearLight(result, black, white);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_PinLight) {
  //   uint8_t result[3];
  //   ColorBlend_PinLight(result, black, white);
  //   CHECK_COLORS_EQUAL(result, black);
  // }

  // TEST(ColorBlend_HardMix) {
  //   uint8_t result[3];
  //   ColorBlend_HardMix(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_Difference) {
  //   uint8_t result[3];
  //   ColorBlend_Difference(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_Exclusion) {
  //   uint8_t result[3];
  //   ColorBlend_Exclusion(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_Subtract) {
  //   uint8_t result[3];
  //   ColorBlend_Subtract(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_Divide) {
  //   uint8_t result[3];
  //   ColorBlend_Divide(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_Hue) {
  //   uint8_t result[3];
  //   ColorBlend_Hue(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_Saturation) {
  //   uint8_t result[3];
  //   ColorBlend_Saturation(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_Color) {
  //   uint8_t result[3];
  //   ColorBlend_Color(result, black, white);
  //   CHECK_COLORS_EQUAL(result, white);
  // }

  // TEST(ColorBlend_Luminosity) {
  //   uint8_t result[3];
  //   ColorBlend_Luminosity(result, black, white);
  //   CHECK_COLORS_EQUAL(result, black);
  // }
};

int main(int argc, char * argv[]) {
  return UnitTest::RunAllTests();
}

