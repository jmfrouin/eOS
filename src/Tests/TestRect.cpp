#include <gtest/gtest.h>
#include <Interface/Base/Rect.h> // Include your CRect class header

// Test fixture for CRect
class CRectTest : public ::testing::Test {
protected:
    Interface::CRect rect;

    void SetUp() override {
        // Initialize the rectangle with some default values
        rect = Interface::CRect(0, 0, 10, 10);
    }
};

// Test case for the default constructor
TEST_F(CRectTest, DefaultConstructor) {
    Interface::CRect defaultRect;
    EXPECT_EQ(defaultRect.Left(), 0);
    EXPECT_EQ(defaultRect.Top(), 0);
    EXPECT_EQ(defaultRect.Right(), 0);
    EXPECT_EQ(defaultRect.Bottom(), 0);
}

// Test case for the parameterized constructor
TEST_F(CRectTest, ParameterizedConstructor) {
    Interface::CRect paramRect(5, 5, 15, 20);
    EXPECT_EQ(paramRect.Left(), 5);
    EXPECT_EQ(paramRect.Top(), 5);
    EXPECT_EQ(paramRect.Right(), 20);
    EXPECT_EQ(paramRect.Bottom(), 25);
}

// Test case for the MoveIn method
TEST_F(CRectTest, MoveIn) {
    Interface::CRect outerRect(0, 0, 20, 20);
    rect.MoveIn(outerRect);
    EXPECT_EQ(rect.Left(), 0);
    EXPECT_EQ(rect.Top(), 0);
    EXPECT_EQ(rect.Right(), 10);
    EXPECT_EQ(rect.Bottom(), 10);
}

// Test case for the Collide method
TEST_F(CRectTest, Collide) {
    Interface::CRect otherRect(5, 5, 15, 15);
    EXPECT_TRUE(rect.Collide(otherRect));
    Interface::CRect nonCollidingRect(20, 20, 30, 30);
    EXPECT_FALSE(rect.Collide(nonCollidingRect));
}

// Test case for the Center method
TEST_F(CRectTest, Center) {
    Interface::CRect refRect(0, 0, 20, 20);
    rect.Center(refRect, true, true);
    EXPECT_EQ(rect.Left(), 5);
    EXPECT_EQ(rect.Top(), 5);
    EXPECT_EQ(rect.Right(), 15);
    EXPECT_EQ(rect.Bottom(), 15);
}

// Test case for the Expand method
TEST_F(CRectTest, Expand) {
    rect.Expand(5);
    EXPECT_EQ(rect.Left(), -5);
    EXPECT_EQ(rect.Top(), -5);
    EXPECT_EQ(rect.Right(), 15);
    EXPECT_EQ(rect.Bottom(), 15);
}

// Test case for the Contract method
TEST_F(CRectTest, Contract) {
    rect.Contract(2);
    EXPECT_EQ(rect.Left(), 2);
    EXPECT_EQ(rect.Top(), 2);
    EXPECT_EQ(rect.Right(), 8);
    EXPECT_EQ(rect.Bottom(), 8);
}