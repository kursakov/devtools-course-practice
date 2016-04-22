// Copyright 2016 Magaziinik Ivan

#include <gtest/gtest.h>
#include <stdexcept>
#include "mine_sweeper_field.h"

#include "include/mine_sweeper_field.h"


TEST(MINEsweeper, can_create){
    // Arrange
    Field* field;

    // Act
    field = new Field();

    // Assert
    EXPECT_NE(nullptr, field);
    delete field;
}

TEST(MINEsweeper, throws_when_wrong_arg){
    // Arrange & Act & Assert
    EXPECT_THROW(Field(101), std::invalid_argument);
}

TEST(MINEsweeper, can_get_size){
    // Arrange
    Field* field;
    unsigned int size = 15;
    // Act
    field = new Field(size);

    // Assert
    EXPECT_EQ(size, field->get_field_size());
    delete field;
}

TEST(MINEsweeper, throws_when_try_to_get_wrong_cell){
    // Arrange
    Field* field;
    // Act
    field = new Field();

    // Assert
    EXPECT_THROW(field->get_cell(11,1), std::invalid_argument);
    delete field;
}

TEST(MINEsweeper, throws_when_try_to_set_wrong_cell){
    // Arrange
    Field* field;
    // Act
    field = new Field();

    // Assert
    EXPECT_THROW(field->set_cell(11,1,0), std::invalid_argument);
    delete field;
}

TEST(MINEsweeper, throws_when_try_to_set_wrong_value){
    // Arrange
    Field* field;
    // Act
    field = new Field();

    // Assert
    EXPECT_THROW(field->set_cell(1,1,9), std::invalid_argument);
    delete field;
}

TEST(MINEsweeper, is_started_field_is_fill_by_zero){
    // Arrange
    Field* field;
    unsigned int expected_val = 0;
    // Act
    field = new Field();

    // Assert
    EXPECT_EQ(expected_val,field->get_cell(1,1));
    delete field;
}

TEST(MINEsweeper, can_set_cell){
    // Arrange
    Field* field;
    unsigned int value = 2;
    unsigned int x = 1;
    unsigned int y = 1;
    // Act
    field = new Field();
    field->set_cell(x,y,value);
    // Assert
    EXPECT_EQ(value,field->get_cell(x,y));
    delete field;
}