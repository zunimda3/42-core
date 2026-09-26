class Plant:
    all_plants = []

    def __init__(self, name, height, age, growth_rate):
        self.name = name
        self.height = height
        self.age_days = age
        self.growth_rate = growth_rate
        
        Plant.all_plants.append(self)

    def grow(self):
        self.height += self.growth_rate

    def age(self):
        self.age_days += 1

    def show(self):
        print(f"{self.name}: {round(self.height, 1)}cm, {self.age_days} days old")

    def grow_a_week(self):
        print("=== Garden Plant Growth ===")
        self.show()
        initial_height = self.height
        for i in range(1, 8):
            self.grow()
            self.age()
            print(f"=== Day {i} ===")
            self.show()
        print(f"Growth this week: {round(self.height - initial_height, 1)}cm")

if __name__ == "__main__":
    plant1 = Plant("Rose", 25, 30, 0.5)

    plant1.grow_a_week()
    # plant2 = Plant("Sunflower", 80, 45, 1.0)
    # plant2.grow_a_week()
    # plant3 = Plant("Cactus", 15, 120, 2.0)
    # plant3.grow_a_week()
