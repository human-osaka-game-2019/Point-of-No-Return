#include "pch.h"

#include "../Point-of-No-Return/Collision.h"

using Collision::operator<;

TEST(CollisionTest, LessThan_1) {
	// Arrange
	CoordinateX x(0.5f);

	// Act
	bool result = (x < 0.6f);

	// Assert
	EXPECT_TRUE(result);
}

TEST(CollisionTest, LessThan_2) {
	// Arrange
	CoordinateX x(0.5f);

	// Act
	bool result = (x < 0.4f);

	// Assert
	EXPECT_FALSE(result);
}

TEST(CollisionTest, LessThan_3) {
	// Arrange
	CoordinateX x(0.5f);

	// Act
	bool result = (x < 0.5f);

	// Assert
	EXPECT_FALSE(result);
}
