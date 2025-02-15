#include "display.h"
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

struct FoodItem {
  const char *ID;
  const char *name;
  const char *expiryDate;
};

const FoodItem foodTracker[] = {
  {"ID-021234", "Milo", "08-24-2025"},
  {"ID-021235", "Vita Milk", "09-24-2022"},
  {"ID-021236", "Juice", "08-24-2021"},
  {"ID-021237", "Lemon", "10-31-2025"},
  {"ID-021238", "Grapes", "12-12-2025"},
  {"ID-021239", "Apple", "03-19-2025"},
  {"ID-0212310", "Melon", "10-04-2025"},
  {"ID-0212312", "Dalandan", "11-05-2025"},
  {"ID-0212313", "Pork", "10-10-2025"}
};

int size = sizeof(foodTracker) / sizeof(foodTracker[0]);

void initLCD() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 1);
  lcd.print("Initialized..");
  delay(2000);
}

void displayLCD(const char *id) {
  for (int i = 0; i < size; i++) {
    if (strcmp(id, foodTracker[i].ID) == 0) {
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("ID: ");
      lcd.print(foodTracker[i].ID);

      lcd.setCursor(2, 1);
      lcd.print("Name: ");
      lcd.print(foodTracker[i].name);

      lcd.setCursor(2, 2);
      lcd.print("Exp: ");
      lcd.print(foodTracker[i].expiryDate);
      break;
    }
  }

  // If ID is not found, display a message
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Not Found!");
}
