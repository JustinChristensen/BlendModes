#ifndef BlackTests_H_
#define BlackTests_H_ 1

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

  TEST(Black_ColorBlend_Screen) {
    uint8_t result[3];
    ColorBlend::Screen(result, black, white);
    CHECK_COLORS_EQUAL(white, result);
  }

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

  TEST(Black_ColorBlend_Overlay) {
    uint8_t result[3];
    ColorBlend::Overlay(result, black, white);
    CHECK_COLORS_EQUAL(white, result);
  }

  TEST(Black_ColorBlend_SoftLight) {
    uint8_t result[3];
    ColorBlend::SoftLight(result, black, white);
    CHECK_COLORS_EQUAL(white, result);
  }

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

  TEST(Black_ColorBlend_Hue) {
    uint8_t result[3];
    ColorBlend::Hue(result, black, white);
    CHECK_COLORS_EQUAL(white, result);
  }

  TEST(Black_ColorBlend_Saturation) {
    uint8_t result[3];
    ColorBlend::Saturation(result, black, white);
    CHECK_COLORS_EQUAL(white, result);
  }

  TEST(Black_ColorBlend_Color) {
    uint8_t result[3];
    ColorBlend::Color(result, black, white);
    CHECK_COLORS_EQUAL(white, result);
  }

  TEST(Black_ColorBlend_Luminosity) {
    uint8_t result[3];
    ColorBlend::Luminosity(result, black, white);
    CHECK_COLORS_EQUAL(black, result);
  }
};

#endif // BlackTests_H_
