#include "gtest/gtest.h"

#include "gmock/gmock.h"  // Brings in Google Mock.

class Turtle {
public: 
	virtual void PenUp() = 0;
	virtual void PenDown() = 0;
	virtual void Forward(int) = 0;
	virtual void Turn(int) = 0;
	virtual void GoTo(int , int) =0;
	virtual int GetX() const = 0;
	virtual int GetY() const = 0;
};

class MockTurtle : public Turtle {
 public:
  
  MOCK_METHOD0(PenUp, void());
  MOCK_METHOD0(PenDown, void());
  MOCK_METHOD1(Forward, void(int distance));
  MOCK_METHOD1(Turn, void(int degrees));
  MOCK_METHOD2(GoTo, void(int x, int y));
  MOCK_CONST_METHOD0(GetX, int());
  MOCK_CONST_METHOD0(GetY, int());
};

TEST(Tutorial, TutorialSimple) {
  ASSERT_EQ(2+2, 4);

}

using ::testing::AtLeast;

TEST(PainterTest, CanDrawSomething) {
  MockTurtle turtle;
  EXPECT_CALL(turtle, PenDown())
      .Times(AtLeast(1));
  turtle.PenDown();
}

int main(int argc, char **argv)
{
    //::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
