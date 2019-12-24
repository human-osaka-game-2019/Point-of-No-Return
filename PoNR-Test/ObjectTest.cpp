#include "pch.h"

#include "../Point-of-No-Return/Object.h"

// operator <(CoordinateX, CoordinateX)
// lhs < rhsの場合
TEST(CoordinateXTest, LessThan_1) {
	// Arrange
	CoordinateX x(0.5f);

	// Act
	bool result = (x < CoordinateX(0.6f));

	// Assert
	EXPECT_TRUE(result);
}

// operator <(CoordinateX, CoordinateX)
// lhs > rhsの場合
TEST(OperatorTest, LessThan_2) {
	// Arrange
	CoordinateX x(0.5f);

	// Act
	bool result = (x < CoordinateX(0.4f));

	// Assert
	EXPECT_FALSE(result);
}

// operator <(CoordinateX, CoordinateX)
// lhs == rhsの場合
TEST(OperatorTest, LessThan_3) {
	// Arrange
	CoordinateX x(0.5f);

	// Act
	bool result = (x < CoordinateX(0.5f));

	// Assert
	EXPECT_FALSE(result);
}

// operator <(CoordinateY, CoordinateY)
// lhs < rhsの場合
TEST(OperatorTest, LessThan_4) {
	// Arrange
	CoordinateY y(0.5f);

	// Act
	bool result = (y < CoordinateY(0.6f));

	// Assert
	EXPECT_TRUE(result);
}

// operator <(CoordinateY, CoordinateY)
// lhs > rhsの場合
TEST(OperatorTest, LessThan_5) {
	// Arrange
	CoordinateY y(0.5f);

	// Act
	bool result = (y < CoordinateY(0.4f));

	// Assert
	EXPECT_FALSE(result);
}

// operator <(CoordinateY, CoordinateY)
// lhs == rhsの場合
TEST(OperatorTest, LessThan_6) {
	// Arrange
	CoordinateY y(0.5f);

	// Act
	bool result = (y < CoordinateY(0.5f));

	// Assert
	EXPECT_FALSE(result);
}

// operator ==(CoordinateX, CoordinateX)
// lhs == rhsの場合
TEST(OperatorTest, EqualityCompare_1) {
	// Arrange
	CoordinateX x(0.5f);

	// Act
	bool result = (x == CoordinateX(0.5f));

	// Assert
	EXPECT_TRUE(result);
}

// operator ==(CoordinateX, CoordinateX)
// lhs > rhsの場合
TEST(OperatorTest, EqualityCompare_2) {
	// Arrange
	CoordinateX x(0.5f);

	// Act
	bool result = (x == CoordinateX(0.4f));

	// Assert
	EXPECT_FALSE(result);
}

// operator ==(CoordinateX, CoordinateX)
// lhs < rhsの場合
TEST(OperatorTest, EqualityCompare_3) {
	// Arrange
	CoordinateX x(0.5f);

	// Act
	bool result = (x == CoordinateX(0.6f));

	// Assert
	EXPECT_FALSE(result);
}

// operator ==(CoordinateY, CoordinateY)
// lhs == rhsの場合
TEST(OperatorTest, EqualityCompare_4) {
	// Arrange
	CoordinateY y(0.5f);

	// Act
	bool result = (y == CoordinateY(0.5f));

	// Assert
	EXPECT_TRUE(result);
}

// operator ==(CoordinateY, CoordinateY)
// lhs > rhsの場合
TEST(OperatorTest, EqualityCompare_5) {
	// Arrange
	CoordinateY y(0.5f);

	// Act
	bool result = (y == CoordinateY(0.4f));

	// Assert
	EXPECT_FALSE(result);
}

// operator ==(CoordinateY, CoordinateY)
// lhs < rhsの場合
TEST(OperatorTest, EqualityCompare_6) {
	// Arrange
	CoordinateY y(0.5f);

	// Act
	bool result = (y == CoordinateY(0.6f));

	// Assert
	EXPECT_FALSE(result);
}
