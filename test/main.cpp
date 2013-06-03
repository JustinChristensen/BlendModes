/**
 * Photoshop Blend Modes Tests
 *
 * Justin Christensen
 * Fri May 31 09:31:25 2013
 */

#include <UnitTest++/UnitTest++.h>
#include <iostream>

#include "blenders.h"

#define NUM_CHANNELS 3
#define CHECK_COLORS_EQUAL(A, B) CHECK_ARRAY_CLOSE(A, B, NUM_CHANNELS, 0.01)

/**
 * The following namespaces are an attempt to spot check the methods of blending
 * layers together in Photoshop
 */
namespace WhiteTests {
  uint8_t black[]        = { 0, 0, 0 },
          white[]        = { 255, 255, 255 };

  TEST(White_ColorBlend_Normal) {
    uint8_t result[3];
    ColorBlend::Normal(result, white, black);
    CHECK_COLORS_EQUAL(white, result);
  }

  // TEST(White_ColorBlend_Dissolve) {
  //   uint8_t result[3];
  //   ColorBlend::Dissolve(result, white, black);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  TEST(White_ColorBlend_Darken) {
    uint8_t result[3];
    ColorBlend::Normal(result, white, black);
    CHECK_COLORS_EQUAL(white, result);
  }

  TEST(White_ColorBlend_Multiply) {
    uint8_t result[3];
    ColorBlend::Multiply(result, white, black);
    CHECK_COLORS_EQUAL(black, result);
  }

  // TEST(White_ColorBlend_ColorBurn) {
  //   uint8_t result[3];
  //   ColorBlend::ColorBurn(result, white, black);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(White_ColorBlend_LinearBurn) {
  //   uint8_t result[3];
  //   ColorBlend::LinearBurn(result, white, black);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(White_ColorBlend_DarkerColor) {
  //   uint8_t result[3];
  //   ColorBlend::DarkerColor(result, white, black);
  //   CHECK_COLORS_EQUAL(black, result);
  // }
   
  TEST(White_ColorBlend_Lighten) {
    uint8_t result[3];
    ColorBlend::Lighten(result, white, black);
    CHECK_COLORS_EQUAL(white, result);
  }

  // TEST(White_ColorBlend_Screen) {
  //   uint8_t result[3];
  //   ColorBlend::Screen(result, white, black);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(White_ColorBlend_ColorDodge) {
  //   uint8_t result[3];
  //   ColorBlend::ColorDodge(result, white, black);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(White_ColorBlend_LinearDodge) {
  //   uint8_t result[3];
  //   ColorBlend::LinearDodge(result, white, black);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(White_ColorBlend_LighterColor) {
  //   uint8_t result[3];
  //   ColorBlend::LighterColor(result, white, black);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(White_ColorBlend_Overlay) {
  //   uint8_t result[3];
  //   ColorBlend::Overlay(result, white, black);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(White_ColorBlend_SoftLight) {
  //   uint8_t result[3];
  //   ColorBlend::SoftLight(result, white, black);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(White_ColorBlend_HardLight) {
  //   uint8_t result[3];
  //   ColorBlend::HardLight(result, white, black);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(White_ColorBlend_VividLight) {
  //   uint8_t result[3];
  //   ColorBlend::VividLight(result, white, black);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(White_ColorBlend_LinearLight) {
  //   uint8_t result[3];
  //   ColorBlend::LinearLight(result, white, black);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(White_ColorBlend_PinLight) {
  //   uint8_t result[3];
  //   ColorBlend::PinLight(result, white, black);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(White_ColorBlend_HardMix) {
  //   uint8_t result[3];
  //   ColorBlend::HardMix(result, white, black);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(White_ColorBlend_Difference) {
  //   uint8_t result[3];
  //   ColorBlend::Difference(result, white, black);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(White_ColorBlend_Exclusion) {
  //   uint8_t result[3];
  //   ColorBlend::Exclusion(result, white, black);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(White_ColorBlend_Subtract) {
  //   uint8_t result[3];
  //   ColorBlend::Subtract(result, white, black);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(White_ColorBlend_Divide) {
  //   uint8_t result[3];
  //   ColorBlend::Divide(result, white, black);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(White_ColorBlend_Hue) {
  //   uint8_t result[3];
  //   ColorBlend::Hue(result, white, black);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(White_ColorBlend_Saturation) {
  //   uint8_t result[3];
  //   ColorBlend::Saturation(result, white, black);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(White_ColorBlend_Color) {
  //   uint8_t result[3];
  //   ColorBlend::Color(result, white, black);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(White_ColorBlend_Luminosity) {
  //   uint8_t result[3];
  //   ColorBlend::Luminosity(result, white, black);
  //   CHECK_COLORS_EQUAL(white, result);
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
          
  TEST(Cyan_ColorBlend_Normal) {
    uint8_t result[3];
    ColorBlend::Normal(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(normal, result);
  }

  // TEST(Cyan_ColorBlend_Dissolve) {
  //   uint8_t result[3];
  //   ColorBlend::Dissolve(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(dissolve, result);
  // }

  TEST(Cyan_ColorBlend_Darken) {
    uint8_t result[3];
    ColorBlend::Darken(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(darken, result);
  }

  TEST(Cyan_ColorBlend_Multiply) {
    uint8_t result[3];
    ColorBlend::Multiply(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(multiply, result);
  }

  // TEST(Cyan_ColorBlend_ColorBurn) {
  //   uint8_t result[3];
  //   ColorBlend::ColorBurn(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(color_burn, result);
  // }

  // TEST(Cyan_ColorBlend_LinearBurn) {
  //   uint8_t result[3];
  //   ColorBlend::LinearBurn(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(linear_burn, result);
  // }

  // TEST(Cyan_ColorBlend_DarkerColor) {
  //   uint8_t result[3];
  //   ColorBlend::DarkerColor(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(darker_color, result);
  // }

  TEST(Cyan_ColorBlend_Lighten) {
    uint8_t result[3];
    ColorBlend::Lighten(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(lighten, result);
  }

  // TEST(Cyan_ColorBlend_Screen) {
  //   uint8_t result[3];
  //   ColorBlend::Screen(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(screen, result);
  // }

  // TEST(Cyan_ColorBlend_ColorDodge) {
  //   uint8_t result[3];
  //   ColorBlend::ColorDodge(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(color_dodge, result);
  // }

  // TEST(Cyan_ColorBlend_LinearDodge) {
  //   uint8_t result[3];
  //   ColorBlend::LinearDodge(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(linear_dodge, result);
  // }

  // TEST(Cyan_ColorBlend_LighterColor) {
  //   uint8_t result[3];
  //   ColorBlend::LighterColor(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(lighter_color, result);
  // }

  // TEST(Cyan_ColorBlend_Overlay) {
  //   uint8_t result[3];
  //   ColorBlend::Overlay(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(overlay, result);
  // }

  // TEST(Cyan_ColorBlend_SoftLight) {
  //   uint8_t result[3];
  //   ColorBlend::SoftLight(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(soft_light, result);
  // }

  // TEST(Cyan_ColorBlend_HardLight) {
  //   uint8_t result[3];
  //   ColorBlend::HardLight(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(hard_light, result);
  // }

  // TEST(Cyan_ColorBlend_VividLight) {
  //   uint8_t result[3];
  //   ColorBlend::VividLight(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(vivid_light, result);
  // }

  // TEST(Cyan_ColorBlend_LinearLight) {
  //   uint8_t result[3];
  //   ColorBlend::LinearLight(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(linear_light, result);
  // }

  // TEST(Cyan_ColorBlend_PinLight) {
  //   uint8_t result[3];
  //   ColorBlend::PinLight(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(pin_light, result);
  // }

  // TEST(Cyan_ColorBlend_HardMix) {
  //   uint8_t result[3];
  //   ColorBlend::HardMix(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(hard_mix, result);
  // }

  // TEST(Cyan_ColorBlend_Difference) {
  //   uint8_t result[3];
  //   ColorBlend::Difference(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(difference, result);
  // }

  // TEST(Cyan_ColorBlend_Exclusion) {
  //   uint8_t result[3];
  //   ColorBlend::Exclusion(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(exclusion, result);
  // }

  // TEST(Cyan_ColorBlend_Subtract) {
  //   uint8_t result[3];
  //   ColorBlend::Subtract(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(subtract, result);
  // }

  // TEST(Cyan_ColorBlend_Divide) {
  //   uint8_t result[3];
  //   ColorBlend::Divide(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(divide, result);
  // }

  // TEST(Cyan_ColorBlend_Hue) {
  //   uint8_t result[3];
  //   ColorBlend::Hue(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(hue, result);
  // }

  // TEST(Cyan_ColorBlend_Saturation) {
  //   uint8_t result[3];
  //   ColorBlend::Saturation(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(saturation, result);
  // }

  // TEST(Cyan_ColorBlend_Color) {
  //   uint8_t result[3];
  //   ColorBlend::Color(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(color, result);
  // }

  // TEST(Cyan_ColorBlend_Luminosity) {
  //   uint8_t result[3];
  //   ColorBlend::Luminosity(result, cyan, yellow_green);
  //   CHECK_COLORS_EQUAL(luminosity, result);
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

  TEST(YellowGreen_ColorBlend_Normal) {
    uint8_t result[3];
    ColorBlend::Normal(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(normal, result);
  }

  // TEST(YellowGreen_ColorBlend_Dissolve) {
  //   uint8_t result[3];
  //   ColorBlend::Dissolve(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(dissolve, result);
  // }

  TEST(YellowGreen_ColorBlend_Darken) {
    uint8_t result[3];
    ColorBlend::Darken(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(darken, result);
  }

  TEST(YellowGreen_ColorBlend_Multiply) {
    uint8_t result[3];
    ColorBlend::Multiply(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(multiply, result);
  }

  // TEST(YellowGreen_ColorBlend_ColorBurn) {
  //   uint8_t result[3];
  //   ColorBlend::ColorBurn(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(color_burn, result);
  // }

  // TEST(YellowGreen_ColorBlend_LinearBurn) {
  //   uint8_t result[3];
  //   ColorBlend::LinearBurn(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(linear_burn, result);
  // }

  // TEST(YellowGreen_ColorBlend_DarkerColor) {
  //   uint8_t result[3];
  //   ColorBlend::DarkerColor(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(darker_color, result);
  // }

  TEST(YellowGreen_ColorBlend_Lighten) {
    uint8_t result[3];
    ColorBlend::Lighten(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(lighten, result);
  }

  // TEST(YellowGreen_ColorBlend_Screen) {
  //   uint8_t result[3];
  //   ColorBlend::Screen(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(screen, result);
  // }

  // TEST(YellowGreen_ColorBlend_ColorDodge) {
  //   uint8_t result[3];
  //   ColorBlend::ColorDodge(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(color_dodge, result);
  // }

  // TEST(YellowGreen_ColorBlend_LinearDodge) {
  //   uint8_t result[3];
  //   ColorBlend::LinearDodge(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(linear_dodge, result);
  // }

  // TEST(YellowGreen_ColorBlend_LighterColor) {
  //   uint8_t result[3];
  //   ColorBlend::LighterColor(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(lighter_color, result);
  // }

  // TEST(YellowGreen_ColorBlend_Overlay) {
  //   uint8_t result[3];
  //   ColorBlend::Overlay(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(overlay, result);
  // }

  // TEST(YellowGreen_ColorBlend_SoftLight) {
  //   uint8_t result[3];
  //   ColorBlend::SoftLight(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(soft_light, result);
  // }

  // TEST(YellowGreen_ColorBlend_HardLight) {
  //   uint8_t result[3];
  //   ColorBlend::HardLight(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(hard_light, result);
  // }

  // TEST(YellowGreen_ColorBlend_VividLight) {
  //   uint8_t result[3];
  //   ColorBlend::VividLight(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(vivid_light, result);
  // }

  // TEST(YellowGreen_ColorBlend_LinearLight) {
  //   uint8_t result[3];
  //   ColorBlend::LinearLight(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(linear_light, result);
  // }

  // TEST(YellowGreen_ColorBlend_PinLight) {
  //   uint8_t result[3];
  //   ColorBlend::PinLight(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(pin_light, result);
  // }

  // TEST(YellowGreen_ColorBlend_HardMix) {
  //   uint8_t result[3];
  //   ColorBlend::HardMix(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(hard_mix, result);
  // }

  // TEST(YellowGreen_ColorBlend_Difference) {
  //   uint8_t result[3];
  //   ColorBlend::Difference(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(difference, result);
  // }

  // TEST(YellowGreen_ColorBlend_Exclusion) {
  //   uint8_t result[3];
  //   ColorBlend::Exclusion(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(exclusion, result);
  // }

  // TEST(YellowGreen_ColorBlend_Subtract) {
  //   uint8_t result[3];
  //   ColorBlend::Subtract(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(subtract, result);
  // }

  // TEST(YellowGreen_ColorBlend_Divide) {
  //   uint8_t result[3];
  //   ColorBlend::Divide(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(divide, result);
  // }

  // TEST(YellowGreen_ColorBlend_Hue) {
  //   uint8_t result[3];
  //   ColorBlend::Hue(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(hue, result);
  // }

  // TEST(YellowGreen_ColorBlend_Saturation) {
  //   uint8_t result[3];
  //   ColorBlend::Saturation(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(saturation, result);
  // }

  // TEST(YellowGreen_ColorBlend_Color) {
  //   uint8_t result[3];
  //   ColorBlend::Color(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(color, result);
  // }

  // TEST(YellowGreen_ColorBlend_Luminosity) {
  //   uint8_t result[3];
  //   ColorBlend::Luminosity(result, yellow_green, cyan);
  //   CHECK_COLORS_EQUAL(luminosity, result);
  // }
};

namespace BlackTests {
  uint8_t black[]        = { 0, 0, 0 },
          white[]        = { 255, 255, 255 };
  
  TEST(Black_ColorBlend_Normal) {
    uint8_t result[3];
    ColorBlend::Normal(result, black, white);
    CHECK_COLORS_EQUAL(black, result);
  }

  // TEST(Black_ColorBlend_Dissolve) {
  //   uint8_t result[3];
  //   ColorBlend::Dissolve(result, black, white);
  //   CHECK_COLORS_EQUAL(black, result);
  // }
    
  TEST(Black_ColorBlend_Darken) {
    uint8_t result[3];
    ColorBlend::Darken(result, black, white);
    CHECK_COLORS_EQUAL(black, result);
  }
      
  TEST(Black_ColorBlend_Multiply) {
    uint8_t result[3];
    ColorBlend::Multiply(result, black, white);
    CHECK_COLORS_EQUAL(black, result);
  }

  // TEST(Black_ColorBlend_ColorBurn) {
  //   uint8_t result[3];
  //   ColorBlend::ColorBurn(result, black, white);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(Black_ColorBlend_LinearBurn) {
  //   uint8_t result[3];
  //   ColorBlend::LinearBurn(result, black, white);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(Black_ColorBlend_DarkerColor) {
  //   uint8_t result[3];
  //   ColorBlend::DarkerColor(result, black, white);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  TEST(Black_ColorBlend_Lighten) {
    uint8_t result[3];
    ColorBlend::Lighten(result, black, white);
    CHECK_COLORS_EQUAL(white, result);
  }

  // TEST(Black_ColorBlend_Screen) {
  //   uint8_t result[3];
  //   ColorBlend::Screen(result, black, white);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(Black_ColorBlend_ColorDodge) {
  //   uint8_t result[3];
  //   ColorBlend::ColorDodge(result, black, white);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(Black_ColorBlend_LinearDodge) {
  //   uint8_t result[3];
  //   ColorBlend::LinearDodge(result, black, white);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(Black_ColorBlend_LighterColor) {
  //   uint8_t result[3];
  //   ColorBlend::LighterColor(result, black, white);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(Black_ColorBlend_Overlay) {
  //   uint8_t result[3];
  //   ColorBlend::Overlay(result, black, white);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(Black_ColorBlend_SoftLight) {
  //   uint8_t result[3];
  //   ColorBlend::SoftLight(result, black, white);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(Black_ColorBlend_HardLight) {
  //   uint8_t result[3];
  //   ColorBlend::HardLight(result, black, white);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(Black_ColorBlend_VividLight) {
  //   uint8_t result[3];
  //   ColorBlend::VividLight(result, black, white);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(Black_ColorBlend_LinearLight) {
  //   uint8_t result[3];
  //   ColorBlend::LinearLight(result, black, white);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(Black_ColorBlend_PinLight) {
  //   uint8_t result[3];
  //   ColorBlend::PinLight(result, black, white);
  //   CHECK_COLORS_EQUAL(black, result);
  // }

  // TEST(Black_ColorBlend_HardMix) {
  //   uint8_t result[3];
  //   ColorBlend::HardMix(result, black, white);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(Black_ColorBlend_Difference) {
  //   uint8_t result[3];
  //   ColorBlend::Difference(result, black, white);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(Black_ColorBlend_Exclusion) {
  //   uint8_t result[3];
  //   ColorBlend::Exclusion(result, black, white);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(Black_ColorBlend_Subtract) {
  //   uint8_t result[3];
  //   ColorBlend::Subtract(result, black, white);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(Black_ColorBlend_Divide) {
  //   uint8_t result[3];
  //   ColorBlend::Divide(result, black, white);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(Black_ColorBlend_Hue) {
  //   uint8_t result[3];
  //   ColorBlend::Hue(result, black, white);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(Black_ColorBlend_Saturation) {
  //   uint8_t result[3];
  //   ColorBlend::Saturation(result, black, white);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(Black_ColorBlend_Color) {
  //   uint8_t result[3];
  //   ColorBlend::Color(result, black, white);
  //   CHECK_COLORS_EQUAL(white, result);
  // }

  // TEST(Black_ColorBlend_Luminosity) {
  //   uint8_t result[3];
  //   ColorBlend::Luminosity(result, black, white);
  //   CHECK_COLORS_EQUAL(black, result);
  // }
};

namespace ColorHelpersTests {
  uint8_t rgb_spring_green[] = { 155, 235, 172 },
          rgb_deep_blue[] = { 68, 51, 175 };

  float hsl_spring_green[] = { 132.75, 66.6667, 76.4706 },
        hsl_deep_blue[] = { 248.226, 54.8673, 44.3137 },

        hsb_spring_green[] = { 132.75, 34.0426, 92.1569 },
        hsb_deep_blue[] = { 248.226, 70.8571, 68.6275 },
  
        hcl_spring_green[] = { 132.75, 31.3725, 79.96 },
        hcl_deep_blue[] = { 248.226, 48.6275, 27.5369 };

  TEST(ColorHelpers_RGB_To_HSL) {
    float result[3];

    ColorHelpers::RGBtoHSL(rgb_spring_green, result);
    CHECK_COLORS_EQUAL(hsl_spring_green, result);

    ColorHelpers::RGBtoHSL(rgb_deep_blue, result);
    CHECK_COLORS_EQUAL(hsl_deep_blue, result);
  }

  TEST(ColorHelpers_RGB_To_HSB) {
    float result[3];
  
    ColorHelpers::RGBtoHSB(rgb_spring_green, result);
    CHECK_COLORS_EQUAL(hsb_spring_green, result);

    ColorHelpers::RGBtoHSB(rgb_deep_blue, result);
    CHECK_COLORS_EQUAL(hsb_deep_blue, result);
  }

  TEST(ColorHelpers_RGB_To_HCL) {
    double result[3];
    using std::cout;
    using std::endl;
  
    ColorHelpers::RGBtoHCL(rgb_spring_green, result);
    CHECK_COLORS_EQUAL(hcl_spring_green, result);

    ColorHelpers::RGBtoHCL(rgb_deep_blue, result);
    CHECK_COLORS_EQUAL(hcl_deep_blue, result);
  }

  TEST(ColorHelpers_HSL_To_RGB) {
    uint8_t result[3];

    ColorHelpers::HSLtoRGB(hsl_spring_green, result);
    CHECK_COLORS_EQUAL(rgb_spring_green, result);

    ColorHelpers::HSLtoRGB(hsl_deep_blue, result);
    CHECK_COLORS_EQUAL(rgb_deep_blue, result);
  }

  TEST(ColorHelpers_HSB_To_RGB) {
    uint8_t result[3];

    ColorHelpers::HSBtoRGB(hsb_spring_green, result);
    CHECK_COLORS_EQUAL(rgb_spring_green, result);

    ColorHelpers::HSBtoRGB(hsb_deep_blue, result);
    CHECK_COLORS_EQUAL(rgb_deep_blue, result);
  }

  TEST(ColorHelpers_HCL_To_RGB) {
    uint8_t result[3];

    ColorHelpers::HCLtoRGB(hcl_spring_green, result);
    CHECK_COLORS_EQUAL(rgb_spring_green, result);

    ColorHelpers::HCLtoRGB(hcl_deep_blue, result);
    CHECK_COLORS_EQUAL(rgb_deep_blue, result);
  }
};

int main(int argc, char * argv[]) {
  return UnitTest::RunAllTests();
}

