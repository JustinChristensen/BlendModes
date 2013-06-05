/**
 * Photoshop Blend Modes Tests
 *
 * Justin Christensen
 * Fri May 31 09:31:25 2013
 */

#include <UnitTest++/UnitTest++.h>
#include <iostream>

#define NUM_CHANNELS 3
#define CHECK_COLORS_EQUAL(A, B) CHECK_ARRAY_CLOSE(A, B, NUM_CHANNELS, 0.01)

#include "blenders.h"

#include "TestWhiteTests.h"
#include "TestCyanTests.h"
#include "TestYellowGreenTests.h"
#include "TestBlackTests.h"

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

