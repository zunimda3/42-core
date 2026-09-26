class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        if height < 0:
            self.print_error("height")
            self._height = 0.0
        else:
            self._height = height

        if age < 0:
            self.print_error("age")
            self._age_days = 0
        else:
            self._age_days = age

    def print_error(self, error_type: str) -> None:
        print(f"{self.name}: Error, {error_type} can't be negative")

    def show(self) -> None:
        print(
            f"{self.name}: {round(self.get_height(), 1)}cm, {self.get_age()} days old"
        )

    def set_height(self, new_height: float) -> None:
        if new_height < 0:
            self.print_error("height")
            print("Height update rejected")
        else:
            self._height = new_height
            print(f"Height updated: {new_height}cm")

    def set_age(self, new_age: int) -> None:
        if new_age < 0:
            self.print_error("age")
            print("Age update rejected")
        else:
            self._age_days = new_age
            print(f"Age updated: {new_age} days")

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age_days


if __name__ == "__main__":
    print("=== Garden Security System ===")
    plant1 = Plant("Rose", 15.0, 10)
    print("Plant created: ", end="")
    plant1.show()
    print()

    plant1.set_height(25)
    plant1.set_age(30)
    print()

    plant1.set_height(-25)
    plant1.set_age(-30)
    print()

    print("Current state: ", end="")
    plant1.show()
    # plant1.set_height(30)
    # plant2 = Plant("Oak", 200.0, 365)
    # plant3 = Plant("Cactus", 5.0, 90)
    # plant4 = Plant("Sunflower", 80.0, 45)
    # plant5 = Plant("Fern", 15.0, 120)
    #
    # Plant.factory_output()
    #
