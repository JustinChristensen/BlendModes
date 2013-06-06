#ifndef CyanTests_H_
#define CyanTests_H_ 1

namespace CyanTests {
  uint8_t black[]              = { 0, 0, 0 },
          white[]              = { 255, 255, 255 },
          cyan[]               = { 113, 199, 216 },
          yellow_green[]       = { 216, 210, 113 };
          
  // expected results (from photoshop)
  uint8_t * const normal        = cyan,
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
          hard_light[]   = { 191, 235, 212 },
          vivid_light[]  = { 211, 255, 255 },
          linear_light[] = { 187, 255, 255 },
          pin_light[]    = { 216, 210, 177 },
          difference[]   = { 103, 11, 103 },
          exclusion[]    = { 138, 81, 138 },
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

  TEST(Cyan_ColorBlend_ColorBurn) {
    uint8_t result[3];
    ColorBlend::ColorBurn(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(color_burn, result);
  }

  TEST(Cyan_ColorBlend_LinearBurn) {
    uint8_t result[3];
    ColorBlend::LinearBurn(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(linear_burn, result);
  }

  TEST(Cyan_ColorBlend_DarkerColor) {
    uint8_t result[3];
    ColorBlend::DarkerColor(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(darker_color, result);
  }

  TEST(Cyan_ColorBlend_Lighten) {
    uint8_t result[3];
    ColorBlend::Lighten(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(lighten, result);
  }

  TEST(Cyan_ColorBlend_Screen) {
    uint8_t result[3];
    ColorBlend::Screen(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(screen, result);
  }

  TEST(Cyan_ColorBlend_ColorDodge) {
    uint8_t result[3];
    ColorBlend::ColorDodge(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(color_dodge, result);
  }

  TEST(Cyan_ColorBlend_LinearDodge) {
    uint8_t result[3];
    ColorBlend::LinearDodge(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(linear_dodge, result);
  }

  TEST(Cyan_ColorBlend_LighterColor) {
    uint8_t result[3];
    ColorBlend::LighterColor(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(lighter_color, result);
  }

  TEST(Cyan_ColorBlend_Overlay) {
    uint8_t result[3];
    ColorBlend::Overlay(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(overlay, result);
  }

  TEST(Cyan_ColorBlend_SoftLight) {
    uint8_t result[3];
    ColorBlend::SoftLight(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(soft_light, result);
  }

  TEST(Cyan_ColorBlend_HardLight) {
    uint8_t result[3];
    ColorBlend::HardLight(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(hard_light, result);
  }

  TEST(Cyan_ColorBlend_VividLight) {
    uint8_t result[3];
    ColorBlend::VividLight(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(vivid_light, result);
  }

  TEST(Cyan_ColorBlend_LinearLight) {
    uint8_t result[3];
    ColorBlend::LinearLight(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(linear_light, result);
  }

  TEST(Cyan_ColorBlend_PinLight) {
    uint8_t result[3];
    ColorBlend::PinLight(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(pin_light, result);
  }

  TEST(Cyan_ColorBlend_HardMix) {
    uint8_t result[3];
    ColorBlend::HardMix(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(hard_mix, result);
  }

  TEST(Cyan_ColorBlend_Difference) {
    uint8_t result[3];
    ColorBlend::Difference(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(difference, result);
  }

  TEST(Cyan_ColorBlend_Exclusion) {
    uint8_t result[3];
    ColorBlend::Exclusion(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(exclusion, result);
  }

  TEST(Cyan_ColorBlend_Subtract) {
    uint8_t result[3];
    ColorBlend::Subtract(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(subtract, result);
  }

  TEST(Cyan_ColorBlend_Divide) {
    uint8_t result[3];
    ColorBlend::Divide(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(divide, result);
  }

  TEST(Cyan_ColorBlend_Hue) {
    uint8_t result[3];
    ColorBlend::Hue(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(hue, result);
  }

  TEST(Cyan_ColorBlend_Saturation) {
    uint8_t result[3];
    ColorBlend::Saturation(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(saturation, result);
  }

  TEST(Cyan_ColorBlend_Color) {
    uint8_t result[3];
    ColorBlend::Color(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(color, result);
  }

  TEST(Cyan_ColorBlend_Luminosity) {
    uint8_t result[3];
    ColorBlend::Luminosity(result, cyan, yellow_green);
    CHECK_COLORS_EQUAL(luminosity, result);
  }
};

#endif // CyanTests_H_
