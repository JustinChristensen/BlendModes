#ifndef YellowGreenTests_H_
#define YellowGreenTests_H_ 1
namespace YellowGreenTests {
  uint8_t black[]        = { 0, 0, 0 },
          white[]        = { 255, 255, 255 },
          cyan[]         = { 113, 199, 216 },
          yellow_green[] = { 216, 210, 113 };
  
  // expected results (from photoshop)
  uint8_t * const normal        = yellow_green,
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
          hard_light[]   = { 212, 235, 191 },
          vivid_light[]  = { 255, 255, 211 },
          linear_light[] = { 255, 255, 187 },
          pin_light[]    = { 177, 199, 216 },
          difference[]   = { 103, 11, 103 },
          exclusion[]    = { 138, 81, 138 },
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

  TEST(YellowGreen_ColorBlend_ColorBurn) {
    uint8_t result[3];
    ColorBlend::ColorBurn(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(color_burn, result);
  }

  TEST(YellowGreen_ColorBlend_LinearBurn) {
    uint8_t result[3];
    ColorBlend::LinearBurn(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(linear_burn, result);
  }

  TEST(YellowGreen_ColorBlend_DarkerColor) {
    uint8_t result[3];
    ColorBlend::DarkerColor(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(darker_color, result);
  }

  TEST(YellowGreen_ColorBlend_Lighten) {
    uint8_t result[3];
    ColorBlend::Lighten(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(lighten, result);
  }

  TEST(YellowGreen_ColorBlend_Screen) {
    uint8_t result[3];
    ColorBlend::Screen(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(screen, result);
  }

  TEST(YellowGreen_ColorBlend_ColorDodge) {
    uint8_t result[3];
    ColorBlend::ColorDodge(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(color_dodge, result);
  }

  TEST(YellowGreen_ColorBlend_LinearDodge) {
    uint8_t result[3];
    ColorBlend::LinearDodge(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(linear_dodge, result);
  }

  TEST(YellowGreen_ColorBlend_LighterColor) {
    uint8_t result[3];
    ColorBlend::LighterColor(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(lighter_color, result);
  }

  TEST(YellowGreen_ColorBlend_Overlay) {
    uint8_t result[3];
    ColorBlend::Overlay(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(overlay, result);
  }

  TEST(YellowGreen_ColorBlend_SoftLight) {
    uint8_t result[3];
    ColorBlend::SoftLight(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(soft_light, result);
  }

  TEST(YellowGreen_ColorBlend_HardLight) {
    uint8_t result[3];
    ColorBlend::HardLight(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(hard_light, result);
  }

  TEST(YellowGreen_ColorBlend_VividLight) {
    uint8_t result[3];
    ColorBlend::VividLight(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(vivid_light, result);
  }

  TEST(YellowGreen_ColorBlend_LinearLight) {
    uint8_t result[3];
    ColorBlend::LinearLight(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(linear_light, result);
  }

  TEST(YellowGreen_ColorBlend_PinLight) {
    uint8_t result[3];
    ColorBlend::PinLight(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(pin_light, result);
  }

  TEST(YellowGreen_ColorBlend_HardMix) {
    uint8_t result[3];
    ColorBlend::HardMix(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(hard_mix, result);
  }

  TEST(YellowGreen_ColorBlend_Difference) {
    uint8_t result[3];
    ColorBlend::Difference(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(difference, result);
  }

  TEST(YellowGreen_ColorBlend_Exclusion) {
    uint8_t result[3];
    ColorBlend::Exclusion(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(exclusion, result);
  }

  TEST(YellowGreen_ColorBlend_Subtract) {
    uint8_t result[3];
    ColorBlend::Subtract(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(subtract, result);
  }

  TEST(YellowGreen_ColorBlend_Divide) {
    uint8_t result[3];
    ColorBlend::Divide(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(divide, result);
  }

  TEST(YellowGreen_ColorBlend_Hue) {
    uint8_t result[3];
    ColorBlend::Hue(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(hue, result);
  }

  TEST(YellowGreen_ColorBlend_Saturation) {
    uint8_t result[3];
    ColorBlend::Saturation(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(saturation, result);
  }

  TEST(YellowGreen_ColorBlend_Color) {
    uint8_t result[3];
    ColorBlend::Color(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(color, result);
  }

  TEST(YellowGreen_ColorBlend_Luminosity) {
    uint8_t result[3];
    ColorBlend::Luminosity(result, yellow_green, cyan);
    CHECK_COLORS_EQUAL(luminosity, result);
  }
};
#endif // YellowGreenTests_H_
