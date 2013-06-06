#ifndef WhiteTests_H_
#define WhiteTests_H_ 1

namespace WhiteTests {
  uint8_t black[]        = { 0, 0, 0 },
          white[]        = { 255, 255, 255 };

  TEST(White_ColorBlend_Normal) {
    uint8_t result[3];
    ColorBlend::Normal(result, white, black);
    CHECK_COLORS_EQUAL(white, result);
  }

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

  TEST(White_ColorBlend_ColorBurn) {
    uint8_t result[3];
    ColorBlend::ColorBurn(result, white, black);
    CHECK_COLORS_EQUAL(black, result);
  }

  TEST(White_ColorBlend_LinearBurn) {
    uint8_t result[3];
    ColorBlend::LinearBurn(result, white, black);
    CHECK_COLORS_EQUAL(black, result);
  }

  TEST(White_ColorBlend_DarkerColor) {
    uint8_t result[3];
    ColorBlend::DarkerColor(result, white, black);
    CHECK_COLORS_EQUAL(black, result);
  }
   
  TEST(White_ColorBlend_Lighten) {
    uint8_t result[3];
    ColorBlend::Lighten(result, white, black);
    CHECK_COLORS_EQUAL(white, result);
  }

  TEST(White_ColorBlend_Screen) {
    uint8_t result[3];
    ColorBlend::Screen(result, white, black);
    CHECK_COLORS_EQUAL(white, result);
  }

  TEST(White_ColorBlend_ColorDodge) {
    uint8_t result[3];
    ColorBlend::ColorDodge(result, white, black);
    CHECK_COLORS_EQUAL(black, result);
  }

  TEST(White_ColorBlend_LinearDodge) {
    uint8_t result[3];
    ColorBlend::LinearDodge(result, white, black);
    CHECK_COLORS_EQUAL(white, result);
  }

  TEST(White_ColorBlend_LighterColor) {
    uint8_t result[3];
    ColorBlend::LighterColor(result, white, black);
    CHECK_COLORS_EQUAL(white, result);
  }

  TEST(White_ColorBlend_Overlay) {
    uint8_t result[3];
    ColorBlend::Overlay(result, white, black);
    CHECK_COLORS_EQUAL(black, result);
  }

  TEST(White_ColorBlend_SoftLight) {
    uint8_t result[3];
    ColorBlend::SoftLight(result, white, black);
    CHECK_COLORS_EQUAL(black, result);
  }

  TEST(White_ColorBlend_HardLight) {
    uint8_t result[3];
    ColorBlend::HardLight(result, white, black);
    CHECK_COLORS_EQUAL(white, result);
  }

  TEST(White_ColorBlend_VividLight) {
    uint8_t result[3];
    ColorBlend::VividLight(result, white, black);
    CHECK_COLORS_EQUAL(white, result);
  }

  TEST(White_ColorBlend_LinearLight) {
    uint8_t result[3];
    ColorBlend::LinearLight(result, white, black);
    CHECK_COLORS_EQUAL(white, result);
  }

  TEST(White_ColorBlend_PinLight) {
    uint8_t result[3];
    ColorBlend::PinLight(result, white, black);
    CHECK_COLORS_EQUAL(white, result);
  }

  TEST(White_ColorBlend_HardMix) {
    uint8_t result[3];
    ColorBlend::HardMix(result, white, black);
    CHECK_COLORS_EQUAL(black, result);
  }

  TEST(White_ColorBlend_Difference) {
    uint8_t result[3];
    ColorBlend::Difference(result, white, black);
    CHECK_COLORS_EQUAL(white, result);
  }

  TEST(White_ColorBlend_Exclusion) {
    uint8_t result[3];
    ColorBlend::Exclusion(result, white, black);
    CHECK_COLORS_EQUAL(white, result);
  }

  TEST(White_ColorBlend_Subtract) {
    uint8_t result[3];
    ColorBlend::Subtract(result, white, black);
    CHECK_COLORS_EQUAL(black, result);
  }

  TEST(White_ColorBlend_Divide) {
    uint8_t result[3];
    ColorBlend::Divide(result, white, black);
    CHECK_COLORS_EQUAL(black, result);
  }

  TEST(White_ColorBlend_Hue) {
    uint8_t result[3];
    ColorBlend::Hue(result, white, black);
    CHECK_COLORS_EQUAL(black, result);
  }

  TEST(White_ColorBlend_Saturation) {
    uint8_t result[3];
    ColorBlend::Saturation(result, white, black);
    CHECK_COLORS_EQUAL(black, result);
  }

  TEST(White_ColorBlend_Color) {
    uint8_t result[3];
    ColorBlend::Color(result, white, black);
    CHECK_COLORS_EQUAL(black, result);
  }

  TEST(White_ColorBlend_Luminosity) {
    uint8_t result[3];
    ColorBlend::Luminosity(result, white, black);
    CHECK_COLORS_EQUAL(white, result);
  }
};

#endif // WhiteTests_H_
