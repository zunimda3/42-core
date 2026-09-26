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
            f"{self.name}: {round(self.get_height(), 1)}cm,/n"
            f"{self.get_age()} days old"
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


class Flower(Plant):
    def __init__(
        self, name: str, height: float, age: int, color: str, bloom: bool
    ) -> None:
        super().__init__(name, height, age)
        self._color = color
        self._bloom = bloom

    def show(self) -> None:
        super().show()
        print(f"Color: {self._color}")
        if self._bloom:
            print(f"{self.name} is blooming beautifully!")
        else:
            print(f"{self.name} has not bloomed yet")

    def bloom(self) -> None:
        if not self._bloom:
            print(f"[asking the {self.name} to bloom]")
            self._bloom = True


class Tree(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        trunk_diameter: float,
        produce_shade: bool,
    ) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = trunk_diameter
        self._produce_shade = produce_shade

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {self._trunk_diameter}")

    def produce_shade(self) -> None:
        if not self._produce_shade:
            print(f"[asking the {self.name} to produce shade]")
            self._produce_shade = True
            print(
                f"Tree {self.name} now produces a shade of {self._height}"
                f"cm long\nand {self._trunk_diameter}cm wide."
            )


class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        growth_rate: float,
        harvest_season: str,
    ) -> None:
        super().__init__(name, height, age)
        self.growth_rate = growth_rate
        self._harvest_season = harvest_season
        self._nutritional_value = 0

    def show(self) -> None:
        super().show()
        print(f"Harvest season: {self._harvest_season}")
        print(f"Nutritional value: {self._nutritional_value}")

    def grow(self) -> None:
        self._height += self.growth_rate

    def age(self) -> None:
        self._age_days += 1

    def grow_tomato(self) -> None:
        print(f"[make {self.name} grow and age for 20 days]")
        for i in range(20):
            self.grow()
            self.age()
            self._nutritional_value += 1


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    rose = Flower("Rose", 15.0, 10, "red", False)
    print("=== Flower")
    rose.show()
    rose.bloom()
    rose.show()
    print()

    oak = Tree("Oak", 200.0, 365, 5.0, False)
    print("=== Tree")
    oak.show()
    oak.produce_shade()
    print()

    tomato = Vegetable("Tomato", 5.0, 10, 2.1, "April")
    print("=== Vegetable")
    tomato.show()
    tomato.grow_tomato()
    tomato.show()
    print()
